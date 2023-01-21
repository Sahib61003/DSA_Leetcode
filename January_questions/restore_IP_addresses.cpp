// Problem: Restore IP Addresses
// Path: https://oj.leetcode.com/problems/restore-ip-addresses/

//Code: 

class Solution {
public:
    vector<string> ip;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if (s.size()<4)
            return res;
        dfs(0,s);
        return res;
    }
    void dfs(int n,string s){
        if (n==4){
            if (s.size()==0){
                string tmp = ip[0];
                for (int i=1;i<4;i++)
                    tmp = tmp + "." + ip[i];
                res.push_back(tmp);
            }
            return;
        }
        for (int i=1;i<=3;i++){
            if (s.size()<i)
                break;
            int val = atoi(s.substr(0,i).c_str());
            if (val>255 || i!=std::to_string(val).size())
                continue;
            ip.push_back(s.substr(0,i));
            dfs(n+1,s.substr(i));
            ip.pop_back();
        }
    }
};

/*Explanation of Code:

    1. Storing IP address and result in the vector
    2. Function to restore the IP address
    3. If the size of string is less than 4 then return empty vector
    4. Call the dfs function
    5. Function to find the IP address
    6. If the number of IP address is 4
    7. If the size of string is 0
    8. Store the first IP address in tmp
    9. Loop from 1 to 3
    10. Add the IP address to tmp
    11. Push the tmp in result vector
    12. Loop from 1 to 3
    13. If the size of string is less than i then break
    14. Convert the string to integer
    15. If the value is greater than 255 or the size of string is not equal to the size of integer then continue
    16. Push the IP address in IP vector
    17. Call the dfs function
    18. Pop the IP address from IP vector
*/

//Time Complexity: O(1)