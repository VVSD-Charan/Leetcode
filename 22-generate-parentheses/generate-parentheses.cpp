class Solution {

    void f(vector<string>&valids,string &res,int opens,int closed,int n)
    {
        if(opens > n || closed > n)return;
        if(opens == n && closed == n)
        {
            valids.push_back(res);
            return;
        }

        if(opens > closed)
        {
            res.push_back(')');
            f(valids,res,opens,closed+1,n);
            res.pop_back();
        }

        res.push_back('(');
        f(valids,res,opens+1,closed,n);
        res.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) 
    {
        string res = "(";
        vector<string>valids;

        f(valids,res,1,0,n);

        return valids;    
    }
};