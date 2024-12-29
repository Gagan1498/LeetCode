char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    static char prefix[200] = {0};
    int minlen = strlen(strs[0]);

    for (int i = 0; i < strsSize; i++) {
        if (minlen > strlen(strs[i])) {
            minlen = strlen(strs[i]);
        }
    }

    int i=0;
    for (i = 0; i < minlen; i++) {
        char newchar = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (newchar != strs[j][i]) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = newchar; 
    }
    prefix[i] = '\0';
    return prefix;
}
