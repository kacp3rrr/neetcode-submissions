class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // a stack for the queue of operands. we push the result
        // of the first operation into here, so that it then
        // becomes an operand for the second operation, and
        // so on
        stack<int> operand_queue;
        // iterate through the tokens, convert each entry to a 
        // num, and put it inside the operand queue. if the current
        // token is an operator, it pops the previous two entries
        // and pushes the result of that operation
        for (int i = 0; i < tokens.size(); ++i) {
            string curr = tokens[i];
            if (curr == "+" || curr == "-" 
            || curr == "*" || curr == "/") {
                // we assume valid arithmetic exprr, so no empty checks
                int second = operand_queue.top();
                operand_queue.pop();
                int first = operand_queue.top();
                operand_queue.pop();
                if (curr == "+") {
                    operand_queue.push(first + second);
                } else if (curr == "*") {
                    operand_queue.push(first * second);
                } else if (curr == "-") {
                    operand_queue.push(first - second);
                } else { // may need divide by zero check
                    operand_queue.push(first / second);
                }
            } else {
                int num = stoi(curr);
                operand_queue.push(num);
            }
        }
        return operand_queue.top();
    }
};
