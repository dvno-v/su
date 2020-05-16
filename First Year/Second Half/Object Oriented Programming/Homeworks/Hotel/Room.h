#ifndef ROOM_H

#define ROOM_H

#include <string>
#include <iostream>
#include "Date.h"

class Room
{
private:
	unsigned guests;
	unsigned beds;
	unsigned room_id;
	Date from;
	Date to;
	std::string note;
	bool boocked;

	void read_from_file();
	void export_to_file() const;
public:
	Room();
	Room(const unsigned&, const unsigned&, const unsigned&);
	Room(const unsigned&, const unsigned&, const unsigned&, const Date&, const Date&, const std::string&);
	Room(std::ostream&);
	Room(const Room&);
	~Room();

	void set_number_of_guests(const unsigned&);
	void set_number_of_beds(const unsigned&);
	void set_room_id(const unsigned&);
	void set_from_date(const Date&);
	void set_to_date(const Date&);
	void set_note(const std::string&);

	void book_room(const Date&, const Date&);
	void check_out_room();

	friend std::ostream& operator<<(std::ostream&, const Room&);
	friend std::istream& operator>>(std::istream&, const Room&);

};

#endif
