## std::move 和 右值 概念及使用的学习
大部分是我自己的翻译，可能不是很准确，来源于[link](http://thbecker.net/articles/rvalue_references/section_01.html);   
### Intro   
右值引用是C++11标准的新特性。

> Rvalue references solve at least two problems:   
> 1.Implementing move semantics   
> 2.Prefect forwarding   

+ 首先回忆一下在C++中左值和右值是什么。   
早些年在c语言中左值和右值的原始定义：   
	左值是一个表达式，它可能出现在一个赋值运算符的左边或者右边，而右值是一个只能出现在赋值运算符右边的表达式。eg:   
    ```c++
    int a = 42;
    int b = 43;
    // a and b are both l-values:
    a=b;//ok
    b=a;//ok
    a=a*b;//ok
    
    //a*b is an rvalue:
    int c=a*b;//ok,rvalue on right hand side of assignment
    a*b=42;//error,rvalue on left hand side of assignment
    ```
    在C++中，上述方法仍然是一个直观的判断左值右值的方法。然而，由于C++中用户自定义类型导致了一些关于可修改性和可赋值性的细微变化使得上述定义变得错误。
    现在我们有一个新的方法去判断左值右值：左值是一个引用了一个内存地址并且允许我们去通过&（取地址符）来得到那个内存地址的表达式，而右值是一个不是左值的表达式。eg：   
    ```c++
    //lvalues:
    //
    int i=42;
    i=43;//ok,i is an lvalue
    int *p=&i;//ok,i is an lvalue;
    int& foo();
    foo()=42;//ok,foo() is an lvalue
    int *p1=&foo();//ok ,foo() is an lvalue
    
    //rvalues:
    //
    int foobar();
    int j=0;
    j=foobar();//ok,foobar() is an rvalue;
    int *p2=&foobar();//error,cannot take the address of an rvalue
    j=42;//ok,42 is an rvalue;
    ```
    
    更多关于左值右值的学习见[链接](https://accu.org/index.php/journals/227);   
    
### Move 语义     
```c++
class X{
	int *m_pResourse[20];
}
X& X::operator=(X const &rhs){
	// [...]
    // Make a clone of what rhs.m_pResource refers to.
    // Destruct the resource that m_pResource refers to.
    // Attach the clone to m_pResource.
    // [...]
}
```   
其他的copy构造函数也类似，现在我们假设 X 被如下使用：
```c++
X foo();
X x;
// perhaps use x in various ways
x = foo(); //这个操作包含了 
// 1. 克隆了foo() 函数所返回的副本对象的资源。    
// 2. 析构释放了x所持有的资源，使它被上一步克隆的资源所替换。 
// 3. 析构了副本对象，由此也释放了副本对象所持有的资源。
```
显而易见的是，如果我们只是交换了x和副本对象所持有的资源指针，然后使副本的析构函数析构x最初所持有的资源的指针，这样会更加有效率。
换句话说，在某种情况下赋值运算符右侧的是一个右值，我们想要copy运算符有如下的操作：
```c++
// [...]
// swap m_pResource and rhs.m_pResource
// [...]
```
这就叫做 move 语义，C++11下，这种操作可以通过重载实现：
```c++
X& X::operator=(<mystery type> rhs){ 
	// [...]
    // swap this->m_pResource and rhs.m_pResource
    // [...]
}
```   
由于我们定义了重载赋值运算符，&lt;mystery type&gt; 本质上是一个引用，我们希望通过引用的方式来传递右侧。进一步来说，我们希望mystery type 有这种行为：当两个重载之间有一个选择是一个普通引用，另一个是mystery type 时，rvalue 必须 选择 mystery type 而lvalue 必须选择普通引用。
我们的rvalue reference就是上述的“mystery type”。   
### Rvalue References   
如果X是任意类型，那么X&&就称为X的右值引用。为了便于区分，普通的引用X&现在也可以称为左值引用。   
右值引用在一般情况下其行为表现与左值引用很相像，只有几种例外。   
最重要的区别是处理函数重载时，左值就会采取老版本左值引用方式，而右值会采取右值引用方式。    
```c++
void foo(X& x); // lvalue reference overload
void foo(X&& x); // rvalue reference overload
X x;
X foobar();

foo(x); // argument is lvalue: calls foo(X&)
foo(foobar());  // argument is rvalue: calls foo(X&&)
```   
所以要点在于：   
> Rvalue reference allow a function to branch at compile time (via overload resolution) on the condition "Am I being called on an lvalue or an rvalue?"   

右值引用允许了函数因其被调用的是左值还是右值而在编译时分支（通过重载）。   

虽然你可以以这种方式重载任意函数，但是在大多数情况下，这种重载只发生在 copy构造函数和赋值构造函数（为了实现move 语义）：
```c++
X& X::operator=(X const & rhs); //classical implementation
X& X::operator=(X&& rhs)
{
	//Move sematics: exchange content between this and rhs
    return *this;
}
```

> Note:   
> if you implement   
> void foo(X&);   
> but not   
> void foo(X&&)   
> foo 只能以左值调用，不能以右值调用
> if you implement   
> void foo(X const&)   
> but not   
> void foo(X&&)   
> foo 可以以左值和右值调用，但是这两种调用不会有所区别，除非有void foo(X&&);   
> if you implement   
> void foo (X&&);   
> but neither void foo(X&); nor void foo(X const&);   
> 则foo可以在右值上调用，而不能在左值调用。   

    
