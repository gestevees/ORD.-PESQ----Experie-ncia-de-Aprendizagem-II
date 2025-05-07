#include "quick_sort.h"
#include <algorithm>

// Função auxiliar para particionar o vetor
int particionar(vector<Aluno>& alunos, int inicio, int fim) {
    float pivo = alunos[fim].nota; // pivô escolhido como último elemento
    int i = inicio - 1;

    for (int j = inicio; j < fim; ++j) {
        if (alunos[j].nota < pivo) {
            ++i;
            swap(alunos[i], alunos[j]);
        }
    }
    swap(alunos[i + 1], alunos[fim]);
    return i + 1;
}

// Função principal do Quick Sort
void quickSort(vector<Aluno>& alunos, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(alunos, inicio, fim);
        quickSort(alunos, inicio, indicePivo - 1);
        quickSort(alunos, indicePivo + 1, fim);
    }
}
