// Question of IISC MTech admission 2022

// Image: https://i.ibb.co/g972MD9/download.png

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Input: 10 23, 20 25, 27 30, 32 40, 40 42
    // Answer: 3
    
    vector<pair<int, int>> loc;
    int start, end;
    cin >> start >> end;
    loc.push_back(make_pair(start, end));
    char ch;
    while (cin >> ch >> start >> end) {
        loc.push_back(make_pair(start, end));
    }
    sort(loc.begin(), loc.end());
    int result = 1;
    int curr_idx = 0;
    for (int i = 1; i < loc.size(); i++) {
        if (loc[curr_idx].second < loc[i].first) {
            result++;
            curr_idx = i;
        }
    }

    cout << result << endl;

    return 0;
}