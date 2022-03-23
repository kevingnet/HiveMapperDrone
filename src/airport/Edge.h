/*
 * Edge.h
 *
 *  Created on: Jan 4, 2018
 *      Author: kg
 */

#ifndef AIRPORT_EDGE_H_
#define AIRPORT_EDGE_H_

#include <string>

class Edge {
public:
  Edge();
  Edge(std::string n1, std::string n2, int vec1, int vec2, double w)
    : name1(n1), name2(n2), v1(vec1), v2(vec2), weight(w) {}
  virtual ~Edge();

  friend std::ostream& operator<<(std::ostream&, const Edge&);

  void setWeight(int w) { weight = w; }

  std::string getName1() { return name1; }
  std::string getName2() { return name2; }
  int getV1() { return v1; }
  int getV2() { return v2; }
  double getWeight() { return weight; }

private:
  std::string name1;
  std::string name2;
  int v1;
  int v2;
  double weight;
};

#endif /* AIRPORT_EDGE_H_ */

