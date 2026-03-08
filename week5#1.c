#include <stdio.h>
#include <stdlib.h>

/* DLL Structure */
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* --- I. CREATION --- */
void create() {
    int n, i;
    struct node *newNode, *temp;
    printf("\nHow many nodes? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Value %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (!head) head = newNode;
        else {
            temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

/* --- II. INSERTION --- */
void ins_beg() {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    printf("Value: "); scanf("%d", &n->data);
    n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

// NEW: Insert at a specific position
void ins_pos() {
    int pos, i = 1;
    struct node *temp = head, *n;
    
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 1 || !head) {
        ins_beg();
        return;
    }

    n = (struct node*)malloc(sizeof(struct node));
    printf("Value: ");
    scanf("%d", &n->data);

    // Traverse to the node just before the target position
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL) temp->next->prev = n;
    temp->next = n;
}

void ins_mid() {
    struct node *slow = head, *fast = head, *n;
    if (!head) { ins_beg(); return; }
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    n = (struct node*)malloc(sizeof(struct node));
    printf("Value: "); scanf("%d", &n->data);
    n->next = slow->next;
    n->prev = slow;
    if (slow->next) slow->next->prev = n;
    slow->next = n;
}

void ins_end() {
    struct node *temp = head, *n = (struct node*)malloc(sizeof(struct node));
    printf("Value: "); scanf("%d", &n->data);
    n->next = NULL;
    if (!head) { n->prev = NULL; head = n; return; }
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

/* --- III. DELETION --- */
void del_beg() {
    struct node *t = head;
    if (!head) return;
    head = head->next;
    if (head) head->prev = NULL;
    free(t);
    printf("Deleted from beginning.\n");
}

void del_mid() {
    struct node *slow = head, *fast = head;
    if (!head) return;
    if (!head->next) { del_beg(); return; }
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (slow->prev) slow->prev->next = slow->next;
    if (slow->next) slow->next->prev = slow->prev;
    if (slow == head) head = slow->next;
    free(slow);
    printf("Middle node deleted.\n");
}

void del_end() {
    struct node *t = head;
    if (!head) return;
    if (!head->next) { free(head); head = NULL; return; }
    while (t->next) t = t->next;
    t->prev->next = NULL;
    free(t);
    printf("Deleted from end.\n");
}

/* --- IV. TRAVERSAL --- */
void display() {
    struct node *t = head;
    if (!head) { printf("Empty.\n"); return; }
    printf("dll: ");
    while (t) { printf("%d <-> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n--- DLL MENU ---\n");
        printf("1.Create  2.InsBeg  3.InsMid  4.InsEnd  5.InsPos\n");
        printf("6.DelBeg  7.DelMid  8.DelEnd  9.Disp    10.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) create();
        else if (ch == 2) ins_beg();
        else if (ch == 3) ins_mid();
        else if (ch == 4) ins_end();
        else if (ch == 5) ins_pos(); // Added call
        else if (ch == 6) del_beg();
        else if (ch == 7) del_mid();
        else if (ch == 8) del_end();
        else if (ch == 9) display();
        else if (ch == 10) exit(0);
    }
    return 0;
}

