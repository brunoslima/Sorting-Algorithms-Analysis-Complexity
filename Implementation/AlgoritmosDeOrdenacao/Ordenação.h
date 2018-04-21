#ifndef ORDENACAO_
#define ORDENACAO_

//#define MAX 10
//#define MAX 100
//#define MAX 1000
//#define MAX 10000
//#define MAX 100000
//#define MAX 500000
#define MAX 1000000

//Funções auxiliares
void GeraVetor(int* vetor, int opcao);
void GerarVetor(int *vetor, int j);
void ImprimeVetor(int* a);
void Swap(int* a, int* b);
void gerarArquivoElementosAleatorios();

//Algoritmos de ordenação
void BubbleSort(int* vetor);                                                    //1)Bubble Sort - original
void BubbleSortAdvanced(int* vetor);                                            //2)Bubble Sort - melhorado

void QuickSortPivoInicio(int *vetor, int esq, int dir);                         //3)Quick Sort - Pivô primeiro elemento
int ParticionarInicio(int *vetor, int esq, int dir);

void QuickSortPivoCentral(int *vetor, int n);                                   //4)Quick Sort - Pivô elemento central
void Sort(int *vetor, int esq, int dir);
void ParticionarCentral(int *vetor, int esq, int dir, int *inicio, int *fim);

void InsertionSort(int* vetor);                                                 //5)Insertion Sort

void ShellSort1(int *vetor);                                                     //6)Shell Sort
void ShellSort2(int *vetor);
void ShellSort3(int *vetor);
void ShellSort(int *vetor);

void SelectionSort(int* vetor);                                                 //7)Selection Sort

void HeapSort(int* vetor);                                                      //8)Heap Sort
void MaxHeap(int* vetor, int p, int m);

void MergeSort(int* vetor, int p, int r);                                       //9)Merge Sort
void Merge(int* vetor, int p, int q, int r);

#endif // ORDENACAO_
