class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!(s == "")){
        bool diff = false;
        string current = "";
        string longest = "";
        int j = 1;
         if (s.length() == 1){
            return 1;
        } 
        for(int i = 0; i<s.length()-1; ++i){
            current = s[i];
            j = 1;
            diff = true;
            do{
                if(static_cast<int>(s[i+j]) != 0){
                    if(current.find(s[i+j]) != std::string::npos){
                        diff = false;
                    } else{
                        current += s[i+j];
                        ++j;
                    }
                } else {diff = false;}
            } while(diff);
            if(longest.length() < current.length()){
                longest = current;
            }
        }
        return longest.length();
        } else {
            return 0;
        }
    }
};

/*
Stats

Runtime: 74ms
Beats 12.27% of users with C++
Memory: 7.27 MB
Beats 93.90% of users with C++
*/
