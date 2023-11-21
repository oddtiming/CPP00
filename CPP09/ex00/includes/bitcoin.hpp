#include <algorithm> // replace
#include <ctime>
#include <fstream> // ifstream
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream> // ostringstream
#include <string>  // string

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

// Dunno yet .cpp
string getInputFileAsString(string filename);
time_t strToUnixTime(string dateStr);