#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char *word;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation Error\n");
        return NULL;
    }
    newNode->word = malloc(31 * sizeof(char));
    if(newNode->word == NULL){
        printf("Memory Allocation Error\n");
        return NULL;
    }
    printf("Enter a word: ");
    scanf("%s", newNode->word);
    newNode->next = NULL;
    newNode->prev = NULL;
    printf("Node created with word: %s\n", newNode->word);
    return newNode;
}

Node* addNodeFinal(Node* head){
    printf("Adding node at the end of the list...\n");
    Node* newNode = createNode();
    Node* ptr = head;

    if(ptr == NULL){
        printf("List is empty. Adding the first node.\n");
        return newNode;
    }
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    printf("Node added at the end with word: %s\n", newNode->word);
    return head;
}

Node* addNodeBeginning(Node* head){
    printf("Adding node at the beginning of the list...\n");
    Node* newNode = createNode();
    if(head == NULL){
        printf("List is empty. Adding the first node.\n");
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    printf("Node added at the beginning with word: %s\n", newNode->word);
    return newNode;
}

Node* addNodeIndex(Node* head, int index){
    printf("Adding node at index %d...\n", index);
    Node* newNode = createNode();
    Node* ptr = head;
    int count = 0;

    if(index == 0){
        return addNodeBeginning(head);
    }

    while(ptr != NULL && count < index - 1){
        ptr = ptr->next;
        count++;
    }

    if(count == index - 1){
        printf("Index out of bounds. Adding node at the end.\n");
        return addNodeFinal(head);
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;
    if(ptr->next != NULL){
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    printf("Node added at index %d with word: %s\n", index, newNode->word);
    return head;
}

void display(Node* head){
    if(head == NULL){
        printf("The list is empty.\n");
        return;
    }
    printf("Displaying list from beginning to end: ");
    Node* ptr = head;
    while(ptr != NULL){
        printf("%s ", ptr->word);
        ptr = ptr->next;
    }
    printf("\n");
}

void invertedDisplay(Node* head){
    if(head == NULL){
        printf("The list is empty.\n");
        return;
    }
    printf("Displaying list from end to beginning: ");
    Node* ptr = head;
    Node* tail = NULL;

    while(ptr != NULL){
        tail = ptr;
        ptr = ptr->next;
    }

    while(tail != NULL){
        printf("%s ", tail->word);
        tail = tail->prev;
    }
    printf("\n");
}

Node* deleteList(Node* head){
    printf("Deleting entire list...\n");
    Node* ptr = head;

    while(ptr != NULL){
        Node* temp = ptr;
        ptr = ptr->next;
        free(temp->word);
        free(temp);
    }
    printf("List deleted successfully.\n");
    return NULL;
}

Node* deleteFirst(Node* head){
    if(head == NULL){
        printf("The list is empty, nothing to delete.\n");
        return NULL;
    }
    printf("Deleting the first node: %s\n", head->word);
    Node* newHead = head->next;
    free(head->word);
    free(head);
    if(newHead != NULL){
        newHead->prev = NULL;
    }
    return newHead;
}

Node* deleteLast(Node* head){
    if(head == NULL){
        printf("The list is empty, nothing to delete.\n");
        return NULL;
    }
    printf("Deleting the last node...\n");
    Node* ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    if(ptr->prev != NULL){
        ptr->prev->next = NULL;
    }
    printf("Deleted last node with word: %s\n", ptr->word);
    free(ptr->word);
    free(ptr);
    return head;
}

int main(){
    int command;
    Node* doubleLinkedList = NULL;

    printf("Commands: \n");
    printf("1 - Display list from beginning to end\n");
    printf("2 - Display list from end to beginning\n");
    printf("3 - Add node at the beginning\n");
    printf("4 - Add node at the end\n");
    printf("5 - Add node at a specific index\n");
    printf("6 - Delete first node\n");
    printf("7 - Delete last node\n");
    printf("8 - Delete entire list\n");
    printf("9 - Exit program\n");

    while(1){
        printf("Enter command: ");
        scanf("%d", &command);

        switch(command){
            case 1:
                display(doubleLinkedList);
                break;

            case 2:
                invertedDisplay(doubleLinkedList);
                break;

            case 3:
                doubleLinkedList = addNodeBeginning(doubleLinkedList);
                break;

            case 4:
                doubleLinkedList = addNodeFinal(doubleLinkedList);
                break;

            case 5:
                {
                    int index;
                    printf("Enter index: ");
                    scanf("%d", &index);
                    doubleLinkedList = addNodeIndex(doubleLinkedList, index);
                    break;
                }

            case 6:
                doubleLinkedList = deleteFirst(doubleLinkedList);
                break;

            case 7:
                doubleLinkedList = deleteLast(doubleLinkedList);
                break;

            case 8:
                doubleLinkedList = deleteList(doubleLinkedList);
                break;

            case 9:
                printf("Exiting program...\n");
                exit(1);

            default:
                printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}

