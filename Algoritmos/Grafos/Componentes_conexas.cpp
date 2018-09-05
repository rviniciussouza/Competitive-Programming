#include <bits/stdc++.h>
using namespace std;


/*************************************
Implementacao do Kosaraju's algorithm
Componentes Conexas
**************************************/


//Classe para representar o grafo
class Graph
{
public:
    vector<vector<int> > adjList;
    vector<bool> discovered;
    int V, E;
    
    Graph(int vertex, int edge)
    {
        V = vertex; //Set V
        E = edge; //Set E
        adjList.resize(V);
        discovered.resize(V);
        readEdges();      
    }

    //Sobrecarga de Contrutor
    Graph(int vertex)
    {
        V = vertex;
        adjList.resize(V);
        discovered.resize(V);
    }

    //Funcao para ler arestas
    void readEdges()
    {
        int u, v; //from u to v
        for (int i = 0; i < E; ++i)
        {
            scanf("%d %d", &u, &v); u--; v--;
            adjList[u].push_back(v); //Inserindo aresta
            adjList[v].push_back(u); //Inserindo aresta
        }
    }
};

//Funcao recursiva DFS com tempo final do vertice
void DFSrStack(Graph &graph, stack<int> &timeEnd, unsigned int v)
{
    graph.discovered[v] = true;
    vector<int>::iterator i;
    for (i = graph.adjList[v].begin(); i != graph.adjList[v].end(); ++i)
    {
        if(!graph.discovered[*i])
            DFSrStack(graph, timeEnd, *i);
    }

    timeEnd.push(v); //Inserindo vetice na pilha
}

//DFS recursiva simples
void DFSr(Graph &graph, unsigned int v)
{
    graph.discovered[v] = true;
    vector<int>::iterator i;
    for (i = graph.adjList[v].begin(); i != graph.adjList[v].end(); ++i)
    {
        if(!graph.discovered[*i])
            DFSr(graph, *i);
    }
}

//Funcao para transpor Grafo
Graph TransposedGraph(Graph &graph)
{
    Graph graphRT(graph.V);

    for (int v = 0; v < graph.V; ++v)
    {
        vector<int>::iterator i;
        for (i = graph.adjList[v].begin(); i != graph.adjList[v].end(); ++i)
            graphRT.adjList[*i].push_back(v);
    }

    return graphRT;
}

//Funcao retorna numero de componentes fortemente conexas no grafo
int Kosaraju(Graph &graph)
{

    stack<int> timeEnd; //Tempo de termino do vertice na DFS

    //Setando vetor de visitados como nao visitado
    for (int i = 0; i < graph.V; ++i)
        graph.discovered[i] = false;

    //DFS
    for (int i = 0; i < graph.V; ++i)
        if(!graph.discovered[i])
            DFSrStack(graph, timeEnd, i);


    //FASE 2
    Graph graphRT = TransposedGraph(graph); //Obtendo grafo com arestas invertidas

    for (int i = 0; i < graph.V; ++i)
        graphRT.discovered[i] = false;

    int k = 0; //Conta componentes conexas
    while(!timeEnd.empty())
    {
        int v = timeEnd.top(); //Recupera elemento do topo
        timeEnd.pop(); //Desempilha

        if(graphRT.discovered[v] == false)
        { 
            k++;
            DFSr(graphRT, v);
        }
    }

    return k; // numero de componentes conexas
}