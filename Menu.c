/**
   @input: lista opções do sistema
   @output: 1,2,3,4 executa ações 
**/

void menu(){
	char acao;
	do{
		printf("1 - Cadastrar cada residência ");			
		printf("2 - Cadastrar inadimplência ");
		printf("3 - Remover uma inadimplência ");
		printf("4 - Relatar inadimplências ");
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
