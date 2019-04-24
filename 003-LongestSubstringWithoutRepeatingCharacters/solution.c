/*#############################################################
 *     File Name    : solution.c
 *     Author       : winddoing
 *     Created Time : Thu Nov 29 21:25:56 2018
 *     Description  :
 *############################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s)
{
    int len = 0;
    int i = 0;
    int left = 0;
    int m[256] = {0};

    for(i = 0; i < strlen(s); ++i) {
        if(m[s[i]] == 0 || m[s[i]] < left) {
            len = MAX(len, i - left + 1);

        } else {
            left = m[s[i]];
        }

        m[s[i]] = i + 1;

    }

    return len;
}

int lengthOfLongestSubstring_8ms(char* s)
{
    int maxlen = 0, currlen = 0;
    int table[128], i, j, start = 0;
    memset(table, 0, sizeof(table));

    for(i = 0; s[i] != '\0'; ++i) {
        int num =  ++table[s[i]];

        if(num == 2) {
            if(currlen > maxlen) {
                maxlen = currlen;
            }

            for(j = start; j < i; ++j) {
                if(s[j] == s[i]) {
                    table[s[j]] = 1;
                    start = j + 1;
                    break;

                } else {
                    --currlen;
                    table[s[j]] = 0;
                }
            }

        } else {
            ++currlen;
        }
    }

    if(currlen > maxlen) {
        maxlen = currlen;
    }

    return maxlen;
}

#if 1
int main(int argc, const char *argv[])
{
    int max_len = 0;
    char s[] = "abcabcbb";

    max_len = lengthOfLongestSubstring(s);
    printf("max_len=%d\n", max_len);

    max_len = lengthOfLongestSubstring_8ms(s);
    printf("max_len=%d\n", max_len);

    return 0;
}
#endif
