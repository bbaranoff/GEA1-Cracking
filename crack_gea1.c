#include <stdio.h>
#include <string.h>

const char *UB[2] = {"0", "1"};
const char *TAC[3] = {"0", "1", "2"};
const char *V[5] = {"0", "1", "2", "3", "4"};

char MB(char *s) {
    if (strcmp(s, "00") == 0)
        return '0';
    else if (strcmp(s, "01") == 0)
        return '1';
    else if (strcmp(s, "10") == 0)
        return '2';
    else
        return '3';
}

char MA(char *s) {
    if (strcmp(s, "00") == 0)
        return '0';
    else if (strcmp(s, "01") == 0)
        return '1';
    else if (strcmp(s, "10") == 0)
        return '2';
    else
        return '3';
}

char MC(char *s) {
    if (strcmp(s, "0") == 0)
        return '0';
    else
        return '1';
}

void find_secret_string(int left, int right, char u, char *v, char *s) {
    if (left > right)
        return;

    char substring[8];
    strncpy(substring, s + left, right - left + 1);
    substring[right - left + 1] = '\0';

    if (MB(substring) != u)
        return;
    if (MA(substring + 1) != v[0] - '0')
        return;
    if (MC(substring + 2) != v[1])
        return;

    if (strcmp(substring, s) == 0) {
        printf("%s\n", substring);
    } else {
        int mid = (left + right) / 2;
        char new_u = v[1] + MB(substring + 2);
        char new_v[3] = {V[strtol(v, NULL, 10) + 1][0], MA(substring + 4), '\0'};
        find_secret_string(left, mid, v[1], new_v, s);
        new_u = V[strtol(v, NULL, 10) + 1][0] + MA(substring + 4);
        new_v[0] = v[1];
        new_v[1] = MC(substring + 5);
        find_secret_string(mid + 1, right, new_u, new_v, s);
    }
}

int main() {
    char *s = "101202220302012032230031010121112";
    int n = strlen(s);
    char u = '0';
    char v[3] = {'0', '0', '\0'};
    find_secret_string(0, n - 1, u, v, s);
    return 0;
}
