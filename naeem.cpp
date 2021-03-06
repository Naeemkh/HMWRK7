/*
 * Prog Tools for Scits Engrs - CIVL 8903/7903 001
 * Prof. Ricardo Taborda
 * Homework 6
 * Written by : Naeem Khoshnevis (nkhshnvs@memphis.edu)
 * https://github.com/Naeemkh/HMWRK7.git
 * March 15 , 2015
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>

#include "earthquake.h"
#include "station.h"
#include "io_print_handler.h"
#include "input_validate.h"

using namespace std;

enum months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum Magnitude_Type {
    ML, Ms, Mb, Mw
};

/***************************** function prototypes *************************************/

bool is_date_valid(string, int&, int&, int&);
bool is_time_valid(string &);
bool is_tzone_valid(string);
bool is_mag_valid(string);
bool is_mag_inrange(float);
bool read_input(ifstream&, ofstream&, Event db[MAXSIZE], int &, int &, int &,
        int &, int &);

void check_validate(Earthquake er_info[1], ofstream&, int &, int &, int &);
void print_header(int, int, int, Earthquake er_info[1], ofstream&);
void generate_recorded_list(Earthquake er_info[1], ofstream&, Event db[MAXSIZE],
        int &, int &);

string Magnitude_Type_to_string(Magnitude_Type);
months int_to_months(int);
Magnitude_Type string_to_Magnitude_Type(string);

/********************************* main function ****************************************/

int main() {

    ifstream inputfile;
    ofstream outputfile;
    ofstream errorfile;

    //string  event_date, event_time, time_zone, event_name,mag_t;

    int month = 0, day = 0, year = 0;
    int total_entry = 0, invalid_counter = 0, valid_counter = 0, total_co = 0;
    double t_lat, t_lon, t_depth;
    string t_event_id, t_event_name, t_event_date, t_event_time, t_time_zone,
            t_mag_t;
    float t_mag;

    Event db[MAXSIZE];
    Earthquake er_info[1];
    int number_of_events;

    open_input(inputfile, errorfile);
    print_output(errorfile, cout, "Processing input ... \n");

    inputfile >> t_event_id;
    inputfile >> t_event_date;
    inputfile >> t_event_time;
    inputfile >> t_time_zone;

    inputfile.ignore();
    getline(inputfile, t_event_name);

    inputfile >> t_lon;
    inputfile >> t_lat;
    inputfile >> t_depth;

    inputfile >> t_mag_t;
    inputfile >> t_mag;

    er_info[0].set_lon(er_info, errorfile, t_lon);
    er_info[0].set_lat(er_info, errorfile, t_lat);
    er_info[0].set_depth(er_info, errorfile, t_depth);

    er_info[0].set_event_id(er_info, errorfile, t_event_id);
    er_info[0].set_event_date(er_info, errorfile, t_event_date);
    er_info[0].set_event_time(er_info, errorfile, t_event_time);
    er_info[0].set_time_zone(er_info, errorfile, t_time_zone);
    er_info[0].set_event_name(er_info, errorfile, t_event_name);
    er_info[0].set_mag_type(er_info, errorfile, t_mag_t);
    er_info[0].set_mag(er_info, errorfile, t_mag);

    check_validate(er_info, errorfile, month, day, year);

    print_output(errorfile, cout, "Header read correctly! \n");
    open_output(outputfile, errorfile, "naeem.out");
    print_header(month, day, year, er_info, outputfile);

    read_input(inputfile, errorfile, db, number_of_events, total_co,
            invalid_counter, total_entry, valid_counter);

    print_output(errorfile, cout, "Total invalid entries ignored: ");
    print_output(errorfile, cout, invalid_counter);
    print_output(errorfile, cout, "\n");

    print_output(errorfile, cout, "Total valid entries read: ");
    print_output(errorfile, cout, valid_counter);
    print_output(errorfile, cout, "\n");

    print_output(errorfile, cout, "Total signal names produced: ");
    print_output(errorfile, cout, total_co);
    print_output(errorfile, cout, "\n");
    print_output(errorfile, cout, "Finished !");
    print_output(errorfile, cout, "\n");

    generate_recorded_list(er_info, outputfile, db, number_of_events, total_co);

    outputfile.close();
    return 0;
}

/********************************* function definition **********************************/

