#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define NWORDS 17
#define MAXLEN 1000

char *WORDS[] = {
	"hot", "dot", "dog", "lot", "log", "lit", "bit", "bat", "bam", "hop",
	"him", "hat", "mat", "man", "hum", "but", "bun", "cot"};


struct dict_t {
	char **items;
	int num_items;
	int max_items;
};
typedef struct dict_t Dict;

Dict *create_dict(int max_items);
void destroy_dict(Dict *dict);
int add_item(Dict *dict, char *item);
int contains(Dict *dict, char *item);


struct queue_t {
	char **items;
	int front;
	int back;
	int num_items;
	int max_items;
};
typedef struct queue_t Queue;

Queue *create_queue(int max_items);
void destroy_queue(Queue *queue);
int enqueue(Queue *queue, char *item);
char *dequeue(Queue *queue, int n);
char *peak(Queue *queue);
int num_items(Queue *queue);


void bfs(Queue *word_queue, char *end, int depth, Dict *dict);
char **get_children(char *word, int *nc, Dict *dict);


int main(void)
{
	char *start = "hit";
	char *end = "cog";
	
	Queue *word_queue;
	Dict *dict;
	int i;

	word_queue = create_queue(MAXLEN);
	dict = create_dict(MAXLEN);
	for (i = 0; i < sizeof(WORDS) / sizeof(char *); i++)
		add_item(dict, WORDS[i]);
	add_item(dict, end);

	enqueue(word_queue, start);
	i = bfs(word_queue, end, 0, dict);

	destroy_queue(word_queue);
	destroy_dict(dict);

	return 0;
}


Queue *create_queue(int max_items)
{
	Queue *queue;

	queue = (Queue *) malloc(sizeof(Queue));
	queue->items = (char **) malloc(max_items * sizeof(char *));
	queue->front = queue->back = queue->num_items = 0;
	queue->max_items = max_items;

	return queue;
}


void destroy_queue(Queue *queue)
{
	free(queue->items);
	free(queue);

	return;
}


int enqueue(Queue *queue, char *item)
{
	if (queue->num_items == queue->max_items)
		return -1;

	queue->items[queue->back] = item;
	queue->back = (queue->back + 1) % queue->max_items;
	queue->num_items++;

	return 0;
}


char *peak(Queue *queue, int n)
{
	if (queue->num_items == 0)
		return NULL;

	if (n < 0 || n >= queue->num_items)
		return NULL;

	return queue->items[(queue->front + n) % queue->max_items];
}


char *dequeue(Queue *queue)
{
	char *item;

	if (queue->num_items == 0)
		return NULL;

	item = queue->items[queue->front];
	queue->front = (queue->front + 1) % queue->max_items;
	queue->num_items--;

	return item;
}


int num_items(Queue *queue)
{
	return queue->num_items;
}


Dict *create_dict(int max_items)
{
	Dict *dict;
	int i;

	dict = (Dict *) malloc(sizeof(Dict));
	dict->items = (char **) malloc(max_items * sizeof(char *));
	for (i = 0; i < dict->num_items; i++)
		dict->items[i] = "";

	dict->num_items = 0;
	dict->max_items = max_items;

	return dict;
}


void destroy_dict(Dict *dict)
{
	free(dict->items);
	free(dict);

	return;
}


int add_item(Dict *dict, char *item)
{
	if (dict->num_items == dict->max_items)
		return -1;

	dict->items[dict->num_items++] = item;

	return 0;
}


int contains(Dict *dict, char *item)
{
	int i;

	for (i = 0; i < dict->num_items; i++)
		if (strcmp(dict->items[i], item) == 0)
			return 1;

	return 0;
}



int bfs(Queue *word_queue, char *end, int depth, Dict *dict)
{
	int i, n, nc;
	
	n = num_items(word_queue);

	for (i = 0; i < n; i++) {
		word = dequeue(word_queue);
		if (strcmp(word, end) == 0)
			return depth;

		children = get_children(word, &nc, dict);
		for (i = 0; i < nc; i++)
			enqueue(word_queue, children[i]);
	}

	return bfs(word_queue, end, depth + 1);
}


char **get_children(char *word, int *nc, Dict *dict)
{
	char *children[20];

	for 
