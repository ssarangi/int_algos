#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

string charToStr(char c)
{
    string op = string(&c);
    return op;
}

vector<string> Permute(string inp)
{
    vector<string> op;
    char fstr = inp[0];

    if (inp.length() == 2)
    {
        op.push_back(inp);
        string S = charToStr(inp[1]) + charToStr(inp[0]);
        op.push_back(S);
        return op;
    }

    vector<string> permutations = Permute(inp.substr(1, inp.size() - 1));

    for (unsigned int j = 0; j < permutations.size(); ++j)
    {
        string tempStr = fstr + permutations[j];
        op.push_back(tempStr);

        for (unsigned int i = 1; i < inp.size(); ++i)
        {
            string str = tempStr;
            char tstr = str[0];
            str[0] = str[i];
            str[i] = tstr;
            op.push_back(str);
        }
    }

    return op;
}

vector<string> Combinations(string inp, int r)
{
    vector<string> op;

    if (r == 1)
    {
        for (unsigned int i = 0; i < inp.length(); ++i)
        {
            string t = charToStr(inp[i]);
            op.push_back(t);
        }

        return op;
    }

    for (unsigned int i = 0; i < inp.length(); ++i)
    {
        string t = charToStr(inp[i]);
        vector<string> comb = Combinations(inp.substr(i+1, inp.length() - 1), r - 1);

        for (unsigned int j = 0; j < comb.size(); ++j)
        {
            string S = t + comb[j];
            op.push_back(S);
        }
    }

    return op;
}

int main()
{
    string inpString;
    int r;
    cout << "Enter String: ";
    cin >> inpString;
    cout << "Combinations(r from nCr): ";
    cin >> r;

    vector<string> permutations = Permute(inpString);
    vector<string> combinations = Combinations(inpString, r);
    cout << "Permutations: " << permutations.size() << endl << endl;
    copy(permutations.begin(), permutations.end(), ostream_iterator<string>(cout, "\n"));

    cout << "Combinations: " << combinations.size() << endl << endl;
    copy(combinations.begin(), combinations.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
