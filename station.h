#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include "io_print_handler.h"
#include "input_validate.h"

using namespace std;

const int MAXSIZE = 300;

enum Network_Code {
    CE, CI, FA, NP, WR
};

enum Band_Type {
    Longperiod, Shortperiod, Broadband
};

enum Instro_Type {
    HighGain, LowGain, Accelerometer
};

string Network_Code_to_string(Network_Code c);
Network_Code string_to_Network_Code(string);
string Instro_Type_to_string(Instro_Type c);
string Band_Type_to_string(Band_Type c);
Band_Type string_to_Band_Type(string);
Instro_Type string_to_instro_Type(string);

class Event {

public:
    void set_nt_name(Event db[MAXSIZE], Network_Code);
    void set_st_name(Event db[MAXSIZE], string);
    void set_b_type(Event db[MAXSIZE], string);
    void set_Ins_type(Event db[MAXSIZE], string);
    void set_orientation(Event db[MAXSIZE], string);
    Network_Code get_nt_name(Event db[MAXSIZE]);
    string get_st_name(Event db[MAXSIZE]);
    Band_Type get_band_type(Event db[MAXSIZE]);
    Instro_Type get_Ins_type(Event db[MAXSIZE]);
    string get_orientation(Event db[MAXSIZE]);

private:
    Network_Code nt_name;
    string st_name;
    Band_Type b_type;
    Instro_Type Ins_type;
    string orientation;
};

