#ifndef body_h
#define body_h

#include <iostream>
#include <vector>
#include <string>

class body{
    public:
        body(){};
        std::vector<std::string> get_body(int i){
            if(i == 1)
                return corpo1;
            else if(i == 2)
                return corpo2;
            else if(i == 3)
                return corpo3;
            else if(i == 4)
                return corpo4;
            else if(i == 5)
                return corpo5;
            else
                return corpo6;
        }

    private:
        std::vector<std::string> corpo1 = { " o ", "   ", "   " };
        
        std::vector<std::string> corpo2 = { " o ", " | ", "   " };
        
        std::vector<std::string> corpo3 = { " o ", "/| ", "   " };
        
        std::vector<std::string> corpo4 = { " o ", "/|\\", "   " };
        
        std::vector<std::string> corpo5 = { " o ", "/|\\", "/  " };
        
        std::vector<std::string> corpo6 = { " o ", "/|\\", "/ \\" };
};

#endif 