#include <iostream>

using namespace std;

int main() {
    bool** matrix;
	int n, m, a, b, q;
	scanf("%i%i", &n, &m);
	matrix = new bool* [n];
	for (int i = 0; i < n; i++) matrix[i] = new bool[n];
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	        matrix[i][j] = 0;
	for (int i = 0; i < m; i++) {
	    scanf("%i%i", &a, &b);
	    matrix[a - 1][b - 1] = 1;
	    matrix[b - 1][a - 1] = 1;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
	    scanf("%i%i", &a, &b);
	    matrix[a - 1][b - 1] ? printf("YES\n") : printf("NO\n");
	}

}
