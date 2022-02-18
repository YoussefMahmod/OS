#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int INTERACTIVE_MODE = 0;
FILE* in = NULL;

char *env[] = {(char *) "PATH=\bin", 0};

void printError(){
  char error_message[30] = "An error has occurred\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

void preparePrompt(){
  static int firstUse = 1;
  if(firstUse == 1){
    const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
    firstUse = 0;
  }

}

void readInputs(char *command, size_t bufSize){
  ssize_t nread;
  while(1){
    printf("sepSH>");
    if((nread = getline(&command, &bufSize, in)) == -1){
      exit(0);
    }
    //Remove trailling endline
    if(command[nread-1] == '\n'){
      command[nread-1] = '\0';
    }
    printf("%s\n", command);
  }
}

int main(int argc, char *argv[]) {
  char *command = NULL;
  char *parameters = NULL;
  size_t bufSize = 0;

  in = stdin;
  INTERACTIVE_MODE = 1;
  // Mode detection
  if(argc > 1){
    if(argc > 2 || (in = fopen(argv[1], "r")) == NULL){
      printError();
      exit(1);
    }
    INTERACTIVE_MODE = 0;
  }

  printf("\n");

  while(1){
    if(INTERACTIVE_MODE == 1){
      preparePrompt();
    }
    //Reading commands
    readInputs(command, bufSize);
    //End if user asked to exit
    if(strcmp((char *) command, "exit") == 0){
      printf("\nBye :(");
      exit(0);
    }
    printf("%s\n",(char *) command);

  }

  free(command);
  return 0;
}
