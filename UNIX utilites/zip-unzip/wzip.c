#include<stdio.h>

int main(int argc, char *argv[]){

  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }

int count = 0;
char last = '\0';
char ch = '\0';
  for (int i = 1; i < argc; ++i) {

    //opening the file
    FILE *fp = fopen(argv[i], "r");
    
    if(fp == NULL){
      printf("wzip: cannot open file\n");
      return 1;
    }


    //reading characters
    while ((ch = fgetc(fp)) != EOF) {
      if(ch == last){
	    count++;
      }else{
	    if(last != '\0'){
	    fwrite(&count, sizeof(int), 1, stdout);
	    fputc(last, stdout);
	    }
	count = 1;
	last = ch;
      }
    }
 //      printf("%d", count);
    
    fclose(fp);
  }
  if(count){
        fwrite(&count, sizeof(int), 1, stdout);
	    fputc(last, stdout);
}
  return 0;
}
