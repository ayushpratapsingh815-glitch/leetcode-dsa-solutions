class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty() && q2.empty()) {
            q1.push(x);
        } else if(!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }
    
    int pop() {
        int tp = -1;
        if(!q1.empty()) {
            while(!q1.empty()) {
                tp = q1.front();
                q1.pop();
                if(q1.empty()) {
                    break;
                }
                q2.push(tp);
            }
        } else {
            while(!q2.empty()) {
                tp = q2.front();
                q2.pop();
                if(q2.empty()) {
                    break;
                }
                q1.push(tp);
            }
        }
        return tp;
    }
    
    int top() {
        int tp = -1;
        if(!q1.empty()) {
            while(!q1.empty()) {
                tp = q1.front();
                q2.push(tp);
                q1.pop();
            }
        } else {
            while(!q2.empty()) {
                tp = q2.front();
                q1.push(tp);
                q2.pop();
            }
        }
        return tp;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */