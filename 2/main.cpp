#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream infile("input.txt");

    string str;
    vector<long long> v;
    infile >> str;

    std::stringstream ss(str);

    for (int i; ss >> i;) {
        v.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (int x = 0; x <= 99; x++) {
        for (int y = 0; y <= 99; y++) {
            v[1] = x;
            v[2] = y;
        }
    }

    // first part
    /*
    v[1] = 12;
    v[2] = 2;

    for (int i = 0; i < v.size(); i += 4) {
        if (v[i] == 99) {
            break;
        } else if (v[i] == 1) {
            v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
        } else if (v[i] == 2) {
            v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
        }

        if (v[0] == 19690720) {
            long long noun, verb;
            noun = v[v[i + 1]];
            verb = v[v[i + 2]];
            cout << 100 * noun + verb << endl;
        }
    }

    cout << v[0] << endl;
    */
    // second part

    for (int x = 0; x <= 99; x++) {
        for (int y = 0; y <= 99; y++) {
            vector<long long> aux(v);
            aux[1] = x;
            aux[2] = y;

            for (int i = 0; i < v.size(); i += 4) {
                if (aux[i] == 99) {
                    break;
                } else if (aux[i] == 1) {
                    aux[aux[i + 3]] = aux[aux[i + 1]] + aux[aux[i + 2]];
                } else if (aux[i] == 2) {
                    aux[aux[i + 3]] = aux[aux[i + 1]] * aux[aux[i + 2]];
                }
            }

            if (aux[0] == 19690720) {
                long long noun, verb;
                noun = aux[1];
                verb = aux[2];
                cout << 100 * noun + verb << endl;
            }
        }
    }

    return 0;
}