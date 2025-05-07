#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include "aluno.h"

// Lê um arquivo CSV contendo nome e nota dos alunos
vector<Aluno> lerCSV(const string& caminho);

// Imprime os dados dos alunos
void imprimirAlunos(const vector<Aluno>& alunos);

#endif
