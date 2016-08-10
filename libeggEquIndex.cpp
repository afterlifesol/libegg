#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <random>
typedef std::mt19937 MersenneTwister;  // Random engine Mersenne Twister
uint32_t RandSeed = 1120; 
//TODO cheange see static seed for testing
// seed = 31415   = EquIndex found index of list(9038) at '13341'
// seed = 0       = EquIndex found index of list(9673) at '95146'
// seed = 1120    = EquIndex found index of list(8678) at '73092'


MersenneTwister RandEng(RandSeed);

int EquIndex(const vector<int> &v) {
    int64_t sum=0;
    int64_t rightsum=0;
    for(const auto &i : v) sum += i;
    vector<int>::size_type index = 0;
    for(const auto &i: v)
    {
        if (sum-i-rightsum == rightsum ) return (int)index;
        rightsum += i;
        index++;
    }
    return -1;  
}


bool IsEquIndex(const vector<int> &v, const vector<int>::size_type index) {
    if (index > v.size()) return false;
    int64_t leftsum=0;
    int64_t rightsum=0;
    for(vector<int>::size_type i=0; i<v.size(); i++)
    {
        if (i==index) continue;
        if (i<index)  leftsum += v[i];
        if (i>index) rightsum += v[i];
    }
    if (leftsum == rightsum) return true;
    return false;
}


int main() 
{
       
    std::uniform_int_distribution<int32_t> RandBig(-2400000,2400000); // ranged [-2.4M,2.4M]
    std::uniform_int_distribution<int32_t> Rand20(-20,20); // ranged [-20,20]
  


    {
        vector<int> list = { 1, 2, 4, -3, -3};    
        auto eindex = EquIndex(list);
        if (IsEquIndex(list,eindex)) cout << "GOOD index: '" << eindex << "'" << endl;
    }


    {
        vector<int> list = { 5, 1, 1, 1, 1, 1, 1};    
        auto eindex = EquIndex(list);
        if (IsEquIndex(list,eindex)) cout << "GOOD index: '" << eindex << "'" << endl;
        if (IsEquIndex(list,0)) cout << "ERR BAD index: '" << 0 << "'" << endl;
        if (IsEquIndex(list,2)) cout << "ERR BAD index: '" << 2 << "'" << endl;
        if (IsEquIndex(list,3)) cout << "ERR BAD index: '" << 3 << "'" << endl;
        if (IsEquIndex(list,4)) cout << "ERR BAD index: '" << 4 << "'" << endl;
        if (IsEquIndex(list,5)) cout << "ERR BAD index: '" << 5 << "'" << endl;
    }


    {
        vector<int> list = { 1, 1, 1, 1, 0, 1, 1, 1, 1};    
        auto eindex = EquIndex(list);
        if (IsEquIndex(list,eindex)) cout << "GOOD index: '" << eindex << "'" << endl;
    }



    cout << "Starting RANDOM CHECKS  ------- (" << RandBig(RandEng) << ")" << endl;


    for (int times=0;times<10000;times++)
    {
            //Create and add 100,000 ints
            const vector<int>::size_type num = 100000;
            vector<int> list;
            for (vector<int>::size_type i=0; i<num; i++) list.push_back(RandBig(RandEng));
            auto eindex = EquIndex(list);
            if (IsEquIndex(list,eindex)) cout << endl << " EquIndex found: list(" << times << ") at '" << eindex << "'" << endl;
            if (times%50==0) cout << '.' << std::flush;
    }   


    
    return 0;
}