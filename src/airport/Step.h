/*
 * Step.h
 *
 *  Created on: Dec 27, 2017
 *      Author: kg
 */

#ifndef AIRPORT_STEP_H_
#define AIRPORT_STEP_H_

#include "Road.h"

class Step {
  static const float TIME_TRANSFER= 0.1;
  static const float TIME_REVERSE = 0.3;
  static const float TIME_ACCELERATE = 4.0;
  static const float TIME_DECELERATE = 4.0;
  static const float TIME_DURING_START = 2.0;
  static const float DISPLACEMENT_DURING_START = 8; //meters
  static const float DISPLACEMENT_DURING_STOP = 8;
  static const float SPEED_MAX_MPS = 4; //seconds

  enum { CW = 0, CCW = 1 };

public:
  Step(Road* ra, Road* rb, int a, int b, bool ix, float w, bool debug);
  virtual ~Step();

  friend std::ostream& operator<<(std::ostream&, const Step&);

  int CalculateCommand(int direction, bool& started, int step);
  std::string getCommand() { return command; }
  float getTime() { return timeCost; }

  int CalculateCommandFast(int direction, bool& started, int step);

private:
  Step() : roadSource(0), roadDestination(0), pointSource(0), pointDestination(0),
    intersection(false), weight(0.0), debug(false), timeCost(0.0) {}

  int flipDirection(int d);
  bool reverseByTransfer();
  bool reverseByDistanceAndDirection(int direction);

  void printTransfer(int enteredDirection, int direction);
  void printDisplacement(int enteredDirection, int direction, bool started, float goTime);

  Road * roadSource;
  Road * roadDestination;
  int pointSource;
  int pointDestination;
  bool intersection;
  float weight;

  bool debug;
  mutable bool reversed;
  float timeCost;
  std::string command;
};

#endif /* AIRPORT_STEP_H_ */
