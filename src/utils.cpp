//
//  utils.cpp
//  ueb01
//

#include "utils.hpp"

using namespace std;

void utils::print_separator(int width) {
    cout << setfill('-') << setw(width) << "-" << setfill(' ') << endl;
}

void utils::print_header(string message) {
    utils::print_separator();
    cout << message << endl;
    utils::print_separator();
}

void utils::print_header(string message, size_t size) {
    utils::print_separator();
    cout << message << " " << size << endl;
    utils::print_separator();
}

void utils::print_elapsed_time(string name, chrono::milliseconds elapsed_time) {
    cout
        << setw(15) << left << name
        << " took "
        << setw(10) << right << elapsed_time.count()
        << "ms."
        << endl;
}

void utils::print_vector(vector<int> vector) {
    
    size_t i {1};
    for (int e : vector) {
        cout << setw(6) << e << ", ";
        
        // Insert a linefeed every ten elements
        if (i++ % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl << endl;
}

bool utils::safe_read(istream& in, ostream& out, int& input, bool (*cond) (int), string message) {
    // Try first read
    out << message;
    in >> input;

    while (!in.good() || !cond(input)) {
        if (in.eof()) {
            return false;
        }
        
        in.clear();
        cerr << "Please enter a valid number" << endl;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        
        out << message;
        in >> input;
    }

    // Consume linefeed
    cin.get();

    return true;
}

bool utils::ask_for_verbose_logging() {
    cout << endl;
    string input;
    do {
        cout << "Do you want to enable verbose logging?" << endl;
        cout << "*Warning* This may take a while and could potentially harm readability" << endl;
        cout << "(yes|no): ";
        getline(cin, input);
    } while(!(input == "yes" || input == "no"));
    cout << endl;
    
    // Set verbose logging
    if (input == "yes") {
        return true;
    } else {
        return false;
    }
}

