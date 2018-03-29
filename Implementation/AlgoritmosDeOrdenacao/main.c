/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*--------------------------                 TRABALHO PR�TICO 01                ------------------------------*/
/*--------------------------         AN�LISE DOS ALGORITMOS DE ORDENA��O        ------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*--------------------------                      AUTORES:                      ------------------------------*/
/*--------------------------        Bruno Santos de Lima   RA: 141251093        ------------------------------*/
/*--------------------------        Leandro Ungari Cayres  RA: 141251992        ------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*--------------------------                    DSICIPLINA:                     ------------------------------*/
/*--------------------------           PROJETO E AN�LISE DE ALGORITMOS          ------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

#include "Ordena��o.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

int main(void){

    setlocale(LC_ALL, "PORTUGUESE");
    system("title An�lise dos Algoritmos de Ordena��o");

    time_t t;
    LARGE_INTEGER li;
    double frequencia, inicio, fim;

    srand((unsigned) time(&t));

    int vetor[MAX];

    //gerarArquivoElementosAleatorios();

    GerarVetor(vetor, 1);

    //ImprimeVetor(vetor);


    //Inicio
    QueryPerformanceFrequency(&li);
    frequencia = (double)li.QuadPart/1000.0;
    QueryPerformanceCounter(&li);
    inicio = li.QuadPart;

    //SimpleBubbleSort(vetor);
    //AdvancedBubbleSort(vetor);
    //QuickSortPivoInicio(vetor, 0, MAX);
    //QuickSortPivoCentral(vetor, MAX);
    //InsertionSort(vetor);
    //ShellSort3(vetor);
    //SelectionSort(vetor);
    //MergeSort(vetor, 0, MAX);
    //HeapSort(vetor);

    QueryPerformanceCounter(&li);
    fim = li.QuadPart;

    //Fim
    double tempo = (double)(fim - inicio)/frequencia;
    //ImprimeVetor(vetor); //Vetor Ordenado

    printf("\n\n Tempo (ms): %.18f\n", tempo);

    //system("PAUSE");
    return(0);
}