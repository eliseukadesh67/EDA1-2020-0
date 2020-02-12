# Busca

## Problemas de busca

Dado um elemento, decidir se x está contido ou não em um conjunto S.

- Ex 1 :

Suponha que x seja um inteiro e S, um vetor de inteiros.

        int busca(int *v, int n, int x){
            int i;
            for(i=n-1,i>=0 && v[i]!=x,i--){
                return i;
            }
        }
Esta algoritmo retorna a ultima ocorrencia de x no vetor.

## Busca em vetor ordenado

Dado um elemento x e um conjunto V ordenado, queremos determinar J tal que:

        V[j-1]<x<=v[j];

## Busca Binária

        int busca_binaria(int *v, int n, int x){
            int meio;
            int e = -1;
            int d = n;

            while(e<d-1){
                m = (e+d)/2;
                if(v[m]<x){
                    e = m;
                }
                else{
                    d = m;
                }
            }
            return d;
        }

## Complexidade da busca binárias

A cada interação do laço, dividimos o vetor "ao meio".