#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> // for string operations
#include <string> // for string operations
#include <unordered_set>
#include <unordered_map>

using namespace std;

void print_words(string str) {
    stringstream s(str);
    string word;
    while (s >> word) {
        cout << word << endl;
    }  
}

void print_letters(string str) {
    stringstream s(str);
    string word;
    while (s>>word) {
        auto it = word.begin();
        while (it != word.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
}

int word_count(string str) {
    int count = 0;
    stringstream s(str);
    string word;
    while (s>>word) {
        count++;
    }
    return count; 
}

void print_upper_case (string str) {
    int A='A', a='a', z='z';
    stringstream s(str);
    string word;
    vector <string> results;
    while (s>>word) {
        string temp_string = "";
        auto it = word.begin();
        while (it != word.end()) {
            if (*it>=a and *it<=z) {
                char temp_char = *it - (a - A);
                temp_string += temp_char;
                it++;
            }
            else {
                temp_string += *it;
                it++;
            }
        }
        results.push_back(temp_string);
    }

    for (int index = 0; index < results.size(); index++) {
        cout << results[index] << " ";
    }
    cout << endl;
}

void print_lower_case (string str) {
    int A='A', Z='Z', a='a';
    stringstream s(str);
    string word;
    vector <string> results;
    while (s>>word) {
        string temp_string="";
        auto it = word.begin();
        while (it != word.end()) {
            if (*it>=A and *it<=Z) {
                temp_string += *it + (a-A);
                it++;
            }
            else {
                temp_string += *it;
                it++;
            }
        }
        results.push_back(temp_string);
    }

    for (int index = 0; index < results.size(); index++) {
        cout << results[index] << " ";
    }
    cout << endl;
}

void unique_words (string str) {
    stringstream s(str);
    string word;
    unordered_set <string> words;
    while (s>>word) {
        if (words.find(word) != words.end()) {
            continue;
        }
        else {
            words.insert(word);
            cout << word << " ";
        }
    }
    cout << endl;
}

void count_frequency (string str) {
    unordered_map <string, int> frequency_counter;
    stringstream s(str);
    string word;
    while (s>>word) {
        if (frequency_counter.find(word) == frequency_counter.end()) {
            frequency_counter.insert(make_pair(word, 1));
        }
        else {
            frequency_counter[word] += 1;
        }
    }

    auto it = frequency_counter.begin();
    while (it != frequency_counter.end()) {
        cout << "[" << it->first << "] : " << it->second << endl;
        it++;
    }
}

int main() {
    string s = " My Name Is Debmalya Sur & My Country Name Is India ";
    print_words(s);
    print_letters(s);
    cout << "Number of words: " << word_count(s) << endl;
    print_upper_case(s);
    print_lower_case(s);
    unique_words(s);
    count_frequency(s);

    return 0;
}