//9. Palindrome Number
//NEED TO TRY AN UPDATED VERSION


class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<char> charArray;
        std::string string = std::to_string(x);
        
        for(int i = 0; i < string.length(); ++i){
            charArray.insert(charArray.begin(), string[i]);
        }
        std::string str(charArray.begin(), charArray.end());

        
        if(str == string){
            return true;
        } else {
            return false;
        }
    }
};

/*
Stats

Runtime: 23ms
Beats 5.06% of users with C++
Memory: 8.95 MB
Beats 5.46% of users with C++
*/
