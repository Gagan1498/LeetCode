/*Trick: Use stack to check valid parenthesis */

bool isValid(char* s) {

    int size = strlen(s);
    char stack_arr[size + 1];
    int top = -1;

    if (size==1) return false;
    for (int i = 0; i < size; i++) {
        if (*(s + i) == '(' || *(s + i) == '{' || *(s + i) == '[') {
            top++;
            stack_arr[top] = *(s + i);
        }

        else if (*(s + i) == ')' || *(s + i) == '}' || *(s + i) == ']') {
            if(top != -1){
                if (*(s + i) == ')' && stack_arr[top] == '(') {
                    top--;
                }
                else if (*(s + i) == '}' && stack_arr[top] == '{') {
                    top--;
                }
                else if (*(s + i) == ']' && stack_arr[top] == '[')
                 {
                    top--;
                }
                else return false;
            }
            else {
                return false;
            }
        }

        else {
            return false;
        }
    }

    if(top!=-1) return false;
    return true;
}
