#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <cctype>

int getIndexChar(char c);

class Palavra
{
public:
    char palavra[100];
    int tamanho = 0;
    void addFrequencia()
    {
        frequencia += 1;
    }
    int getFrequencia()
    {
        return this->frequencia;
    }
    bool operator>(Palavra p2)
    {
        int i = 0;
        while (this->palavra[i] != '\0' && p2.palavra[i] != '\0')
        {
            if (this->palavra[i] == p2.palavra[i])
                i++;
            else
            {
                if (this->palavra[i] >= 97 && p2.palavra[i] >= 97)
                {
                    int i1 = getIndexChar(this->palavra[i]);
                    int i2 = getIndexChar(p2.palavra[i]);
                    if (i1 > i2)
                        return true;
                    return false;
                }
                if (this->palavra[i] > p2.palavra[i])
                    return true;
                return false;
            }
        }
        // printf("this: %s\n", this->palavra);
        // printf("p2: %s\n", p2.palavra);
        if (strcmp(this->palavra, p2.palavra) == 0)
            return false;
        if (this->tamanho > p2.tamanho)
            return true;
        else
            return false;
    }
    bool operator<(Palavra p2)
    {
        int i = 0;
        while (this->palavra[i] != '\0' && p2.palavra[i] != '\0')
        {
            if (this->palavra[i] == p2.palavra[i])
                i++;
            else
            {
                if (this->palavra[i] >= 97 && p2.palavra[i] >= 97)
                {
                    int i1 = getIndexChar(this->palavra[i]);
                    int i2 = getIndexChar(p2.palavra[i]);
                    if (i1 < i2)
                        return true;
                    return false;
                }
                if (this->palavra[i] < p2.palavra[i])
                    return true;
                return false;
            }
        }
        if (strcmp(this->palavra, p2.palavra) == 0)
            return false;
        if (this->tamanho > p2.tamanho)
            return false;
        else
            return true;
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
void Selecao(int Esq, int Dir); 
void defineTamanhoPalavra();
void leEntrada(char *nome_arquivo);
void defineMediana(int med);
void defineTamParticao(int tam);
void leOrdem(FILE *file);
void leTexto(FILE *file);
void escreveSaida(char *nome_arquivo);
void escrevePalavras(FILE *file);

#endif // !WORDCOUNTER_H