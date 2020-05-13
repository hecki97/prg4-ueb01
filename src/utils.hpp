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
    void print_separator(int width = 50);
    void print_header(std::string message);
    void print_header(std::string message, size_t size);
    void print_elapsed_time(std::string name, std::chrono::milliseconds elapsed_time);
    void print_vector(std::vector<int> vector);
    bool safe_read(std::istream& in, std::ostream& out, int& input, bool (*cond) (int), std::string message);
    bool ask_for_verbose_logging();
}

#endif /* utils_hpp */
