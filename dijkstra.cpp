// compile set LD_LIBRARY_PATH=/home/ss/graphs:$LD_LIBRARY_PATH
// g++ -L/home/ss/graphs -o test dijkstra.cpp -ladjList
#include "adjList.h"
#include <queue>

#define INF 9999
struct entry {
public:
int node;
int distance;
};

class cmp {
public:
bool operator()(entry& e1, entry& e2) {
    return e1.distance > e2.distance;
}
};

void dj_pq(Graph& g, int src) {
cout<< "\n In dj_pq";
vector<int> distance(g.nvertex+1, INF);
vector<int> prev(g.nvertex+1, -1);
vector<int> visited(g.nvertex+1, false);
priority_queue<entry, vector<entry>, cmp> pq;
distance[src] = 0;
entry s;s.node=src;s.distance = 0;
pq.push(s);
//visited[src] = true;

while(!pq.empty()) {

    entry u = pq.top();
    pq.pop();
    if(visited[u.node] == false) {
	visited[u.node] = true;
	node* p = g.vertex[u.node];
	while(p!=NULL) {
	    if(distance[u.node] + p->weight < distance[p->dest]){
		distance[p->dest] = distance[u.node]+p->weight;
		entry v;v.node=p->dest;v.distance = distance[p->dest];
		pq.push(v);
		prev[v.node] = u.node;	
	    }
	    p=p->next; 
	}    
    }
}
for(int i=1; i < g.nvertex+1;++i)
{
    cout << "\n dist["<<i<<"]"<< distance[i];
    cout << "\n prev["<<i<<"]"<< prev[i];
}

}

int main()
{

Graph g;
g.create("input.txt");
g.print();
cout<<"\n done with print\n";
dj_pq(g, 1);
return 0;
}
