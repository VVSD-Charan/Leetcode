class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>s;

        for(int i = 0 ; i < asteroids.size() ; i++)
        {
            if(asteroids[i] > 0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                while(s.size() > 0 && s.top() > 0 && s.top() < abs(asteroids[i]))
                {
                    s.pop();
                }

                if(s.size() == 0 || s.top() < 0)
                {
                    s.push(asteroids[i]);
                }
                else if(s.top() == abs(asteroids[i]))
                {
                    s.pop();
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