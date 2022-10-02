#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Entity.h"
bool isPalindrome(int x) {
    if(x<0|| (x % 10 == 0 && x != 0)){
        return false;
    }

    int digits = 0;
    while(x>digits){
        digits =x%10+digits*10;
        x=x/10;
        std::cout<< "Digits:"<<digits<<std::endl;
        std::cout<< "X:"<<x<<std::endl;
    }
    return x == digits || x == digits/10;

}

void Write(std::string filename,std::string text){
    std::ofstream file;
    file.open(filename,std::ios::out);
    if(file.fail()){
        std::cout<<"Cant Open File "<<filename<<std::endl;
    }
    else{
        file << text;
    }
    file.close();
}

void Read(std::string file){
    std::ifstream fstream;
    std::string line;
    char buf[1024]; // Make sure this is big enough!
    fstream.open(file,std::ios::in);
    if(fstream.fail()){
        std::cout<<"Failed in reading file "<<file<<std::endl;
    }
    else{
        while (!fstream.eof()){
            fstream.getline(&(buf[0]),1024,',');
            std::cout<<buf<<std::endl;
        }
    }
    fstream.close();

}

int main() {
    {
        std::unique_ptr<Entity> uniquePtr=std::make_unique<Entity>();
    }
    int i =2;
    int& a =i;
    i=3;
    std::cout<<a<<std::endl;
    return 0;
}


