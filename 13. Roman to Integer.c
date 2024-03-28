/* Trick: It's better to start from right to left instead of left to right */

int findnum(char s){
    if (s == 'I') return 1;
    else if (s == 'V') return 5;
    else if (s == 'X') return 10;
    else if (s == 'L') return 50;
    else if (s == 'C') return 100;
    else if (s == 'D') return 500;
    else if (s == 'M') return 1000;
    else return -1;
}

int romanToInt(char* s) {

    int len = strlen(s);
    int sum = findnum(s[len-1]);

    for (int i=len-1;i>0;i--){
        if (findnum(s[i-1])>=findnum(s[i])) sum += findnum(s[i-1]);
        else sum -= findnum(s[i-1]);
    }

    return sum;
}
