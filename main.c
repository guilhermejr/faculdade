#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void limparTela()
{
	system("cls"); // Limpa a tela
}

void dadosParque()
{
	// Bloco com os dados do parque
	printf("PARQUE DOS ENGENHEIROS\n");
	printf("Rua das pedras, 666 - Jardim Botânico\n");
	printf("Salvador - Bahia\n\n");
}

void valorDuracao()
{
	// Bloco com o valor e duração do ingresso
	printf("VALOR: R$ 5,00\n");
	printf("DURAÇÃO: 10 minutos\n\n");
}

void splash()
{
	limparTela(); // Limpa a tela
	dadosParque(); // Dados do parque
	valorDuracao(); // Valor e duração do ingresso
	printf("PRESSIONE UMA TECLA PARA COMPRAR INGRESSO\n\n");
	getch(); // Aguarda pressionar qualquer tecla
}

int quantidadeIngressos()
{
	
	int quantidade; // Variável quantidade
	
	limparTela(); // Limpa a tela
	valorDuracao(); // Dados do parque
	printf("Deseja comprar quantos ingressos? ");
	scanf("%d", &quantidade); // Quantidade de ingressos
	
	return quantidade; // Retorno da quantidade
}

void totais(int quantidade)
{
	limparTela(); // Limpa a tela
	
	// Total de ingresso e valor
	printf("Total de ingressos: %d\n", quantidade);
	printf("Valor total: R$ %d,00\n\n", (quantidade * 5));
}

char formaPagamento(int quantidade)
{
	char forma; // Varável forma
	
	totais(quantidade); // Mostra mensagem de ingresso e valor
	
	// Menu de opções
	printf("Escolha forma de pagamento:\n");
	printf("1 - Débito\n");
	printf("2 - Crédito\n");
	forma = getch(); // Pega opção escolhida
	
	return forma; // Retorno da forma
}

void formaDePagamento(char forma)
{
	if (forma == '1') 
	{ // Se opção escolhida for 1
		printf("Forma de pagamento: Débito\n\n");
	}	
	
	if (forma == '2')
	{ // Se opção escolhida for 2
		printf("Forma de pagamento: Crédito\n\n");
	}
}

char confirmacao(int quantidade, char forma)
{
	char confirmar; // Variável confirmar
	
	totais(quantidade); // Mostra mensagem de ingresso e valor
	
	formaDePagamento(forma); // Mostra forma de pagamento
	
	// Menu de opções
	printf("Confirma informações?\n");
	printf("1 - Sim\n");
	printf("2 - Não\n");
	confirmar = getch(); // Pega opção escolhida

	return confirmar; // Retorno de confirmar
	
}

void barra(int segundos)
{
	int i; // Variável de controle
	
	for (i = 0; i < segundos; i++) 
	{
		Sleep(1000); // Aguarda 1 segundo
		printf("#"); // Imprime #
	}
	printf("\n"); // Pula uma linha
}

void cobranca()
{
	limparTela(); // Limpa a tela
	printf("Siga as instrções da máquina de cartão.\n\n");
	barra(15); // Mostra a barra
}

void impressao(int quantidade, char forma)
{
	dadosParque(); // Dados do parque
	totais(quantidade); // Mostra mensagem de ingresso e valor
	formaDePagamento(forma); // Mostra forma de pagamento
	printf("AGUARDE IMPRESSÃO DO INGRESSO.\n\n");
	barra(12); // Mostra a barra
}

int main() 
{
	
	int quantidade; // Variável quantidade
	char forma, confirmar; // Variáveis forma e confirmar
	
	setlocale(LC_ALL, "Portuguese"); // Permite que seja impresso acentos
	
	do {
		splash(); // Mostra tela inicial
		quantidade = quantidadeIngressos(); // Mostra tela para selecionar quantidade de ingressos
		forma = formaPagamento(quantidade); // Mostra tela para selecionar forma de pagamento
		confirmar = confirmacao(quantidade, forma); // Mostra tela de confirmação
		
		if (confirmar == '2') {
			continue; // Volta para o início do loop
		}
		
		cobranca(); // Mostra tela de cobrnaça
		impressao(quantidade, forma); // Mostra tela de impressão
		
	} while (0 == 0);
	
}
