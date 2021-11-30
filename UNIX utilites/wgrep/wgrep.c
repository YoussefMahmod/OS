#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  char *search_keyword = argv[1];
  if (argc > 2) {
  
    for (int i = 2; i < argc; ++i) {
      FILE *fp = fopen(argv[i], "r");

      if (fp == NULL) {
	printf("wgrep: cannot open file\n");
	return 1;
      }
    
      char *line = NULL;
      size_t len = 0;
      while (getline(&line, &len, fp) != -1){
	if(strstr(line, search_keyword) != NULL){
	  printf("%s", line);
	
	}
      }
    }
    
  }else{
      char *line = NULL;
      size_t len = 0;
      while (getline(&line, &len, stdin) != -1){
	if(strstr(line, search_keyword) != NULL){
	  printf("%s", line);
	
	}
      }
  }
  return 0;
}
