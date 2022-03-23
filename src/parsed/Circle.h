/*
 * Circle.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_CIRCLE_H_
#define PARSED_CIRCLE_H_

#include <string>

class Circle {
public:
  Circle(const std::string name, const int radius, const int intersections);
  virtual ~Circle() {}

  friend std::ostream& operator<<(std::ostream&, const Circle&);
  bool operator==(const Circle&) const;

  std::string getName() { return name; }
  int getRadius() { return radius; }

private:
  Circle() : name(""), radius(0), intersections(0) {}

  std::string name;
  int radius;
  int intersections;
};

#endif /* PARSED_CIRCLE_H_ */
