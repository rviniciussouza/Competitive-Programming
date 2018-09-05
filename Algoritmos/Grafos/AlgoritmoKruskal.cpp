/********************************************
Implementação do algoritmo de Kruskal para
encontrar uma arvore geradora mínima
Referência: Algoritmos/Thomas H. Cormem
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_E 1000001

int *boss; //Armazena o boss de cada componente
int *qtdF; //O numero de vertices dentro da componente

//Estrutura para representar uma aresta
typedef struct edge
{
	int v;
	int u;
	int custo;
}Edge;

//funcao compare do qsort
int compare(const void *a, const void *b)
{
	Edge aa = *((Edge*)a);
	Edge bb = *((Edge*)b);

	if(aa.custo < bb.custo)
		return -1;
	else if(aa.custo == bb.custo)
		return 0;
	return 1;
}

//Set todo vertice como seu proprio chefe
void setBoss(int V) 
{
	int i;
	for (i = 0; i < V; ++i)
	{
		boss[i] = i;
		qtdF[i] = 1; 
	}
}

//Funcao para procurar em qual componente um vertice pertence
int BossFind(int v)
{
	int aux = v;
	while(aux != boss[aux])
		aux = boss[aux];
	return aux;
}


void FUnion(int V, int W)
{
	if(qtdF[V] < qtdF[W]) {
		boss[V] = W;
		qtdF[W] += qtdF[V];
	}

	else {
		boss[W] = V;
		qtdF[V] += qtdF[W];
	}
}


void Free(Edge edges[])
{
	free(boss);
	free(qtdF);
	free(edges);
}

void Kruskal(Edge edges[], int V, int E)
{
	//Alocando memoria
	boss = (int*)malloc(sizeof(int) * V+10);
	qtdF = (int*)malloc(sizeof(int) * V+10);
	int k = 0;
	int custoT = 0;

	//Ordena o vetor de aresta em ordem crescente de peso
	qsort(edges, E, sizeof(Edge), compare);
	setBoss(V); 
	for (int i = 0; k < V - 1; ++i) //i para i::arestas, k::vertices
	{
		int V0, W0;
		V0 = BossFind(edges[i].v); //Encontra chefe de v
		W0 = BossFind(edges[i].u); //Encontra chefe de u
		if(V0 != W0) 	
		{
			FUnion(V0, W0);	 //Faz um dos chefes encontrados, ser o chefe de ambos os componentes
	 		custoT+=edges[i].custo; //Incremente o custo da aresta ao custo total da arvore geradora minima 
			k++; //+ um vertice incluido a arvore geradora minima
		}

		if(i > E + 2)
		{
			printf("Grafo Desconexo\n");
			Free(edges);
			return;
		}
	}

	printf("%d\n",custoT);
	Free(edges);
}

int main(void)
{
	Edge *edges; //Armazena todas as arestas
	int V, E; //Numero de vertices, e numero de arestas

	scanf("%d %d", &V, &E);
	
	edges = (Edge*)malloc(sizeof(Edge) * MAX_E);
	Edge read; //Aresta auxiliar
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &read.v, &read.u, &read.custo);
		edges[i] = read;
	}

	Kruskal(edges, V, E);
	return 0;
}
