#include <iostream>
#include <chrono>
#include <locale>
#include "util.h"
#include "bucket_sort.h"
#include "quick_sort.h"
using namespace std;
using namespace std::chrono;

int main() {
    string caminho = "alunos.csv";
    
    // Lê os dados do arquivo CSV
    vector<Aluno> alunos = lerCSV(caminho);

    cout << "Alunos lidos:\n";
    imprimirAlunos(alunos);

    // ---------- BUCKET SORT ----------    
    auto inicioBS = high_resolution_clock::now();
    vector<Aluno> alunosBucket = alunos; // cópia para Bucket Sort
    bucketSort(alunosBucket);
    auto fimBS = high_resolution_clock::now();
    auto duracaoBS = duration_cast<microseconds>(fimBS - inicioBS);  // Medição em microsegundos

    cout << "\nAlunos ordenados (Bucket Sort):\n";
    imprimirAlunos(alunosBucket);
    cout << "\nTempo de execucao (Bucket Sort): " << duracaoBS.count() << " microssegundos\n";

    // ---------- QUICK SORT ----------
    auto inicioQS = high_resolution_clock::now();
    vector<Aluno> alunosQuick = alunos; // cópia para Quick Sort
    quickSort(alunosQuick, 0, alunosQuick.size() - 1);
    auto fimQS = high_resolution_clock::now();
    auto duracaoQS = duration_cast<microseconds>(fimQS - inicioQS);  // Medição em microsegundos

    cout << "\nAlunos ordenados (Quick Sort):\n";
    imprimirAlunos(alunosQuick);
    cout << "\nTempo de execucao (Quick Sort): " << duracaoQS.count() << " microssegundos\n";

    return 0;
}
