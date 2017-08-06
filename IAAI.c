#include <stdio.h>
#include <stdlib.h>

#define STTY "/bin/stty "
const char RAW[] = STTY "raw";
const char COOKED[] = STTY "cooked";

int main() {
  system(RAW);

  char str[] = "I AM AN IDIOT ";

  while ( 1 ) {
    for ( int i = 0 ; i < 14 ; i++ ) {
      getchar();
      printf("\b%c", str[i]);
    }
    system(COOKED);
    printf("\n");
    system(RAW);
  }

  return 0;
}
