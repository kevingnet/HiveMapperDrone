/*
 * Road.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kg
 */

#ifndef AIRPORT_ROAD_H_
#define AIRPORT_ROAD_H_

#include <string>
#include <vector>
#include <math.h>

#include "Section.h"

class Roads;
class Intersections;

class Road {
public:
  Road(const std::string n, int r) : name(n), radius(r), segmentSize(0) {
    circumference = 2 * M_PI * radius;
    segmentSize = circumference / 360;
  }
  //TODO: we're not doing deep copy for now...
  virtual ~Road();

  friend std::ostream& operator<<(std::ostream&, const Road&);

  bool operator==(const Road&) const;

  void SetIntersection();

  void BuildEdges(Roads& roads, Intersections& intersections);

  std::vector<Section>& getSections() { return sections; }
  inline const std::string getName() { return name; }
  inline const int getIndex() { return index; }
  inline const int getRadius() { return radius; }
  inline const double getSegmentSize() { return segmentSize; }


private:
  Road() : name(""), radius(0) {}

  void AddSectionsForIntersections(Roads& roads, Intersections& intersections);

  std::string name;
  int index;
  int radius;
  double circumference;
  double segmentSize;
  std::vector<Section> sections;
  bool debug;
};

#endif /* AIRPORT_ROAD_H_ */
