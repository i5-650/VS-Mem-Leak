# VS-Mem-Leak
A simple Visual Studio tool that i use to check if there are some memory leak in my C/C++ code.

## How to use
You just have to add those 2 lines.
```c
#include "mem_leak.h"

int main(){
  _CrtMemState sOld = init_valgrind();
  
 // some code
  char *str = malloc(sizeof(char)*4);

  end_valgrind(sOld);
  return EXIT_SUCCESS;
}
```
When the program will end, it will ask you to press any key of you've finished reading the debug console. 
Every informations will be in there.

## Note
It work **only** on Visual Studio (so on Windows). If you're a linux user, you can directly use valgrind.
