class Solution
{
    public:
        vector <int> search(string pat, string txt) {
            //code here.
            vector<int>v;
            int n=txt.size(),m=pat.size();
            for(int i=0;i<n;i++){
                  string temp=txt.substr(i,m);
                  if(temp==pat){
                      v.push_back(i+1);
                  }
            }
            if(v.empty()) return  {-1};
            return v;
        }
     
};