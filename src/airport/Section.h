/*
 * Edge.h
 *
 *  Created on: Dec 24, 2017
 *      Author: kg
 */

#ifndef AIRPORT_SECTION_H_
#define AIRPORT_SECTION_H_

class Section {
public:
  Section(std::string ra, std::string rb, int a, int b, double w)
    : roadA(ra), roadB(rb), pointA(a), pointB(b), weight(w)
  {}
  virtual ~Section();

  std::string getRoadA() { return roadA; }
  std::string getRoadB() { return roadB; }
  int getPointA() { return pointA; }
  int getPointB() { return pointB; }
  int getWeight() { return weight; }

  friend std::ostream& operator<<(std::ostream&, const Section&);

private:
  Section();

  std::string roadA;
  std::string roadB;
  int pointA;
  int pointB;
  double weight;

};

#endif /* AIRPORT_SECTION_H_ */
