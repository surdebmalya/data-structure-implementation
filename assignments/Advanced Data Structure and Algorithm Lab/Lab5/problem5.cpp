class LRUCache
{
    unordered_map <int, int> m, cnt;
    queue <int> q;
    int n;
public:
    LRUCache(int capacity) {n=capacity;}
    int get(int key) {
        if (cnt.find(key) == cnt.end()) 
            return -1;
        q.push(key);
        cnt[key]++;
        return m[key];
    }
    void put(int key, int value) {
        q.push(key);
        cnt[key]++;
        m[key] = value;
        while (cnt.size() > n) {
            int cur = q.front(); q.pop();
            if (cnt[cur]-- == 1) 
                cnt.erase(cur);
        }
    }
};