#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph {
    int V;

    list<int>* adj;

    void topologicalSortingUtil(int v, bool visited[],stack<int>& myStack);
    
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V); // constructor

    void addEdge(int v, int w);

    void topologicalSorting();
    
    bool isCyclic(); 
};

Graph::Graph(int V){
	
    this->V = V;
    adj = new list<int>[V];
    
}

void Graph::addEdge(int v, int w){ //directed graph

   adj[v].push_back(w);

}

void Graph::topologicalSortingUtil(int v, bool visited[],
                                stack<int>& myStack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortingUtil(*i, visited, myStack);

    myStack.push(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false; 
    return false;
}


bool Graph::isCyclic()
{

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

void Graph::topologicalSorting()
{
    stack<int> myStack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortingUtil(i, visited, myStack);

    // Print contents of stack
    while (myStack.empty() == false) 
    {
        if (myStack.size() == 1)
            break;
        cout << myStack.top() << " ";
        myStack.pop();
    }
}

int main(){
	
    int n, m;
    
    cin >> n >> m;
    Graph topo(n + 1);
    
    for(int i = 0; i < n; i++){
    	
        int x, y;
        cin >> x >> y;
        topo.addEdge(x, y);
        
    }
    
    if(topo.isCyclic()){
        cout << "-1" << endl;
    }// if the graph is cylic then its not a DAG
    
    else{
        topo.topologicalSorting();
    }
    return 0;
}

