#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



//funcao
void menu() {
	
  system("cls");
  printf("========== Menu ================\n");
  printf("1 - Inserir\n");
  printf("2 - Alterar\n");
  printf("3 - Excluir\n");
  printf("4 - Consultar\n");
  printf("5 - Sair\n");
  printf("Digite a opcao desejada: ");
	
	
}

int main(){
	struct pessoa {
  	char nome[50];
  	char email[50];
  	char endereco[50];
  	char telefone[10];
  	char celular[11];
  	int ativo;
};

FILE *pont_arq;
  char texto_str[250];
  char* token;
  
  struct pessoa A[200];
  int i = 0,op;
  int x = 0,j,pos;
  
  //abrindo o arquivo registros.txt
  pont_arq = fopen("registros.txt", "r");
 
  //populando o vetor a partir de cada linha do arquivo
  while(fgets(texto_str, 250, pont_arq) != NULL) {
  	
  	//para cada vez que eu achar @ na linha do arquivo, carrego o peda?o na variaval token
	token = strtok(texto_str, "/");
		
 while (token != NULL) {
        
      if (x == 0)   {
	  //campo Nome
        strcpy(A[i].nome,token);
        x++;
      } else if (x == 1) {
      	//campo email
      	strcpy(A[i].email,token);
		x++;  
	  } else if (x == 2) {
	  	//campo endereco
	  	strcpy(A[i].endereco,token);
	    x++;
	  }	else if (x == 3) {
	  	//campo telefone
	  	strcpy(A[i].telefone,token);
	    x++;
	  } else if (x == 4) {
	  	//campo celular
	  	strcpy(A[i].celular,token);
	    x++;
	  }
	  
	  else if (x == 5) {
	  	//campo ativo
      	A[i].ativo = atoi(token);
        x++;
	  }
        token = strtok(NULL, "/"); // proximo peda?o da linha at? @
       
    }
     x=0; // contador de campos
     i++; // indice geral do vetor
}
  
  fclose(pont_arq); //fechando o arquivo
  
menu(); //chamando o menu
  scanf("%d",&op);
  
  while (op != 5) {
  	
  	
  	switch(op) {
  		case 1:
  			
  			while(A[i].ativo==1){
  				i++;
  			}
  			printf("Nome ...: ");
  			scanf(" %[^\n]",&A[i].nome);
  			
  			printf("Email ...: ");
  			scanf("%s",&A[i].email);
  			
  			printf("Endereço ...: ");
  			scanf(" %[^\n]",&A[i].endereco);
  			
  			printf("Telefone ...: ");
  			scanf("%s",&A[i].telefone);
  			
  			printf("Celular ...: ");
  			scanf("%s",&A[i].celular);
  			
  			A[i].ativo=1;
  			
  		break;
  		case 2:
  			printf("Digite o codigo do registro: ");
  			scanf("%d",&pos);
  			
  			printf("\n%s - %s - %s - %s - %s - %d\n\n", A[pos].nome, A[pos].email, A[pos].endereco, A[pos].telefone, A[pos].celular, A[pos].ativo);
  			
  			printf("Nome ...: ");
  			scanf(" %[^\n]",&A[pos].nome);
  		
  			printf("Email ...: ");
  			scanf("%s",&A[pos].email);
  			
  			printf("Endereço ...: ");
  			scanf(" %[^\n]",&A[pos].endereco);
  			
  			
  			printf("Telefonel ...: ");
  			scanf("%s",&A[pos].telefone);
  			
  			printf("Celular ...: ");
  			scanf("%s",&A[pos].celular);
  			
  			
  		break;
  		case 3:
  			printf("Digite o codigo do registro: ");
  			scanf("%d",&pos);
  			
  			A[pos].ativo=0;
  			printf("\n%s - %s - %s - %s - %s - %d\n\n", A[pos].nome, A[pos].email, A[pos].endereco, A[pos].telefone, A[pos].celular, A[pos].ativo);
  			printf("Registro excluido!\n\n");
  			system("pause");
  			
  		break;
  		case 4:
  			printf("Digite o codigo do registro: ");
  			scanf("%d",&pos);
  			
  			printf("\n%s - %s - %s - %s - %s - %d\n\n", A[pos].nome, A[pos].email, A[pos].endereco, A[pos].telefone, A[pos].celular, A[pos].ativo);
  			system("pause");
  		break;
  		default:
  			printf("Opcao invalida!\n");
		break;    		
  		
	  }
  	
  	menu();
  	scanf("%d",&op);
  	
  	
  }
  // salvando as informa??es no menu. "w" abre o arquivo para escrita e limpa o que h? dentro.
  pont_arq = fopen("registros.txt", "w");
  
  for(j=0; j < 10; j++) {
  	
    if (A[j].ativo == 1){
	  	fprintf(pont_arq,"%s/%s/%s/%s/%s/%d\n", A[j].nome, A[j].email, A[j].endereco, A[j].telefone, A[j].celular, A[j].ativo);
    }
  }
  
  fclose(pont_arq);
    
}
