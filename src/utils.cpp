//
//  utils.cpp
//  ueb01
//

#include "utils.hpp"

using namespace std;

bool utils::is_input_greater_zero(int value) {
    return value > 0;
}

void utils::print_separator(int width, ostream &out) {
    out << setfill('-') << setw(width) << "-" << setfill(' ') << endl;
}

void utils::print_header(const string &message, ostream &out) {
    utils::print_separator();
    out << message << endl;
    utils::print_separator();
}

void utils::print_elapsed_time(const string &name, chrono::milliseconds &elapsed_time) {
    cout
        << setw(15) << left << name
        << " took "
        << setw(10) << right << elapsed_time.count()
        << "ms."
        << endl;
}

