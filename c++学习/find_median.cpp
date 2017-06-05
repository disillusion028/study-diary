#define CATCH_CONFIG_MAIN
#include "/home/caoqi/software/Catch-master/include/catch.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>
#include <utility>

using namespace std;
int sortBucket(vector<int>&v,int beg){
    //先用着sort，有心情了再改
    int x=v.size()-beg;
    if(x>=5)x=5;
    sort(v.begin()+beg,v.begin()+beg+x);
    return 1;
}
int FindM(vector<int>&v,int pos){
    //pick x from S cleverly
    int col=v.size()/5;
    int res=v.size()%5;  
    if(res!=0)col++;
    for(int i=0;i<col;i++)//sort each bucket
    {
        sortBucket(v,5*i);
    }
    vector<int>medians;
    for(int i=0;i<col;i++){
        if(i==col-1){
            if(res!=0)medians.push_back(i*5+res/2);
        }
        else medians.push_back(i*5+2);
    }
    FindM()//TODO: partition 
}

double FindMedian(vector<int> v){
    int sz=v.size();
    if(sz==0)return 0;
    if(sz%2==0){
        return (FindM(v,sz/2-1)+FindM(v,sz/2))/2.0;
    }else{
        return FindM(v,sz/2);
    }
}



TEST_CASE( "Find the median of vector", "[find median]" ) {
    vector<int> a1={1};
    vector<int> a2={1,2,3,4,5,6,7,8,9};
    vector<int> a3={1,2,3,4,5,6,7,8,9,10};
    vector<int> a4={7,5,6,1,4,9,3,2,8};
    vector<int> a5={1,2};
    vector<int> a6;
    for(int i=0;i<1000001;i++){
        a6.push_back(i);
    }
    shuffle(a6.begin(),a6.end(),std::mt19937{random_device{}()});
    REQUIRE( FindMedian(a1) == 1 );
    REQUIRE( FindMedian(a2) == 5 );
    REQUIRE( FindMedian(a3) == 5.5 );
    REQUIRE( FindMedian(a4) == 5 );
    REQUIRE( FindMedian(a5) == 1.5 );
    REQUIRE( FindMedian(a6) == 500000);
}