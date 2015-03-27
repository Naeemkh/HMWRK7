#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>

using namespace std;

bool is_net_valid(string);
bool is_station_valid(string);
bool is_band_valid(string);
bool is_instrument_valid(string);
bool is_or_valid(string);
string uppercase(string &);