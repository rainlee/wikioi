#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
    return;
}

// first, reverse whole sentence
// second, reverse each word
int main()
{
    string sent;
    
    while (getline(cin, sent))
    {
        for (int i = 0; i < sent.size()/2; ++i)
            swap(sent[i], sent[sent.size() - i - 1]);
        //cout << sent << endl;
        int start = 0;
        int end = 0;
        while (start < sent.size())
        {
            end = sent.find(' ', start);
            if (end == string::npos)
                end = sent.size();
            //cout << "end = " << end << endl;
            int mid = (start + end) / 2;
            for (int j = start; j < mid; ++j)
                swap(sent[j], sent[end - 1 - (j - start)]);
            //cout << sent << endl;
            start = end + 1;
        }
        
        cout << sent << endl;
    }
    return 0;
}