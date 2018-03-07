/**
 * Problem: B. Crossing the Road
 * Judge: Codejam
 * Date: 06/03/2018
 * URL: https://code.google.com/codejam/contest/188266/dashboard#s=p1
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <utility>
#include <set>
#define DEBUG false


const int MAXN = 22;
const long long INF = (long long)(1e15);

long long int S[ MAXN ][ MAXN ];
long long int W[ MAXN ][ MAXN ];
long long int T[ MAXN ][ MAXN ];
long long int dist[ MAXN ][ MAXN ][ 4 ];

using celda = pair< long long, pair< pair<int, int>, int> >;

celda create_celda(long long distancia, int i, int j, int mask) {
    return make_pair(distancia, make_pair(make_pair(i, j), mask));
}

long long get_dist(const celda &x) {
    return x.first;
}
int get_col(const celda &x) {
    return x.second.first.second;
}
int get_row(const celda &x) {
    return x.second.first.first;
}
int get_mask(const celda &x) {
    return x.second.second;
}


void print(const celda &x, bool dev = false) {
    if (DEBUG == false) {
        return;
    }
    if (dev)
        cout << "    FROM ";

    cout << "==>> d:" << get_dist(x);
    cout << " row:" << get_row(x);
    cout << " col:" << get_col(x);
    cout << " mask:" << get_mask(x);
    cout << "\n";
}

void move_same_block(const int N, const int M, int ncol, int nrow, int nmask, long long nd, set<celda> &pq){
    int nlcol = ncol;
    int nlrow = nrow;
    int nlmask = nmask;
    long long nld = nd;
    
    // move lateral sobre el mismo bloque
    // sin tener que atravesar la calle
    // izq -> der o der->izq
    if (nmask & 1 || nmask == 0) {
        ncol += (nmask & 1)? 1:-1;
        nd += 2;
        nmask ^= 1;


        bool f = true;
        if (nrow < 0 || nrow >= N) f = false;
        if (ncol < 0 || ncol >= M) f = false;
        print(create_celda(nd, nrow, ncol, nmask), true);

        if (f && nd < dist[ nrow ][ ncol ][ nmask ]) {
            pq.erase(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));
            dist[ nrow ][ ncol ][ nmask ] = nd;
            pq.insert(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));

            // Ya te moviste sobre el bloque
            // trata de rodearlo completamente
            move_same_block(N, M, ncol, nrow, nmask, nd, pq);
        }
    }


    ncol = nlcol;
    nrow = nlrow;
    nmask = nlmask;
    nd = nld;
    
    // move vertical sobre el mismo bloque
    // sin tener que atravesar la calle
    // arriba -> abajo o abajo -> arriba
    if (nmask & 2 || nmask == 0) {
        nrow += (nmask & 2)? -1:1;
        nd += 2;
        nmask ^= 2;

        bool f = true;
        if (nrow < 0 || nrow >= N) f = false;
        if (ncol < 0 || ncol >= M) f = false;
        print(create_celda(nd, nrow, ncol, nmask), true);

        if (f && nd < dist[ nrow ][ ncol ][ nmask ]) {
            pq.erase(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));
            dist[ nrow ][ ncol ][ nmask ] = nd;
            pq.insert(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));

            // Ya te moviste sobre el bloque
            // trata de rodearlo completamente
            move_same_block(N, M, ncol, nrow, nmask, nd, pq);
        }
    }
}

int solve(const int N, const int M) {
    set<celda> pq;
    // Iniciar las distancias infinitas
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k <= 3; ++k) {
                dist[ i ][ j ][ k ] = INF;
            }
        }
    }

    pq.insert(create_celda(0, N-1, 0, 0));
    dist[N - 1][ 0 ][ 0 ] = 0;

    while (!pq.empty()) {
        celda x = *pq.begin();
        pq.erase(pq.begin());

        if (DEBUG)
            cout << "\n-------------------------------------------\n"
                 << "[HERE]"
                 << "\n-------------------------------------------\n";
        print(x);

        long long d   = get_dist(x);
        int row       = get_row(x);
        int col       = get_col(x);
        int mask      = get_mask(x);
        long long mod = S[ row ][ col ] + W[ row ][ col ];

        for (int i = 1; i <= 2; ++i) {

            int nmask    = mask ^ i;
            int nrow     = row;
            int ncol     = col;
            long long nd = d;

            long long r = (d - T[ row ][ col ]%mod + mod)%mod;
            

            if (i == 1) {
                // izq - der
                if (r >= S[ row ][ col ]) 
                    nd += 1;
                else {
                    nd += S[ row ][ col ] - r + 1;
                }
            } else {
                // arriba - abajo
                if (r < S[ row ][ col ]) {
                    nd += 1;
                } else {
                    nd += mod - r + 1;
                }
            }

            print(create_celda(nd, nrow, ncol, nmask), false);
            if (nd < dist[ nrow ][ ncol ][ nmask ]) {
                pq.erase(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));
                dist[ nrow ][ ncol ][ nmask ] = nd;
                pq.insert(create_celda(dist[ nrow ][ ncol ][ nmask ], nrow, ncol, nmask));
                
                // trata de rodear el bloque
                move_same_block(N, M, ncol, nrow, nmask, nd, pq);
            }
        }

    }

    return dist[ 0 ][M - 1][ 3 ];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.sol", "w", stdout);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> S[ i ][ j ]
                    >> W[ i ][ j ]
                    >> T[ i ][ j ];
            }
        }

        cout << "Case #" << caso << ": "
             << solve(n, m) << '\n';
    }
    return 0;
}

