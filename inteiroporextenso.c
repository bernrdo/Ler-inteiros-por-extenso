#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "Portuguese");
  
	int vet[5];
	char transform[5][5];
    
	char* unidades[] = {				"zero", "um", "dois", "três", "quatro",
															"cinco", "seis", "sete", "oito", "nove"	};
	char* dezenas[] = {					"", "dez", "onze", "doze", "treze",
															"quartorze", "quinze","dezesseis",
															"dezessete", "dezoito", "dezenove"	};
	char* multiplosdedez[] = {	"", "", "vinte", "trinta", "quarenta",
															"cinquenta", "sessenta", "setenta",
															"oitenta", "noventa"	};
	char* centenas[] = {				"", "cento", "duzentos", "trezentos",
															"quatrocentos", "quinhentos", "seiscentos",
															"setecentos", "oitocentos", "novecentos"	};
        
	printf("A quantidade máxima de dígitos que cada valor pode ter é quatro(4). Insira 5 valores para o seguinte vetor\n");
	for(int i = 0; i < 5 ;i++){
		printf("Valor %d: ", 1 + i);scanf("%d", vet + i);
	}
	printf("\n\n");
    
	for(int i = 0; i < 5 ;i++){
		sprintf(transform[i], "%d", vet[i]);
		vet[i] = strlen(transform[i]);
	}
	
	for(int i = 0; i < 5 ;i++){
		if(vet[i] == 1)
			printf("%dº termo em extenso: %s\n", 1 + i, unidades[*transform[i] - '0']);

		else if(vet[i] == 2){
			int check;
			
			if((*transform[i] - '0') == 1){
				sscanf(transform[i], "%d", &check);
				printf("%dº termo em extenso: %s\n", 1 + i, dezenas[check - 9]);
			}
				
			else{
				sscanf(transform[i], "%d", &check);

				if(check%10 == 0)
					printf("%dº termo em extenso: %s\n", 1 + i, multiplosdedez[check/10]);
					
				else
					printf("%dº termo em extenso: %s e %s\n", 1 + i, multiplosdedez[check/10], unidades[check%10]);
			}
		}

		else if(vet[i] == 3){
			int check,centena = (*transform[i] - '0');

			sscanf(transform[i], "%d", &check);check -= (centena * 100);

			if(check < 10){
				if(check == 0 && centena == 1)
					printf("%dº termo em extenso: cem\n", 1 + i);

				else if(check == 0 && centena > 1)
					printf("%dº termo em extenso: %s\n", 1 + i, centenas[centena]);

				else
					printf("%dº termo em extenso: %s e %s\n", 1 + i, centenas[centena], unidades[check]);
			}

			else if(check/10 == 1)
				printf("%dº termo em extenso: %s e %s\n", 1 + i, centenas[centena], dezenas[check - 9]);
				
			else{
					if(check%10 == 0)
						printf("%dº termo em extenso: %s e %s\n", 1 + i, centenas[centena], multiplosdedez[check/10]);
					
					else
						printf("%dº termo em extenso: %s e %s e %s\n", 1 + i, centenas[centena], multiplosdedez[check/10], unidades[check%10]);
			}
		}

		else if(vet[i] == 4){
			int checkT,check,milhar = (*transform[i] - '0');
			char temp[4];

			sscanf(transform[i], "%d", &checkT);checkT -= (milhar * 1000);
			sprintf(temp, "%d", checkT);

			if(strlen(temp) < 3){
				check = checkT;
				
				if(check == 0)
					printf("%dº termo em extenso: %s mil\n", 1 + i, unidades[milhar]);

				else if(check/10 == 0)
					printf("%dº termo em extenso: %s mil e %s\n", 1 + i, unidades[milhar], unidades[check]);

				else if(*temp - '0' == 1)
					printf("%dº termo em extenso: %s mil e %s\n", 1 + i, unidades[milhar], dezenas[check - 9]);

				else{
					if(check%10 == 0)
						printf("%dº termo em extenso: %s mil e %s\n", 1 + i, unidades[milhar], multiplosdedez[check/10]);
					
					else
						printf("%dº termo em extenso: %s mil e %s e %s\n", 1 + i, unidades[milhar], multiplosdedez[check/10], unidades[check%10]);
				}
			}

			else{
				int centena;
				centena = (*temp - '0');check = checkT - (centena * 100);
				
				if(check < 10){
					if(check == 0 && centena == 1)
						printf("%dº termo em extenso: %s mil cem\n", 1 + i, unidades[milhar]);

					else if(check == 0 && centena > 1)
						printf("%dº termo em extenso: %s mil %s\n", 1 + i, unidades[milhar], centenas[centena]);

					else
						printf("%dº termo em extenso: %s mil %s e %s\n", 1 + i, unidades[milhar], centenas[centena], unidades[check]);
				}

				else if(check/10 == 1)
					printf("%dº termo em extenso: %s mil %s e %s\n", 1 + i, unidades[milhar], centenas[centena], dezenas[check - 9]);
				
				else{
					if(check%10 == 0)
						printf("%dº termo em extenso: %s mil %s e %s\n", 1 + i, unidades[milhar], centenas[centena], multiplosdedez[check/10]);
					
					else
						printf("%dº termo em extenso: %s mil %s e %s e %s\n", 1 + i, unidades[milhar], centenas[centena], multiplosdedez[check/10], unidades[check%10]);
				}
			}
		}

		else
			printf("Não pode ler esse número\n");
	}
	
  return 0;
}