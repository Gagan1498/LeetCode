/* Trick: Instead of revresing the number and comparing with the original number, just reverse half the number and compare it with other half */

bool isPalindrome(int x) {
    
    int reversedhalf = 0;

    if (x < 0 || (x%10 == 0 && x!=0)){
        return false;
        }
    else {
        while(x>reversedhalf){
            reversedhalf = reversedhalf*10 + x%10;
            x=x/10;
        }
    }

/* When x is odd number, middle digit will be with reversedhalf, hence, the second part of the equation removes that middle number and compares with x */
    return (x==reversedhalf || x==reversedhalf/10);
    
    /* another solution, but with larger runtime */
    
    /* long  q = x;
    long  result=0, rem=0;

    if (x < 0){
        return false;
        }
    else {
        while(q!=0){
            rem = q%10;
            result = (result*10) + rem;
            q=q/10;
        }
    }

    if (result==x) return true;
    else return false; */
}
