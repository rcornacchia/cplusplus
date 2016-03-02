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
    float f[20];
};

vector<int> createVector(int n) {
    vector<int> v;
    for(int i=1; i <= n; i++) {
        // cout << i <<endl;
        v.push_back(i);
        // v[i] = i;
        // default_random_engine generator;
        // uniform_int_distribution<int> distribution(1,n);
        // int random_num = distribution(generator);
    }
    return v;
}

template <typename ContainerT>
void test(vector<int> &v, ContainerT &seq) {
    default_random_engine generator;
    // start timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    // transfer elements from input vector to seq
    int temp;
    while(v.size() > 0){
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the vector in the proper order
        int inserted = 0; // 0 = false
        auto iterator = seq.begin();

        while(inserted == 0 && iterator != seq.end()) {
            if(*iterator > temp) {
                seq.insert(iterator, temp);
                inserted = 1;
            }
            iterator++;
        }
        if(inserted == 0) {
            seq.push_back(temp);
        }
        // for(iterator = seq.begin(); iterator != seq.end(); ++iterator)
        //       cout << *iterator << " ";
        // cout << endl;
    }
    // remove elements at random
    while(seq.size() > 0) {
        auto iterator = seq.begin();
        uniform_int_distribution<int> distribution(0, seq.size()-1);
        int random_num = distribution(generator);
        advance(iterator, random_num);
        seq.erase(iterator);
        // for(iterator = seq.begin(); iterator != seq.end(); ++iterator)
        //       cout << *iterator << " ";
        // cout << endl;
    }

    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    cout << "Vector: " << time_span.count() << " seconds.";
    cout << endl;
}

int main(int argc, char* argv[]) {
    // create a vector of numbers from 1 to n
    vector<int> v = createVector(10);
    vector<int> tv;
    list<int> list;
    testVector(v, tv);
    testVector(v, list);
    // testList(v);

    // testBigVector(big_v);
    // testBigList(big_v);
    // testMap(v);

    // at least one additional test
    return 0;
}
