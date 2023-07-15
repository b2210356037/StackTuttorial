#pragma once
#include <iostream>

typedef struct stack 
{
    int size=2;
    int peak;
    int* dizi;
}*s;

stack* define() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->peak = 0;
    s->size = 2;
    s->dizi = NULL;
    return s;
}

int pop(stack *s) {
    if (s->peak <= 0 || s->dizi == NULL) {
        printf("array is empty!\n");
        return - 1;
    }
    if (s->peak <= s->size / 4) {
        int* array2 = (int*)malloc(sizeof(int) * s->size / 2);
        for (int i = 0; i < s-> peak; i++)
        {
            array2[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = array2;
        s->size /= 2;
    }
    return s->dizi[--s->peak];
}
void push(int a, stack *s) {
    if (s->dizi == NULL) {
        s->dizi = (int*)malloc(sizeof(int) * 2);
    }
    if (s->peak >=s->size) {
        int* array2 = (int*)malloc(sizeof(int) * s->size * 2);
        for (int i = 0; i < s->size; i++)
        {
            array2[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = array2;
        s->size *= 2;
    }
    s->dizi[s->peak++] = a;
}
void print(stack *s) {
    printf("size: %d\n",s-> size);
    for (int i = 0; i < s->peak; i++)
    {
        printf("%d ", s->dizi[i]);
    }
    printf("\n");
}
