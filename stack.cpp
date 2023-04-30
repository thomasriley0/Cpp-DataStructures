#include <stdlib.h>
#include <cstdio>

using namespace std;

#define MAX 15

//Creating a Stack
struct stack
{
    int top;
    int items[MAX];
    int size = 0;
};
typedef struct stack;

//Intialize Top
void createEmptyStack(stack *st) {
    st->top = -1;
}

//Check if stack is full
int isFull(stack *st) {
    if (st->top == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

//Check if stack is empty
int isEmpty(stack *st) {
    if (st->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

//Push item to top stack
void pushItem(stack *st, int item) {
    if (isFull(st)) {
       printf("Stack Full.\n");
    } else {
        st->top++;
        st->items[st->top] = item;
        st->size++;
        printf("Pushed %d.\n", item);
    }
    
}

//Pop item from top of stack
void popItem(stack *st) {
    int item;
    if (isEmpty(st)) {
        printf("Stack Empty. \n");
    } else {
        int item = st->items[st->top];
        st->top--;
        st->size--;
        printf("Popped %d. \n", item);

    }

}

void displayStack(stack *st) {
    printf("-----------Stack------------\n");
    printf("           Size: %d\n\n", st->size);

        for (int i = 0; i < st->size; i++) {
        printf("Item: %d \n", st->items[i]);
    } 
    printf("----------------------------\n");
    
}



//driver code
int main() {
    stack *st = (stack *)malloc(sizeof(stack));
    createEmptyStack(st);

    pushItem(st, 33);    
    pushItem(st, 15);
    pushItem(st, 90);
    popItem(st);
    popItem(st);
    pushItem(st, 22);
    popItem(st);

    displayStack(st);

    return 0;
}