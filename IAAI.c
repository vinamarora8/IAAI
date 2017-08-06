#include <stdio.h>
#include <stdlib.h>

int main() {
  system("/bin/stty raw");

  int i = 0;
  char str[] = "I AM AN IDIOT ";

  while(1){
    for(i = 0; i<14; i++) {
      getchar();
      printf("\b%c", str[i]);
    }
    system("/bin/stty cooked");
    printf("\n");
    system("/bin/stty raw");
  }
	
  return 0;
}
