#include "bitcoin.hpp"
#include <stdexcept>
#include <vector>

void
print_usage(string executableName, string message = "Error.") {
    std::cerr << message << " Usage: " << executableName << " [path_to_input_file]\n\n"
              << "Input format:\n"
              << "      Date | Value \n"
              << "YYYY-MM-DD | [0-1000]\n"
              << std::endl;
}

/**
 * @brief Validates YYYY-MM-DD format
 */
bool
isValidDateFormat(const string& date) {
    if (date.length() != 10) return false; // Length check

    // Check format: YYYY-MM-DD
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') {
                return false; // Expecting a dash at these positions
            }
        } else if (!std::isdigit(date[i])) {
            return false; // Expecting a digit elsewhere
        }
    }
    return true;
}

bool
isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

uint
daysSinceNewYear(uint year, uint month, uint day) {
    uint totalDays = 0;
    uint daysInFebruary = isLeapYear(year) ? 29 : 28;
    uint daysInMonth[] = { 31, daysInFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check if year is valid
    if (year < MIN_YEAR || year > MAX_YEAR) {
        std::cerr << "Error: year " << year << " should be between " << MIN_YEAR << " and " << MAX_YEAR << std::endl;
        return -1;
    }

    // Check if month is valid
    if (month > 11) {
        std::cerr << "Error: invlid month." << std::endl;
        return -1;
    }

    // Check if that month has at least ${day} days in it
    if (day > daysInMonth[month]) {
        std::cerr << "Error: the month " << year << "-" << month + 1 << " only has " << daysInMonth[month]
                  << " days in it." << std::endl;
        return -1;
    }

    // Calculate total number of days
    for (uint i = 0; i < month; ++i) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;

    return totalDays;
}

time_t
strToUnixTime(string dateStr) {
    // Validate the YYYY-MM-DD format, early exit on bad input
    if (!isValidDateFormat(dateStr)) {
        return time_t(0);
    }

    // Extract YMD from dateString
    std::istringstream ss(dateStr);
    char delimiter;
    uint year, month, day;

    // Parse the date, 0-index the month
    ss >> year >> delimiter >> month >> delimiter >> day;
    month -= 1;

    // Get total days since 1970
    uint totalDays = 0;
    for (uint y = 1970; y < year; ++y) {
        totalDays += 365 + isLeapYear(y);
    }
    totalDays += daysSinceNewYear(year, month, day);

    // Convert to seconds
    time_t timestamp = totalDays * 86400;

    return timestamp;
}

// Basic tests to validate the strToUnixTime function
void
testStrToUnixTime() {
    struct Test {
        std::string input;
        bool expectValid;
    };

    Test tests[] = {
        {"2001-02-21",          true },
        { "2012-12-12",         true },
        { "2022-01-10",         true },
        { "202-00-10",          false},
        { "2022-01-10-10-1212", false}
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        time_t result = strToUnixTime(tests[i].input);
        bool isValid = result != 0;

        std::cout << "Test [" << i << "] - ";
        if (isValid == tests[i].expectValid) {
            std::cout << "\033[32m✔\033[0m"; // Green checkmark for passed tests
        } else {
            std::cout << "\033[31m✖\033[0m"; // Red cross for failed tests
        }
        std::cout << " (" << tests[i].input << ")" << std::endl;
    }
}

float
getClosestPrecedingValue(map<uint, float>& db, uint date) {
    map<uint, float>::iterator it = db.lower_bound(date);

    if (it == db.begin()) {
        std::cerr << "No preceding date found for " << date << std::endl;
        return -1.0F;
    } else if (it != db.end()) {
        --it;
    }

    std::cout << "For " << date << ", found closest value to be at " << it->first << " for a value of " << it->second
              << std::endl;
    return it->first;
}

void
calculatePrices(map<uint, float>& db, string inputStr) {
    size_t eol = 0;
    size_t start = 0;
    string row;
    while ((eol = inputStr.find('\n', start)) != string::npos) {
        std::cout << eol << ": ";
        row = inputStr.substr(start, eol - start);
        // TODO: improve parsing of delimiters with ltrim and rtrim
        size_t delim = row.find(" | ");
        string date = row.substr(0, delim);
        string value = row.substr(delim + 3, row.length() - delim + 3);
        std::cout << "value: " << value << ", "
                  << "date: " << date << std::endl;
        long val;
        try {
            val = ft_stof(value);
        } catch (...) {
            std::cerr << "No suitable conversion for value " << val << std::endl;
            continue;
        }
        long int_max = INT_MAX;
        int_max += 1;
        if (val >= int_max) {
            std::cerr << "Value bigger than" << INT_MAX << std::endl;
        } else {
            time_t date_time = strToUnixTime(date);
            getClosestPrecedingValue(db, date_time);
        }

        start = eol + 1;
    }
}

int
main(int argc, char* argv[]) {
    // Early exit on invalid arguments
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Basic tests
    testStrToUnixTime();

    // Initialize the DB and process the input file, exit on error
    string inputAsString;
    map<uint, float> db;
    try {
        db = parseDatabase();
        inputAsString = getInputFileAsString(argv[1]);

    } catch (std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Calculate price
    calculatePrices(db, inputAsString);

    return 0;
}
