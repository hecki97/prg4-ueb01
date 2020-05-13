//
//  io.cpp
//  ueb01
//

#include "io.hpp"

using namespace std;

bool io::safe_read(int& input, bool (*cond) (int), const string &input_description, istream& in, ostream& out) {
    // Try first read
    out << input_description;
    in >> input;

    while (!in.good() || !cond(input)) {
        if (in.eof()) {
            return false;
        }
        
        in.clear();
        cerr << "Please enter a valid number" << endl;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        
        out << input_description;
        in >> input;
    }

    // Consume linefeed
    cin.get();

    return true;
}

bool io::ask_for_verbose_logging(istream &in, ostream &out) {
    out << endl;
    string input;
    do {
        out << "Do you want to enable verbose logging?" << endl;
        out << "*Warning* This may take a while and could potentially harm readability" << endl;
        out << "(yes|no): ";
        getline(in, input);
    } while(!(input == "yes" || input == "no"));
    out << endl;
    
    // Set verbose logging
    if (input == "yes") {
        return true;
    } else {
        return false;
    }
}
