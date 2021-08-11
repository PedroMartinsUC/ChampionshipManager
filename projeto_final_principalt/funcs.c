#include "funcoes.h"

// Para cada pilha existem 4 funções. A inicializar_pilha permite-nos atribuir a cada stack pointer o valor inicial
// NULL. A função Emptycheck vai verificar se o stack pointer da pilha se encontra NULL, ou seja, se a pilha está vazia.
// Caso se verifique, a função deve retornar -1; contudo se não estiver vazia o resultado a devolver será 0. A função
// push vai-nos permitir adicionar uma estrutura à pilha; para isso irá alocar um espaço de memória destinado à estrutu-
// ra que se pretende introduzir. Também é responsável por atualizar o stack pointer uma vez que o topo da pilha muda
// com a introdução de um novo dado na pilha. Por fim temos a função pop que é responsável por remover a estrutura que
// se encontra no topo da pilha, retornando a mesma. Ao longo da função o stack pointer também será atualizado e o espa-
// ço anteriormente ocupado pela estrutura que removemos da pilha será libertado.

// Estrutura da PILHA 1: Esta é a pilha inicial. É aqui que vão ser inseridos os dados iniciais. Também irá servir como
// auxílio para a ordenação dos dados para a pilha final.

static struct pilha *a;

void inicializar_pilha() {
    a = NULL;
}

int Emptycheck(){
    if (a == NULL){
        return -1;
    }
    return 0;
}

int push(struct equipa d) {
    struct pilha *aux;
    
    aux = (struct pilha *) malloc(sizeof(*aux));
    if (aux == NULL) {
        printf("\nSem espaço disponível!\n");
        return 1;
    }
    aux->equipas = d;
    aux->pseg = a;
    a = aux;
    return 0;
}

struct equipa pop() {
    struct equipa d;
    struct pilha *aux;

    d = (a)->equipas;
    aux = a;
    (a) = (a)->pseg;
    free(aux);
    return d;
}

// Estrutura da PILHA 2: Esta é a pilha final e ordenada. É daqui que os dados vão sair para o ficheiro final. Ao longo
// do programa também será usada como uma pilha temporária para circular os dados da primeira pilha de forma a adicionar
// a pontuação.

static struct pilha *b;

void inicializar_pilha2() {
    b = NULL;
}

int Emptycheck2(){
    if (b == NULL){
        return -1;
    }
    return 0;
}

int push2(struct equipa e) {
    struct pilha *aux2;

    aux2 = (struct pilha *) malloc(sizeof(*aux2));
    if (aux2 == NULL) {
        printf("\nSem espaço disponível!\n");
        return 1;
    }
    aux2->equipas = e;
    aux2->pseg = b;
    b = aux2;
    return 0;
}

struct equipa pop2() {
    struct equipa d;
    struct pilha *aux;

    d = (b)->equipas;
    aux = b;
    (b) = (b)->pseg;
    free(aux);

    return d;

}

// Estrutura da PILHA 3: Esta é apenas uma pilha temporária. Serve como auxílio para a organização da pilha final.

static struct pilha *c;

void inicializar_pilha3() {
    c = NULL;
}

int Emptycheck3(){
    if (c == NULL){
        return -1;
    }
    return 0;
}

int push3(struct equipa f) {
    struct pilha *aux3;

    aux3 = (struct pilha *) malloc(sizeof(*aux3));
    if (aux3 == NULL) {
        printf("\nSem espaço disponível!\n");
        return 1;
    }
    aux3->equipas = f;
    aux3->pseg = c;
    c = aux3;
    return 0;
}

struct equipa pop3() {
    struct equipa d;
    struct pilha *aux;

    d = (c)->equipas;
    aux = c;
    (c) = (c)->pseg;
    free(aux);

    return d;
}

// Fim das funções relativas às 3 pilhas.

// A função readteams tem como objetivo ler a lista de equipas e adicioná-las a um array de estruturas para poderem ser
// adicionadas à pilha inicial. Contém diversos mecanismos para deteção de erros no ficheiro ou na introdução de dados
// por parte do utilizador.

