#include <iostream>
#include "int_buffer.h"

int main() {

    int_buffer Ruben(3);
    Ruben[0] = 1337;
    int_buffer Emil(5);
    Emil[0] = 7331;

    std::cout << "Ruben: " <<std::endl;
    for(auto e:Ruben){
        std::cout  << e << ",";

    }
    std::cout <<std::endl;
    std::cout << "Emil innehåller: " << std::endl;
    for(auto a:Emil){
        std::cout  << a << ",";

    }
    Emil = Ruben;
    std::cout << Emil.begin() <<std::endl;
    std::cout << Ruben.begin()<<std::endl;

    int_buffer Bengt(std::move(Ruben));
    std::cout << Ruben.begin();
    std::cout <<Bengt.begin();


    return 0;
}
