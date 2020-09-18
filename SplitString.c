#import <stdlib.h>
#import <string.h>

char ** PG_splitString(char *string, char *delimiter, int *parts) {

	char **result = NULL;
	char *p1 = string;
	char *p2 = NULL;
	char pAux[1024];
	char aux[1024];
	int count = 0;
	int i;
	printf("\nbuffer[%s]\n", string);

	//conta quantos delimitadores tem na string
	do {
		p2 = strstr(p1, delimiter);
		if (p2 != NULL) {
			p1 = p2 + strlen(delimiter);

		}
	printf("\np1[%s], p2[%s]\n", p1, p2);

		count++;
	} while (p2 != NULL);
printf("\ncount[%i]\n", count);

	//Aloca a matriz de saida com a quantidade de delimitadores encontrados
	result = (char**)malloc((count + 1) * sizeof(char*));
	printf("\nHas alocated result\n");
	

	//zera as variaveis
	p2 = NULL;
	p1 = &string[0];

	//separa as partes do delimitador e coloca cada um em uma posição da matriz
	for (i = 0; i < count; i++) {
    printf("\nlaço de numero %i\n", i);
    
		p2 = strstr(p1, delimiter);
    	printf("\np2 is null? [%s]\n", p2);

		if (p2 != NULL) {
			
			strncpy(pAux, p1, p2 - p1);
		printf("\nValue passed to aux\n");
			strcpy(aux, pAux);

			printf("\naux[%s]\n", aux);
			result[i] = (char*)malloc((strlen(aux) +1) * sizeof(char));
			strcpy(result[i], aux);
   // result[i] = strdup(aux);
			printf("\nresult[%i] = [%s]\n", i, result[i]);

			printf("\np2[%s]\n", p2);
			p1 = p2 + strlen(delimiter);printf("\np1[%s]\n", p1);

		}
		else if(p2 == NULL || (p2 != NULL && ((p2+strlen(delimiter) + 1) == NULL )) || ((p2 != NULL && (p2+strlen(delimiter) +1) == '' ))  ){
		result[i] = (char*)malloc((strlen(p1) +1) * sizeof(char));
			
			//result[i] = strdup(aux);
			strcpy(result[i], p1);
			result[i + 1] = NULL;

			printf("result[%i] = [%s]\n", i, result[i]);
			break;
		}
	}

	for (i = 0; i < count + 1; i++) {
		printf("\n\nresult[%i] = [%s]\n", i, result[i]);
	}

	*parts = count +1;
	return result;
}

int main(void) {
int rest;
	char **result = PG_splitString("felipe||gabriel||adriano||", "||", &rest);



}

