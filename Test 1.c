#include <stdio.h> //Bliblioteca de comunica��o com o usuario
#include <stdlib.h> //Blibioteca de aloca��o de memoria
#include <locale.h> //Bliblioteca de aloca��o de de texto por regi�o
#include <string.h> //Bliblioteca responsavel por cuidar das strings

int registro() // fun��o responsalvel por cadastrar os produtos nos sistemas
{
	setlocale(LC_ALL, "portuguese");
	
	//inicio da cria�oes de variaveis/string
	char arquivo[50];
	char Serial[50];
	char Mercadoria[200];
	char Fabricacao[50];
	char Vencimento[50];
	//final da cria�oes de variaveis/string
	
	printf("Digite o serial do produto: ");//coletando informa��es dos produtos
	scanf("%s", Serial);//%s refere-se a strings
	
	strcpy(arquivo, Serial); //Responsalvel Por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen (arquivo, "w"); //Cria o arquivo o "w" e usado para escrever
	fprintf(file,Serial); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome da mercadoria: ");
	scanf("%s",Mercadoria);
	
	file = fopen(arquivo, "a");
	fprintf(file,Mercadoria);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite a data de fabrica��o do produto: ");
	scanf("%s",Fabricacao);
	
	file = fopen(arquivo, "a");
	fprintf(file,Fabricacao);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Dite o vencimento do produto: ");
	scanf("%s",Vencimento);
	
	file = fopen(arquivo, "a");
	fprintf(file,Vencimento);
	fclose(file);
	
	system("pause");
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char Serial[50];
	char conteudo[200];
	char *token;
	
	printf("Digite o serial do produto a ser consultado: ");
	scanf("%s",Serial);
	
	FILE *file;
	file = fopen(Serial,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o locazidado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do produto consultado. \n");
		
		token = strtok(conteudo, ",");
		printf("Serial: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Mercadoria: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Fabricacao: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Vencimento: %s\n", token);
			
	}
	
	printf("\n");
	
	fclose(file);
	system("pause");
	
}

int despacho()
{
	setlocale(LC_ALL, "portuguese");
	
	char Serial[50];
	
	printf("Digite o serial do produto a ser despachado: ");
	scanf("%s", Serial);
	
	
	FILE *file;
	file = fopen(Serial,"r");
	
	if(file == NULL)
	{
		printf("Mercadoria n�o encontrada! \n");
		system("pause");
		return 0;
	}
	
	fclose(file);
	
	if(remove(Serial) == 0)
	{
		printf("Produto despachado com sucesso!\n");
	}
	
	else
	{
		printf("Erro ao remover o arquivo.\n");
	}
	
	fclose(file);
	system("pause");
	return 0;
	
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
{
	
	system("cls");//responsavel por limpar a tela
	
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	printf("###REGISTRO DE MERCADORIAS###\n\n"); //inicio do menu
	printf("OP�OES DE MENU:\n\n");
	printf("\t1 Registrar mercadoria\n");
	printf("\t2 Consultar mercadoria\n");
	printf("\t3 Despachar mercadoria\n\n");
	printf("Op��o:"); // fim do menu
	
	scanf("%d", &opcao); // armazenando a escolha do usuario
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		despacho();
		break;
		
		default:
		printf("ESSA OP��O NAO ESTA DISPONIVEL\n");
		system("pause");
		break;
	}
	

}
}
