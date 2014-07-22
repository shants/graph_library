#include "adjList.h"
#include <queue>

#define INF 9999
void dj(Graph g, int src)
{
vector<int> distance(g.nvertex+1, INF);
vector<int> prev(g.nvertex+1, -1);
vector<int> visited(g.nvertex+1, false);
queue<int> q;
distance[src] = 0;
//visited[src] = true;
q.push(src);
while(!q.empty()) 
{
    int e = q.front();
    q.pop();
    if(visited[e] == false)
    {
	visited[e] = true;
	node* p = g.vertex[e];
	while(p!=NULL) {
	    //q.push(p->dest);
	    if(distance[e] + p->weight < distance[p->dest]) {
		distance[p->dest] = distance[e] + p->weight;
		prev[p->dest] = e;
	    }
	    p=p->next;
	}
    } 
    // find node with min distance and then push in queue
          
}

for(int i=1; i <= g.nvertex+1;++i)
{
    cout << "\n dist["<<i<<"]"<< distance[i];
}
return ;
}

int main()
{

Graph g;
g.create("input.txt");
g.print();

dj(g, 1);
return 0;
}
