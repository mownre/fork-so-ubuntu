#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <time.h>

int main() {

	
	pid_t pidPai = getpid();

	int ano = 0;

	int nascimentoPai = ano;
	int idadePai = 0, idadeFilho1 = 0, idadeFilho2 = 0, idadeNeto1 = 0, idadeNeto2 = 0;
	int nascimentoFilho1, nascimentoFilho2, nascimentoNeto1, nascimentoNeto2;
	pid_t  filho1 = -1, filho2 = -1, neto1 = -1, neto2 = -1;	

	while(1) {


		idadePai = ano - nascimentoPai;
		if(filho1 >= 0) idadeFilho1 = ano - nascimentoFilho1;
		if(filho2 >= 0) idadeFilho2 = ano - nascimentoFilho2;
		if(neto1 >= 0) idadeNeto1 = ano - nascimentoNeto1;
		if(neto2 >= 0) idadeNeto2 = ano - nascimentoNeto2;

		if (!neto1) { /*Se a instancia for a do neto1*/

			if(idadeNeto1 == 12) { /*Idade em que o primeiro neto morre*/
				printf("NETO1: Nascido no ano de %d, Morreu no ano %d aos %d anos [%d encerrado]\n", nascimentoNeto1, ano, idadeNeto1, getpid());
				exit(0);
			}
			
		} else if (!neto2) { /*Se a instancia for a do neto2*/
			
			if(idadeNeto2 == 18) { /*Idade em que o segundo neto morre*/
				printf("NETO2: Nascido no ano de %d, Morreu no ano %d aos %d anos\n [%d encerrado]", nascimentoNeto2, ano, idadeNeto2, getpid());
				exit(0);
			}

		} else if(!filho1) { /*Se a instancia for a do filho1*/

			if(idadePai == 26) { /*Idade do Avô em que o primeiro neto nasceu*/
				neto1 = fork();
				nascimentoNeto1 = ano;
				if(neto1 > 0) printf("NETO1: Primeiro neto nasceu no ano %d [%d criado]\n", ano, neto1);
			}

			if(idadeFilho1 == 30){
				printf("FILHO1: Nascido no ano de %d, Morreu no ano %d aos %d anos [%d encerrado]\n", nascimentoFilho1, ano, idadeFilho1, getpid());
				exit(0);
			}

		} else if (!filho2) { /*Se a instancia for a do filho2*/

			if(idadePai == 30) { /*Idade do Avô em que o segundo neto nasceu*/
				neto2 = fork();
				nascimentoNeto1 = ano;
				if(neto1 > 0) printf("NETO2: Segundo neto nasceu no ano %d [%d criado]\n", ano, neto2);
			}

			if(idadeFilho2 == 30){
				printf("FILHO2: Nascido no ano de %d, Morreu no ano %d aos %d anos [%d encerrado]\n", nascimentoFilho2, ano, idadeFilho2, getpid());
				exit(0);
			}

		} else {

			if(idadePai == 14) { /*Idade em que o primeiro filho nasce*/
				filho1 = fork();
				nascimentoFilho1 = ano;
				if(filho1 > 0) printf("PAI: Primeiro filho nasceu no ano %d [%d criado]\n", ano, filho1);

			}

			if(idadePai == 16) { /*Idade em que o segundo filho nasce*/
				filho2 = fork();
				nascimentoFilho2 = ano;
				if(filho2 > 0) printf("PAI: Segundo filho nasceu no ano %d [%d criado]\n", ano, filho2);
			}

			if(idadePai == 60){

				printf("PAI: Nascido no ano de %d, Morreu no ano %d aos %d anos [%d criado]\n", nascimentoPai, ano, idadePai, getpid());
				exit(0);

			};
		}
		
		
		sleep(1);
		ano++;
	}

}

/*
int main() {

	time_t inicio, fim;

	printf("Inicio da contagem de tempo de execução\n");

	inicio = time(NULL);

	sleep(7);

	fim = time(NULL);

	time_t tempoExecucao = fim - inicio;

	printf("Segundos de execucao do programa %ld segundos\n", tempoExecucao);

}
*/