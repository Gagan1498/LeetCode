/*Trick: Use stack to check valid parenthesis */

bool isValid(char* s) {

    long int size = strlen(s);
    char arr[size+1];
    int top = -1;

    for(int i=0;i<size;i++){
        if (*(s+i) == '(' || *(s+i) == '[' || *(s+i) == '{'){
            top++;
            arr[top] = *(s+i);
            printf("1 %c\n",*(s+i));
        }

        else if 
            (top != -1 &&
            ((*(s+i) == ')' && arr[top] == '(') || 
            (*(s+i) == ']' && arr[top] == '[') || 
            (*(s+i) == '}' && arr[top] == '{'))){
            printf("2 %c\n",*(s+i));
            top--;
            printf("3 %c\n",*(s+i));
        }

        else{
            printf("4 %c\n",*(s+i));
            return false;
        }        

    }

    if(top != -1) return false;
    return true;
}
