#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int findIslands(int A[MAX][MAX], int N, int M);

int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--){
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

bool coordinateIn(pair <int, int> point, int N, int M) {
    return point.first >= 0 && point.first <= N && point.second >= 0 && point.second <= M;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int findIslands(int A[MAX][MAX], int N, int M){
    int islands = 0, value;
    pair<int, int> coordinate;
    stack <pair <int, int>> s;
    for(int i = 0; i < N*M; i++){
            if (A[i/M][i%M] == 1) islands++;
            s.push(pair <int, int> (i/M, i%M));
            while(!s.empty()) {
                coordinate = s.top();
                value = coordinateIn(coordinate, N, M) ? A[coordinate.first][coordinate.second] : 2;
                s.pop();
                if (value == 1)
                    for (int i = 0; i < 9; i++)
                        if (i != 4)
                            s.push(pair<int, int> (coordinate.first + i/3 -1, coordinate.second + i%3 -1));
                if (value == 0 || value == 1)
                    A[coordinate.first][coordinate.second] = 2;
            }
    }
    return islands;
}
