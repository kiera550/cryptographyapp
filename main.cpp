#include <iostream> 
#include <ciphers/caesar.cpp>

int main(){
    int val = CaesarCLI();
    if (val == 1){
        std::cerr << "Error: Caesar Cipher failed to complete.";
    }
}