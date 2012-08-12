#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<long> readInput(long& product, long& nonZero)
{
    bool zeroEncountered = false;
    product = 1;
    nonZero = 1;
    vector<long> numList;
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        long num;
        cin >> num;
        numList.push_back(num);
        product *= num;
        if (num != 0)
            nonZero *= num;
        else if (num == 0 && zeroEncountered == false)
            zeroEncountered = true;
        else if (num == 0 && zeroEncountered == true)
            nonZero = 0;
    }

    return numList;
}

vector<long> MultiplyExceptSelf(const vector<long>& numList, const long product, const long nonZero)
{
    vector<long> op;
    for (int i = 0; i < numList.size(); ++i)
    {
        if (numList[i] == 0)
            op.push_back(nonZero);
        else if (product == 0)
            op.push_back(0);
        else
            op.push_back((long)(product / (long)(numList[i])));
    }

    return op;
}

int main()
{
    long product = 1;
    long nonZero = 1;
    vector<long> inp = readInput(product, nonZero);
    vector<long> op  = MultiplyExceptSelf(inp, product, nonZero);
    copy(op.begin(), op.end(), ostream_iterator<long>(cout, "\n"));
    return 0;
}

