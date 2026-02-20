#include<iostream>
using namespace std;

class Graph
{
    string city;
    int fuel;
    Graph *next;

public:
    int v, e;
    Graph *Head[100];
    int adj[100][100];

    void createVertices();
    void createEdges();
    void displayList();
    void displayMatrix();
};

//  CREATE VERTICES 
void Graph::createVertices()
{
    cout<<"Enter number of cities: ";
    cin>>v;

    for(int i=0;i<v;i++)
    {
        Head[i] = new Graph;
        cout<<"Enter city name: ";
        cin>>Head[i]->city;
        Head[i]->next = NULL;
    }

    // Initialize matrix
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            adj[i][j] = 0;
}

// CREATE EDGES 
void Graph::createEdges()
{
    string src, dest;
    int f;

    cout<<"Enter number of edges: ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter source city: ";
        cin>>src;
        cout<<"Enter destination city: ";
        cin>>dest;
        cout<<"Enter fuel required: ";
        cin>>f;

        int sIndex = -1, dIndex = -1;

        // Find index of source & destination
        for(int j=0;j<v;j++)
        {
            if(Head[j]->city == src)
                sIndex = j;
            if(Head[j]->city == dest)
                dIndex = j;
        }

        if(sIndex == -1 || dIndex == -1)
        {
            cout<<"Invalid city name!\n";
            continue;
        }

        // Update Matrix 
        adj[sIndex][dIndex] = f;

        // Update List 
        Graph *temp = Head[sIndex];

        Graph *newNode = new Graph;
        newNode->city = dest;
        newNode->fuel = f;
        newNode->next = NULL;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

//  DISPLAY LIST 
void Graph::displayList()
{
    Graph *temp;

    cout<<"\n\nAdjacency List:\n";

    for(int i=0;i<v;i++)
    {
        cout<<"\n"<<Head[i]->city;

        temp = Head[i]->next;
        while(temp != NULL)
        {
            cout<<" -> "<<temp->city<<"("<<temp->fuel<<")";
            temp = temp->next;
        }
    }
}

//  MATRIX 
void Graph::displayMatrix()
{
    cout<<"\n\nAdjacency Matrix:\n";

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    Graph g;

    g.createVertices();
    g.createEdges();

    g.displayList();
    g.displayMatrix();

    return 0;
}
