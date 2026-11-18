#include <iostream>
using namespace std;

#define MAX 10

class TopologicalSort {
    int V;
    int adj[MAX][MAX];

public:
    TopologicalSort(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = 1;
        }
    }

    void kahn() {
        int indegree[MAX] = {0};
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] != 0) {
                    indegree[j]++;
                }
            }
        }

        int q[MAX];
        int front = 0, rear = 0;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q[rear++] = i;
            }
        }

        int topo[MAX];
        int idx = 0;
        while (front < rear) {
            int curr = q[front++];
            topo[idx++] = curr;

            for (int i = 0; i < V; i++) {
                if (adj[curr][i] != 0) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q[rear++] = i;
                    }
                }
            }
        }

        if (idx != V) {
            cout << "Cycle Detected! No valid course completion order exists.\n";
        } else {
            cout << "Valid Course Completion Order: ";
            for (int i = 0; i < idx; i++) {
                cout << topo[i] << (i + 1 < idx ? " -> " : "");
            }
            cout << "\n";
        }
    }
};

int main() {
    TopologicalSort ts(6);
    ts.addEdge(0, 1);
    ts.addEdge(0, 2);
    ts.addEdge(1, 3);
    ts.addEdge(2, 4);
    ts.addEdge(2, 5);
    ts.addEdge(3, 5);

    cout << "=== Task 6: Kahn's Topological Sort ===" << endl;
    ts.kahn();

    return 0;
}

