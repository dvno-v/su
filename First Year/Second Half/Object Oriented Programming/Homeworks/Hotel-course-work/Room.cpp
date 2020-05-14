#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include <cassert>

/*
unsigned number_of_guests;
unsigned number_of_beds;
unsigned room_number;
Date from;
Date to;
std::string note;
bool boocked;
*/
Room::Room(){

}
Room::Room(const unsigned& _guests, const unsigned& _beds, const unsigned& _room_id){

}
Room::Room(const unsigned& _guests, const unsigned& _beds, const unsigned& _room_id, 
			const Date& _from, const Date& _to, const std::string& _note): from(_from), to(_to){
	this->set_number_of_guests(_guests);
	this->set_number_of_beds(_beds);
	this->set_room_id(_room_id);
	this->set_note(_note);
}

Room::Room(std::ostream&){

}

Room::Room(const Room& _other): from(_other.from), to(_other.to){
	this->set_number_of_guests(_other.guests);
	this->set_number_of_beds(_other.beds);
	this->set_room_id(_other.room_id);
	this->set_note(_other.note);
	this->book_room(_other.from, this->to);
}

Room::~Room(){}

void Room::set_number_of_guests(const unsigned& _guests){
	assert(_guests <= this->beds);
	this->guests = _guests;
}
void Room::set_number_of_beds(const unsigned& _beds){
	this->beds = _beds;
}
void Room::set_room_id(const unsigned& _room_id){
	this->room_id = _room_id;
}
void Room::set_from_date(const Date& _from){
	this->from = _from;
}

void Room::set_to_date(const Date& _to){
	this->to = _to;
}

void Room::set_note(const std::string& _note) {
	this->note = _note;
}

void Room::book_room(const Date& _from, const Date& _to){
	assert(_from <= _to);
	this->set_from_date(_from);
	this->set_to_date(_to);
}

#endif /* end of include guard: ROOM_CPP */
