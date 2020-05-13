//
//  io.hpp
//  ueb01
//


#ifndef io_hpp
#define io_hpp

#include <stdio.h>
#include <iostream>

namespace io {
    /**
     Safely reads a value from the given input stream if value is an integer and a condition is met
     @param input int pointer where the read result is stored
     @param cond Function pointer to a function that takes an integer and returns a boolean
     @param input_description Input description
     @param in where to read from (default: std::cin)
     @param out where to write to (default: std::cout)
     @returns true if value was safely read, false otherwise
     */
    bool safe_read(int& input, bool (*cond) (int), const std::string &input_description, std::istream &in = std::cin, std::ostream &out = std::cout);

    /**
     Asks the user if verbose logging should be activated
     @param in where to read from (default: std::cin)
     @param out where to write to (default: std::cout)
     @returns true if verbose logging should be activated, false otherwise
     */
    bool ask_for_verbose_logging(std::istream &in = std::cin, std::ostream &out = std::cout);
}

#endif /* io_hpp */
