class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        double required = ((double)arr.size() /(double)4);
    
        int i = 0;
        int j = 0;

        while(i < arr.size() && j < arr.size())
        {
           while(j < arr.size() && arr[i] == arr[j])
           {
               j++;
           }

           double num_elements = j-i;

           if(num_elements > required)
           {
               return arr[i];
           }
           i=j;
        }    

        return arr.back();
    }
};