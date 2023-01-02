class Solution {
public:
    bool all_caps(string word) {
        for(int i=1; i<word.size(); i++) {
            if(word[i]>='A' and word[i]<='Z') continue;
            else return false;
        }
        return true;
    }

    bool all_smalls(string word) {
        for(int i=1; i<word.size(); i++) {
            if(word[i]>='a' and word[i]<='z') continue;
            else return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if(word[0]>='A' and word[0]<='Z') return all_caps(word) or all_smalls(word);
        else return all_smalls(word);
    }
};