bool is_date_valid(string event_date, int & month, int & day, int & year) {

    int s = event_date.size();
    int k = 0, delim;
    int pos[2] = { 0 };
    bool date_flag = 0;

    int p1 = event_date.find("/");
    int p2 = event_date.find("-");

    if (p1 < 0 && (p2 < 0)) {
        date_flag = 1;
    } else if (p1 > 0 && p2 > 0) {
        date_flag = 1;
    } else if (p1 > 0 && p2 < 0) {
        delim = 1;
    } else if (p1 < 0 && p2 > 0) {
        delim = 2;
    }

    if (date_flag == 0) {

        for (int i = 0; i < s; i++) {
            switch (delim) {
            case 1:
                if (strncmp(&event_date[i], "/", 1) == 0) {
                    pos[k] = i;
                    k = k + 1;
                }
                break;
            case 2:
                if (strncmp(&event_date[i], "-", 1) == 0) {
                    pos[k] = i;
                    k = k + 1;
                }
                break;
            }
        }
    }

    if (k != 2) {
        date_flag = 1;
    } else {
        stringstream m, d, y;

        m << event_date.substr(0, pos[0]);
        d << event_date.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        y << event_date.substr(pos[1] + 1, s - pos[1]);

        m >> month;
        d >> day;
        y >> year;

        if (month < 0 || month > 12) {
            date_flag = 1;
        }
        if (day < 0 || day > 31) {
            date_flag = 1;
        }
        if (year < 1900 || year > 2015) {
            date_flag = 1;
        }
    }
    return date_flag;
}

bool is_time_valid(string & event_time) {

    int s = event_time.size();
    int k = 0;
    int pos[2] = { 0 };
    bool time_flag = 0;

    int p1 = event_time.find(":");
    int p2 = event_time.find(".");

    if (p1 < 0 && (p2 < 0)) {
        time_flag = 1;
    }
    if (time_flag == 0) {

        for (int i = 0; i < s; i++) {
            if (strncmp(&event_time[i], ":", 1) == 0) {
                pos[k] = i;
                k = k + 1;
            }
        }
    }

    if (k != 2 || pos[1] > p2) {
        time_flag = 1;
    } else {

        stringstream hh;
        stringstream mm;
        stringstream ss;

        int hour, min;
        double second;

        hh << event_time.substr(0, pos[0]);
        mm << event_time.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        ss << event_time.substr(pos[1] + 1, s - pos[1]);

        hh >> hour;
        mm >> min;
        ss >> second;

        if (hour < 0 || hour > 24) {
            time_flag = 1;
        }
        if (min < 0 || min > 59) {
            time_flag = 1;
        }
        if (second < 0 || second >= 60) {
            time_flag = 1;
        }
    }
    return time_flag;
}

bool is_tzone_valid(string time_zone) {

    int s = time_zone.size();
    stringstream os1;
    bool tzone_flag = 0;

    if (s != 3) {
        tzone_flag = 1;
    }

    return tzone_flag;
}

bool is_mag_valid(string mag_t) {
    string ss = uppercase(mag_t);
    return ((ss == "ML") || (ss == "MS") || (ss == "MB") || (ss == "MW"));
}

bool is_mag_inrange(float mag) {
    return (mag >= 0);
}

string Magnitude_Type_to_string(Magnitude_Type c) {
    switch (c) {
    case ML:
        return "ML";
    case Ms:
        return "Ms";
    case Mb:
        return "Mb";
    case Mw:
        return "Mw";
    }
    // It should never get here!!
    exit (EXIT_FAILURE);
}

Magnitude_Type string_to_Magnitude_Type(string s) {

    string ss = uppercase(s);

    if (ss == "ML")
        return ML;
    if (ss == "MS")
        return Ms;
    if (ss == "MB")
        return Mb;
    if (ss == "MW")
        return Mw;

    // It should never get here!!
    exit (EXIT_FAILURE);
}

months int_to_months(int a) {

    if (a == 1)
        return January;
    if (a == 2)
        return February;
    if (a == 3)
        return March;
    if (a == 4)
        return April;
    if (a == 5)
        return May;
    if (a == 6)
        return June;
    if (a == 7)
        return July;
    if (a == 8)
        return August;
    if (a == 9)
        return September;
    if (a == 10)
        return October;
    if (a == 11)
        return November;
    if (a == 12)
        return December;

    // It should never get here!!
    exit (EXIT_FAILURE);
}

string month_to_string(months c) {
    switch (c) {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    case December:
        return "December";
    }
    // It should never get here!!
    exit (EXIT_FAILURE);
}

void check_validate(Earthquake er_info[1], ofstream & errorfile, int & month,
        int & day, int & year) {

    string event_date, event_time, mag_t, time_zone, magnitude;
    float mag;

    event_date = er_info[0].get_event_date(er_info);
    event_time = er_info[0].get_event_time(er_info);
    mag = er_info[0].get_mag(er_info);
    mag_t = er_info[0].get_mag_type(er_info);
    time_zone = er_info[0].get_time_zone(er_info);

    if (is_date_valid(event_date, month, day, year) != 0) {
        print_output(errorfile, cout, "Date format is not valid. \n");
        errorfile.close();
        exit (EXIT_FAILURE);
    } else if (is_time_valid(event_time) != 0) {
        print_output(errorfile, cout, "Time format is not valid. \n");
        errorfile.close();
        exit (EXIT_FAILURE);
    } else if (is_tzone_valid(time_zone) != 0) {
        print_output(errorfile, cout, "Time zone format is not valid. \n");
        errorfile.close();
        exit (EXIT_FAILURE);
    } else if (is_mag_valid(mag_t) != 1) {
        print_output(errorfile, cout, "Magnitude type is not valid. \n");
        errorfile.close();
        exit (EXIT_FAILURE);
    } else if (is_mag_inrange(mag) != 1) {
        print_output(errorfile, cout, "Magnitude is not in valid range. \n");
        errorfile.close();
        exit (EXIT_FAILURE);
    }

}

