#ifndef ORDENACAO_
#define ORDENACAO_

//#define MAX 10
//#define MAX 100
//#define MAX 1000
//#define MAX 10000
//#define MAX 100000
<<<<<<< HEAD:Implementation/AlgoritmosDeOrdenacao/Ordenacao.h
#define MAX 500000
//#define MAX 1000000
=======
//#define MAX 500000
#define MAX 1000000
>>>>>>> 13a526c9ab609b3ce5e71b82a4ee1f13b1408985:Implementation/AlgoritmosDeOrdenacao/Ordenação.h

unsigned long int contadorTroca;

//Fun��es auxiliares
void GeraVetor(int* vetor, int opcao);
void GerarVetor(int *vetor, int j);
void ImprimeVetor(int* a);
void Swap(int* a, int* b);
void gerarArquivoElementosAleatorios();
void inicializarContadorTroca();

//Algoritmos de ordena��o
void BubbleSort(int* vetor);                                                    //1)Bubble Sort - original
void BubbleSortAdvanced(int* vetor);                                            //2)Bubble Sort - melhorado

void QuickSortPivoInicio(int *vetor, int esq, int dir);                         //3)Quick Sort - Piv� primeiro elemento
int ParticionarInicio(int *vetor, int esq, int dir);

void QuickSortPivoCentral(int *vetor, int n);                                   //4)Quick Sort - Piv� elemento central
void Sort(int *vetor, int esq, int dir);
void ParticionarCentral(int *vetor, int esq, int dir, int *inicio, int *fim);

void InsertionSort(int* vetor);                                                 //5)Insertion Sort

void ShellSort(int *vetor);                                                     //6)Shell Sort

void SelectionSort(int* vetor);                                                 //7)Selection Sort

void HeapSort(int* vetor);                                                      //8)Heap Sort
void MaxHeap(int* vetor, int p, int m);

void MergeSort(int* vetor, int p, int r);                                       //9)Merge Sort
void Merge(int* vetor, int p, int q, int r);

#endif // ORDENACAO_
