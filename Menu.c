/**
   @input: lista opções do sistema
   @output: 1,2,3,4 executa ações 
**/

void menu(){
	char acao;
	do{
		printf("\n\n1 - Cadastrar cada residência ");			
		printf("\n2 - Cadastrar inadimplência ");
		printf("\n3 - Remover uma inadimplência ");
		printf("\n4 - Relatar inadimplências ");
		puts("\n5 - Sair");
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
				puts("\nAté a próxima!");
				break;
			default:
			    printf("\nEscolha invalida!");
		}		
	}while(acao != 5);
}
