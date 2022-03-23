/*
 * Intersections.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_INTERSECTIONS_H_
#define PARSED_INTERSECTIONS_H_

#include <vector>
#include "../parsed/Circles.h"
#include "../parsed/Intersection.h"

class Intersections {
public:
  Intersections() {}
  Intersections(std::vector<std::string> intersections, bool debug);
  virtual ~Intersections() {}

  std::vector<Intersection>& get() { return intersections; }

private:
  Intersections(const Intersections&) {}
  Intersections& operator=(const Intersections&) { return * this; }

  std::vector<Intersection> intersections;
};

#endif /* PARSED_INTERSECTIONS_H_ */
