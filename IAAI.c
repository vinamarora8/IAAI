#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STTY "/bin/stty "
const char RAW[] = STTY "raw";
const char COOKED[] = STTY "cooked";

const char default_str[] = "I AM AN IDIOT ";

int main(int argc, char **argv) {
  system(RAW);

  const char *str;
  if ( argc == 2 )
    str = argv[1];
  else
    str = default_str;

  size_t len = strlen(str);

  while ( 1 ) {
    for ( size_t i = 0 ; i < len ; i++ ) {
      getchar();
      printf("\x1b[2K\r");
      for ( size_t j = 0 ; j <= i ; j++ ) {
	printf("%c", str[j]);
      }
    }
    system(COOKED);
    printf("\n");
    system(RAW);
  }

  return 0;
}
