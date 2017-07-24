#include <string>
#include <iostream>
class Screen{
public:
    typedef std::string::size_type pos;
    char get_cursor() const{return contents[cursor];}
    char get() const;
    char get(pos ht,pos wd)const;
    Screen& home();
    Screen& forward();
    Screen& back();
    Screen& up();
    Screen& down();
    using Action=Screen& (Screen::*)();
    enum Directions{HOME,FORWARD,BACK,UP,DOWN};
    Screen& move(Directions);
private:
    static Action Menu[];
    std::string contents;
    pos cursor;
    pos height,width;
};
auto pmf=&Screen::get_cursor;//成员函数指针
Screen& Screen::move(Directions cm){
    return (*this.*Menu[cm])();
}
Screen::Action Screen::Menu[]={
    &Screen::home,
    &Screen::forward,
    &Screen::back,
    &Screen::up,
    &Screen::down,
};