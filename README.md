# 추상 자료형
---

스택은 유한개의 자료가 순서대로 저장되는 구조로서 이를 바탕으로 연산 작업을 추상화 하면 아래와 같다.

```
ADT Stack
	데이터 : 0개 이상의 원소를 가진 유한의 순서 리스트
    연산:
    	S ∈ Stack; E ∈ Element;
        - create(S) ::= 스택 생성 연산
        - isEmpty(S) ::= 스택  S가 비어있는지 검사하는 연산
        - isFull(S) ::= 스택 S가 가득 찼는지 검사하는 연산
        - push(S, E) ::= 스택의 맨 위에 요소 E를 추가하는 연산
        - pop(S) ::= 스택의 맨 위에 있는 요소를 삭제하는 연산
END Stack
```

스택에 2가지 주요한 연산인 삽입 연산과 삭제 연산인 push와 pop을 구현하기 이전, 이를 알고리즘을 정리하자.

언더플로우(Underflow)와 오버플로우(Overflow)에 유의해 알고리즘을 짜보았다.

> * 언더플로우(Underflow) : 스택이 비어 자료를 꺼낼 수 없는 상태
> * 오버플로우(Overflow) : 스택이 가득 차 자료를 더 이상 입력할 수 없는 상태

<br>

## push 연산 알고리즘

---

먼저, push(S, E)에 대한 알고리즘을 정리하면 아래와 같다.

```
push(S, E)
	if isFull(S) then overflow;
    else{
    	top ← top + 1;
        S[top] ← E;
    }
end push()
```

이를 더 알아보기 쉽게 순서도로 표현하면 아래와 같다.

![](https://images.velog.io/images/suitepotato/post/ba36cd33-86fa-4c43-b683-5b75cc6f8acc/stack_push_algorithm.png)

이는 스택이 가득 차 있는지 검사하고 가득 차 있을 경우 오버플로우(Overflow)를 반환하고 그렇지 않으면 스택 포인터(여기서는 top)의 값을 1 증가시키고 그 곳에 자료 하나를 삽입하는 알고리즘이다.

<br>

## pop 연산 알고리즘
---
pop(S)에 대한 알고리즘을 정리하면 아래와 같다.

```
pop(S)
	if isEmpty(S) then underflow;
    else{
    	E ← S[top];
        top ← top-1;
        return E;
    }
end pop()
```

이를 더 알아보기 쉽게 순서도로 표현하면 아래와 같다.

![](https://images.velog.io/images/suitepotato/post/c34abad5-5224-4988-a004-5e78ccc310c5/stack_pop_algorithm.png)

이는 스택이 비어 있는지 검사하고 자료가 하나도 없을 경우 underflow를 반환하고, 그렇지 않으면 최상위에 있는 자료를 뺀 다음 스택 포인터 값을 하나 감소시킨다.

<br>

# 스택의 구현

---

앞선 과정에서 어떻게 구현할 수 있는가에 대해서 고민해 보았다. 이번에는 그를 바탕으로 C언어에서 구현해 보겠다.

스택의 크기는 5로 설정하고 A, B, C, D, E 문자를 입력 후 출력하는 과정을 수행하도록 지정하였다.

```c
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
```

이 경우 실행 결과는 아래와 같다.

![](https://images.velog.io/images/suitepotato/post/072d5ce0-443d-442c-882b-71e5ddc319a0/image.png)

해당 코드는 https://github.com/suitepotato/velog_stack_01/blob/master/stack.c 에서 더욱 자세히 확인할 수 있다.

<br>

# 참고

---

정관용, 임종범, 박병기, 복대원. (2013). 고등학교 정보과학 (pp. 194-195). 서울: (주)현대아트컴.
