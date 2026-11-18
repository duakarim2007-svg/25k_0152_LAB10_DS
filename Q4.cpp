#include <iostream>
using namespace std;

#define MAX 10

class DeptGraph {
    int V;
    int adj[MAX][MAX];

public:
    DeptGraph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void insertEdge(int u, int v, int cost) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = cost;
            cout << "Inserted edge " << u << " -> " << v << " with cost " << cost << "\n";
        }
    }

    void deleteEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = 0;
            cout << "Deleted edge " << u << " -> " << v << "\n";
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void findEdges() {
        cout << "\nIncoming and Outgoing Edges:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> Outgoing: ";
            for (int j = 0; j < V; j++) {
                if (adj[i][j] != 0) {
                    cout << j << "(" << adj[i][j] << ") ";
                }
            }
            cout << "| Incoming: ";
            for (int j = 0; j < V; j++) {
                if (adj[j][i] != 0) {
                    cout << j << "(" << adj[j][i] << ") ";
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    DeptGraph dg(6);
    dg.insertEdge(0, 1, 4);
    dg.insertEdge(0, 2, 2);
    dg.insertEdge(1, 2, 5);
    dg.insertEdge(1, 3, 10);
    dg.insertEdge(2, 4, 3);
    dg.insertEdge(4, 3, 4);
    dg.insertEdge(3, 5, 11);

    cout << "=== Task 4: Adjacency Matrix & Edges ===" << endl;
    dg.displayMatrix();
    dg.findEdges();

    return 0;
}

