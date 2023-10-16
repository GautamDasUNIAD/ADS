#include <vector>
#include <queue>
#include <iostream>

int kth_largest(std::vector<int> values, int k){
    // intialize a priority que variable
    std::priority_queue<int> pq;
    // add all the values to priority que
    for (int i = 0; i < values.size(); i++) {
        pq.push(values[i]);
    }
    // if k is greater than 1, pop top k-1 elements and then return the top
    if (k != 1){
        for (int j = 0; j < k-1;j++){
            pq.pop();
        }
    }
    // return the top element
    return pq.top();
}
