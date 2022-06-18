#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string> 
#include <string.h> 
#include <assert.h>
#include <iostream>
#include <cctype> 

class Palavra 
{
    public: 
        char palavra[100]; 
        int posicaoOrdem = -1; 
        void addFrequencia()
        {
            frequencia += 1; 
        }
        int getFrequencia()
        {
            return this->frequencia;
        }
    private: 
        int frequencia = 0; 

}; 

int getIndexPalavra(char palavra[]); 
void addFrequenciaPalavra(Palavra *p); 
bool palavrasSaoIguais(char p1[], char p2[]);
void palavraParaMinuscula(char p1[]);
void ignoraPontuacao(char p1[]); 
void ordenaTexto(); 
void Ordena(int Esq, int Dir); 
void Particao(int Esq, int Dir, int *i, int *j); 
void Selecao(); 
void definePosicaoNaOrdem(Palavra *p); 
void definePosicaoTexto(); 
void leEntrada(char * nome_arquivo); 
void defineMediana(int med); 
void defineTamParticao(int tam); 
void leOrdem(FILE * file); 
void leTexto(FILE * file); 
void escreveSaida(char * nome_arquivo); 
void escrevePalavras(FILE * file); 

#endif // !WORDCOUNTER_H