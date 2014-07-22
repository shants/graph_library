#include "adjList.h"


void Graph::print() {
    for(int i=1; i <= nvertex; ++i) {
	if(vertex[i] == NULL)
	    continue;
	node* temp = vertex[i];
	while(temp != NULL) {
	    cout << "src " << i << "dest " <<temp->dest << " ( " << temp->weight << " ) " << endl;
	    temp = temp->next;
	}
	cout<<"------------------------\n";
    }
}

void Graph::create(string filename) {
    std::string line;
    std::ifstream infile(filename.c_str());

    // get no of vertex
    std::getline(infile, line);
    std::istringstream iss(line);
    iss >> nvertex;

    cout << "\n no of vertex is "<< nvertex <<endl;
    while (std::getline(infile, line))  // this does the checking!
    {
	std::istringstream iss(line);
	int src;
	int dest;
	int weight;    
	while (iss >> src >> dest >> weight)
	{
	    // construct graph
	    node* newNode = new node(dest, weight);
	    node* temp = vertex[src];
	    vertex[src] = newNode;
	    newNode->next = temp;
	    degree[src]++;
	    // process value
	}
    }
}


#if 0
int main()
{
struct Graph g;
g.create("input.txt");
g.print();

return 0;
}
#endif
