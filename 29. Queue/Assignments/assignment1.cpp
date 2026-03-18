/*
Question 1 : There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and 
the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy 
is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of 
the line (which happens instantaneously) inorder to buy more tickets. If a person does not have any tickets left to buy, 
the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

Examples : Input: tickets = [2,3,2], k = 2 Output: 6

Explanation: In 1st pass, everyone in the line buys a ticket and the line becomes[1,2, 1].
- In 2nd pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
*/

#include<iostream>
#include<queue>
using namespace std;

int timeForBuyTicket(int tickets[], int n, int k) {
    queue<pair<int, int>> q;

    // {tickets, index}
    for (int i=0; i<n; i++) {
        q.push({tickets[i], i});
    }

    int time = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        curr.first--; //buys 1 ticket
        time++;

        // if this is k and finished -> return
        if (curr.first == 0 && curr.second == k) {
            return time;
        }

        // if still has tickets -> go back
        if (curr.first > 0) {
            q.push(curr);
        }
    }

    return time;
}

int main() {
    int tickets[] = {2, 3, 2};
    int n = 3;
    int k = 2;
    
    cout << timeForBuyTicket(tickets, n, k) << " seconds" << endl;
    return 0;
}