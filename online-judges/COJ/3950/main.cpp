/**
 * Problem: 3950 - Counting Patterns
 * Judge: COJ
 * Date: 12/03/2018
 * URL: http://coj.uci.cu/24h/problem.xhtml?pid=3950
 * Solved by: hopkins
 */

using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>

// N * C;
// where C is the average number of characters per word and N is the number of words. 
const int MAXN = 10000 * 100 + 5;
char buff  [ 205 ];
int  tree  [ MAXN ][ 26 ];
int  tree_c[ MAXN ][ 26 ];
int  stateCount = 1;

void add_word(char *s) {
    int state = 0;
    for (; *s; s++) {
        int next = (int)(*s - 'a');
        if (tree[ state ][ next ] == -1) {
            tree[ state ][ next ] = stateCount++;
        }
        tree_c[ state ][ next ]++;
        state = tree[ state ][ next ];
    }
}

int count_pref(char *s) {
    int state = 0;
    for (; *(s + 1); s++) {
        int next = (int)(*s - 'a');
        if (tree[ state ][ next ] == -1) {
            return 0;
        }
        state = tree[ state ][ next ];
    }

    // printf("=> %s\n", s);
    int next = (int)(*s - 'a');
    return tree_c[ state ][ next];
}
int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    memset(tree, -1, sizeof(tree));
    stateCount = 1;

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%s", buff);
        int t = strlen(buff);
        reverse(buff, buff + t);
        add_word(buff);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%s", buff);
        int t = strlen(buff);
        reverse(buff, buff + t);
        printf("%d\n", count_pref(buff));
    }
    return 0;
}
