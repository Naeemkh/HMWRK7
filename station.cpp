#include "station.h"

void Event::set_nt_name(Event db[MAXSIZE],Network_Code nt_name1) {

    nt_name = nt_name1;
}

Network_Code Event::get_nt_name(Event db[MAXSIZE]) {

    return nt_name;
}

void Event::set_st_name(Event db[MAXSIZE], string st_name1) {
    st_name = st_name1;
}

string Event::get_st_name(Event db[MAXSIZE]) {
    return st_name;
}

void Event::set_b_type(Event db[MAXSIZE], Band_Type b_type1) {
    b_type = b_type1;
}

Band_Type Event::get_band_type(Event db[MAXSIZE]) {
    return b_type;
}

void Event::set_Ins_type(Event db[MAXSIZE], Instro_Type Ins_type1) {

    Ins_type = Ins_type1;
}

Instro_Type Event::get_Ins_type(Event db[MAXSIZE]) {
    return Ins_type;
}

void Event::set_orientation(Event db[MAXSIZE], string orientation1) {

    orientation = orientation1;
}

string Event::get_orientation(Event db[MAXSIZE]) {
    return orientation;
}
