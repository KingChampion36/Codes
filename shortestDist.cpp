#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Graph{
    private:
        int V;
        list<pair<int, int> > *adj;

    public:
        Graph(int v);
        void addEdge(int u, int v, int w);
        void shortestPath(int src);
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<pair<int, int> > [V];
}

void Graph:: addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph:: shortestPath(int src)
{
    vector<int> dist(V, INF);
    set<pair<int, int> > s;
    s.insert(make_pair(0, src));
    dist[src] = 0;

    while(!s.empty()){
        pair<int, int> temp = *(s.begin());
        s.erase(s.begin());
        int u = temp.second;

        list<pair<int, int> > :: iterator it = adj[u].begin();
        while(it != adj[u].end()){
            int v = (*it).first;
            int weight = (*it).second;
            if(dist[v] > dist[u] + weight){
                if(dist[v] != INF)
                    s.erase(s.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                s.insert(make_pair(dist[v], v));
            }
            it++;
        }
    }
    cout<<"Vertex distance from Source\n";
    for(int i=0;i<V;i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
