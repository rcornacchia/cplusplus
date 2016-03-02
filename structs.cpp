#include <vector>
#include <list>
#include <map>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

struct bigInt {
    int integer;
    float bignumber1 = 0.01;
    float bignumber2 = 0.01;
    float bignumber3 = 0.01;
    float bignumber4 = 0.01;
    float bignumber5 = 0.01;
    float bignumber6 = 0.01;
};
vector<bigInt> createBigVector(int n) {
    vector<bigInt> v;
    for(int i=1; i <= n; i++) {
        // cout << i <<endl;
        bigInt x;
        x.integer = i;
        v.insert(v.end(), x);
        cout << x.bignumber6 <<endl;
        // v[i] = i;
        // default_random_engine generator;
        // uniform_int_distribution<int> distribution(1,n);
        // int random_num = distribution(generator);
    }
    return v;
}

int main(int argc, char* argv[]) {
    // create a vector of numbers from 1 to n
    vector<bigInt> v = createVector(4);
    // testVector(v);

    // testList(v);

    // testMap(v);

    // at least one additional test
    return 0;
}
