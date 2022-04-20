#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("___________________________________\n\n");
	printf("| Sistem de controle de moradores |\n");
	printf("___________________________________\n");
	
	menu();

	return 0;
}
