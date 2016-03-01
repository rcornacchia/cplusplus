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
    return v;
}

float testVector(vector<int> v) {
    vector<int> seq;
    default_random_engine generator;


    for(int j = 0; j < v.size(); j++){
        cout << v[j] << " ";
    }
    cout << endl;

    // start timer

    // transfer elements from input vector to seq
    int temp;
    while(v.size() > 0){
        uniform_int_distribution<int> distribution(0, v.size()-1);
        int random_num = distribution(generator);

        // remove an element from input vector
        temp = v[random_num];
        // cout << temp << endl;


        v.erase(v.begin() + random_num);
        // add the element to the sequence in the proper order
        int inserted = 0; // 0 = false
        int i = 0;
        // while(i < seq.size

        while(i <= seq.size() && inserted == 0){
            if(seq.size() == 0){
                seq.push_back(temp);
            }
            cout << "test" <<endl;
            // if(seq[i] > temp) {
            //     seq.push_back(temp);
            //     inserted = 1;
            // }
            i++;
        }
    }

    for(int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    // remove elements at random
    // while(seq.size() > 0) {
    //
    // }



    // end timer
    // return time it took
    return 0.1;
}

int main(int argc, char* argv[])
{
    // create a vector of numbers from 1 to n
    vector<int> v = createVector(10);
    // randomly insert numbers from vector and then randomly remove them
    testVector(v);
    return 0;
}
