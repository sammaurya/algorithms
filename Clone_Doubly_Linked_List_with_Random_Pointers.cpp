/*
	Clone doubly linked list with random pointers

	Example:
	Nodes in linked list are 1,2,3,4,5
	Normal pointers  1->2->3->4
	Random pointers  
	1->3
	2->1
	3->3
	4->2

	In time complexity O(n) and space complexity O(1);
*/

#include <bits/stdc++.h>

using namespace std;

//Structure of Nodes of Doubly Linked List
struct node
{
	int data;
	struct node* next;
	struct node* random;
};

struct node *first = NULL, *first_clone = NULL;

struct node* clonedDoublyLinkedListWithRandomPointers(struct node* head){
	//Cloning of the Doubly Linked List
	//Inserting new nodes between the original linked list
	struct node* cpt = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	while(ptr != NULL){
		struct node* tpr = (struct node*)malloc(sizeof(struct node));
		tpr->data = ptr->data;
		tpr->next = ptr->next;
		ptr->next = tpr;
		ptr = ptr->next->next;
	
	}
	//Attaching random pointers to the in between nodes of clone linked list
	ptr = head;
	while(ptr != NULL){
		cpt = ptr->next;
		cpt->random = ptr->random->next;
		ptr = ptr->next->next;
	}
	//Separating of the cloned list from the original list
	ptr = head;
	head = cpt = ptr->next;
	while(cpt->next != NULL){
		ptr->next = ptr->next->next;
		ptr = ptr->next;
		cpt->next = cpt->next->next;
		cpt = cpt->next;
	}
	ptr->next = NULL;
	
	return head;
}

int main(){
	//Creation of Doubly Linked List with value 1 2 3 4 and normal pointers
	unordered_map<int, struct node*>mp;
	struct node *ptr, *cpt;
	string c;
	getline(cin, c);
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = c[0]-48;
	ptr->next = NULL;
	mp.insert(make_pair(ptr->data, ptr));
	first = ptr;
	
	int i=2;
	while(c[i] != '\0'){
		cpt = (struct node*)malloc(sizeof(struct node));
		cpt->data = c[i] - 48;
		cpt->next = NULL;
		ptr->next = cpt;
		ptr = cpt;
		mp.insert(make_pair(ptr->data, ptr));
		i+=2;
	}
	ptr->next = NULL;

	//Attaching random pointers to it
	int n,a,b;
	scanf("%d",&n);	//Number of inputs
	while(n--){
		scanf("%d %d",&a,&b);
		auto it = mp.find(a);
		ptr = it->second;
		it = mp.find(b);
		ptr->random = it->second;
	}

	//Print Doubly Linked List
	printf("Doubly Linked List With Normal Pointers:\n");
	ptr = first;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	
	printf("\nRandom Pointers to the corresponding node in the Doubly Linked List:\n");
	//Print Random Pointers value
	ptr = first;
	while(ptr!=NULL){
		cout<<ptr->data<<"-->"<<ptr->random->data<<" ";
		ptr = ptr->next;
	}
	printf("\n");

	first_clone = clonedDoublyLinkedListWithRandomPointers(first);
	
	//Print Doubly Linked List
	printf("\nCloned Doubly Linked List With Normal Pointers:\n");
	ptr = first_clone;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	printf("\nRandom Pointers to the corresponding node in the Cloned Doubly Linked List:\n");
	//Print Random Pointers value
	ptr = first;
	while(ptr!=NULL){
		cout<<ptr->data<<"-->"<<ptr->random->data<<" ";
		ptr = ptr->next;
	}
	printf("\n");

	return 0;
	
}