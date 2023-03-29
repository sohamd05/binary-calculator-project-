#include<stdio.h>
#include<stdlib.h>
#include"node_structure.h"

int reverse(list *l);

void initList(list *l){
	*l = NULL;
	return;
}

node* createnode(int data) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    //newnode->sign = sign;
    newnode->next = NULL;
    return newnode;	
}

void append(list *l , int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	//newnode -> sign = sign;
	newnode -> next = NULL;
	
	if( (*l) == NULL){
		*l = newnode;
		return;
	}
	
	else{
	     node* temp = *l;
	     
	     while(temp -> next != NULL){
	     		temp = temp -> next;
	     }
	     temp -> next = newnode;
	     newnode -> next = NULL;
	}
	return;
}

void push(list *l , int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> next = NULL;
	
	
	if((*l) == NULL){
		*l = newnode;
		newnode -> next = NULL;
	}
	
	else{
		newnode -> next = (*l);
		(*l) = newnode;
	}
	return ;
}


void createLL(list *l,long number){
	long lastValue;
	while(number != 0){
		lastValue = number % 10;
		push(l,lastValue);
		//push_sign(l,sign);
		number = number / 10;	
	}
	return;
}

void display(list l){
	if(l == NULL){
		//printf("List is NULL");;
	}
	
	node* disp = l;
	
	while(disp != NULL){
		printf("%d",disp -> data);
		disp = disp -> next;
	}
	printf("\n");
	return;
}

long listToNumber(list *l){
	node* ptr = (*l);
	long num = 0;
	
	while(ptr != NULL){
		num = (num*10) + ptr -> data;
		ptr = ptr -> next;
	}
	
	return num;		
}

void assignTheValueToNullList(list l1 ,  list *l2){
	
	node* ptr1 = l1;
	
	while(ptr1 != NULL){
		//push_sign(&(*l2),ptr1 -> sign);
		append(&(*l2) , ptr1->data);
		ptr1 = ptr1 -> next;
	}
	
	return;
}

int countList(list l){

	node* ptr = l;
	int counter = 0;
	if(l == NULL){
		return counter = 0;
	}
	
	else{
		while(ptr != NULL){
		
			counter++;
			ptr = ptr ->next;
		}
	}
	return counter;
}

int reverse(list* head){
    	node* prev = NULL;
    	node* current = *head;
    	node* next = NULL;
    	int len = 0;
    	
    	while (current != NULL) {
        	len++;
        	next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
    	}
    	*head = prev;
   	 return len;
}

node* make_empty_list(int size){
   	node* head = NULL;
    	while (size--)
        	push(&head, 0);
   		return head;
}

int isZero(list l){
	node* ptr = l;
		if(ptr -> data == 0){
			return 1;
		}
		
		else{
			return 0;
		}
}

int isNumber(char ch){
    	int digit = ch - '0';
    	if (digit >=0 && digit <=9){
        	return 1;
    	}
    	else
    		return 0;
}

list addList(list *l1 , list *l2){
	
	list l3;
	initList(&l3);
	
	
	if(!(*l1) && !(*l2)){
		printf("List doesnt have any value");
		exit(0);
	}
	
	if(!(*l1)){
		assignTheValueToNullList(*l2, &l3);
		return l3;
	}
	
	if(!(*l2)){
		assignTheValueToNullList(*l1,&l3);
		return l3;
	}
	
	//display(*l2);
	reverse(l1);	
	reverse(l2);
	
	node* ptr1 = *l1;
	node* ptr2 = *l2;
	
	int sum ;
	int carry = 0;
		
	while(ptr1 != NULL || ptr2 != NULL || carry){
		sum = 0;
		if(ptr1 != NULL){
		   sum += ptr1 -> data;
		}
		
		if(ptr2 != NULL){
		   sum += ptr2 -> data;
		}
		
		sum += carry;
		
		carry = sum / 10;
		sum = sum % 10;
		
		append(&l3 ,sum);
		
		if(ptr1 != NULL){
		   ptr1 = ptr1 -> next;
		 }
		 
		if(ptr2 != NULL){    
		   ptr2 = ptr2 -> next;
		}
	}
	
	if(carry != 0){
		push(&l3 , carry);
	}
	
	
	reverse(l1);
	reverse(l2);
	
	reverse(&l3);
	
	
	return l3;
}

list multiplyList(list l1,list l2){
	
	int val1 = countList(l1);
	int val2 = countList(l2);
	
	if(val1 == 1 || val2 == 1){
		list l3;
		initList(&l3);
		
		node* ptr1 = l1;
		node* ptr2 = l2;
		if(ptr1 -> data == 0 || ptr2 -> data == 0){
			append(&l3,0);

			return l3;
		}
	}
	
	if(val1 == 1 || val2 == 1){
		list l3;
		initList(&l3);
		
		node* ptr1 = l1;
		node* prt2 = l2;
		if(ptr1 -> data == 1){
			assignTheValueToNullList(l2,&l3);
		}
		
		else{ //ptr2 -> data == 1 
			assignTheValueToNullList(l1,&l3);
		}
		return l3;
	}
	
	int m = reverse(&l1), n = reverse(&l2);
	list l3 = make_empty_list(m + n + 1);
	
        node *second_ptr = l2,
        *result_ptr1 = l3, *result_ptr2, *first_ptr;

    	while (second_ptr) {
 
        int carry = 0;
        result_ptr2 = result_ptr1;
        first_ptr = l1;
         
        while (first_ptr) {
        
            int mul = first_ptr->data * second_ptr->data+ carry;
            result_ptr2->data += mul % 10;

            carry = mul / 10 + result_ptr2->data / 10;
            result_ptr2->data = result_ptr2->data % 10;
 
            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }
 
        // if carry is remaining from last multiplication
        if (carry > 0) {
            result_ptr2->data += carry;
        }
 
        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }
 
    // reverse the result_list as it was populated
    // from last node
    reverse(&l3);
    
 
    // remove if there are zeros at starting
    while (l3->data == 0) {
        node* temp = l3;
        l3 = l3->next;
        free(temp);
    }
    
 
 
    // Return head of multiplication list

    return l3;
}	

