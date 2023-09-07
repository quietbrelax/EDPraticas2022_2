
/*
    Pratica Estrutura de Dados 2022/02
    #1191 Tree Recovery

    Pratica em Dupla

    Maria Clara Oliveira Domingos Ruas
    Lucas Samuel Fernandes Andrade Oliveira
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50


 
using namespace std;

class No{
    public:
    int peso, prioridade;
    char letra;
} ;



void imprime(int tam, No arvore[]){
        No galhoDir[MAXSIZE];
        No galhoEs[MAXSIZE];
        int j = 0;
        int k = 0;
        if(tam == 0){
            return;
        }
    for (int i = 1; i < tam; i++)
    {
        if(arvore[0].prioridade < arvore[i].prioridade){
            galhoDir[j] = arvore[i];
            j++;
        }
        if(arvore[0].prioridade > arvore[i].prioridade){
            galhoEs[k] = arvore[i];
            k++;
        }
    }
    imprime(k, galhoEs);
    imprime(j, galhoDir);
    cout << arvore[0].letra;
    }

int main() {
 
    int qtsCasos;
    char aux1[MAXSIZE], aux2[MAXSIZE];
	string prefixa;
    string infixa;
    No arvore[MAXSIZE];
    int contador = 0;

	while (scanf("%s %s", aux1, aux2) != EOF){
        
        prefixa = aux1;
        infixa = aux2;

        for(int i = 0; i < prefixa.length(); i++){
            arvore[i].letra = prefixa[i];
            arvore[i].peso = i;
            contador++;
        }

        for(int i = 0; i < infixa.length(); i++){
            for (int j = 0; j < infixa.length(); j++)
            {
                if(infixa[j] == arvore[i].letra){
                    arvore[i].prioridade = j;
                }
            }
            
        }

        imprime(contador, arvore);
        cout << endl;
        contador = 0;

    }
    
    return 0;
}