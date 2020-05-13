//
//  utils.hpp
//  ueb01
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <chrono>

namespace utils {
    /**
     Tests if the input is greater zero
     @param value Value that is tested
     @returns true if value is greater than zero, false otherwise
    */
    bool is_input_greater_zero(int value);

    /**
     Prints a line consisting only of dashes ("-")
     @param width number of dashes (default: 50 characters)
     @param out where to write to  (default: std::cout)
     */
    void print_separator(int width = 50, std::ostream &out = std::cout);

    /**
     Prints the given message with a separator above and below
     @param message The message to print
     @param out  where to write to  (default: std::cout)
     */
    void print_header(const std::string &message, std::ostream &out = std::cout);

    /**
     Prints the elapsed time to the given output stream
     @param name The name of the sorting algorithm
     @param elapsed_time Elapsed time in milliseconds
     */
    void print_elapsed_time(const std::string &name, std::chrono::milliseconds &elapsed_time);

    /**
     Prints the content of the given vector and insert a linefeed after ten elements for improved readability
     @param vector The vector to print
     */
    template <typename T>
    void print_vector(std::vector<T> &vector) {
        
        size_t i {1};
        for (T e : vector) {
            std::cout << std::setw(6) << e << ", ";
            
            // Insert a linefeed every ten elements
            if (i++ % 10 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl << std::endl;
    }
}

#endif /* utils_hpp */
