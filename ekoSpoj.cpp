#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    int n;
    ll m, element, best = LLONG_MAX, out = 0;
    scanf("%i%lld", &n, &m);
    //ll* the_heights = (ll*) malloc(1000001);
    set<ll> the_set;
    ll* the_heights = new ll[1000001];
    for(int i = 0; i < 1000001; i++) the_heights[i] = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &element);
        ++the_heights[element];
        the_set.insert(element);
    }
    int set_size = the_set.size();
    ll* ordered = new ll[set_size];
    set<ll>::reverse_iterator reverse_it = ++the_set.rend();
    for (int i = 0; i < set_size; i++) ordered[i] = *(reverse_it++);
    ll first = 0, last = *ordered, mid;
    while (first <= last) {
        element = 0;
        mid = first + (last - first)/2;
        for (int i = 0; ordered[i] > mid && i < set_size; i++)
            element += (ordered[i] - mid) * (the_heights[ordered[i]]);
        if (element > m) {
            first = mid + 1;
            if (element < best){
                out = mid;
                best = element;
            }
        } else if (element < m) {
            last = mid - 1;
        } else {
            out = mid;
            break;
        }
    }
    printf("%lld\n", out);
}
