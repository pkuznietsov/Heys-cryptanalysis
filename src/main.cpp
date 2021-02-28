#include <iostream>
#include <heys.h>

int main(){
    std::cout<<"hello"<<std::endl;
    heys * a = new heys();
    auto x = a -> txt2blocks("text1.txt");
    a -> ~heys();
}