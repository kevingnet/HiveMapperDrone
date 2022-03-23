/*
 * Intersection.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_INTERSECTION_H_
#define PARSED_INTERSECTION_H_

#include "../parsed/Circle.h"

class Intersection {
public:
  Intersection(std::string cA, std::string cB, const int aA, const int aB)
    : circleA(cA), circleB(cB), angleA(aA), angleB(aB) {}
  virtual ~Intersection() {}

  friend std::ostream& operator<<(std::ostream&, const Intersection&);

  std::string GetCircleA() { return circleA; }
  std::string GetCircleB() { return circleB; }
  int GetAngleA() { return angleA; }
  int GetAngleB() { return angleB; }

private:
  Intersection() : circleA(""), circleB(""), angleA(0), angleB(0) {}

  std::string circleA;
  std::string circleB;
  int angleA;
  int angleB;
};

#endif /* PARSED_INTERSECTION_H_ */
