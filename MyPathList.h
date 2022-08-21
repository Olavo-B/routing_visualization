#ifndef MYPATHLIST_H__
#define MYPATHLIST_H__

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<pair<int,int>> moves;
typedef vector<moves> path;
typedef vector<path> pathlist;

const int dir[4][2]={
    {-1,0},     // LEFT
    {1,0},      // RIGHT
    {0,-1},     // UP
    {0,1}       // DOWN
};

class MyPathList{

private:
pathlist *data;     // pathlist vector
vector<int> *adj;   // graph representation
int listsize;       // num nodes V
int _n,_m,_k;

vector<int> connections(int x, int y, int n, int m); // get adjacency nodes given a position x,y in matrix(MESH ONLY)
pair<int,int> movement(int beg, int end);            // return the movement that was maded(right,left,up,down)

// Methods to find paths node src to node target
void path_finding(vector<vector<int>>&paths, vector<int>&path, vector<int> parent[], int n, int v);
path all_pair_shortest_path(int n, int src, int dest);
void mybfs(vector<int> parent[], int n, int src);

public:
// Constructor
MyPathList(int nv, int ne, int k); // Build graph

// // Destructor
~MyPathList();

// Methods
void build();               // Build list of paths
void print_graph();         // Print adj list
void print_all_paths();     // Print all paths

// operators -> vec[src][dest] return all shortest paths src/dest
pathlist &operator[](int pos);              
const pathlist &operator[](int pos) const;
};

#endif