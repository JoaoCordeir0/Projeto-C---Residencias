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

struct Pessoa{
	char nome[40];
	char sexo;
	char cpf;
	struct Telefone fone;
	struct Data nascimento;	
};

struct Residencia{
	int quantidade;
	int inadimplenciasCadastradas;	
	int inadimplenciasAtivas;
	int inadimplencias;		
	char titular[200];	
	struct Endereco end;
	struct Pessoa residente;
};

void menu(){
	int acao, pos=0, result=0, compara;
	char nome[40], lixo, aux[40];
	struct Residencia res[MAX];
	struct Pessoa titular[MAX];
		
	do{
		printf("\n\n1 - Cadastrar resid�ncia ");			
		printf("\n2 - Cadastrar inadimpl�ncia ");
		printf("\n3 - Remover uma inadimpl�ncia ");
		printf("\n4 - Relatar inadimpl�ncias ");
		puts("\n5 - Sair");
		scanf("%d", & acao);
		
		switch(acao){
			case 1:
				result = CadastrarResidencia(res, &pos);	
				if(result){
					puts("\nCadastrado!");
				}
				else{
					puts("\nN�o cadastrado!");
				}			
				break;
			case 2:
				CadastrarInadimplencia();
				break;
			case 3:
				RemoverInadimplencia();
				break;
			case 4:
				RelatarInadimplencia();
				break;
			case 5:
				puts("\nAt� a pr�xima!");
				break;
			default:
			    printf("\nEscolha invalida!");
		}		
	}while(acao != 5);
}

int CadastrarResidencia(struct Residencia* res,int* pos){
	int result = 0, i;
	
	if(*pos < MAX){
		printf("----Informa��es sobre a resid�ncia----\n");
		
		printf("\nEndere�o - CEP -> ");
			gets(res[*pos].end.cep);
		printf("\nEndere�o - Estado -> ");
			gets(res[*pos].end.estado);			
		printf("\nEndere�o - Ciadde -> ");
			gets(res[*pos].end.cidade);
		printf("\nEndere�o - Rua -> ");
			gets(res[*pos].end.rua);
		printf("\nEndere�o - Numero ->");
			scanf("%d", & res[*pos].end.numero);
			
		printf("\nQuantidade de residentes -> ");
			scanf("%d", & res[*pos].quantidade);
		printf("\nNome do residente respons�vel -> ");
			gets(res[*pos].titular);
		printf("\nQuantidade de inadimpl�ncias cadastradas -> ");
			scanf("%d", & res[*pos].inadimplenciasCadastradas);
		printf("\nQuantidade de inadimpl�ncias ativas -> ");
			scanf("%d", & res[*pos].inadimplenciasAtivas);
		printf("\nQuantidade de inadimpl�ncias -> ");
			scanf("%d", & res[*pos].inadimplencias);
			
		puts("\n----Informa��es sobre os residentes----\n");	
		
		for(i=1; i<=res[*pos].quantidade; i++){
			printf("\nNome do %d� residente ->", i);
				gets(res[*pos].residente.nome);	
			printf("\nCPF do %d� residente ->", i);
				gets(res[*pos].residente.cpf);
			printf("\nSexo do %d� residente ->", i);
				gets(res[*pos].residente.sexo);
			printf("\nData de nascimento do %d� residente ->");
				scanf("%d/%d/%d", &res[*pos].residente.nascimento.dia, &res[*pos].residente.nascimento.mes, &res[*pos].residente.nascimento.ano);
			
			if(res[*pos].residente.nascimento.ano > 2022){
				printf("\nTelefone de contato do %d� residente ->");
					scanf("%d%d", &res[*pos].residente.fone.ddd, &res[*pos].residente.fone.numero);
			}					
		}				
		(*pos)++;
		
		result = 1;
	} 
	return result;
}

void CadastrarInadimplencia(){
	
}

void RemoverInadimplencia(){
	
}

void RelatarInadimplencia(){
	
}
