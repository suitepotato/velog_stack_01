#include <stdio.h>
#define StackSize 5
char stack[StackSize];
int top = -1;

// 스택이 비었는지 검사하는 함수
int isEmpty() {
    return(top == -1 ? 1 : 0);
}

// 스택이 찼는지 검사하는 함수
int isFull() {
    return(top == (StackSize - 1) ? 1 : 0);
}

// 스택에 원소를 넣는 함수
void push(char item) {
    if(isFull() == 1) {
        printf("스택이 모두 찼습니다.\n");
    }
    else {
        stack[++top] = item;
    }
}

// 스택에서 원소를 제거하는 함수
char pop() {
    if (isEmpty() == 1) {
        printf("스택이 비었습니다.\n");

    }
    else {
        printf("%c\n",stack[top]);
        return stack[top--];
    }
}

int main () {
    push('A');
    push('B');
    push('C');
    push('D');
    push('E');
    printf("isFull : %d\n", isFull());
    pop();
    pop();
    pop();
    pop();
    pop();
    printf("isEmpty : %d", isEmpty());
}
