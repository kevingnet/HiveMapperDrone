/*
 * ParseInputFile.h
 *
 *  Created on: Dec 20, 2017
 *      Author: kg
 */

#ifndef UTILITY_PARSEINPUTFILE_H_
#define UTILITY_PARSEINPUTFILE_H_

#include <iostream>
#include <fstream>
#include <vector>

std::string trim(const std::string& str,
    const std::string& whitespace = " \t\r\n") {
  if (str.length() == 0) {
    return str;
  }
  unsigned int beginStr = str.find_first_not_of(whitespace);
  if (beginStr == std::string::npos)
    return "";
  unsigned int endStr = str.find_last_not_of(whitespace);
  unsigned int rangeStr = endStr - beginStr + 1;
  return str.substr(beginStr, rangeStr);
}

bool ParseInputFile(const std::string& inputFileName,
    std::vector<std::string>& circles, std::vector<std::string>& intersections,
    std::vector<std::string>& route) {
  std::string line;
  std::ifstream f(inputFileName.c_str());

  enum {
    CIRCLE, INTERSECTION, ROUTE
  };
  int parsing = CIRCLE;

  if (f.is_open()) {
    while (f.good()) {
      getline(f, line);
      line = trim(line);
      if (line.c_str()[0] == '#') {
        continue;
      }
      switch (parsing) {
      case CIRCLE:
        if (line.length() > 0) {
          circles.push_back(line);
        } else {
          parsing = INTERSECTION;
        }
        break;
      case INTERSECTION:
        if (line.length() > 0) {
          intersections.push_back(line);
        } else {
          parsing = ROUTE;
        }
        break;
      case ROUTE:
        if (line.length() > 0) {
          route.push_back(line);
        }
        break;
      }
    }
    f.close();
  } else {
    std::cout << "Unable to open input file" << std::endl << std::endl;
  }
  return true;
}

#endif /* UTILITY_PARSEINPUTFILE_H_ */
