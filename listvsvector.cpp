#include <vector>
#include <random>
#include <iostream>

using namespace std;

vector<int> createVector(int n)
{
    vector<int> v;
    for(int i=1; i <= n; i++) {
        // cout << i <<endl;
        v.push_back(i);
        // v[i] = i;
        // default_random_engine generator;
        // uniform_int_distribution<int> distribution(1,n);
        // int random_num = distribution(generator);
    }
    for(int j = 0; j<v.size(); j++){
        cout << v[j] << endl;
    }
    return v;
}

float testVector(vector<int> v) {
    return 0.1;
}

int main(int argc, char* argv[])
{
    // create a vector of numbers from 1 to n
    vector<int> v = createVector(1000);
    // randomly insert numbers from vector and then randomly remove them
    // testVector(v);
    return 0;
}
