// ParentingPartneringReturns.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>

#define NAMES "CJ"

int main()
{
    size_t T, N;
    std::ifstream in("data.txt");
    //auto& in = std::cin;
    in >> T;
    for (int t = 1; t <= T; ++t) {
        std::ostringstream os;
        struct { int count, ends, starts; struct { int activity, day; } until[2]; } days[1441] = {};
        int N;
        in >> N;
        std::vector<char> takers(N);
        auto imp = false;
        for (int n = 0; n < N; ++n) {
            int start, end;
            in >> start >> end;
            if (imp) continue;
            for (int day = start; day < end; ++day) {
                if (++days[day].count > 2) {
                    imp = true;
                    break;
                }
            }
            days[start].until[days[start].starts].activity = n;
            days[start].until[days[start].starts].day = end;
            ++days[start].starts;
            ++days[end].ends;
        }
        if (imp) {
            os << "IMPOSSIBLE";
        } else {
            int busy[2] = {};
            for (int day = 0; day < 1440; ++day) {
                while (days[day].ends--) {
                    for (int j = 0; j < 2; ++j) {
                        if (busy[j] == day) {
                            busy[j] = 0;
                            break;
                        }
                    }
                }
                while (days[day].starts--) {
                    for (int j = 0; j < 2; ++j) {
                        if (!busy[j]) {
                            busy[j] = days[day].until[days[day].starts].day;
                            takers[days[day].until[days[day].starts].activity] = j;
                            break;
                        }
                    }
                }
            }
            for (auto& taker : takers) {
                os << NAMES[taker];
            }
        }
        std::cout << "Case #" << t << ": " << os.str() << std::endl;
    }

}
