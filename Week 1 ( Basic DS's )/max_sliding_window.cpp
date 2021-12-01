#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;
void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}
vector<int> max_sliding_window(const vector<int> &A, int B) {
    
    vector<int> v;
    deque<int> dq;
        
    for(auto i=0; i<A.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-B)
            dq.pop_front();
        
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
        
        if(i >= B-1) {
            v.push_back(A[dq.front()]);

            cout<<A[dq.front()]<<" ";
        }

    }
    
    return v;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}