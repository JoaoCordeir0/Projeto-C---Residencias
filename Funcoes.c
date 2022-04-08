#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 100

struct Telefone{ int ddd, numero; };

struct Data{ int dia, mes, ano; };

struct Pessoa{
	char nome[40];
	char sexo[10];
	char cpf[14];
	struct Telefone fone;
	struct Data nascimento;	
};

struct Residencia{
	int quantidade;
	int inadimplenciasCadastradas[50];	
	int inadimplenciasAtivas[50];
	int inadimplencias[50];	
	int numero;
	
	int ano;
	int mes;
	float valor;
	
	char rua[60];	
	char cep[60];
	char cidade[60];
	char estado[60];
	char titular[60];	
	
	struct Pessoa residente;
};

void menu(){
	int acao, pos=0, result=0, compara, a, numeroCasa, mes, ano;
	float valor;
	char lixo, aux[40], rua[60];
	struct Residencia res[MAX];
	struct Pessoa user[MAX];	
		
	do{
		printf("\n\n1 - Cadastrar residência ");			
		printf("\n2 - Cadastrar inadimplência ");
		printf("\n3 - Remover uma inadimplência ");
		printf("\n4 - Relatar inadimplências ");
		puts("\n5 - Sair");
		scanf("%d", & acao);
		
		switch(acao){
			case 1:
				scanf("%c", &lixo);
				result = CadastrarResidencia(user, res, &pos);	
					if(result){
						puts("\nCadastrado!");
					}
					else{
						puts("\nNão cadastrado!");
					}			
				break;
			case 2:
				scanf("%c", &lixo);
				printf("\nInforme o nome da rua -> ");
					gets(rua);
				printf("\nInforme o numero da casa -> ");
					scanf("%d", & numeroCasa);
					
				result = CadastrarInadimplencia(rua, numeroCasa, res, pos);
				
				if(result==-1){
					printf("\nResidência não encontrada!");					
				}else{
					printf("\nInadimplência cadastrada com sucesso para está residência!");	
				}																
				break;
			case 3:
				printf("Em dev");
				break;
			case 4:	
				scanf("%c", &lixo);										
				RelatarInadimplencia(res, pos);
				break;
			case 5:
				puts("\nAté a próxima!");
				break;
			default:
			    printf("\nEscolha invalida!");
		}		
	}while(acao != 5);
}

/*
	Função que realiza o cadastro de uma nova residência;
*/
int CadastrarResidencia(struct Pessoa* user, struct Residencia* res, int* pos){
	int result = 0, i;
	
	if(*pos < MAX){	
		puts("----Informações sobre a residência----");
		
		printf("\nNome do residente responsável -> ");
			gets(res[*pos].titular);
		printf("\nEndereço - CEP -> ");
			gets(res[*pos].cep);			
		printf("\nEndereço - Estado -> ");
			gets(res[*pos].estado);			
		printf("\nEndereço - Ciadde -> ");
			gets(res[*pos].cidade);
		printf("\nEndereço - Rua -> ");
			gets(res[*pos].rua);
			
		printf("\nEndereço - Numero ->");
			scanf("%d", & res[*pos].numero); fflush(stdin);			
		printf("\nQuantidade de residentes -> ");
			scanf("%d", & res[*pos].quantidade); fflush(stdin);		
			
		puts("\n----Informações sobre os residentes----");	
		
		for(i=1; i<=res[*pos].quantidade; i++){
			printf("\nNome do %dº residente ->", i);
				gets(user[*pos].nome); 
			printf("\nCPF do %dº residente ->", i);
				gets(user[*pos].cpf); 
			printf("\nSexo do %dº residente ->", i);
				gets(user[*pos].sexo); 
			printf("\nData de nascimento do %dº residente ->", i);
				scanf("%d/%d/%d", &user[*pos].nascimento.dia, &user[*pos].nascimento.mes, &user[*pos].nascimento.ano);
			
			if((user[*pos].nascimento.ano + 18) <= 2022){
				printf("\nTelefone de contato do %dº residente ->", i);
					scanf("%d%d", &user[*pos].fone.ddd, &user[*pos].fone.numero);
			}					
		}				
		(*pos)++;
		
		result = 1;
	} 
	return result;
}

/*
	Função que realiza a busca de uma residência e cadastra uma inadimplência;
*/
int CadastrarInadimplencia(char *rua, int numeroCasa, struct Residencia* res, int pos){
	int i, result=-1, mes, ano;
	float valor;
	
	for(i=0; i<pos; i++){
		if(strcmp(res[i].rua, rua) == 0 && res[i].numero == numeroCasa){		
			result = i;
			i = pos;		
		}
	}
	if(result >= 0){
		printf("\nResidência selecionada!\n");	
			printf("\nDigite o mes e ano da inadimplência -> ");
				scanf("%d%d", & mes, &ano);
			printf("Digite o valor da inadimplência -> ");
				scanf("%f", & valor);
			if(mes >= 1 && ano >= 1){
				res[result].mes = mes;
				res[result].ano = ano;
				res[result].valor = valor;
				res[result].inadimplenciasCadastradas[result] = res[result].inadimplenciasCadastradas[result] + 1;
				res[result].inadimplenciasAtivas[result] = res[result].inadimplenciasAtivas[result] + 1;											
			}
	}
	return result; 
}

int RemoverInadimplencia(){
	
}

void RelatarInadimplencia(struct Residencia* res, int pos){
	int i, j;
	float somaValor=0;
	
	puts("\n----Listagem de residências----");
		for(i=0; i<pos; i++){
			printf("\n\nNome do titular -> %s\n", res[i].titular);
			printf("\nNome da rua -> %s\n", res[i].rua);
			printf("\nNumero da casa -> %d\n", res[i].numero);
			
			for(j=0; j<res[i].inadimplenciasCadastradas; j++){
				printf("\nInadimplência no mês %d ano %d no valor de %f\n", res[j].mes, res[j].ano, res[j].valor);
			}
			somaValor = somaValor + res[i].valor;
			printf("\nValor total de inadimplências -> %f", somaValor);
		}	
}

