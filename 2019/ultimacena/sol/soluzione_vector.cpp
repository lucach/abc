#include<bits/stdc++.h>
using namespace std;
int const MAXN=50100;
bool vis[MAXN];         //Indica se un nodo è presente nella copertura 
vector<vector<int>> graph;      
vector<pair<int,int>> edges;
vector<int> res;        //Indica quali nodi sono presenti nella copertura attuale
void add(int i){        //Aggiunge alla copertura i nodi che ne faranno parte al 100%
	vis[i]=true;
	res.push_back(i);
	for(auto x:graph[i])        //Rimuove gli archi che non servono
		graph[x].erase(find(graph[x].begin(), graph[x].end(), i));
	graph[i].clear();
}
bool ans(int i){        //Iesimo arco
	if(i==edges.size()) 
		return true;        //Ho analizzato ogni arco usando meno di 11 nodi
	pair<int,int> edge=edges[i];
	if(vis[edge.first] || vis[edge.second]) 
		return ans(i+1);    //Se ho incluso uno dei suoi 2 nodi allora passo all'arco successivo
	if(res.size()==10) 
		return false;        //Se devo includere uno dei suoi nodi ma non ho più spazio allora non posso completare la copretura 
	vis[edge.first]=true;                   //Provo inserendo nella copertura il primo nodo
	res.push_back(edge.first);
	if(ans(i+1)) 
		return true;               //Risulta corretto
	vis[edge.first]=false;                  
	res.pop_back();
	vis[edge.second]=true;                  //Provo inserendo il secondo nodo(dopo avere rimosso il primo)
	res.push_back(edge.second);
	if(ans(i+1)) 
		return true;               //Risulta corretto
	vis[edge.second]=false;
	res.pop_back();
	return false;                           //Non posso completare la copertura da questa situazione
}
int riassumi(int N, int M, int* A, int* B, int* S){                           //Numero di archi
	graph.resize(N+1);
	for(int i=0;i<M;i++){                   //Creo il grafo
		graph[A[i]].push_back(B[i]);
		graph[B[i]].push_back(A[i]);
	}
	for(int i=1;i<=N;i++)                   //Aggiungo alla copertura i nodi che hanno un grado>10 (non includendoli dovrei includere sicuramente più di 10 nodi)
		if(graph[i].size()>10)
			add(i);
	for(int i=1;i<=N;i++)                   //Aggiungo alla copertuta i vicini dei nodi che hanno grado 1
		if(graph[i].size()==1)
			add(graph[i][0]);
	for(int i=1;i<=N;i++)                   //Creo una lista degli archi
		for(auto x:graph[i])
			if(i<x)
				edges.push_back({i,x});
	ans(0);
	for(int i=0;i<res.size();i++)           //Salvo la copertuta trovata
		S[i]=res[i];
	return res.size();
}
