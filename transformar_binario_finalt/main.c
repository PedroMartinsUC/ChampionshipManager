#include "funcoes.h"

// Este programa autónomo permite a transformação dos dois ficheiros de texto iniciais em dois ficheiros binários, para
// serem posteriormente usados no programa principal. Se tudo decorrer normalmente, o programa retornará 0.

int main() {

    textToBinaryTeams("configi.txt", "outputteams.bin");
    textToBinaryResults("config.txt", "outputresults.bin");

    printf("\nOs ficheiros foram convertidos para binário com sucesso!\n");
    return 0;

}
