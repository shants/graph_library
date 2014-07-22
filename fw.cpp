#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

#define MAX 10
#define INF 9999
int _nvertex= 0;

void 
create(string filename, vector< vector<int> >& v) 
{
    int nvertex = 0;
    std::string line;
    std::ifstream infile(filename.c_str());

    // get no of vertex
    std::getline(infile, line);
    std::istringstream iss(line);
    iss >> _nvertex;

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
	    v[src][dest] = weight;
	    cout << "src" <<src << " " << dest << " " << v[src][dest] << "\n";
	    // process value
	}
    }
}


int 
print(const vector< vector<int> >& v)
{
    for(int i=1; i <= _nvertex; ++i)
    {
	for(int j=1; j <= _nvertex;++j) {
	    cout << " " <<v[i][j];
	}
	cout <<"\n";
    }

    return 0;
}

int 
fw(const vector< vector<int> >& v)
{
    vector< vector<int> > dist(MAX, vector<int>(MAX, INF));
    for(int i=1; i <= _nvertex; ++i)
    {
	for(int j=1; j <= _nvertex;++j) 
	{
	    if(i == j) 
	    {
		dist[i][j] = 0;
	    }
	    else
	    {
		dist[i][j] = v[i][j];
	    }
	}
    }
 
    for(int k=1; k<=_nvertex;++k)
    {
	for(int i=1; i <= _nvertex; ++i)
	{
	    for(int j=1; j <=_nvertex; ++j) 
	    {
		dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));	    
	    }
	}
    }

print(dist);
return 0;
}

int 
main()
{
    string fname;
    cout << "\n give the  name of the file\n ";
    cin>> fname;

    vector< vector<int> > adj(MAX, vector<int>(MAX, INF));
    create(fname, adj);
    //print(adj);
    fw(adj);
    return 0;
}
