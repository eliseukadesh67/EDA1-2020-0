# Ordenação

Dado um vetor V com N elementos, queremos colocar esses elementos em ordem(não decrescente).

Os principais algoritmos de ordenação são : 

1. Insertion Sort
2. Selection Sort
3. Bubble Sort

## Insertion Sort(Ordenação por inserção)

        void insertion_sort(){
            for(int i = 1; i<n; i++){
                for(int j = i;j>0 && v[j]<v[j-1]; j--){
                    troca(&v[j],&v[j-1]);
                }
            }
        }


A solução recursiva seria : 

    void inserção_rec(int *v, int n, int i){
        if(i==0){
            inserção_rec(v, n, i-1);
        }
        for(int j=i;j>0 && v[j]<v[j-1];j--){
            troca(&v[j],v[j-1]);
        }
    }

## Estabilidade

Um algoritmo de ordenação é dito estável quando preserva a ordem original de elementos repetidos.

## 2. Selection Sort 

    void selection_sort(int *v, int n){
        for(int i = 0, i<n, i++){
            int min = i;
            for(int i+1 = 0,j<n,j++){
                if(v[j]<v[min]){
                    min = j;
                }

                troca(&v[min], &v[i]);
            }
        }
    }

A solução recursiva seria :

        void selection_sort_rec(int *v, int n, int i){
            if(i<n-1){
                int min=1;
                for(int j=i+1, j<n;j++){
                    if(v[j]<v[min]){
                        min = j;
                    }
                    troca(&v[min], &v[i]);
                    selectiom_sort_rec(v, n, i+1);
                }
            }
        }
