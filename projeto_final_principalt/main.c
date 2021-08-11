#include "funcoes.h"

// Este programa é responsável por receber 2 ficheiros binários, um contendo uma lista de equipas e o outro uma lista de
// resultados. De seguida irá ser pedido ao utilizador o número de equipas que constam da lista de equipas. Este número
// tem de ser superior a 3 de forma a que, num dos ficheiros de saida, o programa possa devolver as 2 equipas promovidas
// e as duas equipas despromovidas. De seguida é feita a inicialização das 3 pilhas com recurso à função
// inicializar_pilha. Depois irão ser executadas as funções readteams e readsults para ler o ficheiro das equipas e dos
// resultados, respetivamente. De seguida é executada a função Organizar, que irá ordenar a pilha que contem as equipas
// e por fim a função Imprimir, que escreve os dados nos dois ficheiros de saída. Se tudo funcionar, o programa retorna
// 0. Caso aconteça alguma anomalia, o código de retorno será diferente de 0. O ficheiro outputteams.bin corresponde à
// lista de equipas em binário e o ficheiro outputresults.bin corresponde à lista de resultados também em binário.

int main() {

    int n = 0;

    while(1){
        printf("\nBem-vindo ao programa. Por favor introduza o número de equipas:");
        scanf("%d", &n);
        if (n > 3){
            break;
        } else{
            printf("\nIntroduza um número maior que 3!\n");
        }
    }

    inicializar_pilha();
    inicializar_pilha2();
    inicializar_pilha3();

    if (readteams("outputteams.bin", n+1) == -1){
        return -1;
    }

    if (readresults("outputresults.bin", n) == -1){
        return -2;
    }

    Organizar();

    Imprimir(n);

    return 0;
}