class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size());
        // monotonic stack of indexes in temperatures. we pop when the current days temperature is
        // hotter than the top of the stack, and continually pop until we either reach the bottom or
        // reach a day with a hotter temperature. at each pop, update the output for day x as
        // current index - x
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            if (st.empty()) {
                st.push(0);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    int index = st.top();
                    st.pop();
                    output[index] = i - index;
                }
                st.push(i);
            }
        }
        return output;
    }
};