int readteams(char *inp, int n){

    FILE *ifpbt;
    equipa equipas[n];
    int i = 0;
    int j = 0;

    ifpbt = fopen(inp, "rb");

    if (ifpbt == NULL){
        printf("\nFicheiro inválido ou em branco\n");
        return -1;
    }

    while((fread(&equipas[i].nome, sizeof(char), MAXSIZE, ifpbt))){
        equipas[i].pontos = 0;
        while(1){
            if (equipas[i].nome[j] != '\n'){
                j++;
            } else{
                equipas[i].nome[j] = '\0';
                break;
            }
        }
        push(equipas[i]);
        i++;
        if (i == n){
            break;
        }
        j = 0;
    }

    if (i+1 != n){
        printf("\nO número de equipas não coincide com o valor que introduziu. A encerrar programa!\n");
        exit(1);
    }

    fclose(ifpbt);

    return 0;
}

// A função readresults têm como objetivo ler todos os resultados do ficheiro binário de origem, armazená-los numa va-
// riável temporária para que os pontos possam ser atribuídos a cada equipa. Também é responsável por detetar um diverso
// conjunto de erros na lista de resultados.

int readresults(char *inp, int n){

    int n1, n2;
    char equipa1[MAXSIZE];
    char equipa2[MAXSIZE];
    FILE *ifpbr;

    ifpbr = fopen(inp, "rb");

    if (ifpbr == NULL){
        printf("\nFicheiro inválido ou em branco\n");
        return -1;
    }

    while((fread(&equipa1, sizeof(char), MAXSIZE, ifpbr))){
        (fread(&equipa2, sizeof(char), MAXSIZE, ifpbr));
        (fread(&n1, sizeof(int), 1, ifpbr));
        (fread(&n2, sizeof(int), 1, ifpbr));

        if (n1 < 0 || n2 < 0){
            printf("\nVocê possui um resultado com um valor negativo na lista de resultados. A encerrar programa!\n");
            exit(2);
        }

        if (n1 > n2){
            addPoints(equipa1, 2, n);
            addPoints(equipa2, 1, n);
        } else if (n1 < n2){
            addPoints(equipa1, 1, n);
            addPoints(equipa2, 2, n);
        } else {
            printf("\nA lista de resultados contém um empate, o que não é possível. A encerrar programa!\n");
            exit(3);
        }

    }

    fclose(ifpbr);
    return 0;
}

// A função addPoints vai ser utilizada de forma a atualizar a pontuação das equipas à medida que os resultados são li-
// dos. Para isso é-nos fornecido o nome da equipa e a pontuação que queremos adicionar, assim como o número de equipas.
// Com estes dados a função vai fazer uma iteração pela pilha 1 até encontrar o nome da equipa à qual queremos adicionar
// a pontuação. Se o nome que encontrar não for idêntico àquele que procura, a estrutura que possui esse nome é removida
// da pilha 1 e é introduzida na pilha 2, atualizando assim o stack pointer para permitir que a procura continue. Após o
// resultado ser corretamente adicionado, todas as equipas que foram movidas para a pilha 2 são novamente recolocadas na
// pilha 1.

void addPoints(char equipa[MAXSIZE], int pontos, int n){
    int i;
    int found = 0;

    for(i = n; i > 0; i--){
        if (strcmp(equipa, a->equipas.nome) == 0){
            a->equipas.pontos += pontos;
            found++;
            break;
        } else{
            push2(pop());

        }

    }

    if (found == 0){
        printf("\nA equipa %s que se encontra no ficheiro de resultados não consta da lista de equipas. A encerrar programa!\n", equipa);
        exit(4);
    }

    while (Emptycheck2() != -1){
        push(pop2());

    }

}

