#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int main(){
    srand(time(0));
    ofstream fr("randomfile.txt");
    long i=0;
    while(i<10000000){
        fr<<rand()%10000000<<" ";
        i++;
    }
    return 0;
}