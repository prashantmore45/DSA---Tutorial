/*
Question 4 : Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
beginWord -> s1 -> s2 -> ... -> sk such that: Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation 
sequence from beginWord to endWord, or 0 if no such sequence exists. 
*/


#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    // if endWord not present → impossible
    if(st.find(endWord) == st.end()) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);

    int level = 1;

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            string word = q.front();
            q.pop();

            // reached target
            if(word == endWord) {
                return level;
            }

            // try all transformations
            for(int j = 0; j < word.length(); j++) {
                char original = word[j];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[j] = ch;

                    if(st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word); // mark visited
                    }
                }

                word[j] = original; // restore
            }
        }

        level++;
    }

    return 0;
}


int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList);
}