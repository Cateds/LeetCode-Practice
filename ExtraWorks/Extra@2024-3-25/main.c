#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_STRUCT {
    struct NODE_STRUCT * next;
    int val;
} Node;

typedef struct QUEUE_STRUCT {
    Node * last;
} queue;

void queue_init(queue* obj) {
    obj->last = NULL;
}

void queue_push(queue* obj, int val) {
    if (obj->last!=NULL) {
        Node* newNode = malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = obj->last->next;
        obj->last->next = newNode;
        obj->last = newNode;
    }
    else {
        obj->last = malloc(sizeof(Node));
        obj->last->val = val;
        obj->last->next = obj->last;
    }
}

int queue_pop(queue* obj) {
    if (obj->last==NULL) {
        return NULL;
    }
    else if (obj->last->next==obj->last) {
        int ans = obj->last->val;
        free(obj->last);
        obj->last = NULL;
        return ans;
    }
    else {
        Node* ptr = obj->last;
        while (ptr->next!=obj->last) ptr = ptr->next;
        int ans = obj->last->val;
        ptr->next = obj->last->next;
        free(obj->last);
        obj->last = ptr;
        return ans;
    }
}

int main(void) {
    queue* Test = malloc(sizeof(queue));
    queue_init(Test);
    queue_push(Test,1);
    queue_push(Test,2);
    queue_push(Test,3);
    printf("%d %d %d %d\n",
        queue_pop(Test), queue_pop(Test), queue_pop(Test), queue_pop(Test)
    );
    return 0;
}