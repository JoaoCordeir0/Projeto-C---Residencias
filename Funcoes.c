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
	int inadimplenciasAtivas;
	int inadimplencias;		
	char informacoes[200];
	char titular[200];	
	struct Endereco end;
};

void menu(){
	int acao, pos=0, result=0, compara;
	char nome[40], lixo, aux[40];
	struct Residencia res[MAX];
	struct Pessoa titular[MAX];
		
	do{
		printf("\n\n1 - Cadastrar residência ");			
		printf("\n2 - Cadastrar inadimplência ");
		printf("\n3 - Remover uma inadimplência ");
		printf("\n4 - Relatar inadimplências ");
		puts("\n5 - Sair");
		scanf("%d", & acao);
		
		switch(acao){
			case 1:
				result = CadastrarResidencia(res, &pos);	
				if(result){
					printf("\nCadastrado.");
				}
				else{
					printf("\nNão cadastrado.");
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
				puts("\nAté a próxima!");
				break;
			default:
			    printf("\nEscolha invalida!");
		}		
	}while(acao != 5);
}

void CadastrarResidencia(struct Residencia* res,int* pos){
		
}

void CadastrarInadimplencia(){
	
}

void RemoverInadimplencia(){
	
}

void RelatarInadimplencia(){
	
}
