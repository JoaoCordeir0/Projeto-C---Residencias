#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

int tamanhoVetor = 100;

struct Telefone{ int ddd, numero; };

struct Data{ int dia, mes, ano; };

struct DataInadiplencia { int ano, mes; float valor;};

struct Pessoa{
	char nome[40];
	char sexo[10];
	char cpf[14];
	struct Telefone fone;
	struct Data nascimento;	
};

struct Residencia{
	int quantidade;
	int inadimplenciasCadastradas;	
	int inadimplenciasAtivas;
	int inadimplencias;	
	int numero;	
	
	char rua[60];	
	char cep[60];
	char cidade[60];
	char estado[60];
	char titular[60];	
	
	struct Pessoa residente;
	struct DataInadiplencia date;
};

void menu(){
	int acao, pos=0, result=0, compara, numeroCasa, mes, ano;
	float valor;
	char lixo, aux[40], rua[60];
	struct Residencia *res[tamanhoVetor];
	struct Pessoa *user[tamanhoVetor];	
		
	do{
		printf("\n1 - Cadastrar residência ");			
		printf("\n2 - Cadastrar inadimplência ");
		printf("\n3 - Remover uma inadimplência ");
		printf("\n4 - Relatar inadimplências ");
		puts("\n5 - Sair");
		scanf("%d", & acao);
		
		switch(acao){
			case 1:
				scanf("%c", &lixo);			
				if(pos == tamanhoVetor){
					res[tamanhoVetor] = malloc(sizeof(struct Residencia)*(tamanhoVetor+10));					
					tamanhoVetor += 10;
					printf("\nALocando mais espaço de memória... tente denovo! \n");			
				}else{				
					result = CadastrarResidencia(user, res, &pos);		
					if(result){
						puts("\nCadastrado!");
					}
					else{
						puts("\nNão cadastrado!");
					}
				}									
				break;
			case 2:
				scanf("%c", &lixo);
				printf("\nInforme o nome da rua -> ");
					gets(rua);
				printf("Informe o numero da casa -> ");
					scanf("%d", & numeroCasa);
					
				result = CadastrarInadimplencia(rua, numeroCasa, res, pos);
				
				if(result==-1){
					printf("\nResidência não encontrada!\n");					
				}else{
					printf("\nInadimplência cadastrada com sucesso para está residência!\n");	
				}																
				break;
			case 3:
				scanf("%c", &lixo);
				printf("\nInforme o nome da rua -> ");
					gets(rua);
				printf("\nInforme o numero da casa -> ");
					scanf("%d", & numeroCasa);
				printf("\nDigite o mes e ano da inadimplência a ser removida-> ");
					scanf("%d%d", & mes, & ano);		
					
				result = RemoverInadimplencia(rua, numeroCasa, mes, ano, res, pos);
				
				if(result==-1){
					printf("\nResidência não encontrada!\n");					
				}else{
					printf("\nInadimplência removida com sucesso para está residência!\n");	
				}
				break;
			case 4:	
				scanf("%c", &lixo);										
				RelatarInadimplencia(res, pos);
				break;
			case 5:
				puts("\nAté a próxima!");
				exit(0);
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
	char lixo;
	//fflush(stdin); == Serve para limpar o buffer do teclado.
	
	if(*pos < tamanhoVetor){	
		puts("----Informações sobre a residência----");
		
		printf("\nNome do residente responsável -> ");
			gets(res[*pos].titular); fflush(stdin);	
		printf("Endereço - CEP -> ");
			gets(res[*pos].cep); fflush(stdin);				 
		printf("Endereço - Estado -> ");
			gets(res[*pos].estado);	fflush(stdin);		 	
		printf("Endereço - Ciadde -> ");
			gets(res[*pos].cidade); fflush(stdin);	
		printf("Endereço - Rua -> ");
			gets(res[*pos].rua); fflush(stdin);	
		printf("Endereço - Numero -> ");
			scanf("%d", & res[*pos].numero); fflush(stdin);			
		printf("Quantidade de residentes -> ");
			scanf("%d", & res[*pos].quantidade); fflush(stdin);		
			
		puts("\n----Informações sobre os residentes----");	
		
		for(i=1; i<=res[*pos].quantidade; i++){
			printf("\nNome do %dº residente ->", i);
				gets(user[*pos+i].nome); fflush(stdin);	
			printf("CPF do %dº residente ->", i);
				gets(user[*pos+i].cpf); fflush(stdin);	
			printf("Sexo do %dº residente ->", i);
				gets(user[*pos+i].sexo); fflush(stdin);	
			printf("Data de nascimento do %dº residente ->", i);
				scanf("%d/%d/%d", &user[*pos+i].nascimento.dia, &user[*pos+i].nascimento.mes, &user[*pos+i].nascimento.ano); fflush(stdin);	
			
			if((user[*pos+i].nascimento.ano + 18) <= 2022){
				printf("Telefone de contato do %dº residente ->", i);
					scanf("%d%d", &user[*pos+i].fone.ddd, &user[*pos+i].fone.numero); fflush(stdin);	
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
				scanf("%d%d", & mes, & ano);
			printf("Digite o valor da inadimplência -> ");
				scanf("%f", & valor);
			if(mes >= 1 && ano >= 1){
				res[result].date.mes = mes;
				res[result].date.ano= ano;
				res[result].date.valor= valor;
				res[result].inadimplenciasCadastradas = res[result].inadimplenciasCadastradas + 1;
				res[result].inadimplenciasAtivas = res[result].inadimplenciasAtivas + 1;											
			}
	}
	return result; 
}

int RemoverInadimplencia(char *rua, int numeroCasa, int mes, int ano, struct Residencia* res, int pos){
	int i, result=-1;
	
	for(i=0; i<pos; i++){
		if(strcmp(res[i].rua, rua) == 0 && res[i].numero == numeroCasa && res[i].date.mes == mes && res[i].date.ano == ano){		
			result = i;	
			i = pos;		
		}
	}
	if(result >= 0){
		res[result].date.valor= res[result].date.valor - res[result].date.valor;
		res[result].inadimplenciasCadastradas = res[result].inadimplenciasCadastradas - 1;
		res[result].inadimplenciasAtivas = res[result].inadimplenciasAtivas - 1;														
	}
	return result; 
}

void RelatarInadimplencia(struct Residencia* res, int pos){
	int i, j;
	float somaValor=0;
	
	puts("\n----Listagem de residências----");
		for(i=0; i<pos; i++){
			printf("\n\nNome do titular -> %s\n", res[i].titular);
			printf("\nNome da rua -> %s\n", res[i].rua);
			printf("\nNumero da casa -> %d\n", res[i].numero);
			
			for(j=i; j<res[i].inadimplenciasCadastradas; j++){
				printf("\nInadimplência no mês %d no ano de %d no valor de %.2f\n", res[j].date.mes, res[j].date.ano, res[j].date.valor);
				somaValor = somaValor + res[j].date.valor;
			}			
			printf("\nValor total de inadimplências -> %.2f", somaValor);
			
			somaValor = 0;
			printf("\n");
		}	
}

