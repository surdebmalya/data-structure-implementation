// https://leetcode.com/problems/prefix-and-suffix-search/

// Hard

class WordFilter {
private:
    unordered_map<string, int> m; // perfix+'|'+suffix, index
public:
    WordFilter(vector<string> &words) {
        // Key note:
        // word length => minimum 1 and maximum 10
        // same for the prefix & suffix length
        // If there is more than one valid index, return "the largest index"
        // else return -1
        for (int i = 0; i < words.size(); i++) {
            string currWord = words[i];
            for (int prefixIndex = 0; prefixIndex < currWord.size(); prefixIndex++) {
                string prefix = currWord.substr(0, prefixIndex + 1);
                for (int suffixIndex = currWord.size() - 1; suffixIndex >= 0; suffixIndex--) {
                    string suffix = currWord.substr(suffixIndex, currWord.size() - suffixIndex);
                    m[prefix + '|' + suffix] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string key = prefix + '|' + suffix;
        if (m.find(key) != m.end())
            return m[key];
        return -1;
    }
};