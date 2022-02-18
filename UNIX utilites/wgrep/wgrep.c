#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#define BUF_SIZE 1

int main(int argc, char *argv[])
{

  int fd[2];

  if(pipe(fd) == -1){
    return 1;
  }
  
  if (argc == 1) {
    printf("grep: searchterm [file ...]\n");
    return 1;
  }
  char *search_keyword = argv[1];


  int ch_id = fork();
  if (ch_id < 0) {
    return 1;
  }else if (ch_id == 0){
    //child process to preprocess the files or stdin to extract lines that contain the search tearm
    close(fd[0]);
    if (argc > 2) {
  
      for (int i = 2; i < argc; ++i) {
	FILE *fp = fopen(argv[i], "r");

	if (fp == NULL) {
	  close(fd[1]);
	  printf("wgrep: cannot open file\n");
	  return 1;
	}

	char *line = NULL;
	size_t len = 0;    
	while (getline(&line, &len, fp) != -1){
	  if(len > 0 && strstr(line, search_keyword) != NULL){
	    write(fd[1], line, len);
	  }
	  
	line = NULL;
	len = 0;
	}
	fclose(fp);
      }
    
    }else{
      char *line = NULL;
      size_t len = 0;
      while (getline(&line, &len, stdin) != -1){
	if(strstr(line, search_keyword) != NULL){
	  write(fd[1], line, len);
	}
      }
    }
    close(fd[1]);
    exit(0);
  }else{
    wait(NULL);
    //Parent wait for child to find lines which are contains a search term
    
    close(fd[1]);
    char buffer[BUF_SIZE];
    //Reading results from the pipe
    while(read(fd[0], buffer, BUF_SIZE)){
      printf("%s", buffer);
    }
    close(fd[0]);
    exit(0);
  }
  
  return 0;
}
