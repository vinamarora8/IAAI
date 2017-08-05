#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
	system("/bin/stty raw");

	int i = 0;
	char str[] = "I AM AN IDIOT ";
	char c = 'a';
	while(1){
		for(i = 0; i<14; i++) {
			c = getchar();
			printf("\b%c", str[i]);
		}
		system("/bin/stty cooked");
		printf("\n");
		system("/bin/stty raw");
	}
	
	return 0;
}
