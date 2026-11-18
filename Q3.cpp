#include <iostream>
using namespace std;

#define MAX 10

class KruskalMST {
    int V, E;
    int edges[MAX * MAX][3];
    int parent[MAX];

public:
    KruskalMST(int vertices) {
        V = vertices;
        E = 0;
    }

    void addEdge(int u, int v, int w) {
        edges[E][0] = u;
        edges[E][1] = v;
        edges[E][2] = w;
        E++;
    }

    int find(int i) {
        while (parent[i])
            i = parent[i];
        return i;
    }

    void union1(int i, int j) {
        parent[j] = i;
    }

    void solve() {
        for(int i = 0; i < E; i++) {
            for(int j = 0; j < E - 1; j++) {
                if(edges[j][2] > edges[j+1][2]) {
                    int tempU = edges[j][0], tempV = edges[j][1], tempW = edges[j][2];
                    edges[j][0] = edges[j+1][0];
                    edges[j][1] = edges[j+1][1];
                    edges[j][2] = edges[j+1][2];
                    edges[j+1][0] = tempU;
                    edges[j+1][1] = tempV;
                    edges[j+1][2] = tempW;
                }
            }
        }

        for(int i = 0; i < V; i++) parent[i] = 0;

        int count = 0, totalCost = 0;
        cout << "Edge \tWeight\n";
        for(int i = 0; i < E && count < V - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int rootU = find(u);
            int rootV = find(v);

            if(rootU != rootV) {
                cout << u << " - " << v << " \t" << w << "\n";
                totalCost += w;
                union1(rootU, rootV);
                count++;
            }
        }
        cout << "Total Cost: " << totalCost << "\n";
    }
};

int main() {
    KruskalMST k1(5);
    k1.addEdge(0, 2, 10);
    k1.addEdge(0, 2, 21);
    k1.addEdge(0, 3, 22);
    k1.addEdge(1, 2, 53);
    k1.addEdge(1, 4, 45);
    k1.addEdge(2, 4, 33);
    k1.addEdge(4, 3, 19);

    cout << "=== Task 3: Kruskal's Algorithm ===" << endl;
    k1.solve();

    return 0;
}

