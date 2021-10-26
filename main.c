#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void limparTela()
{
	system("cls");
}

void dadosParque()
{
	printf("PARQUE DOS ENGENHEIROS\n");
	printf("Rua das pedras, 666 - Jardim Bot�nico\n");
	printf("Salvador - Bahia\n\n");
}

void ingressoDuracao()
{
	printf("INGRESSO: R$ 5,00\n");
	printf("DURA��O: 10 minutos\n\n");
}

void splash()
{
	limparTela();
	dadosParque();
	ingressoDuracao();
	printf("PRESSIONE UMA TECLA PARA COMPRAR INGRESSO\n\n");
	getch();
}

int quantidadeIngressos()
{
	
	int quantidade;
	
	limparTela();
	ingressoDuracao();
	printf("Deseja comprar quantos ingressos? ");
	scanf("%d", &quantidade);
	
	return quantidade;
}

void totais(int quantidade)
{
	limparTela();
	printf("Total de ingressos: %d\n", quantidade);
	printf("Valor total: R$ %d,00\n\n", (quantidade * 5));
}

char formaPagamento(int quantidade)
{
	char forma;
	
	totais(quantidade);
	printf("Escolha forma de pagamento:\n");
	printf("1 - D�bito\n");
	printf("2 - Cr�dito\n");
	forma = getch();
	
	return forma;
}

void formaDePagamento(char forma)
{
	if (forma == '1') {
		printf("Forma de pagamento: D�bito\n\n");
	}	
	
	if (forma == '2')
	{
		printf("Forma de pagamento: Cr�dito\n\n");
	}
}

char confirmacao(int quantidade, char forma)
{
	char confirmar;
	
	totais(quantidade);
	
	formaDePagamento(forma);
	
	printf("Confirma informa��es?\n");
	printf("1 - Sim\n");
	printf("2 - N�o\n");
	confirmar = getch();

	return confirmar;
	
}

void barra(int segundos)
{
	int i;
	
	for (i = 0; i < segundos; i++) 
	{
		Sleep(1000);
		printf("#");
	}
	printf("\n");
}

void cobranca()
{
	limparTela();
	printf("Siga as instr��es da m�quina de cart�o.\n\n");
	barra(15);
}

void impressao(int quantidade, char forma)
{
	dadosParque();
	totais(quantidade);
	formaDePagamento(forma);
	printf("AGUARDE IMPRESS�O DO INGRESSO.\n\n");
	barra(12);
	
}

int main() 
{
	
	int quantidade;
	char forma, confirmar;
	
	setlocale(LC_ALL, "Portuguese");
	do {
		splash();
		quantidade = quantidadeIngressos();
		forma = formaPagamento(quantidade);
		confirmar = confirmacao(quantidade, forma);
		
		if (confirmar == '2') {
			continue;
		}
		
		cobranca();
		impressao(quantidade, forma);
		
	} while (0 == 0);
	
}
