/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/

// Write a program in C++ to find Frequency of Character in String
#include<iostream>
#include<cstring>

void charFrequency(char *);

int main(){
    char name[] = "Kaiser Sakhi";
    charFrequency(name);
    return 0;
}

void charFrequency(char *str){
    int str_len = strlen(str);
    int alpha[26] = {0};
    char *newStr = (char *) malloc(str_len + 1);
    // strcpy(newStr, str);
    for (int i = 0 ; i < str_len; ++i){
        newStr[i] = tolower(str[i]);
    }
    newStr[str_len] = '\0';
    for (int i = 0; i < str_len; ++i ){
        ++alpha[newStr[i] - 96];
    }

    for (int i = 0; i < 26; ++i){
        if (alpha[i] != 0){
            std::cout<<((char) (i + 64)) << " is " << alpha[i] << " times.\n";
        }
    }

    delete []newStr;
}
