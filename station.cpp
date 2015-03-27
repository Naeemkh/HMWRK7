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







void Event::set_nt_name(Event db[MAXSIZE], Network_Code nt_name1) {
    
    string nt_name2 = Network_Code_to_string (nt_name1);
    
    if (is_net_valid(nt_name2) == 1) {
           nt_name = nt_name1;
    } else {
        cout << "Invalide alloacation.";
    }
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
