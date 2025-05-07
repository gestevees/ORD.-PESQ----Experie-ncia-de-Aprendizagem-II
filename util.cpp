#include "util.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Aluno> lerCSV(const string& caminho) {
    vector<Aluno> alunos;
    ifstream file(caminho);
    string linha;
    getline(file, linha); // ignora cabeçalho

    // Lê linha por linha do arquivo
    while (getline(file, linha)) {
        stringstream ss(linha);
        string nome, notaStr;

        // Separa os campos por vírgula
        if (getline(ss, nome, ',') && getline(ss, notaStr)) {
            Aluno a;
            a.nome = nome;
            a.nota = stof(notaStr); // converte nota para float
            alunos.push_back(a);
        }
    }
    return alunos;
}

void imprimirAlunos(const vector<Aluno>& alunos) {
    for (const Aluno& a : alunos) {
        cout << a.nome << ": " << a.nota << endl;
    }
}
