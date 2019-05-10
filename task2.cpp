#include <iostream>
#include <string>
int main(){
    std::string str;
    int alpha[27];
    for(int i = 1; i < 27; i++){
        alpha[i] = 0;
    }
    bool duplicate = false;
    char dup = '\0';
    std::getline(std::cin, str);
 
    for(auto& i : str){
        if(i >= 'a' && i <= 'z'){
            i ^= 32;
        }
        if(i >= 'A' && i <= 'Z'){
            alpha[i - 64]++;
            if (duplicate == false && (alpha[i - 64] == 2)){
                duplicate = true;
                dup = i;
            }
        }
    }
    int count = 0;
    char largestC;
    for(int i = 1; i < 27; i++){
        if(alpha[i] >= count){
            count = alpha[i];
            largestC = i + 64;
        }
    }
    std::cout << "most common character " << largestC << ": " << count;
    std::cout << std::endl;
    if(dup == '\0'){std::cout << "No duplicates";}
    else{std::cout << dup;}
    std::cout << '\n';
    return 0;
}
