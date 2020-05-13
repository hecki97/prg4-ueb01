//
//  main.cpp
//  ueb01
//

#include <iostream>
#include <vector>
#include <random>
#include <locale>
#include <iomanip>
#include <array>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "utils.hpp"
#include "io.hpp"

#include "sorting_algorithms/insertionsort.hpp"
#include "sorting_algorithms/mergesort.hpp"
#include "sorting_algorithms/shellsort.hpp"
#include "sorting_algorithms/bubblesort.hpp"

using namespace std;

array<size_t, 6> ARRAY_SIZES {10, 100, 1'000, 10'000, 100'000, 1'000'000};
mt19937 mt_rand;
uniform_int_distribution<int> dist(0, 1'000'000);
bool verbose = false;

/**
 Run the given sorting algorithm with the given vector and print results to std::cout
 @param vector Unsorted vector
 @param func_pointer Function pointer of sorting algorithm
 @param name Name of sorting algorithm
 */
void run_sorting_algorithm(vector<int> vector, int* (*func_pointer)(int array[], size_t size), const string &name) {
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    func_pointer(&vector[0], vector.size());
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    
    chrono::milliseconds elapsed_time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
    utils::print_elapsed_time(name, elapsed_time);
    
    if (verbose) {
        utils::print_vector(vector);
    }
}

/**
 Initalizes a vector of the given size with pseudorandom values and runs all defined sorting algorithms on it
 @param size Size of vector
 */
void run_benchmark(size_t size) {
    // Fill array with pseudo-random values
    vector<int> vector;
    for (size_t i = 0; i < size; i++) {
        vector.push_back(dist(mt_rand));
    }

    stringstream message;
    message << "Running sorting suites on array of size " << size;
    utils::print_header(message.str());

    if (verbose) {
        cout << "Unsorted array" << endl;
        utils::print_vector(vector);
    }
    
    run_sorting_algorithm(vector, msort::sort, "MergeSort"s);
    run_sorting_algorithm(vector, ssort::sort, "ShellSort"s);
    run_sorting_algorithm(vector, bsort::sort, "BubbleSort"s);
    run_sorting_algorithm(vector, isort::sort, "InsertionSort"s);
}

/**
 Tests if value is in array bounds
 @param value Value to test
 @returns true if value is in bounds, false otherwise
 */
bool is_input_in_range(int value) {
    return value > 0 && static_cast<size_t>(value) <= ARRAY_SIZES.size() + 3;
}

/**
 Prints the elapsed time to std::cout
 @param name Name of sorting algorithm
 @param elapsed_time Elapsed time in milliseconds
*/
void print_elapsed_time(const string &name, chrono::milliseconds &elapsed_time) {
    cout
        << setw(15) << left << name
        << " took "
        << setw(10) << right << elapsed_time.count()
        << "ms."
        << endl;
}

/**
 Prints a selection menu to std::cout
 @returns Selected menu item
*/
int selection_menu() {
    utils::print_header("Sorting algorithm benchmark"s);
    cout << "Run benchmark for:" << endl;
    
    size_t i {0};
    while (i < ARRAY_SIZES.size()) {
        cout << i + 1 << ") Array with " << setw(8) << left << ARRAY_SIZES[i] << " elements" << endl;
        i++;
    }
    cout << ++i << ") Run all" << endl;
    cout << ++i << ") Custom number of elements" << endl;
    cout << ++i << ") Exit" << endl;
    cout << endl;
    
    int selection;
    io::safe_read(selection, is_input_in_range, "Selection: "s);
    return selection;
}

int main() {
    bool is_running = true;

    while(is_running) {
        size_t selection = selection_menu();

        if (selection <= ARRAY_SIZES.size()) {
            run_benchmark(ARRAY_SIZES[selection-1]);
        } else if (selection == ARRAY_SIZES.size() + 1) {
            for_each(ARRAY_SIZES.begin(), ARRAY_SIZES.end(), run_benchmark);
        } else if (selection == ARRAY_SIZES.size() + 2) {
            int size;
            io::safe_read(size, utils::is_input_greater_zero, "Number of elements: "s);
            verbose = io::ask_for_verbose_logging();
            run_benchmark(size);
        } else {
            is_running = false;
        }

        cout << endl << endl;
        // Reset verbose flag
        verbose = false;
    }

    return 0;
}
