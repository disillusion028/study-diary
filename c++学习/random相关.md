前段时间写了个题，要求一串随机数，c++中有些比较新一点儿的random函数还没用过，所以记录一下。
```c++
std::shuffle(v.begin(),v.end(),std::mt19937{std::random_device{}()});
/*
mt19937: 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998
std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31, 
                             0x9908b0df, 11, 
                             0xffffffff, 7, 
                             0x9d2c5680, 15, 
                             0xefc60000, 18, 1812433253>
mt19937_64:64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
std::mersenne_twister_engine<std::uint_fast64_t, 64, 312, 156, 31,      0xb5026f5aa96619e9, 29,      0x5555555555555555, 17,      0x71d67fffeda60000, 37,      0xfff7eee000000000, 43, 6364136223846793005>
*/
```