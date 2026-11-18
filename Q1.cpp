#include <iostream>
using namespace std;

#define MAX 10

class Graph {
    int V;
    int adj[MAX][MAX];
    char labels[MAX];
    bool isDirected;

public:
    Graph(int vertices, char nodeLabels[], bool directed = true) {
        V = vertices;
        isDirected = directed;
        for (int i = 0; i < V; i++) {
            labels[i] = nodeLabels[i];
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    int getIndex(char label) {
        for (int i = 0; i < V; i++) {
            if (labels[i] == label) return i;
        }
        return -1;
    }

    void addEdge(char uLabel, char vLabel) {
        int u = getIndex(uLabel);
        int v = getIndex(vLabel);
        if (u != -1 && v != -1) {
            adj[u][v] = 1;
            if (!isDirected) {
                adj[v][u] = 1;
            }
        }
    }

    void BFS(char startLabel) {
        int start = getIndex(startLabel);
        bool visited[MAX] = {false};
        int queue[MAX];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS from " << startLabel << ": ";
        while (front < rear) {
            int curr = queue[front++];
            cout << labels[curr] << " ";

            for (int i = 0; i < V; i++) {
                if (adj[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int u, bool visited[]) {
        visited[u] = true;
        cout << labels[u] << " ";

        for (int i = 0; i < V; i++) {
            if (adj[u][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(char startLabel) {
        int start = getIndex(startLabel);
        bool visited[MAX] = {false};
        cout << "DFS from " << startLabel << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    char nodesA[] = {'a', 'b', 'c', 'd', 'e'};
    Graph ga(5, nodesA, true);
    ga.addEdge('a', 'b'); 
    ga.addEdge('a', 'c'); 
    ga.addEdge('a', 'd'); 
    ga.addEdge('a', 'e'); 
    ga.addEdge('b', 'd'); 
    ga.addEdge('c', 'd'); 
    ga.addEdge('c', 'e'); 
    ga.addEdge('d', 'e'); 
    cout << "=== Graph a ===" << endl;
    ga.BFS('a'); 
    ga.DFS('a'); 

    char nodesC[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Graph gc(6, nodesC, true);
    gc.addEdge('A', 'B'); 
    gc.addEdge('A', 'C'); 
    gc.addEdge('B', 'F'); 
    gc.addEdge('C', 'B'); 
    gc.addEdge('C', 'D'); 
    gc.addEdge('C', 'E'); 
    gc.addEdge('D', 'E'); 
    gc.addEdge('E', 'F'); 
    cout << "\n=== Graph c ===" << endl;
    gc.BFS('A'); 
    gc.DFS('A'); 

    char nodesE[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    Graph ge(8, nodesE, true);
    ge.addEdge('A', 'B'); 
    ge.addEdge('B', 'C'); 
    ge.addEdge('B', 'F'); 
    ge.addEdge('C', 'G'); 
    ge.addEdge('C', 'H'); 
    ge.addEdge('D', 'A'); 
    ge.addEdge('D', 'F'); 
    ge.addEdge('E', 'C'); 
    ge.addEdge('F', 'A'); 
    ge.addEdge('F', 'E'); 
    ge.addEdge('G', 'E'); 
    ge.addEdge('H', 'A'); 
    ge.addEdge('H', 'G'); 
    cout << "\n=== Graph e ===" << endl;
    ge.BFS('A'); 
    ge.DFS('A'); 

    char nodesF[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    Graph gf(8, nodesF, true);
    gf.addEdge('0', '1'); 
    gf.addEdge('0', '3'); 
    gf.addEdge('1', '3'); 
    gf.addEdge('2', '4'); 
    gf.addEdge('3', '5'); 
    gf.addEdge('3', '6'); 
    gf.addEdge('4', '5'); 
    gf.addEdge('4', '7'); 
    gf.addEdge('5', '2'); 
    cout << "\n=== Graph f ===" << endl;
    gf.BFS('0'); 
    gf.DFS('0'); 

    char nodesG[] = {'0', '1', '3', '4', '5', '6', '7'};
    Graph gg(7, nodesG, true);
    gg.addEdge('0', '1'); 
    gg.addEdge('0', '3'); 
    gg.addEdge('0', '7'); 
    gg.addEdge('1', '4'); 
    gg.addEdge('3', '5'); 
    gg.addEdge('4', '6'); 
    gg.addEdge('5', '6'); 
    gg.addEdge('7', '4'); 
    gg.addEdge('7', '5'); 
    cout << "\n=== Graph g ===" << endl;
    gg.BFS('0'); 
    gg.DFS('0'); 

    char nodesH[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    Graph gh(8, nodesH, false);
    gh.addEdge('A', 'B'); 
    gh.addEdge('A', 'D'); 
    gh.addEdge('A', 'F'); 
    gh.addEdge('A', 'H'); 
    gh.addEdge('B', 'C'); 
    gh.addEdge('B', 'F'); 
    gh.addEdge('C', 'E'); 
    gh.addEdge('C', 'G'); 
    gh.addEdge('C', 'H'); 
    gh.addEdge('D', 'F'); 
    gh.addEdge('E', 'F'); 
    gh.addEdge('E', 'G'); 
    gh.addEdge('G', 'H'); 
    cout << "\n=== Graph h ===" << endl;
    gh.BFS('A'); 
    gh.DFS('A'); 

    return 0;
}
