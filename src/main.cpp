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

#include "utils.hpp"

#include "sorting_algorithms/insertionsort.hpp"
#include "sorting_algorithms/mergesort.hpp"
#include "sorting_algorithms/shellsort.hpp"
#include "sorting_algorithms/bubblesort.hpp"

using namespace std;

array<size_t, 6> ARRAY_SIZES {10, 100, 1'000, 10'000, 100'000, 1'000'000};
mt19937 mt_rand;
uniform_int_distribution<int> dist(0, 1'000'000);
bool verbose = false;

void run_sorting_suite(vector<int> vector, int* (*func_pointer)(int array[], size_t size), string name) {
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    func_pointer(&vector[0], vector.size());
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    
    chrono::milliseconds elapsed_time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
    utils::print_elapsed_time(name, elapsed_time);
    
    if (verbose) {
        utils::print_vector(vector);
    }
}

void run_benchmark(size_t size) {
    // Fill array with pseudo-random values
    vector<int> vector;
    for (size_t i = 0; i < size; i++) {
        vector.push_back(dist(mt_rand));
    }
    
    utils::print_header("Running sorting suites on array of size", size);
    
    if (verbose) {
        cout << "Unsorted array" << endl;
        utils::print_vector(vector);
    }
    
    run_sorting_suite(vector, msort::sort, "MergeSort");
    run_sorting_suite(vector, ssort::sort, "ShellSort");
    run_sorting_suite(vector, bsort::sort, "BubbleSort");
    run_sorting_suite(vector, isort::sort, "InsertionSort");
}

bool is_input_in_range(int input) {
    return input > 0 && static_cast<size_t>(input) <= ARRAY_SIZES.size() + 3;
}

bool is_input_non_negative(int input) {
    return input > 0;
}

int selection_menu() {
    utils::print_header("Sorting algorithm benchmark");
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
    utils::safe_read(cin, cout, selection, is_input_in_range, "Selection: ");
    return selection;
}

int main() {
    bool is_running = true;

    while(is_running) {
        size_t selection = selection_menu();

        if (selection <= ARRAY_SIZES.size()) {
            run_benchmark(ARRAY_SIZES[selection-1]);
        } else if (selection == ARRAY_SIZES.size() + 1) {
            for (size_t i = 0; i < ARRAY_SIZES.size(); i++) {
                run_benchmark(ARRAY_SIZES[i]);
            }
        } else if (selection == ARRAY_SIZES.size() + 2) {
            int size;
            utils::safe_read(cin, cout, size, is_input_non_negative, "Number of elements: ");
            verbose = utils::ask_for_verbose_logging();
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
