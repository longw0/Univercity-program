#include <iostream>
#define initsize 100;
typedef int intt;
using namespace std;
typedef struct
{
	int top;
	intt * base;
	int stacksize;
}sqstack;

void initstack(sqstack * s)
{
	s->base = (intt*)malloc(100 * sizeof(intt));
	s->top = 0;
	s->stacksize = initsize;
}

int push(sqstack *s, intt x)
{
	if (s->top >= s->stacksize)
	{
		s->base = (intt*)realloc(s->base,(s->stacksize + 1) * sizeof(intt));
		if (!s->base)
		{
			return 0;
		}
		s->stacksize++;
	}
	s->base[s->top] = x;
	s->top++;
	return 1;
}

int pop(sqstack *s, intt *e)
{
	if (s->top == 0)
	{
		return 0;
	}
	s->top--;
	*e = s->base[s->top];
	return 1;
}

void list(sqstack *s)
{
	for (int i = s->top - 1; i >= 0; i--)
	{
		cout << s->base[i] << "  ";
	}
}

int main()
{
	int a;
	sqstack s;
	initstack(&s);
	while (1)
	{
		cout << "1-压栈，2-弹栈，0-退出" << endl;
		cin >> a;
		if (a == 1)
		{
			intt in;
			cout << "请输入压栈值： ";
			cin >> in;
			cout << endl;
			push(&s,in);
		}
		else if (a == 2)
		{
			intt out;
			pop(&s,&out);
			cout << "弹栈的值为：" << out << endl;
		}
		else
		{
			break;
		}
	}
	list(&s);
	return 0;
}

非递归法算叠乘
long fac(int n)
{
	long f = 1; int x; stack s;
	initstack(&s);
	while (n > 0)
	{
		push(&s, n);
		n--;
	}
	while (getlen(&s))
	{
		pop(&s, &x);
		f *= x;
	}
	return f;
}
