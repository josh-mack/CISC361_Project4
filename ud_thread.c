
#include "ud_thread.h"


typedef struct tcb ready;
typedef struct tcb running;
struct tcb* head_ready;
struct tcb* head_running;


int main(char* argv){
	t_init();

	struct tcb* t1 = calloc(1, sizeof(struct tcb));
	t1 -> thread_id = 1;
	struct tcb* t2 = calloc(1, sizeof(struct tcb));
	t2 -> thread_id = 2;
	struct tcb* t3 = calloc(1, sizeof(struct tcb));
	t3 -> thread_id = 3;
	struct tcb* t4 = calloc(1, sizeof(struct tcb));
	t4 -> thread_id = 4;
	struct tcb* t5 = calloc(1, sizeof(struct tcb));
	t5 -> thread_id = 5;
	struct tcb* t6 = calloc(1, sizeof(struct tcb));
	t6 -> thread_id = 6;
	struct tcb* t7 = calloc(1, sizeof(struct tcb));
	t7 -> thread_id = 7;
	struct tcb* t8 = calloc(1, sizeof(struct tcb));
	t8 -> thread_id = 8;
	struct tcb* t9 = calloc(1, sizeof(struct tcb));
	t9 -> thread_id = 9;
	struct tcb* t10 = calloc(1, sizeof(struct tcb));
	t10 -> thread_id = 10;


	append_list_entry(t1, head_running);
	append_list_entry(t2, head_running);
	append_list_entry(t3, head_running);
	append_list_entry(t4, head_running);
	append_list_entry(t5, head_running);
	append_list_entry(t6, head_running);
	append_list_entry(t7, head_running);
	append_list_entry(t8, head_running);
	append_list_entry(t9, head_running);
	append_list_entry(t10, head_running);

	print_list(head_ready);
	print_list(head_running);

	
	remove_list_entry(t5, head_running);
	move_list_entry(t6, head_running, head_ready);
	remove_list_entry(t6, head_ready);



printf("\nREMOVED\n\n");
	print_list(head_ready);
	print_list(head_running);
}


void t_init(){
	
	head_ready = (struct tcb*)malloc(sizeof(struct tcb));
	head_running = (struct tcb*)malloc(sizeof(struct tcb));
	head_ready->next = NULL;
	head_running->next = (struct tcb*)malloc(sizeof(struct tcb));
	(head_running->next)->thread_id = pthread_self();
	(head_running->next)->next = NULL;

}


int remove_list_entry(struct tcb* entry, struct tcb* head)
{
	struct tcb **indirect = &head;
	while((*indirect) != entry){
		indirect = &((*indirect)->next);
	}
	*indirect = entry->next;
	
}


int move_list_entry(struct tcb* entry, struct tcb* head1,struct tcb* head2)
{
	struct tcb **indirect1 = &head1;
	struct tcb **indirect2 = &head2;

	while((*indirect1) != entry){
		indirect1 = &((*indirect1)->next);
	}
	*indirect1 = entry->next;
//APPEND
	
	while((*indirect2)->next != NULL){
		indirect2 = &((*indirect2)->next);
	}
	(*indirect2)->next = entry;
	entry->next = NULL;
	


	
}


void print_list(struct tcb* head){
	struct tcb **indirect = &head;
	if((*indirect) != NULL){
		indirect = &((*indirect)->next);
	}
	while((*indirect) != NULL){
		if(head == head_ready){
			printf("READY %d\n",(*indirect)->thread_id);
		}
		else{
			printf("RUNNING %d\n",(*indirect)->thread_id);
		}
		indirect = &((*indirect)->next);
	}
}

int append_list_entry(struct tcb* entry, struct tcb* head)
{
	struct tcb **indirect = &head;
	while((*indirect)->next != NULL){
		indirect = &((*indirect)->next);
	}
	(*indirect)->next = entry;
	entry->next = NULL;
	
}

