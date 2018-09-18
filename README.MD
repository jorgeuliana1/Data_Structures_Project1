# OUR DATA STRUCTURES PROJECT (2018/2)
Project by @jorgeuliana1 and @LuccaPassos

## Messages Area:
### The example message (DD-MM-YYYY):
This is a message
### "Version 0.1" (18-09-2018):
We made some progress!\
I am going to write everything here.
**Think different (And simple):**\
Now there's only one library, wich is nice! I named it "net", because it is really short and fits its functionalities (basically it controls the net).\
We can create other libs in the future!

### Messages to Lucca (16 - 09 - 2018):
Here I am going to send you some ideas and specifications.\
I am open to any suggestions, this is only my original idea.
#### About the code appearence:
Well, I am thinking about something like this:\
Identation size: 2 spaces
**Apearence:**
```c
#include <lib.h>

void codeBlock(char ThisIsAnArgument1, float ThisIsAnArgument2) {
  int thisIsAVariable;
  if(statement) {
    doIt(thisIsAnArgument1, thisIsAnArgument2);
  }
  return;
}
```
#### About the libraries:
**main.c:**
\
Initial idea:
```c
  openFile;
  doInicializations;
  while(thereIsCommands) {
    interpretateFileCommands;
    doTheCommands;
  }
  generateTheGraphVisFile;
  doFinalizations;
  closeFile;
  finish;
```
\
**list.h:**
\
This library is responsible for the TypeLists and TypeCells, it would be great.
\
if you knew how to implementate the structures in a generic way, because I don't know how.

**router.h:**
\
Well, it controls the Router type, not much to say.

**router.h:**
\
Well, it controls the Terminal type, also not much to say.
#### Extra:
For more info look at the header files.\
You can freely edit this file. I highly recommend you to follow the guidelines, but you are free.
