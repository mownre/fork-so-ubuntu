#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const char* imprimirData(time_t t) {
	char* timeString = malloc(sizeof(char)*9);
	struct tm *local = localtime(&t);
	sprintf(timeString, "%02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);
	return timeString;
}

int main() {
	pid_t pidPai = getpid();

	int ano = 0;

	int nascimentoPai = ano;
	int idadePai = 0, idadeFilho1 = 0, idadeFilho2 = 0, idadeNeto1 = 0, idadeNeto2 = 0;
	time_t nascimentoPai_t = time(NULL), nascimentoFilho1_t, nascimentoFilho2_t, nascimentoNeto1_t, nascimentoNeto2_t;
	int nascimentoFilho1, nascimentoFilho2, nascimentoNeto1, nascimentoNeto2;
	pid_t  filho1 = -1, filho2 = -1, neto1 = -1, neto2 = -1;

	nascimentoPai_t = time(NULL);

	printf("PAI: Nasceu em %s [%d criado]\n", imprimirData(nascimentoPai_t), pidPai);


	while(1) {


		idadePai = ano - nascimentoPai;
		if(filho1 >= 0) idadeFilho1 = ano - nascimentoFilho1;
		if(filho2 >= 0) idadeFilho2 = ano - nascimentoFilho2;
		if(neto1 >= 0) idadeNeto1 = ano - nascimentoNeto1;
		if(neto2 >= 0) idadeNeto2 = ano - nascimentoNeto2;

		if (!neto1) { /*Se a instancia for a do neto1*/

			if(idadeNeto1 == 12) { /*Idade em que o primeiro neto morre*/
				printf("NETO1: Nascido em %s. Morreu em %s aos %d anos [%d encerrado]\n", imprimirData(nascimentoNeto1_t), imprimirData(time(NULL)), idadeNeto1, getpid());
				exit(0);
			}
			
		} else if (!neto2) { /*Se a instancia for a do neto2*/
			
			if(idadeNeto2 == 18) { /*Idade em que o segundo neto morre*/
				printf("NETO2: Nascido em %s. Morreu em %s aos %d anos [%d encerrado]\n", imprimirData(nascimentoNeto2_t), imprimirData(time(NULL)), idadeNeto2, getpid());
				exit(0);
			}

		} else if(!filho1) { /*Se a instancia for a do filho1*/

			if(idadePai == 26) { /*Idade do Avô em que o primeiro neto nasceu*/
				neto1 = fork();
				nascimentoNeto1_t = time(NULL);
				nascimentoNeto1 = ano;
				if(neto1 > 0) printf("NETO 1: Nasceu em %s [%d criado]\n", imprimirData(nascimentoNeto1_t), neto1);
			}

			if(idadeFilho1 == 30){
				printf("FILHO1: Nascido em %s. Morreu em %s aos %d anos [%d encerrado]\n", imprimirData(nascimentoFilho1_t), imprimirData(time(NULL)), idadeFilho1, getpid());
				exit(0);
			}

		} else if (!filho2) { /*Se a instancia for a do filho2*/

			if(idadePai == 30) { /*Idade do Avô em que o segundo neto nasceu*/
				neto2 = fork();
				nascimentoNeto2_t = time(NULL);
				nascimentoNeto2 = ano;
				if(neto2 > 0) printf("NETO 2: Nasceu em %s [%d criado]\n", imprimirData(nascimentoNeto2_t), neto2);
			}

			if(idadeFilho2 == 30){
				printf("FILHO2: Nascido em %s. Morreu em %s aos %d anos [%d encerrado]\n", imprimirData(nascimentoFilho2_t), imprimirData(time(NULL)), idadeFilho2, getpid());
				exit(0);
			}

		} else {

			if(idadePai == 14) { /*Idade em que o primeiro filho nasce*/
				filho1 = fork();
				nascimentoFilho1_t = time(NULL);
				nascimentoFilho1 = ano;
				if(filho1 > 0) printf("FILHO 1: Nasceu em %s [%d criado]\n", imprimirData(nascimentoFilho1_t), filho1);

			}

			if(idadePai == 16) { /*Idade em que o segundo filho nasce*/
				filho2 = fork();
				nascimentoFilho2_t = time(NULL);
				nascimentoFilho2 = ano;
				if(filho2 > 0) printf("FILHO 2: Nasceu em %s [%d criado]\n", imprimirData(nascimentoFilho2_t), filho2);
			}

			if(idadePai == 60){

				printf("PAI: Nascido em %s. Morreu em %s aos %d anos [%d criado]\n", imprimirData(nascimentoFilho2_t), imprimirData(time(NULL)), idadePai, getpid());
				exit(0);

			};
		}
		
		
		sleep(1);
		ano++;
	}

}
