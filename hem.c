1. Sum of Array Elementsc
#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}
2. Insert an Element at a Specified Positionc
#include <stdio.h>

int main() {
    int n, pos, element;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position (0 to %d) and element: ", n);
    scanf("%d %d", &pos, &element);
    printf("Before insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    printf("After insertion: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
.3. Delete an Element from a Specified Positionc
#include <stdio.h>

int main() {
    int n, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    printf("Before deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("After deletion: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
4. Linear Searchc
#include <stdio.h>

int main() {
    int n, key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }
    return 0;
}
5. Sort an Array in Ascending Orderc
#include <stdio.h>

int main() {
    int n, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
.6. Element-wise Sum and Difference of Matricesc
#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], sum[r][c], diff[r][c];
    printf("Enter Matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter Matrix B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Sum Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    printf("Difference Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }
    return 0;
}
7. Matrix Multiplicationc
#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Multiplication not possible\n");
        return 0;
    }
    int a[r1][c1], b[r2][c2], mul[r1][c2];
    printf("Enter Matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter Matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Result Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}
8. Pointers with Arraysc
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    printf("Element\tAddress\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%p\n", *(ptr + i), (void*)(ptr + i));
    }
    return 0;
}
9. Student Information Structurec
#include <stdio.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    struct Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
    return 0;
}
10. Stack Implementation (Array)c
#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int value;
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) push();
        else if (choice == 2) pop();
        else if (choice == 3) peek();
        else if (choice == 4) display();
        else break;
    }
    return 0;
}
11. Queue Implementation (Array)c#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) enqueue();
        else if (choice == 2) dequeue();
        else if (choice == 3) peek();
        else if (choice == 4) display();
        else break;
    }
    return 0;
}
12. Infix to Postfix Conversion Using Stackc
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[100], x;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    int i = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                printf("%c", pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}