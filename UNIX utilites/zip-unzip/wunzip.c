#include<stdio.h>

int main(int argc, char *argv[]){

  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }
 
  for (int i = 1; i < argc; ++i) {
    int counter = 0;
    FILE *fp = fopen(argv[i], "r");
    
    if(fp == NULL){
      printf("wunzip: cannot open file\n");
      return 1;
    }

    while(fread(&counter, sizeof(int), 1, fp) == 1){
      char compressed_char = fgetc(fp);
      
      for (int j = 0; j < counter; ++j) {
	printf("%c",compressed_char);
      }
    }
    
    fclose(fp);
  }

  return 0;
}

