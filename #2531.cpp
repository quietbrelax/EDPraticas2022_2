/*
    Pratica Estrutura de Dados 2022/02
    #2531 Shopping in Fdl

    Pratica em Dupla

    Maria Clara Oliveira Domingos Ruas
    Lucas Samuel Fernandes Andrade Oliveira
*/

#include <stdio.h>
#include <stdlib.h>

class Valor{
    public:    
        int maior;
	    int menor;
};

Valor valores[1000100*4];
int vetor[1000100];

int numMaior(int a, int b){
    if(a > b)
        return a;
    return b;
}

int numMenor(int a, int b){
    if(a < b)
        return a;
    return b;
}

void Novo(int p, int l, int r){

	if (l == r){
		valores[p].maior = valores[p].menor = vetor[l];
		return;
	}

	Novo(p * 2, l, ((l + r) / 2));
	Novo(p * 2 + 1, ((l + r) / 2) + 1, r);

	valores[p].maior = numMaior(valores[p * 2].maior, valores[p * 2 + 1].maior);
	valores[p].menor = numMenor(valores[p * 2].menor, valores[p * 2 + 1].menor);

}

void Alterar(int p , int l, int r, int x, int v){

	if (l == r){
		vetor[x] = valores[p].maior = valores[p].menor = v;
		return;
	}

	if (x <= ((l + r) / 2))
		Alterar(p*2, l, ((l + r) / 2), x, v);
	else
		Alterar(p*2 + 1, ((l + r) / 2) + 1, r, x , v);

	valores[p].maior = numMaior(valores[p * 2].maior, valores[p * 2 + 1].maior);
	valores[p].menor = numMenor(valores[p * 2].menor, valores[p * 2 + 1].menor);

}

Valor Pesquisa(int p, int l, int r, int a, int b){

	if (a <= l && b >= r)
		return valores[p];

	Valor tmp;
	tmp.maior = -1410065407;
	tmp.menor = 1410065407;

	if (b < l || a > r)
		return tmp;

	Valor rL = Pesquisa(p * 2, l, ((l + r) / 2), a, b);
	Valor rR = Pesquisa(p * 2 + 1, ((l + r) / 2) + 1, r, a, b);

	Valor aux;
	aux.maior = numMaior(rL.maior, rR.maior);
	aux.menor = numMenor(rL.menor, rR.menor);

	return aux;

}

int main (){
	unsigned int  a, b, i, n, tmp, q;

	while (scanf("%u", &n) != EOF)
	{

		for(i = 1; i <= n; ++i)
			scanf("%u", &vetor[i]);

		Novo(1, 1, n);
		scanf("%d", &q);

		while (q--){

			scanf("%u", &tmp);

			if (tmp != 1){
				scanf("%u %u", &a, &b);
				Valor aux = Pesquisa(1, 1, n, a, b);
				printf("%u\n", abs(aux.maior - aux.menor));
			}else{
                scanf("%u %u", &a, &b), Alterar(1, 1, n, a, b);
			}

		}

	}
    return 0;
}

