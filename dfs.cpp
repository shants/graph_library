#include "adjList.h"
#include<iostream>
#include<vector>

using namespace std;
// node numbering starts with 1
// start time denote when we start processing a node
// end denotes when we mark it as complete for processing

vector<int> visited(MAX, 0);
vector<int> start(MAX, 0);
vector<int> end(MAX, 0);
int tm = 0;

void dfs(Graph g, int s)
{
tm++;
start[s] = tm;
visited[s] = 1;
cout << "\n " << s;
node* temp = g.vertex[s];
 
while(temp != NULL) {
    if(visited[temp->dest] == 0) {
	dfs(g, temp->dest);
    } 
    temp=temp->next;
}
tm++;
end[s] = tm;
}

int main()
{

Graph g;
g.create("input.txt");
g.print();
dfs(g,1);

for(int i=1; i <= g.nvertex; ++i)
    cout << "\n vertex " << i << " Start " << start[i] << " End " << end[i];

cout << endl;
return 0;
}
