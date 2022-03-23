/*
 * GraphElementsMaps.h
 *
 *  Created on: Dec 28, 2017
 *      Author: kg
 */

#ifndef AIRPORT_GRAPHELEMENTSMAPS_H_
#define AIRPORT_GRAPHELEMENTSMAPS_H_

#include <vector>
#include <map>
#include <set>
#include <string>

#include <boost/lexical_cast.hpp>

class GraphElementsMaps {
public:
  GraphElementsMaps();
  virtual ~GraphElementsMaps();

  void addVertexAngle(int idx, int angle) { vertexAngleMap[idx] = angle; }
  int getVertexAngle(int idx) { return vertexAngleMap[idx]; }

  void addVertexRoadName(int idx, std::string name) { vertexRoadNameMap[idx] = name; }
  std::string getVertexRoadName(int idx) { return vertexRoadNameMap[idx]; }

  void addNameVertex(std::string name, int idx) { vertexNameMap[name] = idx; }
  int getNameVertex(std::string name) { return vertexNameMap[name]; }

  void addIntersection(std::string name) { intersections.insert(name); }
  bool hasIntersection(std::string e) {
    const bool found = intersections.find(e) != intersections.end();
    return found;
  }

  std::string getVertexName(int v) {
    return getVertexRoadName(v) + boost::lexical_cast<std::string>(getVertexAngle(v));
  }

  void addItem(std::string circle, std::string name, int vertex, int angle) {
    addNameVertex(name, vertex);
    addVertexAngle(vertex, angle);
    addVertexRoadName(vertex, circle);
  }

private:
  std::map<int, int> vertexAngleMap;
  std::map<int, std::string> vertexRoadNameMap;
  std::map<std::string, int> vertexNameMap;
  std::set<std::string> intersections;
};

#endif /* AIRPORT_GRAPHELEMENTSMAPS_H_ */
