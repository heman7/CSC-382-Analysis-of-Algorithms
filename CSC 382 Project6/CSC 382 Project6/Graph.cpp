//Heman Zhang
//CSC 382
//5/10/2018
//Project 6 Graph

#include<iostream>

using namespace std;



struct node {
	int vertex;
	node * next;
};


bool cycles = false;// determine if a graph has cycles.
bool * Visited;

class Graph{
private:
	node * headnodes;
	int n;
	int e;

public: 
	
	Graph(int nodes) // construtor
{
	n = nodes;
	headnodes = new node[n]; // headnodes is an array of nodes.
	for (int i = 0; i < n; i++)
	{
		headnodes[i].vertex = i;
		headnodes[i].next = 0;
	}
}

	void create()
		{
			int vertex1, vertex2;
			cout << "please enter the number of edge: ";
			cin >> e;
			for (int j = 0; j < e;j++)
			{
				cout << "Please enter 2 number of vertices (0-" << n - 1 << ") you want to connect: ";
				cin >> vertex1 >> vertex2;
				createEdge(vertex1, vertex2);
				createEdge(vertex2, vertex1);
			}

		}

	void createEdge(int vertex1, int vertex2){

			node *newNode = new node;
			newNode->vertex = vertex2;
			newNode->next = headnodes[vertex1].next;
			headnodes[vertex1].next = newNode;
	

		}
	void DFS(int father, int v)
		{
			Visited[v] = true;
			node* adjnode = headnodes[v].next;
			while (adjnode) // visit all vertices adjacent to v
			{
				if (!Visited[adjnode->vertex]) //if adjacent vertex to v was not visited previously
					DFS(v, adjnode->vertex); // when we call DFS, we pass the father vertex of the call
				else if (father != adjnode->vertex) // if the vertex adjacent to v is not the father, we have a 
					//cycle
				{
					cycles = true;
				}
				adjnode = adjnode->next;
			}
		}
	
		void displayGraph(){

			node *showConnectedNode=new node;
		
			for (int i = 0; i < n; i++)
				{
					showConnectedNode = &headnodes[i];
					
					cout << "Connected vertice V" << i << ": { ";
					while (showConnectedNode != NULL)
					{
						cout << showConnectedNode->vertex<<" " ;
						showConnectedNode = showConnectedNode->next;

					}
					cout << " }";
					cout << endl;
				}
			
		}
}; // end class


int main()
{
	
	int n;
	cout << "Please enter the number of vertice you want to creat: ";
	cin >> n;
	int Nmbrcmpnts = 0; //we initialize the counter for the number of components
	
	
	Graph G(n); // constructor
	Visited = new bool[n];
	G.create(); // to create graph, that is the linked-list
	G.displayGraph();

	for (int i = 0; i < n; i++)
	{

		Visited[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!Visited[j]) {
				G.DFS(0, j);
				Nmbrcmpnts++;
			}
		}
	}
	
	
	cout << "This graph has " << Nmbrcmpnts << " components."<<endl;
	if (cycles)
		cout << "This graph has cycles."<<endl;
	else
		cout << "This graph has no cycles." << endl;



	return 0;
}


/*OUTPUT
Please enter the number of vertice you want to creat: 4
please enter the number of edge: 2
Please enter 2 number of vertices (0-3) you want to connect: 0 1
Please enter 2 number of vertices (0-3) you want to connect: 2 3
Connected vertice V0: { 0 1  }
Connected vertice V1: { 1 0  }
Connected vertice V2: { 2 3  }
Connected vertice V3: { 3 2  }
This graph has 2 components.
This graph has no cycles.
Press any key to continue . . .
*/

/*OUTPUT
Please enter the number of vertice you want to creat: 5
please enter the number of edge: 5
Please enter 2 number of vertices (0-4) you want to connect: 0 1
Please enter 2 number of vertices (0-4) you want to connect: 1 2
Please enter 2 number of vertices (0-4) you want to connect: 2 3
Please enter 2 number of vertices (0-4) you want to connect: 3 4
Please enter 2 number of vertices (0-4) you want to connect: 4 0
Connected vertice V0: { 0 1 4  }
Connected vertice V1: { 1 0 2  }
Connected vertice V2: { 2 1 3  }
Connected vertice V3: { 3 2 4  }
Connected vertice V4: { 4 3 0  }
This graph has 1 components.
This graph has cycles.
Press any key to continue . . .
*/

/*OUTPUT 3
Please enter the number of vertice you want to creat: 8
please enter the number of edge: 12
Please enter 2 number of vertices (0-7) you want to connect: 0 1
Please enter 2 number of vertices (0-7) you want to connect: 0 2
Please enter 2 number of vertices (0-7) you want to connect: 0 4
Please enter 2 number of vertices (0-7) you want to connect: 1 2
Please enter 2 number of vertices (0-7) you want to connect: 1 7
Please enter 2 number of vertices (0-7) you want to connect: 2 3
Please enter 2 number of vertices (0-7) you want to connect: 3 7
Please enter 2 number of vertices (0-7) you want to connect: 4 5
Please enter 2 number of vertices (0-7) you want to connect: 5 6
Please enter 2 number of vertices (0-7) you want to connect: 3 4
Please enter 2 number of vertices (0-7) you want to connect: 3 6
Please enter 2 number of vertices (0-7) you want to connect: 6 7
Connected vertice V0: { 0 4 2 1  }
Connected vertice V1: { 1 7 2 0  }
Connected vertice V2: { 2 3 1 0  }
Connected vertice V3: { 3 6 4 7 2  }
Connected vertice V4: { 4 3 5 0  }
Connected vertice V5: { 5 6 4  }
Connected vertice V6: { 6 7 3 5  }
Connected vertice V7: { 7 6 3 1  }
This graph has 1 components.
This graph has cycles.
Press any key to continue . . .
*/