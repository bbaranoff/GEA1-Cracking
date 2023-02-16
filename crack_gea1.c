#include <stdio.h>
#include <string.h>

char *UB[] = {"0", "1"};
char *TAC[] = {"0", "1", "2"};
char *V[] = {"0", "1", "2", "3", "4"};

char *MB(char *s) {
    if (strcmp(s, "00") == 0)
        return "0";
    if (strcmp(s, "01") == 0)
        return "1";
    if (strcmp(s, "10") == 0)
        return "2";
    return "3";
}

char *MA(char *s) {
    if (strcmp(s, "00") == 0)
        return "0";
    if (strcmp(s, "01") == 0)
        return "1";
    if (strcmp(s, "10") == 0)
        return "2";
    return "3";
}

char *MC(char *s) {
    if (strcmp(s, "0") == 0)
        return "0";
    return "1";
}

void find_secret_string(int left, int right, char *u, char *v, char *s) {
    if (left > right)
        return;
    
    char substring[8];
    strncpy(substring, &s[left], right-left+1);
    substring[right-left+1] = '\0';
    
    if (strcmp(MB(strncpy(substring, &s[left], 2)), u) != 0)
        return;
    if (strcmp(MA(strncpy(substring+1, &s[left+1], 3)), TAC[atoi(v)]) != 0)
        return;
    if (strcmp(MC(strncpy(substring+6, &s[right], 1)), &v[1]) != 0)
        return;
    
    if (strcmp(substring, s) == 0) {
        printf("%s\n", substring);
    } else {
        int mid = (left + right) / 2;
        char vu[3];
        vu[0] = v[1];
        vu[1] = MB(strncpy(substring+2, &s[mid+1], 3))[0];
        vu[2] = '\0';
        char va[3];
        va[0] = V[atoi(v)+1][0];
        va[1] = MA(strncpy(substring+4, &s[mid-1], 3))[0];
        va[2] = '\0';
        find_secret_string(left, mid, vu, va, s);
        vu[0] = V[atoi(v)+1][0];
        vu[1] = MA(strncpy(substring+7, &s[mid], 2))[0];
        find_secret_string(mid+1, right, vu, v, s);
    }
}

int main() {
    char *s = "101202220302012032230031010121112";
    find_secret_string(0, strlen(s)-1, "0", "0", s);
    return 0;
}
