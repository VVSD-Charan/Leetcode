class Solution {

    void getProduct(char ch,string &s,vector<int>&temp)
    {
        int carry = 0;

        for(int i = s.length()-1 ; i >= 0 ; i--)
        {
            int product = (s[i] - '0')*(ch - '0') + carry;
            
            temp.push_back(product % 10);
            carry = (product / 10);
        }

        if(carry > 0)temp.push_back(carry);
    }

public:
    string multiply(string num1, string num2) 
    {
        if(num2.length() > num1.length())return multiply(num2,num1);

        //Get individual products
        vector<vector<int>>arr;
        int zeroes = num2.length()-1;
        for(int i = 0 ; i < num2.length() ; i++)
        {
            if(num2[i] == '0'){
                zeroes = zeroes - 1;
                continue;
            }

            vector<int>temp;
            for(int j = 1 ; j <= zeroes ; j++)temp.push_back(0);
            getProduct(num2[i],num1,temp);
            arr.push_back(temp);

            zeroes = zeroes - 1;
        }    

        // Store sum of individual products into string
        string res = "";
        int carry = 0;
        int max_len = 0;

        for(int i = 0 ; i < arr.size() ; i++){
            max_len = max(max_len,(int)arr[i].size());
        }

        for(int i = 0 ; i < max_len ; i++){
            int sum = carry;
            for(int j = 0 ; j < arr.size() ; j++){
                if(arr[j].size() <= i)continue;
                sum = sum + arr[j][i];
            }
            res.push_back((sum % 10)+'0');
            carry = (sum / 10);
        }

        if(carry > 0)res.push_back(carry+'0');
        if(res.length() == 0)return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};