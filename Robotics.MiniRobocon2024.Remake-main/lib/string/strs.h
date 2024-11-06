#pragma once

template<typename T>
T pow(T base, int exp){
    if(exp == 0)
        return 1;
    else if(exp & 1)
        return base * pow(base, exp - 1);
    else{
        const T ans = pow(base, exp / 2);
        return ans * ans;
    }
}
template<typename T>
T convert(const char* str){
    T pn = 1, n = 0, exp = 0;
    char* it = (char*)str;
    if(*it == '-'){
        pn = -1;
        it++;
    }
    while(*it!= '\0'){
        if(*it == '.'){
            it++;
            break;
        }
        n = n * 10 + (*it - '0');
        it++;
    }
    if(*it == '.'){
        it++;
        while(*it != '\0'){
            exp--;
            n = n * 10 + (*it - '0');
            it++;
        }
    }
    return pn * n * pow<int>(10, exp);
}

char** split(const char* str, const char delimiter){
    char** arr = new char*[100], *tmp = new char[100];
    for (int i = 0; str[i] != '\0'; i++){
        tmp += str[i];
        if(str[i] == delimiter){
            *(arr++) = tmp;
            tmp = new char[100];
        }
    }
     *(arr++) = tmp;
    *(arr++) = NULL;
    return arr;
}