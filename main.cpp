#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include "parser.h"

using namespace std; 

int main(){


    Parser parser;
    
  // FILE *handle = popen("/bin/cat", "README.md");


  // pclose(handle);
  {
    string aliases[]={"echo"};
    string args[]={"cmd", "aqs"};
    Command echo=Command(1, aliases, "prints stuff", 2, args, "echo <stuff to print>", "long desc");
    parser.addCommand(echo);
  }
  {
    string aliases[]={"exit"};
    string args[]={"cmd"};
    Command exit=Command(1, aliases, "exits", 1, args, "exit", "long desc");
    parser.addCommand(exit);
  }

  while(true){
    printf("[user@host dir]$ ");
    parser.readLn();

    if(parser.getArgumentString(0)=="exit")
      break;
    
    if(parser.getArgumentString(0)=="echo")
      printf("%s\n", parser.getArgumentString(1).c_str());
  
  }
  

  char* args[]={"echo", "a b", NULL};

  for(int i=0; i<1; i++){

    pid_t pid=fork();
    
    if(pid==0)
      execvp(args[0], args);
    // else
      // printf("end\n");
    // execvp(cmd, args);

    // std::system("printf message");

  }

}







