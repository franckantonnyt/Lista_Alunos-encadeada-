#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*LISTA ENCADEADA
-info contato(nome, telefone)
-implementar adicionar a lista(i,m,f)
-buscar(pos,nome)
-remover(i,m,f)
*/
typedef struct agenda{
	char nome[30];
	int numero;
	struct agenda *prox;
}contato;
//MENU
int menu(int x)
{
	do
	{
		printf("1 - Cadastrar Novo Contato\n2 - Buscar Contato\n3 - Remover Contato\n4 - Sair\n");
		scanf("%i",&x);
		if(x < 1 || x > 4)
		{
			printf("Opção Invalida!\n");
		}
	}while(x < 1 || x > 4);
	return x;
}
//IMPLEMENTAR
void implementar(contato *fim)
{
	printf("- Novo Contato -\n");
	printf("Nome - ");
	scanf(" %[^\n]s", fim->nome);
	printf("Telefone - ");
	scanf("%i",&fim->numero);
	fim->prox = (contato*) malloc(sizeof(contato));
	fim = fim->prox;
	fim->prox = NULL;	
}
//BUSCAR
void buscar(contato *fim)
{
	int x,p,i=1;
	char nome[30];
	printf("1 - Nome\n2 - Posição\n");
	if(x == 1)
	{
		printf("Digite o nome - ");
		scanf(" %[^\n]s",nome);
		while(fim->prox != NULL)
		{
			if(strcmp(nome,fim->nome) == 0)
			{	
				printf("Nome - %s\nTelefone - %i",fim->nome,fim->numero);	
			}
			fim = fim->prox;	
		}
	}else{
		printf("Digite a Posição - ");
		scanf("%i",&p);
		while(fim->prox != NULL)
		{
			if(i == p)
			{	
				printf("Nome - %s\nTelefone - %i",fim->nome,fim->numero);	
			}
			i++;
			fim = fim->prox;	
		}
	}	
}
//listar
void listar(contato *fim)
{
	do
	{	
		printf("Nome - %s\nTelefone - %i\n",fim->nome,fim->numero);	
		fim = fim->prox;	
	}while(fim->prox != NULL);
}
int main(int argc, char *argv[]) {
	contato *in, *fim;
	int x;
	in = (contato*) malloc(sizeof(contato));
	if(in == NULL)
	{
		return;
	}
	fim = in;
	do
	{
		x = menu(x);
		switch(x)
		{
		case 1:
			implementar(fim);
			break;
		case 2:
			fim = in;
			do
			{	
				printf("Nome - %s\nTelefone - %i\n",fim->nome,fim->numero);	
				fim = fim->prox;	
			}while(fim->prox != NULL);
			break;
		case 3:
			
			break;
		}
		system("pause");
		system("cls");
	}while(x != 4);
	return 0;
}
