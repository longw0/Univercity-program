#include <iostream>
using namespace std;
#define maxsize 100;
typedef struct
{
	int *base;
	int front;
	int rear;
}cqueue;

void initcqueue(cqueue *cq)
{
	cq->base = (int *)malloc(100 * sizeof(int));
	cq->front = cq->rear = 0;
}

int inqueue(cqueue *cq, int x)
{
	/*if ((cq->rear + 1) % (maxsize) == cq->front)
	{
		return 0;
	}*/
	cq->base[cq->rear] = x;
	cq->rear = (cq->rear + 1) % maxsize;
	return 1;
}

int outqueue(cqueue *cq, int *x)
{
	if (cq->rear == cq->front) return 0;
	*x = cq->base[cq->front];
	cq->front = (cq->front + 1) % maxsize;
	return 1;
}

void list(cqueue *cq)
{
	int i=cq->front;
	cout << "this queue is ";
	while (i != cq->rear)
	{
		cout << cq->base[i] << " ";
		i = (i + 1) % maxsize;
	}
	cout << endl;
}

int main()
{
	cqueue cq;
	initcqueue(&cq);
	int a;
	while (1)
	{
		cout << "0 -- In    1 -- Out    2 -- Quit  " << endl;
		cin >> a;
		if (a == 0)
		{
			int in;
			cin >> in;
			inqueue(&cq, in);
		}
		else if (a == 1)
		{
			int out;
			outqueue(&cq, &out);
			cout << out << endl;
		}
		else
		{
			break;
		}

	}
	list(&cq);
	return 0;
}
