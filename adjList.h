#ifndef _ADJLIST_H_
#define _ADJLIST_H_


#include<iostream>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;
#define MAX 100

struct node {
int dest;
int weight;
node* next;
node() : dest(0), weight(0), next(NULL) {}
node(int d, int w) : dest(d), weight(w), next(NULL) {}
};

class Graph
{

public :
int nvertex;
vector<node*> vertex;
std::vector<int> degree;

public :
Graph() : nvertex(0), vertex(MAX), degree(MAX,0) {}
void print();
void create(string filename);

};
#endif
