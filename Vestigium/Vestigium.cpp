// Vestigium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_N 5

int r[MAX_N][MAX_N] = {};
int c[MAX_N][MAX_N] = {};

int main()
{
    size_t T, N;
    std::ifstream in("data.txt");
    //auto& in = std::cin;
    in >> T;
    for (int t = 1; t <= T; ++t) {
        int tr = 0;
        std::memset(r, 0, sizeof r);
        std::memset(c, 0, sizeof c);
        in >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int v;
                in >> v;
                if (i == j) tr += v;
                --v;
                ++r[i][v];
                ++c[j][v];
            }
        }
        int dc = 0, dr = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (r[i][j] > 1) {
                    dr++;
                    break;
                }
            }
            for (int j = 0; j < N; ++j) {
                if (c[i][j] > 1) {
                    dc++;
                    break;
                }
            }
        }
        std::cout << "Case #" << t << ": " << tr << " " << dr << " " << dc << std::endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
