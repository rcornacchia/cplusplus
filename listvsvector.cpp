#include <vector>
#include <list>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

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

void testVector(vector<int> v) {
    vector<int> vector;
    default_random_engine generator;
    // start timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    // transfer elements from input vector to vector
    int temp;
    while(v.size() > 0){
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the vector in the proper order
        int inserted = 0; // 0 = false
        // int i = 0;
        auto iterator = list.begin();
        while(inserted == 0 && i < vector.size()){
            if(vector[i] > temp) {
                vector.insert(vector.begin() + i, temp);
                inserted = 1;
            }
            i++;
        }
        if(inserted == 0) {
            vector.push_back(temp);
        }
    }
    // remove elements at random
    while(vector.size() > 0) {
        uniform_int_distribution<int> distribution(0, vector.size()-1);
        int random_num = distribution(generator);
        vector.erase(vector.begin()+random_num);
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    cout << "It took: " << time_span.count() << " seconds.";
    cout << endl;
    // return time_span.count();
}

void testList(vector<int> v) {
    list<int> list;
    default_random_engine generator;
    // start timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    // transfer elements from input vector to list
    int temp;
    while(v.size() > 0){
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);
        // remove an element from input vector
        temp = v[random_num];
        v.erase(v.begin() + random_num);
        // add the element to the list in the proper order
        int inserted = 0; // 0 = false
        auto iterator = list.begin();

        while(inserted == 0 && iterator != list.end()) {
            if(*iterator > temp) {
                list.insert(iterator, temp);
                inserted = 1;
            }
            iterator++;
        }
        if(inserted == 0) {
            list.push_back(temp);
        }
        for(iterator = list.begin(); iterator != list.end(); ++iterator)
		      cout << *iterator << " ";
	    cout << endl;

    }
    // remove elements at random
    while(list.size() > 0) {
        auto iterator = list.begin();
        uniform_int_distribution<int> distribution(0, list.size()-1);
        int random_num = distribution(generator);
        advance(iterator, random_num);
        list.erase(iterator);
        // TODO list.erase(list.begin()+random_num);
        for(iterator = list.begin(); iterator != list.end(); ++iterator)
              cout << *iterator << " ";
        cout << endl;
    }

    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    cout << "It took: " << time_span.count() << " seconds.";
    cout << endl;
    // return time_span.count();
}

int main(int argc, char* argv[]) {
    // create a vector of numbers from 1 to n
    vector<int> v = createVector(10);
    testVector(v);

    testList(v);

    // testMap(v);

    // at least one additional test
    return 0;
}
