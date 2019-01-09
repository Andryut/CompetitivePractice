#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> the_vector, int value){
    int start = 0, finish = the_vector.size() - 1, mid;
    while(finish - start > 1) {
        mid = start + (finish - start)/2;
        if(the_vector[mid] < value)
            start = mid;
        else if(the_vector[mid] > value)
            finish = mid;
        else{
            while(mid < the_vector.size() && the_vector[mid] == value) mid++;
            return mid;
        }
    }
    if(the_vector[finish] <= value){
        while(finish < the_vector.size() && the_vector[finish] <= value) finish++;
        return finish;
    }else if(the_vector[start] <= value) return start + 1;
    else return 0;
}

int main(){
    vector<int> fighters;
    int input, bishu_power, power, sol, sum;
    scanf("%i", &input);
    for(int i = 0; i < input; i++){
        scanf("%i", &power);
        fighters.push_back(power);
    }
    sort(fighters.begin(), fighters.end());
    scanf("%i", &input);
    for(int i = 0; i < input; i++){
        scanf("%i", &bishu_power);
        sol = bs(fighters, bishu_power);
        sum = 0;
        for(int i = 0; i<sol; i++)
            sum += fighters[i];
        printf("%i %i\n", sol, sum);
    }
}
