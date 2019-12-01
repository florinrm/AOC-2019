#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    int total_sum = 0, n;
    ifstream infile("input.txt");

    while (infile >> n) {
        int module = ((n / 3) - 2);

        // first part
        // total_sum += module;

        // second part
        int module_sum = 0;

        while (module > 0) {
            module_sum += module;
            module = ((module / 3) - 2);
        } 

        total_sum += module_sum;
    }

    cout << total_sum << endl;

    return 0;
}