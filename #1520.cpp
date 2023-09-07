/*
    Pratica Estrutura de Dados 2022/02
    #1520 Screws and Nuts

    Pratica em Dupla

    Maria Clara Oliveira Domingos Ruas
    Lucas Samuel Fernandes Andrade Oliveira
*/

#include <stdio.h>
#include <string.h>

#define MAX 10001

class valores{
public:
    int inicio, fim, intervalo;
};

void zeraVetor(int v[]){
    for (int i = 0; i < MAX; i++)
        v[i] = 0;
}


int main(){
	int vet[MAX];
	int i, tam, tam2;
    valores val;
    
	while (scanf("%d", &tam) != EOF){

	    
		zeraVetor(vet);

		for(int j = 0; j < tam; j++){
			scanf("%d %d", &val.inicio, &val.fim);
			for(i = val.inicio; i <= val.fim; i++)
				vet[i]++;
		}

		val.intervalo = 0;
		scanf("%d", &tam2);

		if(vet[tam2]){

			for(i = 1; i < tam2; i++)
				val.intervalo += vet[i];

			printf("%d found from %d to %d\n", tam2, val.intervalo, (val.intervalo + vet[i] - 1));
		}
		else
			printf("%d not found\n", tam2);
	}

	return 0;
}