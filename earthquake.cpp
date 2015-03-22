#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include "earthquake.h"
#include "io_print_handler.h"

using namespace std;

void Earthquake::set_lat(Earthquake er_info[1], ofstream& errorfile, double lat1) {
    if (-60 <= lat && lat <= 60) {
        lat = lat1;
    } else {
        print_output(errorfile, cout, "Latitude is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_lat(Earthquake er_info[1], string lat1) {
    return lat;
}

void Earthquake::set_lon(Earthquake er_info[1], ofstream& errorfile, double lon1) {
    if (-180 <= lon && lon <= 180) {
        lon = lon1;
    } else {
        print_output(errorfile, cout, "Longitude is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_lon(Earthquake er_info[1], string lon1) {
    return lon;
}

void Earthquake::set_depth(Earthquake er_info[1], ofstream& errorfile, double depth1) {
    if (0 <= depth1) {
        depth = depth1;
    } else {
        print_output(errorfile, cout, "Depth of earthquake is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_depth(Earthquake er_info[1], string depth1) {
    return depth;
}

void Earthquake::set_event_id(Earthquake er_info[1], ofstream& errorfile, string event_id1) {

    event_id = event_id1;
}

string Earthquake::get_event_id(Earthquake er_info[1], string event_id1) {
    return event_id;
}

void Earthquake::set_event_date(Earthquake er_info[1], ofstream& errorfile,
        string event_date1) {

    event_date = event_date1;
}

string Earthquake::get_event_date(Earthquake er_info[1], string event_date1) {
    return event_date;
}

void Earthquake::set_event_time(Earthquake er_info[1], ofstream& errorfile,
        string event_time1) {

    event_time = event_time1;
}

string Earthquake::get_event_time(Earthquake er_info[1], string event_time1) {
    return event_time;
}

void Earthquake::set_time_zone(Earthquake er_info[1], ofstream& errorfile,
        string time_zone1) {

    time_zone = time_zone1;
}

string Earthquake::get_time_zone(Earthquake er_info[1], string time_zone1) {
    return time_zone;
}

void Earthquake::set_event_name(Earthquake er_info[1], ofstream& errorfile,
        string event_name1) {

    event_name = event_name1;
}

string Earthquake::get_event_name(Earthquake er_info[1], string event_name1) {
    return event_name1;
}

void Earthquake::set_mag_type(Earthquake er_info[1], ofstream& errorfile, string mag_t1) {

    mag_t = mag_t1;
}

string Earthquake::get_mag_type(Earthquake er_info[1], string mag_type1) {
    return mag_t;
}

void Earthquake::set_mag(Earthquake er_info[1], ofstream& errorfile, float mag1) {

    mag = mag1;

}

float Earthquake::get_mag(Earthquake er_info[1], string magnitude1) {
    return mag;
}

