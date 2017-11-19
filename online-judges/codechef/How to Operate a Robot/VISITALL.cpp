#include <iostream>
#include <string>
#include <vector>

std::string g[ 1005 ];
int n, points;

int mov[][ 2 ] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
char movc[ 6 ] = "DURL\0";

std::vector<char> sol;



int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        sol.clear();

        points = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> g[ i ];
            std::cout << g[ i ] << "\n";
        }



        for (int x : sol) {
            std::cout << movc[ x ];
        }
        std::cout << "\n";
    }
    return 0;
}