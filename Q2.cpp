#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

class PrimMST {
    int V;
    int adj[MAX][MAX];
public:
    PrimMST(int vertices) {
        V = vertices;
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void solve() {
        int parent[MAX];
        int key[MAX];
        bool mstSet[MAX];

        for (int i = 0; i < V; i++) {
            key[i] = INF;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int min = INF, u = -1;
            for (int v = 0; v < V; v++)
                if (!mstSet[v] && key[v] < min)
                    min = key[v], u = v;

            mstSet[u] = true;

            for (int v = 0; v < V; v++)
                if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v])
                    parent[v] = u, key[v] = adj[u][v];
        }

        int totalCost = 0;
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << adj[i][parent[i]] << "\n";
            totalCost += adj[i][parent[i]];
        }
        cout << "Total Cost: " << totalCost << "\n";
    }
};

int main() {
    PrimMST p1(5);
    p1.addEdge(0, 1, 3);
    p1.addEdge(0, 3, 7);
    p1.addEdge(0, 4, 8);
    p1.addEdge(1, 2, 1);
    p1.addEdge(1, 3, 4);
    p1.addEdge(2, 3, 2);
    p1.addEdge(3, 4, 3);
    
    cout << "=== Task 2: Prim's Algorithm ===" << endl;
    p1.solve();

    return 0;
}

