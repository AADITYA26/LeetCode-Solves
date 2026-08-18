class Solution {
public:
    int maxConsecutiveAnswers(string answerkey, int k) {
        int ans = 0 ;
        int count = 0 ;
        int left = 0 ;
        int right = 0;
        //T
        while(right < answerkey.size()){
            if(answerkey[right] == 'T')count++;
            while(count > k){
                if(answerkey[left]=='T')count--;
                left++;
            }
            ans = max(ans , right -left +1);
            right ++;
        }
        count = 0;
        left = 0;
        right = 0;
        //F
        while(right < answerkey.size()){
            if(answerkey[right] == 'F')count++;
            while(count > k){
                if(answerkey[left]=='F')count--;
                left++;
            }
            ans = max(ans , right -left +1);
            right ++;
        }
        return ans;
    }
};