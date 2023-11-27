#include "bitcoin.hpp"

// On error upon parsing the DB, exit gracefully with proper error message
void exitOnDbError(string message = "Generic error") {
    std::cerr << "Internal DB Error: " << message << "\nExiting." << std::endl;
    exit(EXIT_FAILURE);
}

void parseDatabaseRow(map<uint, float> &db, string row, uint lineNb) {
    // Find position of CSV delimiter
    size_t splitPos = row.find(',');

    // Extract date, crash on error
    time_t date = strToUnixTime(row.substr(0, splitPos));
    if (!date) {
        exitOnDbError("Invalid date at line " + ft_to_string(lineNb) + row);
    }

    // Extract value, crash on error
    float value = 1.0F;
    try {
        string valueStr = row.substr(splitPos + 1, row.length() - splitPos - 1);
        value = ft_stof(valueStr);
    } catch (std::exception &e) {
        exitOnDbError("Invalid value at line " + ft_to_string(lineNb));
    }

    // Add to the map
    db[date] = value;
}

map<uint, float> parseDatabase() {
    // Try to open the input file with an ifstream
    std::ifstream ifs(DB_PATH);
    if (!ifs.is_open()) {
        exitOnDbError(string("Could not open the DB at ") + DB_PATH);
    }

    map<uint, float> db;
    string dbRow;
    ifs >> dbRow;

    // If first line of file is `date,exchange_rate`, discard it
    if (dbRow == "date,exchange_rate")
        ifs >> dbRow;

    uint line = 2;
    do {
        parseDatabaseRow(db, dbRow, line);
        line++;
    } while (ifs >> dbRow);

    ifs.close();

    return db;
}

/**
 * @throws std::runtime_error if file cannot be opened
 */
string
getInputFileAsString(string filename) {
    std::ifstream ifs(filename.c_str());
    std::ostringstream oss;

    if (!ifs.is_open()) {
        throw std::runtime_error("File not found: " + filename);
    }

    oss << ifs.rdbuf();
    ifs.close();

    std::cout << "[--- File contents ---]\n" << oss.str() << std::endl;
    return oss.str();
}
