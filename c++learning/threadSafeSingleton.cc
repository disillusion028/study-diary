template<typename T>
class Singleton: boost::noncopyable{
    public:
    static T& instance(){
        pthread_once(&ponce_,&Singleton::init);
        return *value_;
    }
    private:
    Singleton();
    ~Singleton();

    static void init(){
        value_=new T();
    }

    private:
        static pthread_once_t ponce_;
        static T*value_;
}

template <typename T>
pthread_once_t Singleton<T>::ponce_=PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_=NULL;