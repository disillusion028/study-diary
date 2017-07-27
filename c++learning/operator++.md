operator++ 分为前置和后置两种，那我们该如何实现以区别这两种情况呢？

```
type& operator++(){
	this->increment();
	return *this;
}
type operator++(int){
	type temp=*this;
	this->increment();
	return temp;
}

```
网上看的要令第二个type为const，以防止 i++++的情况出现，然后我看stl里面并没带const（sgi_stl）。
编译器在处理第二种的时候自己会给int赋个0，就变成了 operator++(0)


