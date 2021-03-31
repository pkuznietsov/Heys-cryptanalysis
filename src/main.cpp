#include <iostream>
#include <vector>
#include <heys.h>

int main(){
    heys * cipher = new heys();
    auto t2d_error_handler = cipher -> txt_to_data("text.txt");
    auto enc_error_handler = cipher -> encrypt();
    auto dec_error_handler = cipher -> decrypt();

    auto check_enc_dec = cipher -> verificator();
    std::cout << check_enc_dec << std::endl;

//    auto d2t_error_handler = cipher -> data_to_txt("enc.txt");



    
    cipher -> ~heys();
}