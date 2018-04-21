#include "Ordenação.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/


void GerarVetor(int *vetor, int j){

    int i;
    FILE *f1;

    if(j == 1){ //Crescente
        for(i = 0; i < MAX; i++) vetor[i] = i + 1;
    }
    else if(j == 2){ //Decrescente
        for(i = 0; i < MAX; i++) vetor[i] = MAX - i;
    }
    else{ //Aleatório

        if( (f1 = fopen("elementosAleatorios.txt", "rt")) == NULL){
            printf("Erro na abertura do arquivo!");
            return;
        }

        for(i = 0; i < MAX; i++){
            fscanf(f1,"%d", &vetor[i]);
        }
    }
}


void ImprimeVetor(int* a){

    printf("\n");
    int i;
    for(i = 0; i < MAX; i++){
        printf("  %14d\n", a[i]);
    }

    printf("\n\n");
}


void gerarArquivoElementosAleatorios(){

    FILE *f1;

    if( (f1 = fopen("elementosAleatorios.txt", "wt")) == NULL){
        printf("Erro na abertura do arquivo!");
        return;
    }

    int i;
    for(i = 0; i < MAX; i++) fprintf(f1,"%d\n",rand()%MAX);

    fclose(f1);

}

void Swap(int* a, int* b){

    int aux = *a;
    *a = *b;
    *b = aux;
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void BubbleSort(int* vetor){

    int i, j;
    for(i = 1; i < MAX; i++){
        for(j = 0; j < (MAX-i); j++){
            if (vetor[j+1] < vetor[j]) Swap(vetor+j, vetor+j+1);
        }
    }

}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void BubbleSortAdvanced(int* vetor){

    int i = 1, j, troca = 1;
    while( (i < MAX) && troca){

        troca = 0;
        for(j = 0; j < (MAX-i); j++){

            if ( vetor[j+1] < vetor[j] ){
                Swap(vetor+j, vetor+j+1);
                troca = 1;
            }
        }
        i++;
    }

}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void QuickSortPivoInicio(int *vetor, int esq, int dir){ //Com Pivo sendo primeiro elemento

    if(esq < dir){
        int parte = ParticionarInicio(vetor,esq,dir);
        QuickSortPivoInicio(vetor,esq,parte-1);
        QuickSortPivoInicio(vetor,parte+1,dir);

    }

}

int ParticionarInicio(int *vetor, int esq, int dir){

    int inicio = esq, fim = dir, pivo = vetor[esq];

    while(inicio < fim){

        while(vetor[inicio] <= pivo && inicio < dir) inicio++;
        while(vetor[fim] > pivo && fim > esq) fim--;
        if(inicio < fim) Swap(vetor+inicio, vetor+fim);
    }
    vetor[esq] = vetor[fim];
    vetor[fim] = pivo;
    return(fim);
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void QuickSortPivoCentral(int *vetor, int n){

    Sort(vetor, 0, n-1);
}


void Sort(int *vetor, int esq, int dir){

    int inicio, fim;

    ParticionarCentral(vetor, esq, dir, &inicio, &fim);
    if(esq < fim) Sort(vetor, esq, fim);
    if(inicio < dir) Sort(vetor, inicio, dir);
}


void ParticionarCentral(int *vetor, int esq, int dir, int *inicio, int *fim){

    *inicio = esq; *fim = dir;
    int pivo = vetor[(*inicio + *fim)/2]; //Obtendo pivo central.

    do{
        while(*inicio < dir && pivo > vetor[*inicio]) (*inicio)++;
        while(*fim > esq && pivo < vetor[*fim]) (*fim)--;

        if(*inicio <= *fim){
            Swap(vetor+(*inicio), vetor+(*fim));
            (*inicio)++;
            (*fim)--;
        }

    }while(*inicio <= *fim);
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void InsertionSort(int* vetor){

    int i, j, aux;

    for (i = 1; i < MAX; i++){

        aux = vetor[i];
        j = i-1;
        while (j >= 0 && (vetor[j] > aux)){

            vetor[j+1] = vetor[j];
            j--;
        }

        vetor[j+1] = aux;
    }
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void ShellSort(int *vetor){ //NOVA IMPLEMENTAÇÃO

    /**
       Teorema1: Com a sequência de incrementos 1, 3, 7, 15, 31, 63, 127, ..., 2k–1,
       Shell-sort precisa de O(n.n1/2) passos para ordenar uma seqüência de tamanho n.
       Complexidade O(n^(3/2))

       http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/shell/shellen.htm
       https://www.toptal.com/developers/sorting-algorithms/shell-sort

    */

	int i, j , k, x, salto, decrem[8] = {255, 127, 63,31,15,7,3,1};
    //O vetor de saltos também pode ser passado como parametro.

	for(k = 0; k < 8; k++){
		salto = decrem[k];
		for(i = salto; i < MAX; i++){
			x = vetor[i];
			for(j = i; (j>=salto && x < vetor[j-salto]); j -= salto){
				vetor[j] = vetor[j-salto];
			}
			vetor[j] = x;
		}
	}

	return;
}

void ShellSort3(int *vetor) {

    int i, j, salto, aux;

    for(salto = 1; salto < MAX; salto = 3*salto+1); //Cálcula salto inicial

    while(salto > 0){

        salto = (salto-1)/3; //Atualiza valor do salto
        for(i = salto; i < MAX; i++){

            aux = vetor[i];
            for(j = i; (j >= salto && aux < vetor[j-salto]); j-=salto){

                vetor[j] = vetor[j-salto];
            }
            vetor[j] = aux;

        }

    }

    return;
}


void ShellSort2(int *vetor){
	int i, j ,x, salto;

	for(salto = MAX/2; salto > 0; salto /= 2){
    //Saltos controlados não por um vetor, mais sim com base no tamanho do vetor a ser ordenado.

		//printf("\n%d\n\n", salto);
		for(i = salto; i < MAX; i++){

			x = vetor[i];
			for(j = i; (j >= salto && x < vetor[j-salto]); j-=salto){

				vetor[j] = vetor[j-salto];
				//printf("\n\n");
			}
			vetor[j] = x;
			//printf("\n\n");
		}
	}
	return;
}


void ShellSort1(int *vetor){
	int i, j , k, x, salto, decrem[5] = {7,5,3,2,1}; //Número primos, melhor escolha? Pensar?
    //O vetor de saltos também pode ser passado como parametro.

	for(k = 0; k < 5; k++){
		salto = decrem[k];
		for(i = salto; i < MAX; i++){
			x = vetor[i];
			for(j = i; (j>=salto && x < vetor[j-salto]); j -= salto){
				vetor[j] = vetor[j-salto];
			}
			vetor[j] = x;
		}
	}

	return;
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void SelectionSort(int* vetor){

    int i, j, limite, indice;

    limite = MAX - 1;
    for (i = 0; i < limite; i++) {

        indice = i;
        for (j = i+1; j < MAX; j++){

            if ( vetor[j] < vetor[indice] ) indice = j;
        }

        if (indice != i) Swap(vetor+i, vetor+indice);
    }

}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void HeapSort(int* vetor){

    int p, m;

    for(p = MAX/2; p >= 0; p--){

        MaxHeap(vetor, p, MAX);
    }

    for(m = MAX; m >= 1; m--){

        Swap(vetor, vetor+m);
        MaxHeap(vetor, 0, m-1);
    }

}


void MaxHeap(int* vetor, int p, int m){

    int f = 2*p + 1, x = vetor[p];
    while(f <= m){

        if(f < m && vetor[f] < vetor[f+1]) f++;
        if(x >= vetor[f]) break;
        vetor[p] = vetor[f];
        p = f, f = 2*p+1;

    }

    vetor[p] = x;
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void MergeSort(int* vetor, int p, int r){

    int q;

    if(p < r-1){

        q = (p + r)/2;
        MergeSort(vetor, p, q);
        MergeSort(vetor, q, r);
        Merge(vetor, p, q, r);

    }
}


void Merge(int* vetor, int p, int q, int r){

    int i, j, k = 0;
    int* temp = (int*) malloc((r-p)*sizeof(int));
    i = p; j = q;

    while(i < q && j < r){

        if( vetor[i] <= vetor[j]) temp[k++] = vetor[i++];
        else temp[k++] = vetor[j++];
    }

    while(i < q) temp[k++] = vetor[i++];
    while(j < r) temp[k++] = vetor[j++];

    for(i = p; i < r; i++){
        vetor[i] =  temp[i-p];
    }

    free(temp);
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
