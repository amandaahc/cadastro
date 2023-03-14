#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct cadastro {
    char nome [30];
    char cpf [30];
    char vacina[30];
    char data[30];
    char lote[30];    
};

struct cadastro cadastroVacina(){
	
	struct cadastro cadast;
	
	printf("informe o nome: \n");
	fflush(stdin);
	gets(cadast.nome);	
	printf("Informe o CPF: \n");
	fflush(stdin);
	gets(cadast.cpf);	
	printf("Informe a vacina: \n");
	fflush(stdin);
	gets(cadast.vacina);	
	printf("Informe a data da aplicação:  DD/MM/AAAA \n");
	fflush(stdin);
	gets(cadast.data);	
	printf("Informe o número do lote: \n");
	fflush(stdin);
	gets(cadast.lote);
	
	return cadast;
	
	
};

void listaCadastro (struct cadastro cadastros[], int quantCadastro){
	int i;
	for(i= 0; i < quantCadastro; i++){
		printf("\n\n");
		printf("Codigo: %d \n", i);
		printf("Nome: %s \n", cadastros[i].nome);
		printf("CPF: %s \n", cadastros[i].cpf);
		printf("Vacina: %s \n", cadastros[i].vacina);
		printf("Data: %s \n", cadastros[i].data);
		printf("Número do Lote: %s \n", cadastros[i].lote);
		printf("\n\n");
		
	}
};

void pesquisaCpf (struct cadastro buscarCpf[], char cpfPesquisar[], int quantCadastro ){
	int i, achou = 0;
	for (i = 0; i < quantCadastro; i++){
	    if (strcmp (buscarCpf[i].cpf, cpfPesquisar) == 0 ){	
			printf("\n\n");
	     	printf("Codigo: %d \n", i);
			printf("Nome %s \n", buscarCpf[i].nome);
			printf("CPF %s \n", buscarCpf[i].cpf);
			printf("Vacina %s \n",buscarCpf[i].vacina);
			printf("Data %s \n", buscarCpf[i].data);
			printf("Lote %s \n", buscarCpf[i].lote);
			printf("\n\n");
			achou = 1;
		}
	}
	if(achou != 1){
		printf("Não encontramos o CPF: %s nos %d cadastros", cpfPesquisar, quantCadastro);
	}
}

void main() {
	
	setlocale(LC_ALL, "Portuguese");
    char busca[30];
    int i;
	int opcao = 0;
	int contCadastro = 0;
	struct cadastro cadVacina[999];

	
  do{
  	printf("\n\n");
   	printf("++++++++++MENU++++++++++ \n");
  	printf("\n\n");
  	printf("1- Cadastrar vacina \n");
  	printf("2- Listar Aplicações \n");
  	printf("3- Consultar por CPF \n");
  	printf("4- Sair \n");
  	printf("Digite uma opcao desejada: \n");
  	scanf("%d" , &opcao);
  	  system("cls");
  	    switch(opcao){
  	    	case 1: {
  	  	    	cadVacina[contCadastro] = cadastroVacina();
  	  	    	contCadastro++; 
		    	system("pause"); 	  		
			break;
	    	} 
		
	    	case 2:{
            	system("cls");			
	    		listaCadastro( cadVacina, contCadastro);
		    	system("pause"); 
		    break;
	    	}
  	    	case 3: {
            	fflush(stdin); 	  		
  	  			printf("Informe o CPF desejado: \n");
				gets(busca);
            	pesquisaCpf (cadVacina, busca, contCadastro);
		    	system("pause"); 
            break;
            }
    		case 4: {
		    	printf("Encerando... \n");
			
			break;
			
    		}default: {
    	    	printf(" Opção inválida! \n");
		    	system("pause"); 		
		    break;
	    	}
  	  	
		}
  }while(opcao !=4);
	
}