// Função Organizar tem como objetivo ordenar a pilha inicial. Para esse efeito a pilha 2 será a pilha final, onde os
// dados irão estar organizados pela sua pontuação. Para isso vamos remover os dados da pilha 1 (pilha inicial) um a um
// e movê-los para a pilha 2. Nesta pilha iremos mover todos os dados cuja pontuação seja superior à da equipa que
// pretendemos introduzir nesta pilha para uma terceira pilha. Após encontrarmos o lugar para a equipa que estamos a mo-
// ver da pilha 1 iremos reintroduzir todos os dados temporariamente movidos para a 3ª pilha de volta na pilha 2. Este
// ciclo repete-se até a pilha inicial se encontrar totalmente vazia.

void Organizar(){

    int g = 0;

    while(Emptycheck() != -1){
        if(g != 0){
            for(; g > 0; g++){
                if((a)->equipas.pontos <= (b)->equipas.pontos) {
                    push3(pop2());
                } else{
                    break;
                }
            }
            push2(pop());
            while(Emptycheck3() != -1){
                push2(pop3());
            }
        }else{
            push2(pop());
        }
        g++;
    }
    printf("\nDados introduzidos e organizados!\n\n");
}

// Função Imprimir tem vários objetivos. Primeiro pede ao utilizador dois nomes para os ficheiros de saída que têm de
// ter a extensão ".txt". Caso não se verifique terão de reintroduzir até fornecerem um ficheiro com a extensão correta.
// A seguir, a função vai começar a retirar as estruturas da pilha final e começar a passar as equipas, que já se encon-
// tram ordenadas pelos pontos finais, para um ficheiro de texto. Ao mesmo tempo, irá também enviar para um segundo fi-
// cheiro de texto o vencedor do campeonato, assim como as equipas promovidas e despromovidas.

void Imprimir(int n) {

    FILE *inp;
    FILE *inp2;
    int i = 0;
    char saida[MAXSIZE];

    while(1) {
        printf("Por favor introduza um nome para o primeiro ficheiro de saída (Extensão .txt):");
        scanf("%s", saida);
        if (Extcheck(saida, ".txt") == 0){
            inp = fopen(saida, "w");
            break;
        } else {
            printf("\nA extensão que apresentou não é do tipo txt, por favor reintroduza o nome do ficheiro.\n\n");
        }

    }
    while(1) {
        printf("\nPor favor introduza um nome para o segundo ficheiro de saída (Extensão .txt):");
        scanf("%s", saida);
        if (Extcheck(saida, ".txt") == 0) {
            inp2 = fopen(saida, "w");
            break;
        } else {
            printf("\nA extensão que apresentou não é do tipo txt, por favor reintroduza o nome do ficheiro.\n\n");
        }

    }
    while(Emptycheck2() != -1) {
        fprintf(inp, "%s\t%d\n", b->equipas.nome, b->equipas.pontos);
        if (i == 0) {
            fprintf(inp2, "\n***************Equipa campeã***************\n\n");
            fprintf(inp2, "%s\n\n", b->equipas.nome);
            fprintf(inp2, "\n***************Equipas promovidas***************\n\n");
            fprintf(inp2, "%s\n", b->equipas.nome);
        } else if (i == 1) {
            fprintf(inp2, "%s\n\n", b->equipas.nome);
            fprintf(inp2, "\n***************Equipas despromovidas***************\n\n");
        } else if (i == n-2){
            fprintf(inp2, "%s\n", b->equipas.nome);
        } else if (i == n-1){
            fprintf(inp2, "%s", b->equipas.nome);
        }
        i++;
        pop2();
    }

    printf("\nDados introduzidos nos dois ficheiros de saída com sucesso!\n");
    fclose(inp);
    fclose(inp2);
}

//Função ExtCheck verifica se a extensão fornecida pelo utilizador para os ficheiros de saida corresponde à pedida no
//trabalho. Caso isso não se verifique, a função deve retornar 1 e se se verificar deve retornar 0.

int Extcheck(char nome[MAXSIZE], char ext[MAXSIZE]){
    int k = 0;
    int l = 0;

    for (int i = (int)strlen(nome)-4; i<(int)strlen(nome); i++){
        if (nome[i] == ext[k]){
            l++;
        }
        k++;
    }

    if (l == (int)strlen(ext)){
        return 0;
    } else {
        return 1;
    }

}
