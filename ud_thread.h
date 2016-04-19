/* 
 * thread library function prototypes
 */
#include <stdlib.h>
#include <ucontext.h>
#include <stdio.h>
 #include <unistd.h>
#include <sys/types.h>
#include <pthread.h>




struct tcb {
	int thread_id;
	int thread_priority;
	ucontext_t  thread_context;
	struct tcb *next;
       };



void t_create(void(*function)(int), int thread_id, int priority);
void t_yield(void);
void t_init(void);
void t_shutdown();
void t_terminate();




void clear();
int append_list_entry(struct tcb* entry, struct tcb* head);
int remove_list_entry(struct tcb* entry,struct tcb* head);
int move_list_entry(struct tcb* entry,struct tcb* head1, struct tcb* head2);
void print_list();
void appendT(struct tcb **temp);

