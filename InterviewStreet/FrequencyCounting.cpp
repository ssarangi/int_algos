/*
Frequency Counting of Words / Top N words in a document.
 
Given N terms, your task is to find the k most frequent terms from given N terms.
 
Input format :
 
First line of input contains N, denoting the number of terms to add.
In each of the next N lines, each contains a term.
Next line contains k, most frequent terms.
 
Output format :
 
Print the k most frequent terms in descending order of their frequency. If two terms have same frequency print them in lexicographical order.
 
Sample input :
 
14
Fee
Fi
Fo
Fum
Fee
Fo
Fee 
Fee
Fo
Fi
Fi
Fo
Fum
Fee
3
 
Sample output :
 
Fee
Fo
Fi
 
Constraint :
0 < N < 300000 
0 < term length < 20.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

struct sort_pred
{
    bool operator()(const pair<string, int>& left,
                    const pair<string, int>& right)
    {
        return left.second > right.second;
    }
};

void readInput()
{
    map<string, int> strmap;
    int N, k;
    cin >> N;

    assert(N > 0 && N < 300000);

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        assert(str.length() > 0 && str.length() < 20);

        if (strmap.find(str) != strmap.end())
        {
            strmap[str] += 1;
        }
        else
        {
            strmap[str] = 0;
        }
    }

    cin >> k;

    vector< pair<string, int> > vp;
    // Convert to vector of pairs
    for (map<string, int>::iterator i = strmap.begin(); i != strmap.end(); ++i)
    {
        vp.push_back(make_pair(i->first, i->second));
    }

    strmap.clear();
    sort(vp.begin(), vp.end(), sort_pred());

    for (int i = 0; i < k; ++i)
        cout << vp[i].first << endl;
}

int main()
{
    readInput();
    return 0;
}