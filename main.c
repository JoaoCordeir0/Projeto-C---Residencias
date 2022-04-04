#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("________________________________\n\n");
	printf("| Sistem de controle moradores |\n");
	printf("________________________________");
	
	menu();

	return 0;
}
