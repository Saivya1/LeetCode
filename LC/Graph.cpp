#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int num_vertices;
    vector<vector<int>> adj_matrix;

    void DFSUtil(int v, vector<bool> &visited)
    {

        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < num_vertices; i++)
        {
            if (adj_matrix[v][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

public:
    Graph(int num_vertices)
    {
        this->num_vertices = num_vertices;
        adj_matrix.resize(num_vertices, vector<int>(num_vertices, 0));
    }

    void addEdge(int start, int end, int weight = 1)
    {
        adj_matrix[start][end] = weight;
        // adj_matrix[end][start] = weight;   for undirected
    }
    void printGraph()
    {
        for (int i = 0; i < num_vertices; i++)
        {
            for (int j = 0; j < num_vertices; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int src)
    {
        vector<bool> visited(adj_matrix.size(), false);
        DFSUtil(src, visited);
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 2);

    g.printGraph();
    cout << endl;
    cout << endl;

    g.dfs(0);
}