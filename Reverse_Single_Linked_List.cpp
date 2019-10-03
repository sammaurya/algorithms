/*
	Reverse a Single Linked List

	In O(n) time complexity and O(1) space complexity

*/

#include <bits/stdc++.h>

using namespace std;

//Structure of Nodes of Single Linked List
struct node
{
	int data;
	struct node* next;
};

struct node *first = NULL;

//Reversing of Single Linked List in O(n) time complexity and O(1) space complexity
struct node* reverseSingleLinkedList(struct node* head){

	struct node *pre, *cur, *next;
	pre = NULL;
	cur = first;
	while(cur != NULL){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

//Reverse single linked list using recursion
struct node* reverseSingleLinkedListUsingRecursion(struct node* head){

	if(head == NULL)
		return NULL;
	else if(head->next == NULL)
		return head;
	struct node* cur = reverseSingleLinkedListUsingRecursion(head->next);
	head->next->next = head;
	head->next = NULL;
	return cur;
}

int main(){
	//Creation of Single Linked List with value 1 2 3 4 5
	struct node *ptr, *cpt;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = 1;
	ptr->next = NULL;
	first = ptr;
	for(int i=2; i<=5; ++i){
		cpt = (struct node*)malloc(sizeof(struct node));
		cpt->data = i;
		cpt->next = NULL;
		ptr->next = cpt;
		ptr = cpt;
	}
	//Print Single Linked List
	ptr = first;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	

	//first = reverseSingleLinkedList(first);

	first = reverseSingleLinkedListUsingRecursion(first);
	
	//Print Reverse Single Linked List
	printf("\n");
	ptr = first;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}

	return 0;
	
}