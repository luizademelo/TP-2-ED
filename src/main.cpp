#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/wordcounter.hpp"

int main(int argc, char **argv)
{
    int opt;
    char *arquivo_entrada;
    char *arquivo_saida;

    while ((opt = getopt(argc, argv, "i:I:o:O:s:S:m:M:")) != -1)
    {
        switch (opt)
        {
        case 'i':
        case 'I':
            arquivo_entrada = optarg;
            break;
        case 'o':
        case 'O':
            arquivo_saida = optarg;
            break;
        case 'm':
        case 'M': 
            defineMediana(atoi(optarg)); 
            break; 
        case 's':
        case 'S':
            defineTamParticao(atoi(optarg)); 
            break; 
        }
    }
    leEntrada(arquivo_entrada);
    defineTamanhoPalavra(); 
    ordenaTexto();
    escreveSaida(arquivo_saida);

    return 0;
}
