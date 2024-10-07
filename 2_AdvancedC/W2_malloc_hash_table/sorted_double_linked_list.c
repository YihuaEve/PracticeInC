#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}

struct node *g_head = NULL, *g_tail = NULL;

void insertData(int num){
	struct node *insertedPtr = NULL, *ptr = NULL;
	
    // Try to malloc node insertedPtr
    if ((insertedPtr = (struct node *)malloc(sizeof(struct node))) == NULL)
        return;
    insertedPtr -> data = num;
    insertedPtr -> prev = NULL;
    insertedPtr -> next = NULL;
		
	ptr = g_head;
	while(ptr){
		if(ptr -> data == num) return; // no duplicate
		if(ptr -> data > num) break;
		ptr = ptr -> next;
	}
	
	
	if(NULL == g_head || NULL == g_tail){ // case1: origin array is empty
		g_head = g_tail = insertedPtr;
	}else if(NULL == ptr){ // case2: insert into the end
		g_tail -> next = insertedPtr;
		insertedPtr -> prev = g_tail;
		g_tail = insertedPtr;
	}else if(ptr == g_head){ // case3: insert into the beginning
		insertedPtr -> next = g_head;
		g_head -> prev = insertedPtr;
		g_head = insertedPtr;
	}else{ // case4: insert into the front of ptr
		ptr -> prev -> next = insertedPtr;
		insertedPtr -> prev = ptr -> prev;
		insertedPtr -> next = ptr;
		ptr -> prev = insertedPtr;
	}    
} // end of insertData();

void deleteData(int num){
	struct node *ptr;

	ptr = g_head;
	while(ptr){
		if(ptr -> data == num) break;
		ptr = ptr -> next;
	}
	
    
} // end of deleteData();

void printList(void){
    struct node *ptr = NULL;
    ptr = g_head;
    while(ptr){
        printf("%d,",ptr -> data);
        ptr = ptr -> next;
    } // end of while(ptr)
    printf("\n");
} // end of printList();

void freeList(void){
    struct node *ptr = NULL;
    ptr = g_head;
    while(ptr){
        g_head = g_head -> next;
        free(ptr);
        ptr = g_head;
    }    
} // end of freeList();

int main(viod){
    insertData(5);
    insertData(2);
    insertData(8);
    printList();

    insertData(6);
    insertData(10);
    printList();

    deleteData(2);
    deleteData(10);
    deleteData(6);
    printList();

    freeList();

    return 0;
}