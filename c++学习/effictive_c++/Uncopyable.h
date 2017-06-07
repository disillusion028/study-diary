class Uncopyable{
    protected:
        Uncopyable(){}
        ~Uncopyable(){}
        //允许derived对象构造和析构
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
        //但阻止copying
};