#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char RAW[] = "/bin/stty raw";
#define CLEAR_LINE     "\x1b[2K"
#define GOTO_START     "\r"
#define GOTO_NEXT_LINE "\n"

const char default_str[] = "I AM AN IDIOT ";

int main(int argc, char **argv) {
  const char *str;
  if ( argc == 2 )
    str = argv[1];
  else
    str = default_str;

  size_t len = strlen(str);

  system(RAW);

  while ( 1 ) {
    for ( size_t i = 0 ; i < len ; i++ ) {
      getchar();
      printf(CLEAR_LINE GOTO_START);
      for ( size_t j = 0 ; j <= i ; j++ ) {
	printf("%c", str[j]);
      }
    }
    printf(GOTO_NEXT_LINE GOTO_START);
  }

  return 0;
}
