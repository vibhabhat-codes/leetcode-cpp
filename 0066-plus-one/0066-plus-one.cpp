class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {

            digits[i]++;

            // If no carry, return immediately
            if (digits[i] < 10)
                return digits;

            // Else make it 0 and continue carry
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};