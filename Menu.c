/**
   @input: lista op��es do sistema
   @output: 1,2,3,4 executa a��es 
**/

void menu(){
	char acao;
	do{
		printf("1 - Cadastrar cada resid�ncia ");			
		printf("2 - Cadastrar inadimpl�ncia ");
		printf("3 - Remover uma inadimpl�ncia ");
		printf("4 - Relatar inadimpl�ncias ");
		printf("5 - Sair");
		scanf("%d", & acao);
		
		switch(acao){
			case 1:
				CadastrarResidencia();				
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
				break;
			default:
			    printf("\nEscolha invalida!");
		}		
	}while(acao != 5);
}
