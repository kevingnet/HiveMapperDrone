/*
 * Vertex.h
 *
 *  Created on: Jan 4, 2018
 *      Author: kg
 */

#ifndef AIRPORT_VERTEX_H_
#define AIRPORT_VERTEX_H_

#include <string>

class Vertex {
public:
  Vertex();
  Vertex(std::string r, std::string n, int a) : roadName(r), name(n), angle(a) {}
  virtual ~Vertex();

  friend std::ostream& operator<<(std::ostream&, const Vertex&);

  void setVertex(int v) { vertex = v; }

  std::string getRoadName() { return roadName; }
  std::string getName() { return name; }
  int getAngle() { return angle; }
  int getVertex() { return vertex; }

private:
  std::string roadName;
  std::string name;
  int angle;
  int vertex;
};

#endif /* AIRPORT_VERTEX_H_ */
