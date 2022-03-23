/*
 * Path.h
 *
 *  Created on: Dec 27, 2017
 *      Author: kg
 */

#ifndef AIRPORT_PATH_H_
#define AIRPORT_PATH_H_
#include <vector>
#include <string>
#include "Step.h"

class Path {
public:
  Path();
  virtual ~Path();

  friend std::ostream& operator<<(std::ostream&, const Path&);

  std::vector<Step>& getSteps() { return steps; }

private:
  std::vector<Step> steps;

};

#endif /* AIRPORT_PATH_H_ */
