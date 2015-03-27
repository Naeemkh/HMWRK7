#include "station.h"

Network_Code string_to_Network_Code(string s) {

    string ss = uppercase(s);

    if (ss == "CE")
        return CE;
    if (ss == "CI")
        return CI;
    if (ss == "FA")
        return FA;
    if (ss == "NP")
        return NP;
    if (ss == "WR")
        return WR;

    // It should never get here!!
    exit (EXIT_FAILURE);

}

string Network_Code_to_string(Network_Code c) {
    switch (c) {
    case CE:
        return "CE";
    case CI:
        return "CI";
    case FA:
        return "FA";
    case NP:
        return "NP";
    case WR:
        return "WR";
    }
    // It should never get here!!
    exit (EXIT_FAILURE);
}

Band_Type string_to_Band_Type(string s) {

    string ss = uppercase(s);

    if (ss == "LONG-PERIOD")
        return Longperiod;
    if (ss == "SHORT-PERIOD")
        return Shortperiod;
    if (ss == "BROADBAND")
        return Broadband;

    // It should never get here!!
    exit (EXIT_FAILURE);

}

string Band_Type_to_string(Band_Type c) {
    switch (c) {
    case Longperiod:
        return "L";
    case Shortperiod:
        return "B";
    case Broadband:
        return "H";

    }

    // It should never get here!!
    exit (EXIT_FAILURE);
}

Instro_Type string_to_instro_Type(string s) {

    string ss = uppercase(s);

    if (ss == "HIGH-GAIN")
        return HighGain;
    if (ss == "LOW-GAIN")
        return LowGain;
    if (ss == "ACCELEROMETER")
        return Accelerometer;

    // It should never get here!!
    exit (EXIT_FAILURE);

}

string Instro_Type_to_string(Instro_Type c) {
    switch (c) {
    case HighGain:
        return "H";
    case LowGain:
        return "L";
    case Accelerometer:
        return "N";

    }
    // It should never get here!!
    exit (EXIT_FAILURE);
}

void Event::set_nt_name(Event db[MAXSIZE], Network_Code nt_name1) {

    string nt_name2 = Network_Code_to_string(nt_name1);

    if (is_net_valid(nt_name2) == 1) {
        nt_name = nt_name1;
    } else {
        cout << "Invalid Network alloacation." << "\n";
    }
}

Network_Code Event::get_nt_name(Event db[MAXSIZE]) {

    return nt_name;
}

void Event::set_st_name(Event db[MAXSIZE], string st_name1) {
    if (is_station_valid(st_name1) == 1) {
        st_name = st_name1;
    } else {
        cout << "Invalid station alloacation." << "\n";
    }
}

string Event::get_st_name(Event db[MAXSIZE]) {
    return st_name;
}

void Event::set_b_type(Event db[MAXSIZE], string b_type1) {

    if (is_band_valid(b_type1) == 1) {
        b_type = string_to_Band_Type(b_type1);
    } else {
        cout << "Invalid bandtype alloacation." << "\n";
    }
}

Band_Type Event::get_band_type(Event db[MAXSIZE]) {
    return b_type;
}

void Event::set_Ins_type(Event db[MAXSIZE], string Ins_type1) {

    if (is_instrument_valid(Ins_type1) == 1) {
        Ins_type = string_to_instro_Type(Ins_type1);
    } else {
        cout << "Invalid instrument type alloacation." << "\n";
    }

}

Instro_Type Event::get_Ins_type(Event db[MAXSIZE]) {
    return Ins_type;
}

void Event::set_orientation(Event db[MAXSIZE], string orientation1) {
    if (is_or_valid(orientation) == 1) {
        orientation = orientation1;
    } else {
        cout << "Invalid orientation alloacation." << "\n";
    }

}

string Event::get_orientation(Event db[MAXSIZE]) {
    return orientation;
}
