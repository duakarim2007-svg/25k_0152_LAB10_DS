#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

class DijkstraGraph {
    int V;
    int adj[MAX][MAX];

public:
    DijkstraGraph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int cost) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = cost;
        }
    }

    void solve(int src) {
        int dist[MAX];
        bool visited[MAX];

        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int min = INF, u = -1;
            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (!visited[v] && adj[u][v] != 0 && dist[u] != INF && 
                    dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "Shortest Paths from Vertex " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To Vertex " << i << ": ";
            if (dist[i] == INF) {
                cout << "UNREACHABLE\n";
            } else {
                cout << "Cost = " << dist[i] << "\n";
            }
        }
    }
};

int main() {
    DijkstraGraph dg(6);
    dg.addEdge(0, 1, 4);
    dg.addEdge(0, 2, 2);
    dg.addEdge(1, 2, 5);
    dg.addEdge(1, 3, 10);
    dg.addEdge(2, 4, 3);
    dg.addEdge(4, 3, 4);
    dg.addEdge(3, 5, 11);

    cout << "=== Task 5: Dijkstra's Algorithm ===" << endl;
    dg.solve(0);

    return 0;
}

