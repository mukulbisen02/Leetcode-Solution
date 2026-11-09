class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (char c : s){
            if (stk.empty() || stk.top().first != c){
                stk.push({c, 1});
                continue;
            }
            
            if (stk.top().second < k-1){
                pair<char, int> p = stk.top();
                stk.pop();

                stk.push({p.first, p.second+1});
                continue;
            }

            stk.pop();
        }

        string answer;

        while(!stk.empty()){
            pair<char, int> p = stk.top();
            stk.pop();

            while (p.second--){
                answer.push_back(p.first);
            }
        }

        reverse (answer.begin(), answer.end());

        return answer;
    }
};