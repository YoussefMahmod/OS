#include<stdio.h>
#define MAX 32

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      return 1;
    }
    char buf[MAX];
    while(fgets(buf, 32, fp) != NULL){
      printf("%s", buf);
    }
    fclose(fp);
  }
  return 0;
}