void print_header(int month, int day, int year, Earthquake er_info[1],
        ofstream& outputfile) {

    string lat, lon, depth, event_id, mag, event_name, magnitude, event_time,
            time_zone, mag_t;

    outputfile << "# " << day << " " << month_to_string(int_to_months(month))
            << " " << year << " " << er_info[0].get_event_time(er_info) << " "
            << er_info[0].get_time_zone(er_info) << " "
            << Magnitude_Type_to_string(
                    string_to_Magnitude_Type(er_info[0].get_mag_type(er_info)))
            << " " << er_info[0].get_mag(er_info) << " "
            << er_info[0].get_event_name(er_info) << " " << "["
            << er_info[0].get_event_id(er_info) << "]" << "("
            << er_info[0].get_lon(er_info) << ", "
            << er_info[0].get_lat(er_info) << ", "
            << er_info[0].get_depth(er_info) << ")" << "\n";

}

bool read_input(ifstream& inputfile, ofstream& errorfile, Event db[MAXSIZE],
        int & size, int & total_co, int & invalid_counter, int & total_entry,
        int & valid_counter) {

    string nt_name, st_name, b_type, Ins_type, orientation;
    stringstream os1;
    size = 0;
    total_entry = 1;

    while (size < MAXSIZE) {

        bool save_record_flag = 1;
        if (!(inputfile >> nt_name >> st_name >> b_type >> Ins_type
                >> orientation))
            break;

        if (is_net_valid(nt_name) == 0) {

            stringstream ks;
            string kk;
            ks << total_entry;
            ks >> kk;
            print_output(errorfile, cout, "Entry # ");
            print_output(errorfile, cout, kk);
            print_output(errorfile, cout, " Ignored. ");
            print_output(errorfile, cout, "Invalid Network. \n");
            save_record_flag = 0;
        }

        if (is_station_valid(st_name) == 0) {

            stringstream ks;
            string kk;
            ks << total_entry;
            ks >> kk;

            print_output(errorfile, cout, "Entry # ");
            print_output(errorfile, cout, kk);
            print_output(errorfile, cout, " Ignored. ");
            print_output(errorfile, cout, "Invalid station code. \n");
            save_record_flag = 0;
        }

        if (is_band_valid(b_type) == 0) {

            stringstream ks;
            string kk;
            ks << total_entry;
            ks >> kk;

            print_output(errorfile, cout, "Entry # ");
            print_output(errorfile, cout, kk);
            print_output(errorfile, cout, " Ignored. ");
            print_output(errorfile, cout, "Invalid band type. \n");
            save_record_flag = 0;
        }

        if (is_instrument_valid(Ins_type) == 0) {

            stringstream ks;
            string kk;
            ks << total_entry;
            ks >> kk;
            print_output(errorfile, cout, "Entry # ");
            print_output(errorfile, cout, kk);
            print_output(errorfile, cout, " Ignored. ");
            print_output(errorfile, cout, "Invalid instrument type. \n");
            save_record_flag = 0;
        }

        if (is_or_valid(orientation) == 0) {

            stringstream ks;
            string kk;
            ks << total_entry;
            ks >> kk;
            print_output(errorfile, cout, "Entry # ");
            print_output(errorfile, cout, kk);
            print_output(errorfile, cout, " Ignored. ");
            print_output(errorfile, cout, "Invalid orientation. \n");
            save_record_flag = 0;
        }

        if (save_record_flag == 1) {

            db[size].set_nt_name(db, string_to_Network_Code(nt_name));
            db[size].set_st_name(db, st_name);
            db[size].set_b_type(db, b_type);
            db[size].set_Ins_type(db, Ins_type);
            db[size].set_orientation(db, orientation);

            total_co = total_co + orientation.size();

            size++;

        } else {
            invalid_counter = invalid_counter + 1;
        }
        total_entry++;
    }
    valid_counter = total_entry - invalid_counter - 1;
    return true;
}

void generate_recorded_list(Earthquake er_info[1], ofstream& outputfile,
        Event db[MAXSIZE], int & size, int & total_co) {

    string event_id, nt_name, orientation, st_name, b_type, Ins_type;

    outputfile << total_co << "\n";

    for (int i = 0; i < size; i++) {
        int sc = db[i].get_orientation(db).size();

        for (int j = 0; j < sc; j++) {
            outputfile << er_info[0].get_event_id(er_info) << "."
                    << Network_Code_to_string(db[i].get_nt_name(db)) << "."
                    << db[i].get_st_name(db) << "."
                    << Band_Type_to_string(db[i].get_band_type(db))
                    << Instro_Type_to_string(db[i].get_Ins_type(db))
                    << db[i].get_orientation(db)[j] << "\n";

        }

    }
}

