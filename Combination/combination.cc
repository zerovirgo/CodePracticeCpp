#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void printDigi(int num)
{
    bitset<sizeof(num) * 8 > s(num);
    cout << num  << " = " << s << endl ;
}

int sum(vector<int> nums)
{
    int sum = 0; 
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        sum += *it ;
    }
    return sum ;
}

void comb(/*vector<vector< int > > intLists, */
vector<int> ints , int total, int steps, int step = 0, int loc = 0,int prev = 0,int nit = 0)
{
    if (total < loc || total < steps ) 
    {
        cout << "Error inputs" << endl ;
        return ;
    }
    if (loc == total)
    {
        printDigi(step);
        return ;
    }
    for (int i = loc; i < total - step ; i++)
    {
        if(step>0)
        {
            ints.push_back( (1 << i ));
            comb(ints, total, steps, step-1, i + 1, prev,nit++);
            ints.pop_back() ;
        }
        else //if(ints.size() == steps -1)
        {
           printDigi(sum(ints)+ (1 << i) ); 
        }
    }
}

int main()
{
    vector<int> myV ;
    comb(myV,7,3,2);
    return 1 ;
}
