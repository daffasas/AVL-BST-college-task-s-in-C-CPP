#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
  int V; // No. of vertices

  // In a weighted graph, we need to store vertex
  // and weight pair for every edge
  list<pair<int, int>> *adj;

public:
  Graph(int V); // Constructor

  // function to add an edge to graph
  void addEdge(int u, int v, int w);

  // prints shortest path from s
  void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
  // Create a priority queue to store vertices that
  // are being preprocessed. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

  // Create a vector for distances and initialize all
  // distances as infinite (INF)
  vector<int> dist(V, INF);

  // Insert source itself in priority queue and initialize
  // its distance as 0.
  pq.push(make_pair(0, src));
  dist[src] = 0;

  /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
  while (!pq.empty())
  {
    // The first vertex in pair is the minimum distance
    // vertex, extract it from priority queue.
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted distance (distance must be first item
    // in pair)
    int u = pq.top().second;
    pq.pop();

    // 'i' is used to get all adjacent vertices of a vertex
    list<pair<int, int>>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
      // Get vertex label and weight of current adjacent
      // of u.
      int v = (*i).first;
      int weight = (*i).second;

      //  If there is shorted path to v through u.
      if (dist[v] > dist[u] + weight)
      {
        // Updating distance of v
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  // Print shortest distances stored in dist[]
  for (int i = 1; i < V; i++){
    cout << i;
    cout << " " << dist[i];
    cout << "\n";
  }
}

// Driver program to test methods of graph class
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int edge, vertex, weight;
    int vertex1;
    int vertex2;
    cin >> vertex;
    cin >> edge;
    Graph cabang(vertex);
    
    for (int i = 0; i < edge; ++i){
        cin >> vertex1;
        cin >> vertex2;
        cin >> weight;
        cabang.addEdge(vertex1, vertex2, weight);
    }
    cabang.shortestPath(0);  
    
    return 0;
}
