class Solution {
public:
    string defangIPaddr(string address) {
        string add="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                add+="[.]";
            }
            else add+=address[i];
        }
        return add;
    }
};