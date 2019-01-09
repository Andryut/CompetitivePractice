#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solve(ll value, ll* a, int n){
    int start = 0, finish = n-1, mid;
    while(finish - start > 1) {
        mid = start + (finish - start)/2;
        if(a[mid] <= value) start = mid;
        else if(a[mid] > value) finish = mid;
    }
    if(a[finish] <= value) return finish + 1;
    else if(a[start] <= value) return start + 1;
    else return 0;
}

int main(){
    ll *a, b;
    int  *out, n, m;
    scanf("%i%i", &n, &m);
    a = new ll[n];
    out = new int[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < m; i++){
        cin >> b;
        out[i] = solve(b, a, n);
    }
    for(int i = 0; i < m; i++)
        printf("%i ", out[i]);
    printf("\n");
}
