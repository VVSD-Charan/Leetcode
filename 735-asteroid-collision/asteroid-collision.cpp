class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>s;


        for(auto it : asteroids)
        {
            if(it > 0)
            {
                s.push(it);
            }
            else
            {
                while(s.size() > 0 && s.top() > 0 && s.top() < abs(it))
                {
                    s.pop();
                }

                if(s.size() > 0 && s.top() == abs(it))
                {
                    s.pop();
                }
                else if((s.size() > 0 && s.top() < 0) || (s.size() == 0))
                {
                    s.push(it);
                }
            }
        }

        vector<int>arr;

        while(s.size() > 0)
        {
            arr.push_back(s.top());
            s.pop();
        }    

        reverse(arr.begin(),arr.end());
        return arr;
    }
};