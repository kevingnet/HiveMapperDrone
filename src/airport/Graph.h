/*
 * Graph.h
 *
 *  Created on: Jan 4, 2018
 *      Author: kg
 */

#ifndef AIRPORT_GRAPH_H_
#define AIRPORT_GRAPH_H_

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <list>

class Graph
{
public:
  Graph(int verticesCount) {
    this->verticesCount = verticesCount;
    vertices = new std::list<int>[verticesCount];
    index = 0;
  }
  ~Graph() { delete [] vertices; }

  int addVertex(std::string v) {
    vertexNames[v] = index;
    vertexIndexes[index] = v;
    index++;
    return index - 1;
  }

  void addEdge(int v, int w, double weight) {
    //check if they exist
    vertices[v].push_back(w);
    weights[std::make_pair(v, w)] = weight;
  }

  double getWeight(int v, int w) {
    return weights[std::make_pair(v, w)];
  }

  std::string getName(int v) {
    return vertexIndexes[v];
  }

  void addEdge(std::string v, std::string w, double weight) {
    int v1 = vertexNames[v];
    int w1 = vertexNames[w];
    addEdge(v1, w1, weight);
  }

  void DFS(int s, int d);
  void DFS(std::string s, std::string d) {
    int vs = vertexNames[s];
    int vd = vertexNames[d];
    DFS(vs, vd);
  }

  void BFS(int s, int d);
  void BFS(std::string s, std::string d) {
    int vs = vertexNames[s];
    int vd = vertexNames[d];
    BFS(vs, vd);
  }

  const std::vector<std::pair<int, int> >& getResult() { return result; }
  void allPaths(int s, int d);

  std::vector<std::vector<std::pair<int, int> > >& getAllPaths() {
    return allPathsResult;
  }

private:
  void DFSUtil(int v, int p, bool visited[]);
  void allPathsUtil(int , int , bool [], int [], int &);

  int verticesCount;
  std::list<int>* vertices;
  int index;
  std::map<std::string, int> vertexNames;
  std::map<int, std::string> vertexIndexes;
  std::vector<std::pair<int, int> > result;
  std::map<std::pair<int, int>, double> weights;
  std::vector<std::vector<std::pair<int, int> > > allPathsResult;
  std::vector<std::pair<int, int> > allPathsCurrent;
};

#endif /* AIRPORT_GRAPH_H_ */
