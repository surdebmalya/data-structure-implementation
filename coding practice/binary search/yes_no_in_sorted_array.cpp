// https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true

// Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>v;
    while(n){
        n--;
        int num;
        cin >> num;
        v.push_back(num);
    }
    int q;
    cin >>q;
    while (q) {
        q--;
        int number;
        cin >> number;
        int start=0, end=v.size();
        int mid;
        while (start<=end) {
            mid = ( start + end ) / 2;
            if (v[mid]==number){
                if (mid!=0 and v[mid-1]==number){
                    end = mid-1;
                }
                else {
                    cout<<"Yes "<<mid + 1<<endl;
                    break; 
                }
            }
            else if(v[mid]>number) {
                end = mid-1;
            }
            else {
                start = mid +1;
            }
        }
        if (start>end)
            cout << "No "<<start + 1<<endl;
    }
    
    return 0;
}
