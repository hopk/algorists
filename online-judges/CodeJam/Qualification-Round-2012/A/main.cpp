/**
 * Problem: A. Speaking in Tongues
 * Judge: CodeJam
 * Date: 06/12/2017
 * URL: https://code.google.com/codejam/contest/1460488/dashboard#s=p0
 * Solved by: hopkins
 */

#include <bits/stdc++.h>

std::map<char, char> map;

void create(std::string ori, std::string dest){

    for (int i = 0; i < ori.size(); ++i) {
        map[ ori[ i ] ] = dest[ i ];
        // map[ dest[ i ] ] = ori[ i ];
    }

    // for (int i = 0; i < ori.size(); ++i) {
    //  std::cout << map[ ori[ i ] ];
    // }
    // std::cout << '\n';
}
int main(int argc, char const *argv[])
{
    map['a'] = 'y';
    // map['y'] = 'a';
    map['o'] = 'e';
    // map['e'] = 'o';
    map['z'] = 'q';
    map['q'] = 'z';


    create("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    create("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    create("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

    // for (auto c: map) {
    //  std::cout << c.first << " " << c.second << '\n';
    // }
    // freopen("test.txt", "r", stdin);
    int tc;
    std::cin  >> tc;
    std::cin.ignore();
    for (int caso = 1; caso <= tc; ++caso) {
        std::cout << "Case #" << caso <<": " ;
        std::string s;
        std::getline(std::cin, s);
        for (char c: s) {
            std::cout << map[ c ];
        }
        std::cout << '\n';
    }
    return 0;
}
