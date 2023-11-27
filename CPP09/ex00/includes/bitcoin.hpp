#pragma once

#include <algorithm> // replace
#include <ctime>
#include <fstream> // ifstream
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream> // ostringstream
#include <string>  // string
#include <climits> // INT_MAX

using std::map;
using std::string;

typedef u_int32_t uint;

/* Defines */
#define MIN_YEAR 2009
#define MAX_YEAR 2023

#define DB_PATH "./data.csv"

/******************************************************************************/
/*                            Function prototypes                             */
/******************************************************************************/

// parse.cpp
map<uint, float> parseDatabase();
string getInputFileAsString(string filename);

// main.cpp, to be removed
time_t strToUnixTime(string dateStr);

// utils.cpp
float ft_stof(string s);

template<typename T>
std::string ft_to_string(const T & value);
