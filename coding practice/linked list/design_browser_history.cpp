// https://leetcode.com/problems/design-browser-history/

// Medium

class BrowserHistory {
private:
    struct Node {
        struct Node *prev;
        string url;
        struct Node *next;
    };
    struct Node *newNode(string newInput) {
        struct Node *temp = new Node();
        temp->prev = NULL;
        temp->next = NULL;
        temp->url = newInput;
        return temp;
    }
    struct Node *curr = NULL;

public:
    BrowserHistory(string homepage) {
        struct Node *root = newNode(homepage);
        curr = root;
    }

    void visit(string url) {
        struct Node *temp = newNode(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    string back(int steps) {
        while (steps > 0 and curr->prev != NULL) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (steps > 0 and curr->next != NULL) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};