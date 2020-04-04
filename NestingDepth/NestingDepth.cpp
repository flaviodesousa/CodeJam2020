#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main()
{
    size_t T, N;
    //std::ifstream in("data.txt");
    auto& in = std::cin;
    in >> T; in.get();
    for (int t = 1; t <= T; ++t) {
        std::ostringstream os;
        char c;
        int l = 0;
        do {
            c = in.get();
            if (c >= '0' && c <= '9') {
                int v = c - '0';
                while (v < l) os.put(')'), --l;
                while (v > l) os.put('('), ++l;
                os.put(c);
            }
        } while (c != '\n' && !in.eof());
        while (l--) os.put(')');
        std::cout << "Case #" << t << ": " << os.str() << std::endl;
    }

}
