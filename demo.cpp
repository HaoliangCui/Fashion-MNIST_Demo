#include <iostream>  
#include <cstdlib>  
#include <ctime>  
#include <vector>  
  
using namespace std;  
  
typedef vector<int> IntVec;  
typedef typename IntVec::iterator Iter;  
typedef typename IntVec::const_iterator Const_Iter;  
  
// generate a random number between i and k,  
// both i and k are inclusive.  
int randint(int i, int k)  
{  
    if (i > k)  
    {  
        int t = i; i = k; k = t; // swap  
    }  
    int ret = i + rand() % (k - i + 1);  
    return ret;  
}  
  
// take m samples to result from input of n items.  
bool reservoir_sampling(const IntVec &input, IntVec &result, int m)  
{  
    srand(time(NULL));  
    if (input.size() < m)  
        return false;  
  
    result.resize(m);  
    Const_Iter iter = input.begin();  
    for (int i = 0; i != m; ++i)  
        result[i] = *iter++;  
  
    for (int i = m; iter != input.end(); ++i, ++iter)  
    {  
        int j = randint(0, i);  
        if (j < m)  
            result[j] = *iter;  
    }  
    return true;  
}  
  
int main()  
{  
    const int n = 20000000;  
    const int m = 1000;  
    IntVec input(n), result(m);  
  
    for (int i = 0; i != n; ++i)  
        input[i] = i;  
    if (reservoir_sampling(input, result, m))  
        for (int i = 0; i != m; ++i)  
            cout << result[i] << " ";  
    cout << endl;  
    return 0;  
}  
