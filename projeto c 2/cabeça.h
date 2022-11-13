#include <iostream> 
#include <ctime>
#include <experimental/random>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

typedef struct numeros{
    int bubble[100];
    int insertion[100];
    int selection[100];
    }Aleatorio;


int quant = 0, valor = 0;
Aleatorio *estrutura;
void gerar(), bubblesort(), selectionsort(), insertionsort(), swap();

void gerar(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    for(int i = 1; i < 100; i++){
        srand(time(nullptr));

        estrutura->bubble[i] = experimental::randint(0,1000);
        estrutura->insertion[i] = estrutura->bubble[i];
        estrutura->selection[i] =  estrutura->bubble[i];
    } 
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken;
time_taken = (end.tv_sec - start.tv_sec) * 1e9;
time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

cout << "Levou : " << fixed << time_taken << setprecision(9);
cout << " segundos para gerar 100 números pseudo-aleatórios de 0 a 1000" << endl;
}

void bubblesort(){
    cout << "⇩⇩⇩⇩**********BUBBLE SORT**********⇩⇩⇩⇩" << endl;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    int aux;
    for (int i=0; i<100; i++){
        for (int j=i; j<100; j++){
            if (estrutura->bubble[i]>estrutura->bubble[j]){
                aux = estrutura->bubble[i];
                estrutura->bubble[i] = estrutura->bubble[j];
                estrutura->bubble[j] = aux;
            }
        }
    }
    for (int i=0; i<100; i++){
        cout << "Estrutura Bubble-Sort: " << estrutura->bubble[i] << endl;
    }
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken;
time_taken = (end.tv_sec - start.tv_sec) * 1e9;
time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

cout << "Levou : " << fixed << time_taken << setprecision(9);
cout << " segundos para organizar os números usando Bubble Sort" << endl;        

}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void selectionsort(){
    cout << "⇩⇩⇩⇩**********SELECTION SORT**********⇩⇩⇩⇩" << endl;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
  for (int step = 0; step < 100 - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < 100; i++) {
      if (estrutura->selection[i] < estrutura->selection[min_idx])
        min_idx = i;
    }
    swap(&estrutura->selection[min_idx], &estrutura->selection[step]);
  }
for (int i=0; i<100; i++){
    cout << "Estrutura Selection-Sort: " << estrutura->selection[i] << endl;
    }
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken;
time_taken = (end.tv_sec - start.tv_sec) * 1e9;
time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

cout << "Levou : " << fixed << time_taken << setprecision(9);
cout << " segundos para organizar os números usando Selection Sort" << endl;

}

void insertionsort(){
    cout << "⇩⇩⇩⇩**********INSERTION SORT**********⇩⇩⇩⇩" << endl;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    int i, key, j;
	for (i = 1; i < 100; i++){
		key = estrutura->insertion[i];
		j = i - 1;
		while (j >= 0 && estrutura->insertion[j] > key)
		{
			estrutura->insertion[j + 1] = estrutura->insertion[j];
			j = j - 1;
		}
		estrutura->insertion[j + 1] = key;
	}
for (int i=0; i<100; i++){
    cout << "Estrutura Insertion-Sort: " << estrutura->insertion[i] << endl;
    }   
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken;
time_taken = (end.tv_sec - start.tv_sec) * 1e9;
time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

cout << "Levou : " << fixed << time_taken << setprecision(9);
cout << " segundos para organizar os números usando Insertion Sort" << endl;
cout << "****************************************" << endl;
}

