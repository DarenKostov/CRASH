//readLn- reads a line and puts it in the parsers memory

// returnCommand- itll return the command/arguments dependig on what you give it
// 0-command
// 1-arg 1
// 2-arg 2
// etc

//inpit stores the entire line
//command store each induvudual command and argment in the line

//fixCommand- fixes the command input as well as apply aliases

//commandIndex is the index of the inputed command (help is 0, features is 1, tips is 2, etc) 

//command refers to the whole thing the user inputs
//arguments reffers to a specific section of the thing the user inputs

//command definition refers to the structure of the command, what is supposed to be an int, what is bool, etc 


#include <vector>
#include <string>
#include <any>

#include "./command.h"

#ifndef PARSER
#define PARSER

//watch out fot "command" capitalization in the comments

class Parser{
  public:
    //empty parser
    Parser();
    ~Parser();

    //=manage command storage
    
    //adds a single Command from a Command POINTER
    void addCommand(Command*);

    //adds Commands from a vector of Command POINTERS
    void addCommands(std::vector<Command*>);

    //adds a single Command from a Command
    void addCommand(Command);  
    
    //adds Commands from a vector of Commands
    void addCommands(std::vector<Command>); //adds Commands from a vector of Commands
    
    //removes a command given its 1st alias
    bool removeCommand(std::string);


    //gives all commands in the parser
    std::vector<Command> getAllCommands();

    //returns what is the Command definition at an index
    Command commandDefAt(int);
    Command commandDefinitionAt(int);

    //returns the current command index in the Command vector
    int getCommandIndex();


  
    //=manage user input

    //reads in a line from the user's input
    void readLn();

    //returns what is the command/argument inputed at that index in string form
    std::string getArgumentString(int i);
  
    //returns entire inputted string from the user
    std::string getWholeString(int i);
    std::string getWholeInputString(int i);
  
    
  
  private:    
    //where all posible Command definitions are stored
    std::vector<Command> allCommandDef;
    
    //the current commands inputed with its inputed arguments (cast a type pointer of the type it should be)
    // std::any* currentArguments;
  
    // the command inputed but in Text form
    std::string* currentCommandString;

    // the amount of arguments inputed, believe it or not without this there is a major seg fault  
    int currentCommandLength; 
    
    //determines what command the user inputed, returns false if it couldnt determine
    bool setCurrentCommand(std::string);
  
    // fixes the arguments inputed returns 1 for success
    void fixArgs(std::string*, int, int);
  
    // the current command index
    int commandIndex;
  
    // the current command inputed definition
    Command* currentCommandDef;
  
    //an empty command
    Command emptyCommand;

};


//give it between which chars should the string be, your string array, from where to start in the string array, and the size of the array
string parseWithStartAndEnd(char, char, string*, int&, int);


#endif