list subtractList(list *l1,list *l2){

	list l3;
	initList(&l3);
	
	reverse(l1);
	reverse(l2);
	
        node* ptr1 = *l1;
    	node* ptr2 = *l2;
     
    	int borrow = 0;

    	while (ptr1 != NULL || ptr2 != NULL) {
        	int digit1 = (ptr1 != NULL) ? ptr1->data : 0;
        	int digit2 = (ptr2 != NULL) ? ptr2->data : 0;
        	int diff = digit1 - digit2 - borrow;

        	// handle borrow
        	if (diff < 0) {
        	   	 diff += 10;
        	    	borrow = 1;
        	}
        	 else {
        	    	borrow = 0;
        	}
	
		append(&l3,diff);
	
        	// move to the next digits in the two lists
        	
        	if (ptr1 != NULL) {
            		ptr1 = ptr1->next;
        	}
        	
        	if (ptr2 != NULL) {
            		ptr2 = ptr2->next;
        	}
    	}	    
    //free the zero number in the list  
    	/*while (l3 != NULL && l3->data == 0){
      	  	node* temp = l3;
      	 	l3 = l3->next;
        	free(temp);
    	}*/
	reverse(l1);	
	reverse(l2);
    	reverse(&l3);

    	
    	return l3;
}

int compareList(list l1, list l2){
	
	int p = countList(l1);
	int q = countList(l2);
		
	if(q > p)
		return 0;
	else if(p > q)	
		return 1;
	
		
	node* first = l1;
	node* second = l2;
	
	while(first && second){
		if(second -> data > first -> data)
			return 0;
		else if(first -> data > second -> data)
			return 1;
			
		first = first -> next;
		second = second -> next;
			
	}
	
	return 1;
}
 
 list divideList(list *l1 , list *l2){
 	if(!*l1){
 		return *l2;
 	}
 	
 	if(!*l2){
 		return *l1;
 	}
 	
 	list l3;
	initList(&l3);
	
	node* ptr1 = *l1;
	node* ptr2 = *l2;
	
	int val1 = countList(*l1);
	int val2 = countList(*l2);
	
	if(val1 == 1 && ptr1 -> data == 0 ){
		append(&l3 ,0);
		display(l3);
		return l3;
	}
	
	if(val2 == 1 && ptr2 -> data == 0){
		printf("Divide by zero Error\n");
		return NULL;	
	}
	
	else if(val1 == 1 || val2 == 1){
		if((val2 > 1 && ptr1 -> data == 1)){
			append(&l3 , 0);
		}
		
		if(val1 > 1 && ptr2 -> data == 1){ //ptr2 -> data == 1 && val1 > 1
			assignTheValueToNullList((*l1),&l3);
		}
	  display(l3);	
	  return l3;
	}
 	
 	list result,one;
 	initList(&result);
 	initList(&one);
 	append(&result , 0);
 	append(&one , 1);

	if(isZero(*l1)){
		return result;
	} 
	
	list temp = *l2;
	list aux = *l2;
	
	
	while(compareList(*l1,temp)){
		reverse(&temp);
		result = addList(&result, &one);
		temp = addList(&temp , &aux);
		reverse(&temp);
		
		
 	}
 	reverse (&result);
 	return result;
}

list mod(list l1 , list l2){
	list l3;
	initList(&l3);
	
	long val1 = listToNumber(&l1);
	long val2 = listToNumber(&l2);
	
	if(val1 == 0){
		append(&l3,0);
		return l3 ;
	}
	
	if(val2 == 0){
		printf("mod by zero error");
		exit(0);
	}
	
	long answer = val1 % val2;

	createLL(&l3 ,answer);
	
	display(l3);
	return l3;
}

void init_stack(stack *s){
    s-> top = NULL;
    return;
}

int isEmpty(stack s){
   return s.top == NULL;
}

void push_stack(stack *s, list data){
   snode* nn = (snode*)malloc(sizeof(snode));
   nn -> data = data;	
   nn -> next = NULL;
   
   if(isEmpty(*s)){
      s->top = nn;
      return;
   }
   
   nn -> next = s->top;
   s->top = nn;
   printf("\n");
   return;
}


list pop_stack(stack *s){
   if(isEmpty(*s)){
       return NULL;
   }
   snode* temp = s->top; 
   list ele = temp->data;
   s->top = s->top->next;
   free(temp);  
   return ele;
   
}

void display_stack(stack s){
   if(isEmpty(s)){
      return;
   }
    //printf("Disp 1");
   while(s.top){
      //printf("%d\n",s.top -> data);
      s.top = s.top -> next;
   }
   return;
}

list peek(stack s){
    if(isEmpty(s)){
        return NULL;
    }
    
    return s.top->data;
}

char* InfixToPostfix(stack *s , char *infix){
	
}

