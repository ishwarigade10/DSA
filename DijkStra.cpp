#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int V;
int graph[MAX][MAX];

// Function to find vertex with minimum distance
int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}


void printSolution(int dist[], int source)
{
    cout << "\nLocation\tDistance from Source\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int source;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    int dist[MAX];
    bool visited[MAX];

    // Initialization
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Main loop
    for(int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 && !visited[v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, source);

    return 0;
}