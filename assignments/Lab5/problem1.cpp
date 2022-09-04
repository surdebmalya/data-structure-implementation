class Solution {
private:
    struct Node {
        pair<char, int> node;
        vector<struct Node*> children;
    };
    struct Node* newNode(char val) {
        struct Node* temp = new Node();
        temp->node = make_pair(val, 1);
        return temp;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // making the trie
        struct Node* head=NULL, *curr=NULL;
        for(int i=0; i<strs.size(); i++) {
            if(strs[i]=="") return "";
            if(i==0) {
                for(int j=0; j<strs[0].size(); j++) {
                    struct Node* temp = newNode(strs[0][j]);
                    if(head==NULL) {
                        head=temp;
                        curr=head;
                    }
                    else {
                        (curr->children).push_back(temp);
                        curr = (curr->children)[(curr->children).size()-1];
                    }
                }
            }
            else {
                if((head->node).first == strs[i][0]) {
                    (head->node).second++;
                    curr=head;
                    for(int j=1; j<strs[i].size(); j++) {
                        bool flag=false;
                        for(int k=0; k<(curr->children).size(); k++) {
                            if((curr->children)[k]->node.first==strs[i][j]) {
                                (curr->children)[k]->node.second++;
                                curr = (curr->children)[k];
                                flag=true;
                                break;
                            }
                        }
                        if(flag==false) {
                            struct Node* temp = newNode(strs[i][j]);
                            (curr->children).push_back(temp);
                            curr = (curr->children)[(curr->children).size()-1];
                        }
                    }
                }
                else {
                    return "";
                }
            }
        }
        
        // finding out the longest common prefix
        int verify = strs.size();
        int count=1;
        string s;
        s.push_back((head->node).first);
        curr = head;
        while (true) {
            if((curr->children).size()==0) return s;
            
            bool flag=false;
            for(int i=0; i<(curr->children).size(); i++) {
                if((curr->children)[i]->node.second==verify) {
                    count++;
                    s.push_back((curr->children)[i]->node.first);
                    curr = (curr->children)[i];
                    flag=true;
                    break;
                }
            }
            if(flag==false) {
                return s;
            }
        }
    }
};