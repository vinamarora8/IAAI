#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STTY "/bin/stty "
const char RAW[] = STTY "raw";
const char COOKED[] = STTY "cooked";

int main() {
  system(RAW);

  char str[] = "I AM AN IDIOT ";
  size_t len = strlen(str);

  while ( 1 ) {
    for ( size_t i = 0 ; i < len ; i++ ) {
      getchar();
      printf("\b%c", str[i]);
    }
    system(COOKED);
    printf("\n");
    system(RAW);
  }

  return 0;
}
