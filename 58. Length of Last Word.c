int lengthOfLastWord(char* s) {
    int size = strlen(s);
    char* p = &(s[size - 1]);
    int num = 0;

    for (int i = 0; i < size; i++) {
        if (*(p - i) != ' ') {
            num++;
            if ((p - i - 1 >= s) && *(p - i - 1) == ' ') {
                return num;
            }
        }
    }
    return num;
}
