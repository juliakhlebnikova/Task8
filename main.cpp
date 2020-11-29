#include <iostream>
#include <stdlib.h>


using namespace std;

struct Tr
{
    int k;
    int w;
    Tr *left, *right;
};

Tr *tree = NULL;


//�������� �������
void push(int a, Tr **t)
{
    if ((*t) == NULL)
    {
        (*t) = new Tr;
        (*t)->k = a;
        int r;
        r = rand()%3 - 1;
        (*t)->w = r;
        (*t)->left = (*t)->right = NULL;
        return;
    }
    else
        if (a > (*t)->k)
            push(a, &(*t)->right);
        else
            push(a, &(*t)->left);
}

//B����
void print (Tr *t, int u)
{
    if (t == NULL)
        return;
    else
    {
        print(t->left, ++u);
        for (int i=0; i<u; ++i)
            cout << "   ";
        cout << t->k << endl;
        u--;
    }
    print(t->right, ++u);
}

int m = -1;

//����� ������������ �������, ��� ������� ����� 1;
void max (Tr *t)
{
    if (t == NULL)
        return;
    else
    {
        max(t->left);
        if (t->k>m && t->w ==1)
            m = t->k;
    }
    max(t->right);
}

//B���� � ������
void printw (Tr *t, int u)
{
    if (t == NULL)
        return;
    else
    {
        printw(t->left, ++u);
        for (int i=0; i<u; ++i)
            cout << "       ";
        cout << t->k <<"("<< t->w << ")" << endl;
        u--;
    }
    printw(t->right, ++u);
}


//�������� ��������
Tr* del(Tr* node, int val)
{
    if(node == NULL)
        return node;

    if(val == node->k)
    {
        Tr* q;
        if(node->right == NULL)
            q = node->left;
        else
        {
            Tr* r = node->right;
            if(r->left == NULL)
            {
                r->left = node->left;
                q = r;
            }
            else
            {
                Tr* m = r->left;
                while(m->left != NULL)
                {
                    r  = m;
                    m = r->left;
                }
                r->left   = m->right;
                m->left  = node->left;
                m->right = node->right;
                q = m;
            }
        }
        delete node;
        return q;
    } else if(val < node->k)
        node->left  = del(node->left, val);
    else
        node->right = del(node->right, val);
    return node;
}


int main ()
{
    int n;
    n=7;
    int s;

    for (int i=0; i<n; ++i)
    {
        s = rand() % 30;
        push(s, &tree);
    }

    cout << "1. push" <<endl;
    cout << "2. delete" <<endl;
    cout << "3. print" <<endl;
    cout << "4. print with weight" <<endl;
    cout << "5. max with >0 weight" <<endl;
    cout << "6. exit" <<endl;

    cout << endl;
    int c;
    cout << "Enter:";
    cin >> c;

	int p;
	int y;
	while (c!=0)
    {
        switch (c)
        {
            case 1: //�������� �������
            {
                cin >> p;
                push(p, &tree);
                cout << endl;
                break;
            }
            case 2: //������� �������
            {
                //f = 1;
                cin >> y;
                tree = del(tree, y);
                cout << endl;
                break;
            }
            case 3:  //����� ��� �����
            {
                print(tree, 0);
                cout << endl;
                break;
            }
            case 4: //����� � ������
            {
                printw(tree, 0);
                cout << endl;
                break;
            }
            case 5:  //���������� � ������������� �����
            {
                m = -1;
                max(tree);
                cout << m << endl;
                cout << endl;
                break;
            }
            case 6: //�����
            {
                return 0;
            }
            default:
            {
                cout << "Mistake" <<endl;
                break;
            }
        }
        cout << "Enter:";
        cin >> c;
    }
    return 0;
}
