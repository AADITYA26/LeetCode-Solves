class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0 ;
        double prevupper = 0;
        for(int i = 0 ; i < brackets.size() ; i++){
            double upper = brackets[i][0];
            double percent = brackets[i][1];
            if(income > prevupper){
                if(income > upper)tax+=(upper-prevupper)*percent/100;
                else {
                    tax+=(income-prevupper)*percent/100;
                    break;
                }
            }
            prevupper = upper;
        }
        return tax;
    }
};