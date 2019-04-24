/*#############################################################
 *     File Name    : solution.c
 *     Author       : winddoing
 *     Created Time : Thu Nov 29 21:25:56 2018
 *     Description  :
 *############################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p = NULL, *q = NULL, *head = NULL;

    int index = 0, x, y, sum = 0;

    while(l1 != NULL || l2 != NULL) {
        x = (l1 != NULL) ? l1->val : 0; /*当l1非空时x等于l1所指向的值*/
        y = (l2 != NULL) ? l2->val : 0; /*当l2非空时y等于l2所指向的值*/

        sum = x + y + index;    /*求和的时候记得加上用来进位的index*/

        p = (struct ListNode*)malloc(sizeof(struct ListNode));

        if(p != NULL) { /*当节点分配成功*/
            p->val = sum % 10;  /*对和求余数*/
            index = sum / 10;   /*计算是否需要进位*/
            p->next = NULL;
        }

        if(q == NULL) { /*才产生了一个节点的时候，让head指向该节点*/
            q = p;
            head = q;

        } else {
            q->next = p;    /*将每一个节点连接起来*/
            q = p;
        }

        /*判断l1是否已经指向了一个空节点，这一步很重要， 也很危险，
         * 切记不能写成if(l1->next!NULL)
         * 这样会产生死循环（l1和l2一直指向最后一个节点）*/
        if(l1)
            l1 = l1->next;

        if(l2)
            l2 = l2->next;
    }

    if(index == 1) { /*当最后一个节点相加超过10了，需要再产生一个节点来完成进位*/
        p = (struct ListNode*)malloc(sizeof(struct ListNode));

        if(p != NULL) {
            p->val = 1;
            p->next = NULL;
            q->next = p;
            q = p;
        }

    }

    return head;
}

static struct ListNode *node_build(const char *digits)
{
    struct ListNode *res, *p, *prev;
    int first = 1;
    int len = strlen(digits);
    const char *c = digits + len - 1;
    prev = NULL;

    while(len-- > 0) {
        p = malloc(sizeof(*p));

        if(first) {
            first = 0;
            res = p;
        }

        p->val = *c-- - '0';
        p->next = NULL;

        if(prev != NULL) {
            prev->next = p;
        }

        prev = p;
    }

    return res;
}

static void show(struct ListNode *ln)
{
    int sum = 0, factor = 1;

    while(ln != NULL) {
        sum += ln->val * factor;
        factor *= 10;
        ln = ln->next;
    }

    printf("%d\n", sum);
}

int main(int argc, char **argv)
{
    if(argc < 3) {
        fprintf(stderr, "Usage: ./test n1 n2\n");
        exit(-1);
    }

    struct ListNode *l1 = node_build(argv[1]);

    struct ListNode *l2 = node_build(argv[2]);

    struct ListNode *res = addTwoNumbers(l1, l2);

    show(l1);

    show(l2);

    show(res);

    return 0;
}
