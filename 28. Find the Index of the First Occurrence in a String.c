int strStr(char* haystack, char* needle) {

    int size_hay = strlen(haystack);
    int size_nee = strlen(needle);
    int index = 0;

    if (size_hay < size_nee) {
        return -1;
    }

    for (int i = 0; i <= size_hay - size_nee; i++) {
        int j = 0;
        for (j = 0; j < size_nee; j++) {

            if (haystack[i + j] != needle[j]) { //This is good as we use relative increment, instead of using another variable. 
                break; // Mismatch found, exit inner loop
            }
        }
        if (j == size_nee) {
            return i; // Full match found
        }
    }
    return -1;
}
