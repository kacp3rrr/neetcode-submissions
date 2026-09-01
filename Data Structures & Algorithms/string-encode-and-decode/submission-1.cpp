class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        string length_values = "";
        // put the number n of strings in the beginning, so that
        // the numbers appended at the end, the lengths of each of the
        // n strings
        output += to_string(strs.size()) + "|";
        for (string s : strs) {
            output += s;
            length_values = "|" + to_string(s.size()) + length_values;
        }
        output += length_values;
        cout << output;
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        // extract the number of strings
        int number_of_strs = stoi(s.substr(0, s.find_first_of('|')));
        s = s.substr(s.find_first_of('|') + 1);
        // extract each string based on the length appended to the end of the encoded string
        while (output.size() < number_of_strs) {
            int current_string_size = stoi(s.substr(s.find_last_of('|') + 1));
            string curr = s.substr(0, current_string_size);
            output.push_back(curr);
            // trim the string from both ends
            s = s.substr(current_string_size);
            s = s.substr(0, s.find_last_of('|'));
        }
        return output;
    }
};
