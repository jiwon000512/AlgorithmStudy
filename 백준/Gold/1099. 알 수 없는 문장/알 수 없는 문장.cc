#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX 999999

using namespace std;

string targetWord;
int n;
vector<string> words;
vector<int> dp;
vector<vector<int>> checkDP(51,vector<int>(51, -1));
int minSize = 51;


int getValue(int wordIndex, int startIndex)
{
    int& value = checkDP[wordIndex][startIndex];
    if(value != -1) return value;
    
    string word = words[wordIndex];
    if(startIndex + word.size() > targetWord.size()) return value = MAX;
    
    value = 0;
    vector<int> alpha(26);
    for (int i = 0; i < word.size(); i++)
    {
        int a = word[i] - 'a';
        int b = targetWord[startIndex + i] - 'a';
        
        
        alpha[a]++;
        alpha[b]--;
        if(a != b) value++;
    }
    
    for(int i=0; i<26; i++)
        if(alpha[i] != 0) return value = MAX;
        
    return value;
}

int solve(int index)
{
    if(index >= targetWord.size()) return 0;
    int& value = dp[index];
    if(value != -1) return value;
    
    value = MAX;
    for(int i=0; i<words.size(); i++)
    {
        int cost = getValue(i, index);
        if(cost != MAX) value = min(value, cost + solve(index + words[i].size()));
    }
    return value;
}

int main()
{
    cin >> targetWord >> n;
    dp.resize(targetWord.size() + 1);
    fill(dp.begin(), dp.end(), -1);

    while (n--)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);

        if (tmp.size() < minSize)
            minSize = tmp.size();
    }
    int answer = solve(0);
    if(answer == MAX)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
}