#include "input_validate.h"


bool is_net_valid(string nt_name) {
    bool net_flag = 0;
    string ss = uppercase(nt_name);
    if (((ss == "CE") || (ss == "CI") || (ss == "FA") || (ss == "NP")
         || (ss == "WR")) && (ss == nt_name)) {
        net_flag = 1;
    }
    return net_flag;
}

bool is_band_valid(string b_type) {
    bool band_flag = 0;
    string ss = uppercase(b_type);
    if ((ss == "LONG-PERIOD") || (ss == "SHORT-PERIOD")
        || (ss == "BROADBAND")) {
        band_flag = 1;
    }
    return band_flag;
}

bool is_instrument_valid(string Ins_type) {
    bool ins_flag = 0;
    string ss = uppercase(Ins_type);
    if ((ss == "HIGH-GAIN") || (ss == "LOW-GAIN") || (ss == "ACCELEROMETER")) {
        ins_flag = 1;
    }
    return ins_flag;
}

bool is_station_valid(string st_name) {
    bool st_flag = 0;
    string ss = uppercase(st_name);
    int sn = st_name.size();
    
    stringstream st_sst;
    int st_in;
    string st_string;
    
    st_sst << st_name;
    st_sst >> st_in;
    st_sst << st_in;
    st_sst >> st_string;
    
    if (sn == 3 && ss == st_name && st_string == "") {
        st_flag = 1;
    }
    if (sn == 5) {
        st_flag = 1;
        for (int i = 0; i == 4; i++) {
            if (isdigit(st_name[i] == 0)) {
                st_flag = 0;
            }
        }
    }
    return st_flag;
}

bool is_or_valid(string orientation) {
    
    bool or_flag = 0;
    int kk = 1;
    int ors = orientation.size();
    
    if (ors < 4 && ors > 0) {
        if (isdigit(orientation[0])) {
            for (int i = 0; i < ors; i++) {
                if (strncmp(&orientation[i], "1", 1) == 0
                    || strncmp(&orientation[i], "2", 1) == 0
                    || strncmp(&orientation[i], "3", 1) == 0) {
                    kk = kk + 1;
                }
            }
        } else {
            
            for (int i = 0; i < ors; i++) {
                if (strncmp(&orientation[i], "N", 1) == 0
                    || strncmp(&orientation[i], "E", 1) == 0
                    || strncmp(&orientation[i], "Z", 1) == 0) {
                    kk = kk + 1;
                }
            }
        }
    }
    
    if (kk - 1 == ors) {
        or_flag = 1;
    }
    if (ors == 2 && orientation[0] == orientation[1]) {
        or_flag = 0;
    }
    if (ors == 2
        && (orientation[0] == orientation[1]
            || orientation[0] == orientation[2]
            || orientation[1] == orientation[2])) {
            or_flag = 0;
        }
    
    return or_flag;
}


string uppercase(string & s) {
    string result = s;
    for (int i = 0; i < (int) result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
    
    
}




