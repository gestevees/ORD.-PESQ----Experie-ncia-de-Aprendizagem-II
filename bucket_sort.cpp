#include "bucket_sort.h"
#include <algorithm>
#include <cmath>

// Função auxiliar para ordenar os buckets individualmente
bool compararNotas(const Aluno& a, const Aluno& b) {
    return a.nota < b.nota;
}

void bucketSort(vector<Aluno>& alunos) {
    if (alunos.empty()) return;

    // Define o número de baldes (buckets)
    int n = alunos.size();
    vector<vector<Aluno>> buckets(n);

    // Encontra a maior nota para normalizar os valores entre 0 e 1
    float maxNota = alunos[0].nota;
    for (const Aluno& a : alunos) {
        if (a.nota > maxNota) maxNota = a.nota;
    }

    // Distribui os alunos nos buckets com base em suas notas
    for (const Aluno& a : alunos) {
        int indice = (a.nota / maxNota) * (n - 1);
        buckets[indice].push_back(a);
    }

    // Ordena cada bucket individualmente
    for (int i = 0; i < n; ++i) {
        sort(buckets[i].begin(), buckets[i].end(), compararNotas);
    }

    // Concatena os buckets ordenados de volta ao vetor original
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (const Aluno& a : buckets[i]) {
            alunos[index++] = a;
        }
    }
}
