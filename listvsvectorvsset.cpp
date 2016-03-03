#include <vector>
#include <list>
#include <set>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

typedef struct {
    int integer;
    float f[500];
} bigInt;

vector<bigInt> createBigVector(int n) {
    vector<bigInt> v;
    for(int i=1; i <= n; i++) {
        bigInt x;
        x.integer = i;
        v.insert(v.end(), x);
    }
    return v;
}
vector<int> createVector(int n) {
    vector<int> v;
    for(int i=1; i <= n; i++) {
        v.push_back(i);
        // v[i] = i;
        // default_random_engine generator;
        // uniform_int_distribution<int> distribution(1,n);
        // int random_num = distribution(generator);
    }
    return v;
}

// insert elements from input vector to seq
template <typename ContainerT>
void insert(vector<int> v, ContainerT &seq) {
    default_random_engine generator;
    int temp;
    while(v.size() > 0){
        auto iterator = seq.begin();
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the vector in the proper order
        int inserted = 0; // 0 = false

        while(inserted == 0 && iterator != seq.end()) {
            if(*iterator > temp) {
                seq.insert(iterator, temp);
                inserted = 1;
            }
            iterator++;
        }
        if(inserted == 0) {
            seq.insert(iterator, temp);
        }
        // for(iterator = seq.begin(); iterator != seq.end(); ++iterator)
        //       cout << *iterator << " ";
        // cout << endl;
    }
}


// for big ints
template <typename ContainerX, typename ContainerT>
void insert(ContainerX v, ContainerT &seq) {
    default_random_engine generator;
    bigInt temp;
    while(v.size() > 0){
        auto iterator = seq.begin();
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the vector in the proper order
        int inserted = 0; // 0 = false

        while(inserted == 0 && iterator != seq.end()) {
            if(*iterator > temp.integer) {
                seq.insert(iterator, temp.integer);
                inserted = 1;
            }
            iterator++;
        }
        if(inserted == 0) {
            seq.insert(iterator, temp.integer);
        }
        // for(iterator = seq.begin(); iterator != seq.end(); ++iterator){
        //       cout << *iterator << " ";
        // }
        // cout << endl;
    }
}


template<>
void insert<set<int>>(vector<int> v, set<int> &seq) {
    default_random_engine generator;
    int temp;
    while(v.size() > 0){
        auto iterator = seq.begin();
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the vector in the proper order
        seq.insert(temp);
        // for(iterator = seq.begin(); iterator != seq.end(); ++iterator)
        //       cout << *iterator << " ";
        // cout << endl;
    }
}

// remove elements at random
template <typename ContainerT>
void remove(ContainerT &seq) {
    default_random_engine generator;
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
}

template <typename ContainerX, typename ContainerT>
void test(ContainerX &v, ContainerT &seq) {
    // start timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    insert(v, seq);
    // check timer
    high_resolution_clock::time_point mid = high_resolution_clock::now();
    remove(seq);
    // end timer
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> insertion_time = duration_cast<duration<double>>(mid - start);
    duration<double> removal_time = duration_cast<duration<double>>(end - mid);
    cout << insertion_time.count() << endl;
    cout << removal_time.count() << endl;
    cout << endl;
}

template <typename ContainerX, typename ContainerT>
void bigTest(ContainerX &v, ContainerT &seq) {
    // start timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    insert(v, seq);
    // check timer
    high_resolution_clock::time_point mid = high_resolution_clock::now();
    remove(seq);
    // end timer
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> insertion_time = duration_cast<duration<double>>(mid - start);
    duration<double> removal_time = duration_cast<duration<double>>(end - mid);
    cout << insertion_time.count() << endl;
    cout << removal_time.count() << endl;
    cout << endl;
}


int main(int argc, char* argv[]) {
    // create a vector of numbers from 1 to n
    // vector<int> v = createVector(7);
    vector<bigInt> big_v = createBigVector(2500);


    vector<int> vector;
    list<int> list;
    set<int> set;
    // cout << "Vector" << endl;
    // test(v, vector);
    // cout << "List" << endl;
    // test(v, list);
    // cout << "Set" << endl;
    // test(v, set);

    cout << "Vector" << endl;
    bigTest(big_v, vector);
    cout << "List" << endl;
    bigTest(big_v, list);
    cout << "Set" << endl;
    bigTest(big_v, set);

    // at least one additional test
    return 0;
}
