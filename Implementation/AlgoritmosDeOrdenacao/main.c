/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------      PROGRAMA DE PÓS-GRADUAÇÃO EM CIÊNCIA DA COMPUTAÇÃO      ------------------------------*/
/*--------------------------                         DSICIPLINA:                          ------------------------------*/
/*--------------------------                ANÁLISE E PROJETO DE ALGORITMOS               ------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------                      TRABALHO PRÁTICO 01                     ------------------------------*/
/*--------------------------              ANÁLISE DOS ALGORITMOS DE ORDENAÇÃO             ------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------                           AUTORES:                           ------------------------------*/
/*--------------------------                     Bruno Santos de Lima                     ------------------------------*/
/*--------------------------                     Leandro Ungari Cayres                    ------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/

#include "Ordenacao.h"
#include "Ordenacao.c"

#include <stdio.h>  
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//#include <windows.h>

int main(void){

    setlocale(LC_ALL, "PORTUGUESE");
    system("title Análise dos Algoritmos de Ordenação");

    time_t t;
    //LARGE_INTEGER li;
    //double frequencia, inicio, fim;

    srand((unsigned) time(&t));

    int vetor[MAX];

    inicializarContadorTroca();

    //gerarArquivoElementosAleatorios();

    GerarVetor(vetor, 2);

    //ImprimeVetor(vetor);

    //Inicio
    //QueryPerformanceFrequency(&li);
    //frequencia = (double)li.QuadPart/1000.0;
    //QueryPerformanceCounter(&li);
    //inicio = li.QuadPart;

    //BubbleSort(vetor);
    BubbleSortAdvanced(vetor);
    //QuickSortPivoInicio(vetor, 0, MAX);
    //QuickSortPivoCentral(vetor, MAX);
    InsertionSort(vetor);
    //ShellSort(vetor);
    //SelectionSort(vetor);
    //MergeSort(vetor, 0, MAX);
    //HeapSort(vetor);

    //QueryPerformanceCounter(&li);
    //fim = li.QuadPart;

    //Fim
    //double tempo = (double)(fim - inicio)/frequencia;
    //ImprimeVetor(vetor); //Vetor Ordenado

    //printf("\n\n Tempo (ms): %.18f\n", tempo);
    printf("Algoritmo: BubbleSortAdvanced Aleatorio");
    printf("\n Tamanho: %d", MAX);
    printf("\n\n Trocas: %lu\n", contadorTroca);

    //system("PAUSE");
    return(0);
}
