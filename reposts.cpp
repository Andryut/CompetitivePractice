#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, path = 1;
    string stdIn;
    string* data;
    map <string, int> theMap;
    theMap["polycarp"] = 1;
    scanf("%i", &n);
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, stdIn);
        stringstream ssin(stdIn);
        data = new string[3];
        for(int i = 0; i < 3; i++)
            ssin >> data[i];
        transform(data[0].begin(), data[0].end(), data[0].begin(), ::tolower);
        transform(data[2].begin(), data[2].end(), data[2].begin(), ::tolower);
        theMap[data[0]] = theMap[data[2]] + 1;
        if(theMap[data[0]] > path) path = theMap[data[0]];
    }
    printf("%i\n", path);
}
