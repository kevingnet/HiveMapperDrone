/*
 * Roads.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kg
 */

#ifndef AIRPORT_ROADS_H_
#define AIRPORT_ROADS_H_

#include <vector>
#include <string>

#include "../parsed/Circles.h"
#include "Road.h"

class Roads {
public:
  Roads() {}
  virtual ~Roads();

  std::vector<Road>& get() { return roads; }
  Road* getByName(std::string name);

  void Build(Circles& circles);
  void BuildEdges(Intersections& intersections);

private:
  Roads(const Roads&) {}
  Roads& operator=(const Roads&) { return * this; }

  std::vector<Road> roads;
};

#endif /* AIRPORT_ROADS_H_ */
