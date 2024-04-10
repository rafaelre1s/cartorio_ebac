#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	// Inicio da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação das variáveis/strings
	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", cpf); //%S refere-se a s de String
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever (write)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	char cpf[40];
    char conteudo[200];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause"); 
}

int deletar()
{
	char cpf [40];
	
	printf ("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
{
	printf("O usuário digitado não se encontra no sistema! .\n");
	system("pause");
}
	
}

int main()
{
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		
	system("cls"); //responsável por limpar a tela
	
	
	setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
		
	printf("### Registro de alunos - EBAC ### \n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n\n"); 
	printf("Opção: "); //fim do menu
    
    scanf("%d", &opcao); //armazenando a escolha do usuário
    
    system("cls"); //limpando a tela depois da opção do usuário
    
    switch(opcao) //Inicio da seleção do menu
    {
    	case 1:
    	registro(); //chama função
    	break;
    	
    	case 2:
    	consulta();
	    break;
	    
	    case 3:
	    deletar();
	  	break;
		
		default:
		printf("Esta opção não está disponível\n");
        system("pause");
        break;  		
	}  //fim da selação
}
}


