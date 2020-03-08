//(7-8) Заменить все слова в строке заданной подстрокой, 
//если длина слова совпадает с длиной подстроки и слово содержит хотя бы одну цифру.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//--- functions ---
void substrReplace(char*, char*);
void  inputString(char*&);

int main()
{
//---create---
    char* str = nullptr;
    char* substr = nullptr;

//--- input strings ----
    cout << "Please, input string : ";
    inputString(str);
    cout << "Please,input substring : ";
    inputString(substr);

//--- function --- 
    substrReplace(str, substr);
    cout << str;

//---delete---
    delete[] str;
    delete[] substr;
    str = nullptr;
    substr = nullptr;

//---end-----
    return 0;
}
//--- solving below --- 
void substrReplace(char* str, char* substr) {
    int Len = strlen(substr);
    int k(0);
    for (int i(0); i <= strlen(str); ++i) {
        if (str[i] == 32 || !str[i]) {//i = position after word
            int c = (i - k);
            if (c == Len) {// checking length equality
                int y(0);
                for (int w = k; w < i; ++w) {// checking numbers in the word
                    if (str[w] > 47 && str[w] < 58) ++y; //  48-- 0,1,2,3,4,5,6,7,8,9 --57
                }
                if (y) {// if we found number in word
                    int d(0);
                    for (int j = k; j < i; ++j) {// change word with number and equal length to substring
                        str[j] = substr[d];
                        ++d;
                    }
                }
            }
            k = i + 1;
        }
    }
}
void inputString(char*& str) {
    const int MAX = 70;
    char tmp[MAX];
    cin.getline(tmp, MAX);
    str = new (nothrow) char[strlen(tmp) + 1]; if (!str) { cout << "No memory"; exit(1); }
    strcpy(str, tmp);
}