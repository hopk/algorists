#include <iostream>
#include <map>

int main() {
    std::map<char, int> acom;
    std::string s;
    std::cin >> s;

    long long ans = 0;
    for (char c : s) {
        ans += acom[ c ] * 2LL + 1LL;
        acom[ c ]++;
    }
    std::cout << ans << '\n';

    return EXIT_SUCCESS;
}
