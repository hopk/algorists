//COJ: 1647 - Fire

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int R, C;
char line[ 1000 ];
int  mov[ ][ 2 ] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
char G[ 1005 ][ 1005 ];
int  D1[ 1005 ][ 1005 ];
int  D2[ 1005 ][ 1005 ];

vector < pair<int,int> > F;
queue < pair<int,int> > Q;
void bfs1( int xx, int yy ){

    memset( D1, -1, sizeof(D1) );

    D1[ xx ][ yy ] = 0;
    Q.push( mp(xx,yy) );

    while ( !Q.empty() ){
        int x = Q.front().first;
        int y = Q.front().second;
        int w = D1[ x ][ y ];
        Q.pop();

        for ( int i=0; i < 4; i++ ){
            int nx = x + mov[ i ][ 0 ];
            int ny = y + mov[ i ][ 1 ];
        
            if ( nx < 0 || nx  >= R ) continue;
            if ( ny < 0 || ny  >= C ) continue;
            if ( G[nx][ny] == '#' ) continue;
            if ( G[nx][ny] == 'F' ) continue;
            if ( D1[nx][ny] != -1  ) continue;

            if ( D2[nx][ny] > w+1 || D2[nx][ny]==-1 ){
                D1[nx][ny] = w +1;
                Q.push( mp(nx,ny) );
            }
        }
    }
}

void bfs2(  ){

    memset( D2, -1, sizeof(D2) );

    for ( int i =0; i< F.size(); i++ ){
        int xx = F[i].first;
        int yy = F[i].second;
        D2[ xx ][ yy ] = 0;
        Q.push( mp(xx,yy) );
    }

    while ( !Q.empty() ){
        int x = Q.front().first;
        int y = Q.front().second;
        int w = D2[ x ][ y ];
        Q.pop();

        for ( int i=0; i < 4; i++ ){
            int nx = x + mov[ i ][ 0 ];
            int ny = y + mov[ i ][ 1 ];
        
            if ( nx < 0 || nx  >= R ) continue;
            if ( ny < 0 || ny  >= C ) continue;
            if ( G[nx][ny] == '#' ) continue;
            if ( G[nx][ny] == 'J' ) continue;
            if ( D2[nx][ny] != -1 ) continue;

            D2[nx][ny] = w +1;
            Q.push( mp(nx,ny) );
        }
    }
}

main(){

    sscanf( gets(line), "%d %d", &R, &C );
    int Jx=-1, Jy=-1;
    int Fx, Fy;

    for ( int i=0; i < R; i++ ){
        gets( G[ i ] );
        for (  int j =0; j < C; j++ ){
            if ( G[ i ][ j ] == 'J' ){
                Jx = i;
                Jy = j;
            }else if ( G[ i ][ j ] == 'F' ){
                F.push_back( mp(i,j) );
            }
        }
    }

    bfs2(  );
    if ( Jx!=-1 && Jy!=-1 ) bfs1( Jx, Jy );

    bool ban = false;
    int mini = 1<<20;

    for ( int i = 0; i < R; i++ ){
        if ( D1[i][ 0 ] != -1 ){
                mini = min( D1[i][0], mini );
                ban = true;
            }

        if ( D1[i][ C-1 ] != -1 ){
                mini = min( D1[i][ C-1 ], mini );
                ban = true;
            }    
    }


    for ( int i = 0 ; i < C; i++ ){
        if ( D1[ 0 ][ i ] != -1 ){
                mini = min( D1[0][i], mini );
                ban = true;
            }

        if ( D1[ R-1 ][i] != -1 ){
                mini = min( D1[ R-1 ][i], mini );
                ban = true;
            }    
    }

    if ( ban )  printf("%d\n", mini+1);
    else printf("IMPOSSIBLE\n");

    return 0;
}
