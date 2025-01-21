#include <stdio.h> //Biblioteca de Comunicação com o usuário
#include <stdlib.h> //Biblioteca de Alocação de espaço em memória
#include <locale.h>//Biblioteca de alocações de texto por região 
#include <string.h>//Biblioteca responsavel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file;//cria um arquivo 
	file = fopen(arquivo, "w");//cria um arquivo 
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);// fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite  o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, não foi localizado!.\n");
	}
	
	while(fgets(conteudo,200, file) != NULL) 
	{
		printf("\nEssas são as informaçoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}



int deletar()
{
	printf("você escolheu deletar nomes!\n");
	system("pause");
}



int main()
	{
	int opcao=0;//Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
   {
   	
   	system("cls");
   	
	 setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	 
	 printf("### Cartório da EBAC ###\n\n");//Inicio do menu 
	 printf("Escolha a opçao desejada no menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do sistema\n\n");
	 printf("opção: "); //Final do menu
	
	 scanf("%d", &opcao);//Armazenando a escolha do usuário
	
	 system("cls");
	 
	 switch(opcao)
	 {
	 	 case 1:
	 	 registro();
	 	 break;
	 	 
	 	 case 2:
	 	 consultar();
		 break;
		 
		 case 3:
		 deletar();
		 break;
		 
		 case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		 default:
		 printf("esta opcao nao esta disponivel!\n");
	     system("pause");
		 break;
	     }
	 	
    }

}
