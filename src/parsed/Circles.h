/*
 * Circles.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_CIRCLES_H_
#define PARSED_CIRCLES_H_

#include <vector>

#include "../parsed/Circle.h"

class Circles {
  static const int MINIMUM_RADIUS = 1000;
public:
  Circles() {}
  Circles(std::vector<std::string> circles, bool debug);
  virtual ~Circles() {}

  std::vector<Circle>& getCircles() { return circles; }

private:
  Circles(const Circles&) {}
  Circles& operator=(const Circles&) { return * this; }

  std::vector<Circle> circles;
};

#endif /* PARSED_CIRCLES_H_ */
