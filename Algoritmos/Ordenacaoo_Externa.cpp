/***************************************
 * Ordenação Externa
 * Vinícius Rodrigues Souza
 * 08/04/2018 - IFNMG - Montes Claros
 * *************************************/

#include <bits/stdc++.h>
using namespace std;

#define sizereg 11 //Tamanho do registro
#define sc second
#define ft first

typedef long long LL;
typedef pair<int, LL> ii;
typedef struct {
    LL pos_cur; //Posicao atual no arquivo
    LL qtd_lidos; //Posicao atual no buffer
    LL qtd_itens; //Quantidade de itens atualmente no Buffer
    LL qtd_total; //Quantidade total de registros passados no buffer
    int *dados;
}BufferIn;

typedef struct {
    LL pos_cur; //Posicao atual dio ponteiro no aquivo de saida
    LL qtd_inseridos; //Quantidade inseridos no buffer
    LL qtd_total; //Quanitdade total de registros inseridos no arquivo de saida
    int *dados;
}BufferOut;

/**********************************
M memoria RAM / tamanho do registro
N Numero de registros no arquivo de entrada
B Tamanho de cada Buffer
K numero de blocos
K + 1 numero de Buffers
***********************************/

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

struct comparepq
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.ft > y.ft;
    }
};

/**********************************
PRIMEIRA FASE: ORDENACAO DOS BLOCOS
***********************************/
void primeiraFase(FILE *arq, FILE *temporario, LL M, LL K) {
    
    int *v;
    v = new int[M];
    
    LL posin, posOut;
    posin = posOut = 0;
    
    while(K--) {
        LL J = 0;
        fseek(arq, posin, SEEK_SET);
        while(J < M && fscanf(arq, "%d", &v[J]) == 1) J++;
        posin = ftell(arq);
        qsort(v, J , sizeof(v[0]), compare);
        fseek(temporario, posOut, SEEK_SET);
        for(int i=0; i < J; ++i) fprintf(temporario, "%010d\n", v[i]);
        posOut = ftell(temporario);
    }

    delete v;
}

/**********************************
SEGUNDA FASE
***********************************/
/**********************************
Carregar BUffer
***********************************/
void loadBuffer(FILE *temporario, BufferIn *v, ii menor, LL M, LL B) {
    if(v[menor.sc].qtd_lidos == v[menor.sc].qtd_itens && v[menor.sc].qtd_total < M) {
        LL J = 0;
        v[menor.sc].qtd_lidos = 0;
        fseek(temporario, v[menor.sc].pos_cur, SEEK_SET);
        while(J < B && v[menor.sc].qtd_total < M && fscanf(temporario, "%d", &v[menor.sc].dados[J]) == 1) {
            J++;
            v[menor.sc].qtd_total++;
            v[menor.sc].pos_cur = ftell(temporario);
        }

        v[menor.sc].qtd_itens = J;
    }
}

/************************************
Descarregar bUffer de saida no arquivo
de saida
**************************************/
void downloadBufferOut(FILE *saida, BufferOut *control, LL B) {
    if(control->qtd_inseridos == B) {
        fseek(saida, control->pos_cur, SEEK_SET);
        for(int i=0; i < B; ++i) fprintf(saida, "%010d\n", control->dados[i]);
        control->qtd_inseridos = 0;
        control->qtd_total += B;            
        control->pos_cur = ftell(saida);
    }
}

/****************************************
 * Inicializar Buffers
 * **************************************/
void setBuffer(FILE *temporario, BufferIn *v, BufferOut *control, LL K, LL D, LL B) {
    for(int i=0; i < K; ++i) {
        v[i].pos_cur = D*i;
        v[i].qtd_total = 0;
        v[i].qtd_lidos = 0;        
        v[i].dados = new int[B];
        LL J = 0;
        fseek(temporario, v[i].pos_cur, SEEK_SET);
        while(J < B && fscanf(temporario, "%d", &v[i].dados[J]) == 1) {
            J++;
            v[i].qtd_total++;
            v[i].pos_cur = ftell(temporario);                    
        }
        v[i].qtd_itens = J;
    }

    control->dados = new int[B];
    control->qtd_inseridos = 0;
    control->qtd_total = 0;    
    control->pos_cur = 0;

}

void segundaFase(const char *fileIn, FILE *temporario, LL M, LL K, LL N) {
    LL B = M / (K + 1); //Tamanho de cada Buffer
    LL D = M * sizereg;  

    FILE *saida;
    char outFile[60]; LL I = 0;    
    do sprintf(outFile, "%s(%lld).ordenado", fileIn, I++);
    while((saida = fopen(outFile, "r")));
    saida = fopen(outFile, "w+");

    BufferIn *v = new BufferIn[K];
    BufferOut *control = new BufferOut;    

    priority_queue<ii, vector<ii>, comparepq> pq;
    setBuffer(temporario, v, control, K, D, B);
    for(int i=0; i < K; ++i) pq.push(ii(v[i].dados[v[i].qtd_lidos++], i));

    ii menor;
    while(!pq.empty()) {
        menor = pq.top(); pq.pop();
        control->dados[control->qtd_inseridos++] = menor.ft;
        downloadBufferOut(saida, control, B);
        loadBuffer(temporario, v, menor, M, B);
        if(v[menor.sc].qtd_lidos < v[menor.sc].qtd_itens)
            pq.push(ii(v[menor.sc].dados[v[menor.sc].qtd_lidos++], menor.sc));            
    }

    for(int i=0; i < N-control->qtd_total; i++)
        fprintf(saida, "%010d\n", control->dados[i]);

    fclose(saida);
}

bool ordenacaoExterna(const char *memoria, const char *arquivo) {

    LL N, M, K, I;

    sscanf(memoria, "%lld", &M);
    FILE *arq = fopen(arquivo, "r");
    if(!arq || M == 0) return false; //Caso o arquivo nao tenha sido encontrado        

    fseek(arq, 0, SEEK_END);
    N = ftell(arq)/ sizereg; //Numero de registros
    M = M / sizeof(int);

    if(N%M != 0) K = N/M + 1;
    else K = N/M;
    
    if(K == 0 || M / (K + 1) == 0) return false;

    FILE *temporario;
    char tmpFile[60]; I = 0;    
    do sprintf(tmpFile, "(%lld).tmp", I++);
    while((temporario = fopen(tmpFile, "r")));
    temporario = fopen(tmpFile, "w+");
    
    fseek(arq, 0, SEEK_SET);

    primeiraFase(arq, temporario, M, K);
    segundaFase(arquivo, temporario, M, K, N);

    fclose(temporario);
    fclose(arq);
    remove(tmpFile); //Remove o arquivo temporario

    return true;
}

//Interface argv[1] = MEMORIA EM BYTES
//argv[2] = NOME DO ARQUIVO DE ENTRADA
int main(int argc, char *argv[]) {

    if(argc != 3) printf("ERRO: ENTRADA INCORRETA\n");
    else {
        if(!ordenacaoExterna(argv[1], argv[2]))
            printf("ERRO: NAO FOI POSSIVEL ORDENAR O ARQUIVO\n");
    }
    return 0;
}
