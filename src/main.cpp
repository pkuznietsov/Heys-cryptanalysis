#include <iostream>
#include <heys.h>

int main(){
    std::cout<<"hello"<<std::endl;
    heys * a = new heys();
    auto x = a -> txt2blocks("text1.txt");
    auto y = a -> blocks2sub(x);
    
    std::ofstream out("test.txt");
    if(! out)
    {  
        std::cout<<"Cannot open output file\n";
        return 1;
    }
    //char nums[4]={'a','b','c','d'};
    //out.write((char *)nums,sizeof(nums));
    for (int i = 0; i < y.size(); i++){
        out << y[i];
    }
    
    
    out.close();

    a -> ~heys();
}