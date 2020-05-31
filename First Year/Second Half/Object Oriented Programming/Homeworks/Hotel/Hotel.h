#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>
#include "Room.h"
#include "Activity.h"

class Hotel
{
private:
  std::vector<Room*> rooms;
  std::vector<Activity*> rooms;
public:
  Hotel();
  Hotel(std::ostream&);
  Hotel(const std::vector<Room*>&);
  ~Hotel();

  void check_in(const std::string&);
  void get_available(const Date&);
  void check_out(const Room*);

};

#endif /* end of include guard: HOTEL_H */
