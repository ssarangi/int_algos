/*
Given an unordered list of N elements, write a function to find the top four elements of the given list. Make sure your function runs in linear time O(N).
 
Input format :
 
First line of input contains N , number of elements in list.
Next N line , each contains a element.
 
Output format :
 
Print the top four elements of list.
 
Sample input :
 
8
6930886
-1692777
4636915
7747793
-4238335
9885386
9760492
6516649
 
Sample ouput :
 
9885386
9760492
7747793
6930886
 
Constraint :
 
N < 1000000.
all numbers will fit  in 32-bit integer.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <cstring>
#include <limits.h>
#include <cstdlib>

using namespace std;

class TopFour
{
    unsigned char* m_pTracker;
    unsigned char* m_pNegTracker;
    vector<int> m_numList;
    int   m_maxElement;
    int   m_minElement;

    bool maxint;
    bool minint;

public:
    TopFour()
    {
        m_maxElement = -INT_MAX;
        m_minElement = INT_MAX;
        maxint = false;
        minint = false;
    }

    ~TopFour() 
    {
        delete [] m_pTracker;
        delete [] m_pNegTracker;
    }
    
    void readInput()
    {
        int totalNum;
        cin >> totalNum;

        for (int i = 0; i < totalNum; ++i)
        {
            int number;
            cin >> number;

            if (number == INT_MAX)
                maxint = true;
            else if (number == -INT_MAX)
                minint = true;
            else
            {
                m_maxElement = max(m_maxElement, number);
                m_minElement = min(m_minElement, number);
                m_numList.push_back(number);
            }
        }

        int posArrSize = m_maxElement / 8 + 1;
        int negArrSize = abs(m_minElement) / 8 + 1;
        m_pTracker = new unsigned char[posArrSize];
        m_pNegTracker = new unsigned char[negArrSize];
        memset(m_pTracker, 0, sizeof(unsigned char) * posArrSize);
        memset(m_pNegTracker, 0, sizeof(unsigned char) * negArrSize);

        for (int i = 0; i < m_numList.size(); ++i)
        {
            int num = abs(m_numList[i]);
            int arrIndex = num / 8;
            int shift = num - (arrIndex * 8);
            if (m_numList[i] < 0)
                m_pNegTracker[arrIndex] |= 1 << shift;
            else
                m_pTracker[arrIndex] |= 1 << shift;
        }
    }

    vector<int> analyze(int topNums)
    {
        vector<int> topFour;

        if (maxint == true)
            topFour.push_back(INT_MAX);

        int i = m_maxElement;
        while (topFour.size() < topNums && i >= m_minElement)
        {
            int arrIndex = abs(i) / 8;

            int shift = abs(i) - (arrIndex * 8);
            bool add = false;
            if (i >= 0)
                if ((m_pTracker[arrIndex] & (1 << shift)) > 0)
                    add = true;

            if (i < 0)
                if ((m_pNegTracker[arrIndex] & (1 << shift)) > 0)
                    add = true;

            if (add)
                topFour.push_back(i);

            --i;
        }

        if (topFour.size() < topNums)
            if (minint == true)
                topFour.push_back(-INT_MAX);

        return topFour;
    }
};


int main(void)
{
    TopFour tf;
    tf.readInput();
    vector<int> topFour = tf.analyze(4);
    for (int i = 0; i < topFour.size(); ++i)
        cout << topFour[i] << endl;
}