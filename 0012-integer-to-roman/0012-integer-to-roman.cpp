class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int x=num;
        while(x>0){
            if(x>=1000){
                x=x-1000;
                ans+='M';
            }
            else if(x<1000 && x>=500){
                if(x>=900){
                    x=x-900;
                    ans+='C';
                    ans+='M';
                }
                else {
                    x=x-500;
                    ans+='D';
                }
            }
            else if(x<500 && x>=100){
                if(x>=400){
                    x=x-400;
                    ans+='C';
                    ans+='D';
                }
                else {
                    x=x-100;
                    ans+='C';
                }
            }
            else if(x<100 && x>=50){
                if(x>=90){
                    x=x-90;
                    ans+='X';
                    ans+='C';
                }
                else {
                    x=x-50;
                    ans+='L';
                }
            }
            else if(x<50 && x>=10){
                if(x>=40){
                    x=x-40;
                    ans+='X';
                    ans+='L';
                }
                else{
                    x=x-10;
                    ans+='X';
                }
            }
            else if(x<10 && x>=5){
                if(x>=9){
                    x=x-9;
                    ans+='I';
                    ans+='X';
                }
                else {
                    x=x-5;
                    ans+='V';
                }
            }
            else if(x<5 && x>=1){
                if(x>=4){
                    x=x-4;
                    ans+='I';
                    ans+='V';
                }
                else{
                    x=x-1;
                    ans+='I';
                }
            }
        }
        return ans;
    }
};