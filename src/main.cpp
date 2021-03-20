#include <iostream>
#include <vector>
#include <heys.h>

int main(){
    heys * a = new heys();
    auto x = a -> txt_to_data("text1.txt");
    auto y = a -> data_to_txt("output1.txt");
    
    a -> ~heys();
}