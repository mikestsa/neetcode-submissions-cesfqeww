class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens){
            if (token == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = a + b;
                s.push(res);
            }
            else if (token == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res =  b - a;
                s.push(res);

            }
            else if (token == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = a * b;
                s.push(res);
                
            }
            else if (token == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res =  b / a;
                s.push(res);
                
            }
            else{
                int num = stoi(token);
                s.push(num);
            }
        }
        return s.top();

        
    }
};
