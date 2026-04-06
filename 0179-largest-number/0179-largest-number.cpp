class Solution {
public:
    static bool compare(string a, string b){
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // convert int to string
        for(int num : nums){
            arr.push_back(to_string(num));
        }

        // sort using custom comparator
        sort(arr.begin(), arr.end(), compare);

        // edge case: if largest is "0"
        if(arr[0] == "0") return "0";

        // build result
        string result = "";
        for(string s : arr){
            result += s;
        }

        return result;
    }
};