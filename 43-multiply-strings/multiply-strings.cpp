class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1 == "0" || num2 == "0")return "0";

        vector<string>products;

        int max_length = 0;
        int curr = 0;

        for(int i = num1.length()-1 ; i >= 0 ; i-- )
        {
            string product = "";
            int remainder = 0;

            for(int j = num2.length()-1 ; j >= 0 ; j--)
            {
                int val = (num1[i]-'0')*(num2[j]-'0') + remainder;

                remainder = (val / 10);
                val = (val % 10);

                product.push_back(val + '0');
            }

            if(remainder > 0)
            {
                product.push_back(remainder + '0');
            }

             reverse(product.begin(),product.end());

            for(int j = 0 ; j < curr ; j++)
            {
                product.push_back('0');
            }

            reverse(product.begin(),product.end());

            max_length = max(max_length , (int)product.length());

            products.push_back(product);
            curr++;
        }

        string res_product = "";
        int reminder = 0;

        for(int i = 0 ; i < max_length ; i++)
        {
            int sum = reminder;

            for(int j = 0 ; j < products.size() ; j++)
            {
                if(i >= products[j].length())continue;

                sum += (products[j][i] - '0');
            }

            reminder = (sum / 10);
            sum = (sum % 10);

            res_product.push_back(sum + '0');
        }

        if(reminder > 0)res_product.push_back(reminder + '0');

        reverse(res_product.begin(),res_product.end());

        return res_product;
    }
};