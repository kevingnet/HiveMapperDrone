/*
 * Planner.h
 *
 *  Created on: Dec 23, 2017
 *      Author: kg
 */

#ifndef AIRPORT_PLANNER_H_
#define AIRPORT_PLANNER_H_

#include "GraphElementsMaps.h"
#include "../parsed/Route.h"
#include "Roads.h"
#include "Path.h"
#include "Vertex.h"
#include "Edge.h"

#include "boost/date_time/posix_time/posix_time_types.hpp"

class Planner {
public:
  Planner() {}
  Planner(Roads* roads, bool d) : debug(d), roads(roads) {
    totalTime = 0.0;
  }
  virtual ~Planner();

  enum algorithm { EXHAUSTIVE, BFS, DIJKSTRA };

  void Solve(Route& route, int algo);

private:
  void SolveExhaustive(Route& route);
  void SolveBFS(Route& route);
  void SolveDijkstra(Route& route);

  void FillVertices();
  void FillEdges();
  void OutputGraph(std::string fileName);

  void AddStepSourceIsDestination(Route& route, std::vector<Step>& steps, int& solutionIndex);
  void AddStep(std::vector<Step>& steps, int v1, int v2, std::string n1, std::string n2,
      double weight, int& solutionIndex, bool supressOutput);

  void ComputeSolution(Route& route, std::vector<Step>& steps);
  void ComputeSolutionFast(Route& route, std::vector<Step>& steps);
  void OutputSolution(Route& route);
  void OutputTimeElapsed();

  void ProfileAllPaths(Route& route);

  bool debug;
  Roads* roads;
  Path path;
  GraphElementsMaps map;
  std::map<std::string, int> solutionNodeToStepMap;
  std::set<std::string> solutionNodes;
  std::set<std::string> cset;
  std::multimap<std::string, std::string> circleToNodeMap;

  Vertex vertexDeptarture;
  Vertex vertexArrival;
  std::map<std::string, Vertex> vertices;
  std::map<std::string, Edge> edges;

  float totalTime;
  std::string commands;
  boost::posix_time::ptime start;
  boost::posix_time::ptime stop;
};

#endif /* AIRPORT_PLANNER_H_ */
