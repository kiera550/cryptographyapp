// Caesar cipher works by shifting the alphabet by a specific number
#include <iostream>
#include <string>

std::string caesarEncrypt(const std::string& text, int shift){
    std::string result;
    shift = shift%26; 
    for (char c : text){
        if(std::isalpha(c)){
            char base = std::islower(c) ? 'a' : 'A';
            result += char((c-base+shift+26) % 26 + base);
        }else{
            //numbers and punctuation do not shift
            result+=c;
        }
    }
    return result;
}

std::string caesarDecrypt(const std::string& text, int shift){
    return caesarEncrypt(text, -shift);
}

int CaesarCLI(){
    std::string input;
    int shift;
    int mode;
    std::cout << "Caesar Cipher\n";
    std::cout << "Choose your mode: \n 1. Encrypt\n 2. Decrypt\n";
    std::cin >> mode;
    while (!(mode==1)|| !(mode==2)){
        std::cerr << "Error: Invalid mode, please enter 1 or 2";
        std::cin >> mode;
    }
    std::cout << "Please enter your text: \n";
    std::cin >> input;
    std::cout << "Please enter your shift: \n";
    std::cin >> shift;
    
    if (mode == 1){
        std::cout << "\nEncrypted message: " + caesarEncrypt(input, shift);
        return 0;
    }else{
        std::cout << "\nDecrypted message: " + caesarDecrypt(input,shift);
        return 0;
    }
    return 1;
}