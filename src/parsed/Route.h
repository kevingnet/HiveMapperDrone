/*
 * Route.h
 *
 *  Created on: Dec 21, 2017
 *      Author: kg
 */

#ifndef PARSED_ROUTE_H_
#define PARSED_ROUTE_H_

#include <string>
#include <vector>

#include "../parsed/Circle.h"

class Route {
public:

  Route() : circleDeparture(""), circleArrival(""), angleDeparture(0), angleArrival(0), direction(0) {}
  Route(const std::string circleDeparture, const std::string circleArrival,
      const int angleDeparture, const int angleArrival, const int direction)
    : circleDeparture(circleDeparture), circleArrival(circleArrival),
      angleDeparture(angleDeparture), angleArrival(angleArrival),
      direction(direction)
  {}
  virtual ~Route() {}

  enum { CLOCK_WISE, COUNTER_CLOCK_WISE };

  friend std::ostream& operator<<(std::ostream&, const Route&);

  std::string getCircleDeparture() { return circleDeparture; }
  std::string getCircleArrival() { return circleArrival; }
  int getAngleDeparture() { return angleDeparture; }
  int getAngleArrival() { return angleArrival; }
  int getDirection() { return direction; }

private:
  std::string circleDeparture;
  std::string circleArrival;
  int angleDeparture;
  int angleArrival;
  int direction;
};

#endif /* PARSED_ROUTE_H_ */
