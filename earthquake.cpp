#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>

using namespace std;

#include "earthquake.h"
#include "io_print_handler.h"

void Earthquake::set_lat(Earthquake er_info[1], ofstream& errorfile, double lat1) {
    if (-60 <= lat && lat <= 60) {
        lat = lat1;
    } else {
        print_output(errorfile, cout, "Latitude is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_lat(Earthquake er_info[1], string lat) {
    return er_info[0].lat;
}

void Earthquake::set_lon(Earthquake er_info[1], ofstream& errorfile, double lon) {
    if (-180 <= lon && lon <= 180) {
        er_info[0].lon = lon;
    } else {
        print_output(errorfile, cout, "Longitude is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_lon(Earthquake er_info[1], string lon) {
    return er_info[0].lon;
}

void Earthquake::set_depth(Earthquake er_info[1], ofstream& errorfile, double depth) {
    if (0 <= depth) {
        er_info[0].depth = depth;
    } else {
        print_output(errorfile, cout, "Depth of earthquake is not valid. \n");
        errorfile.close();
        exit(1);
    }
}

double Earthquake::get_depth(Earthquake er_info[1], string depth) {
    return er_info[0].depth;
}

void Earthquake::set_event_id(Earthquake er_info[1], ofstream& errorfile, string event_id) {

    er_info[0].event_id = event_id;
}

string Earthquake::get_event_id(Earthquake er_info[1], string event_id) {
    return er_info[0].event_id;
}

void Earthquake::set_event_date(Earthquake er_info[1], ofstream& errorfile,
        string event_date) {

    er_info[0].event_date = event_date;
}

string Earthquake::get_event_date(Earthquake er_info[1], string event_date) {
    return er_info[0].event_date;
}

void Earthquake::set_event_time(Earthquake er_info[1], ofstream& errorfile,
        string event_time) {

    er_info[0].event_time = event_time;
}

string Earthquake::get_event_time(Earthquake er_info[1], string event_time) {
    return er_info[0].event_time;
}

void Earthquake::set_time_zone(Earthquake er_info[1], ofstream& errorfile,
        string time_zone) {

    er_info[0].time_zone = time_zone;
}

string Earthquake::get_time_zone(Earthquake er_info[1], string time_zone) {
    return er_info[0].time_zone;
}

void Earthquake::set_event_name(Earthquake er_info[1], ofstream& errorfile,
        string event_name) {

    er_info[0].event_name = event_name;
}

string Earthquake::get_event_name(Earthquake er_info[1], string event_name) {
    return er_info[0].event_name;
}

void Earthquake::set_mag_type(Earthquake er_info[1], ofstream& errorfile, string mag_t) {

    er_info[0].mag_t = mag_t;
}

string Earthquake::get_mag_type(Earthquake er_info[1], string mag_type) {
    return er_info[0].mag_t;
}

void Earthquake::set_mag(Earthquake er_info[1], ofstream& errorfile, float mag) {

    er_info[0].mag = mag;

}

float Earthquake::get_mag(Earthquake er_info[1], string magnitude) {
    return er_info[0].mag;
}

