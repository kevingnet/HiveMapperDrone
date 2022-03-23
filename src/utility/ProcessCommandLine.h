/*
 * ProcessCommandLine.h
 *
 *  Created on: Dec 20, 2017
 *      Author: kg
 */

#ifndef UTILITY_PROCESSCOMMANDLINE_H_
#define UTILITY_PROCESSCOMMANDLINE_H_

#include <algorithm>

std::string GetCommandLineOption(char ** begin, char ** end, const std::string& option, const std::string& def = "") {
  std::string result =  def;
  char ** itr = std::find(begin, end, option);
  char ** itr2 = itr;
  if (itr != end && ++itr != end) {
    result = *itr;
  }
  if (def == "" && result == "" && *itr2) {
    result = option;
  }
  return result;
}

#endif /* UTILITY_PROCESSCOMMANDLINE_H_ */
