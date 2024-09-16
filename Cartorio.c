#include <stdio.h>//biblioteca de comunicaçao com o usuario
#include <stdlib.h>//biblioteca de alocaçao de espaaço em memoria
#include <locale.h>//biblioteca de alocaçao de texto por regiao
#include <string.h>//biblioteca responsalvel  por cuidar das strings
	
int registro()//funçao responsavel por cadastrar os usuarios
{    //inicio da criaçao de variaveis/strings q sao conjuto de variaveis
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);//%s referece as strings
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores da string
	
	FILE*file;// criar o arquivo
	file=fopen(arquivo, "w");//criar o arquivo,  "w" seginifica escrever
	fprintf(file,cpf);//salvar o valor da variavel
	fclose(file);//fechar o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o seu cargo na ebac: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");

}	
	
int consulta()
{
    setlocale(LC_ALL, "PORTUGUESE");
   
    char cpf[40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE*file;
    file=fopen(cpf, "r");
    
    
    if(file == NULL)
	{
    	printf("Esse cpf não foi cadastrado, tente novamente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		
		printf("\nEssas são as informações de usuario.");
		printf("%s", conteudo);
		printf("\n\n");
	}
    system("pause");
}

 



int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf q você quer deletar.\n");
	scanf("%s", cpf);
	
	remove(cpf);
    	{
		printf("Seu cpf foi deletado!.");
		system("pause");
		}
		
		FILE*file;
		file=fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("Esse cpf não foi cadastrado.");
		system("pause");
	}

	
}

int falha()
{
	printf("Essa opção não existe.\n");
		system("pause");
}


int main()
{

	
int opcao=0;

int voltmenu=0;

    for(voltmenu=1; voltmenu=1;){
    
	
		system("cls");
	
    	setlocale(LC_ALL, "PORTUGUESE");
	
	    printf("\n\t*** Cartório Ebac *** \n\n");
	    printf("Escolha a opção que desejar: \n\n");
     	printf("\t1- registrar nome. \n");
    	printf("\t2- consultar nome. \n");
	    printf("\t3- deletar nome. \n");
	    printf("\t4- Sair do sistema\n\n");
    	printf("Opção:");

    	scanf("%d", &opcao);
	
    	system("cls");//responsavel por limpar a tela 
	
    	switch(opcao)
	{
		case 1:
		registro();
		break;
				
		case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!. \n");
		return 0;
		break;
			
		default:
	    falha();
		break;
		
	}
	
                                }
						
}
