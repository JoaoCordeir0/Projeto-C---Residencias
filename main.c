#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>

#define MAX 100

struct Telefone{ 
	int ddd;
	int numero;
};

struct Data{
	int dia,
	    mes,
	    ano;
};

struct Endereco{
	int numero;
	char rua;	
	char cep;
	char cidade;
	char estado;
};

struct Dados{
	char nome[40];
	char sexo;
	char cpf;
	struct Telefone fone;
	struct Data nascimento;	
};

struct Residencia{
	int quantidade;
	int inadimplenciasAtivas;
	int inadimplencias;	
	struct Endereco end;
	char informacoes[200];
	char titular[200];	
};

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("________________________________\n\n");
	printf("| Sistem de controle moradores |\n");
	printf("________________________________");
	
	menu();

	return 0;
}
