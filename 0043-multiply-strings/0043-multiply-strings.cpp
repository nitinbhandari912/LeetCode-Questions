class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += (sum % 10) + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<string> vec;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            string sum1 = "";
            carry = 0; 
            for (int j = num2.size() - 1; j >= 0; j--) {
                int digit = num2[j] - '0';
                int digit1 = num1[i] - '0';
                int product = digit * digit1;
                int sum = product + carry;
                sum1 += (sum % 10) + '0';
                carry = sum / 10;
            }
            if (carry > 0) {
                sum1 += (carry + '0');
            }
            reverse(sum1.begin(), sum1.end());
            int trailing_zeros = (num1.size() - 1) - i;
            for (int z = 0; z < trailing_zeros; z++) {
                sum1 += '0';
            }
            vec.push_back(sum1);
        }
        string totalsum = "0";
        for (int i = 0; i < vec.size(); i++) {
            totalsum = addStrings(totalsum, vec[i]);
        }
        return totalsum;
    }
};