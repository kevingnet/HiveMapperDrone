/*
 * World.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_WORLD_H_
#define PARSED_WORLD_H_

#include "../parsed/Circles.h"
#include "../parsed/Circles.h"
#include "../parsed/Intersections.h"
#include "../parsed/Route.h"
#include "../airport/Roads.h"
#include "../airport/Planner.h"

class World {
public:
  World(std::vector<std::string> circles,
      std::vector<std::string> intersections,
      std::vector<std::string> route,
      bool debug = false);
  virtual ~World() {}

  void Solve(std::string algorithm);
  void SetRoute(std::vector<std::string> route);

private:
  World() {}
  World(const World&) {}

  Circles circles;
  Intersections intersections;
  Route route;
  Roads roads;
  Planner planner;
  bool debug;
};

#endif /* PARSED_WORLD_H_ */
