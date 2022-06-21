#include "../include/wordcounter.hpp"

char ordem[28];
Palavra texto[5000];
int tamanho_texto = 0;
int mediana = -1;
int max_tam_particao = -1;

void leEntrada(char *nome_arquivo)
{
    FILE *entrada;
    entrada = fopen(nome_arquivo, "r");
    assert(entrada && "Arquivo nao encontrado!");
    char tag[10];
    fscanf(entrada, "%s\n", tag);
    if (tag[1] == 'O')
    {
        leOrdem(entrada);
        fscanf(entrada, "%s\n", tag);
        leTexto(entrada);
    }
    else
    {
        leTexto(entrada);
        leOrdem(entrada);
    }
}

void defineTamParticao(int tam)
{
    max_tam_particao = tam;
}

void defineMediana(int med)
{
    mediana = med / 2;
}

void leOrdem(FILE *file)
{
    for (int i = 0; i < 26; i++)
    {
        fscanf(file, "%c ", &ordem[i]);
        ordem[i] = tolower(ordem[i]);
    }
}

void leTexto(FILE *file)
{
    while (fscanf(file, "%s ", &texto[tamanho_texto].palavra) == 1)
    {
        char tag_ordem[100] = "#ORDEM";
        if (palavrasSaoIguais(tag_ordem, texto[tamanho_texto].palavra))
            break;
        palavraParaMinuscula(texto[tamanho_texto].palavra);
        ignoraPontuacao(texto[tamanho_texto].palavra);
        addFrequenciaPalavra(&texto[tamanho_texto]);
        tamanho_texto++;
    }
}

void ignoraPontuacao(char p1[])
{
    char *src, *dst;
    for (src = dst = p1; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != ',' && *dst != '.' && *dst != '!' && *dst != '?' && *dst != ':' && *dst != ';' && *dst != '_' && *dst != ' ')
            dst++;
    }
    *dst = '\0';
    p1 = dst;
}

void addFrequenciaPalavra(Palavra *p)
{
    int index_palavra = getIndexPalavra(p->palavra);
    if (index_palavra >= 0)
    {
        texto[index_palavra].addFrequencia();
        tamanho_texto--;
    }
    else
        p->addFrequencia();
}

void defineTamanhoPalavra()
{
    for (int i = 0; i < tamanho_texto; i++)
    {
        int tam = 0;
        while (texto[i].palavra[tam] != '\0')
            tam++;
        texto[i].tamanho = tam; 
    }
}

int getIndexChar(char c)
{
    for (int i = 0; i < 26; i++)
        if (c == ordem[i])
            return i;
    return (int)c;
}

int getIndexPalavra(char palavra[])
{
    for (int i = 0; i < tamanho_texto; i++)
        if (palavrasSaoIguais(texto[i].palavra, palavra))
            return i;
    return -1;
}

bool palavrasSaoIguais(char p1[], char p2[])
{
    if (strcmp(p1, p2) == 0)
        return true;
    return false;
}

void palavraParaMinuscula(char p1[])
{
    for (int i = 0; p1[i]; i++)
        p1[i] = tolower(p1[i]);
}

void ordenaTexto()
{
    Ordena(0, tamanho_texto - 1);
}

void Selecao(int Esq, int Dir)
{
    int i = Esq, j, Min;
    for (; i < Dir; i++)
    {
        Min = i;
        for (j = i + 1; j < Dir; j++)
        {
            if (texto[j] < texto[Min])
                Min = j;
        }
        Palavra aux = texto[i];
        texto[i] = texto[Min];
        texto[Min] = aux;
    }
}

void Ordena(int Esq, int Dir)
{
    int i, j;
    Particao(Esq, Dir, &i, &j);
    if (Esq < j)
        Ordena(Esq, j);
    if (i < Dir)
        Ordena(i, Dir);
}

void Particao(int Esq, int Dir, int *i, int *j)
{
    Palavra x, w;
    *i = Esq;
    *j = Dir;
    /* obtem o pivo x */
    if (mediana >= 0)
        x = texto[mediana];
    else
        x = texto[(*i + *j) / 2];
    do
    {
        while (x > texto[*i])
            (*i)++;
        while (x < texto[*j])
            (*j)--;
        if (*i <= *j)
        {
            w = texto[*i];
            texto[*i] = texto[*j];
            texto[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}


void escreveSaida(char *nome_arquivo)
{
    FILE *saida;
    saida = fopen(nome_arquivo, "w");
    escrevePalavras(saida);
    fprintf(saida, "#FIM\n");
    fclose(saida);
}

void escrevePalavras(FILE *file)
{
    for (int i = 0; i < tamanho_texto; i++)
        fprintf(file, "%s %d\n", texto[i].palavra, texto[i].getFrequencia());
}