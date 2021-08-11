#include "funcoes.h"

// A função textToBinaryTeams é responsável por converter o ficheiro de texto contendo a lista de equipas num ficheiro
// binário, de forma a poder ser lido pelo programa principal.

void textToBinaryTeams(char *inp, char *out){
    FILE *ifp;
    FILE *ofp;
    char first[MAXSIZE];

    ifp = fopen(inp, "r");
    if (ifp == NULL){
        printf("\nFicheiro de equipas inválido ou em branco. A encerrar programa!\n");
        exit(1);
    }
    ofp = fopen(out, "wb");

    rewind(ifp);

    while(1)
    {
        fgets(first, MAXSIZE, ifp);
        fwrite(first, MAXSIZE, sizeof(char), ofp);
        if(feof(ifp))
        {
            break;
        }
    }

    fclose(ifp);
    fclose(ofp);
}

// A função textToBinaryTeams é responsável por converter o ficheiro de texto contendo a lista de resultados num fichei-
// ro binário, de forma a poder ser lido pelo programa principal.

void textToBinaryResults(char *inp, char *out){
    FILE *ifp;
    FILE *ofp;
    unsigned int x;
    unsigned int y;
    char first[MAXSIZE];
    char second[MAXSIZE];

    ifp = fopen(inp, "r");
    if (ifp == NULL){
        printf("\nFicheiro de resultados inválido ou em branco. A encerrar programa!\n");
        exit(2);
    }
    ofp = fopen(out, "wb");

    rewind(ifp);

    while(1)
    {
        fscanf(ifp, "%s %s %u %u\n", first, second, &x, &y);
        fwrite(first, MAXSIZE, sizeof(char), ofp);
        fwrite(second, MAXSIZE, sizeof(char), ofp);
        fwrite(&x, 1, sizeof(unsigned int), ofp);
        fwrite(&y, 1, sizeof(unsigned int), ofp);
        if(feof(ifp))
        {
            break;
        }
    }

    fclose(ifp);
    fclose(ofp);
}
