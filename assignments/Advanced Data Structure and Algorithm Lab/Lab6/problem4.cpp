class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(), S.end());
		    vector<string> result;
		    do {
		        result.push_back(S);
		    } while(next_permutation(S.begin(), S.end()));
		    return result;
		}
};