class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(size_t i=0; i<s.size();){
            string s1 = s.substr(i,1);
            string s2 = s.substr(i,2);

            if(R.count(s2)>0){
                sum += R[s2];
                i+=2;
            }else{
                sum += R[s1];
                i++;
            }
        }
        
        return sum;
    }
private:
    map<string, int> R = {
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},

            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
        };
};