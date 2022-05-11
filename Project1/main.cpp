#include<iostream>
#include<cmath>
#include<stack>
#include<string>

using namespace std;
struct dict
{
    int height=0;
    int num;
};
struct tree
{
    struct node
    {
        dict info;
        node* l, * r;
    };
    void push(int num);
    void print();
    void switch_tree();
    int left_height=0;
    int right_height=0;
    int h = 0;
    void delete_leaf();
private:

    node* tree1 = NULL;
    void push1(dict a, node** t);
    void print1(node* t);
    int check = 0;
    int max_count = -1;
    void switch_tree1(node* t);
    void delete_leaf1(node*t,int local_h);
};
void tree::print()
{
    print1(tree1);
}
void tree::switch_tree()
{
    switch_tree1(tree1);
}

void tree::delete_leaf()
{
    if (left_height > right_height)
    {
        h = left_height / 2;
    }
    else h = right_height / 2;
    delete_leaf1(tree1,0);
}

void tree::delete_leaf1(node* t, int local_h)
{
    if (t == NULL|| local_h == h) return;
    if (t->l->info.height == t->r->info.height)
    {
        t->l->info.num = NULL;
        t->r->info.num = NULL;
    }
    if (t == NULL || local_h == h) return;
    else
    {
        local_h++;
        delete_leaf1(t->l,local_h);
        
       


    }
    delete_leaf1(t->r,local_h);

}
void tree::print1(node* t)
{
    if (t == NULL) return;
    else
    {
        print1(t->l);
        if (t->info.num != NULL)
        {
            cout << t->info.num << endl;
        }
           
       

    }
    print1(t->r);
}

void tree::switch_tree1(node* t)
{
   if (t == NULL) return;
    else
    {
       switch_tree1(t->l);
        
       node* s;
       s = t->l;
       t->l = t->r;
       t->r = s;
       

    }
   switch_tree1(t->r);
}




void tree::push(int num)
{
    dict a;
        a.num= num;
    push1(a, &tree1);
}
void tree::push1(dict a, node** t)
{
    if ((*t) == NULL)
    {
        (*t) = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        check = 0;
        return;
    }
    if (a.num > (*t)->info.num)
    {
        if (check == 0)
        {
            right_height++;
            a.height = right_height;
        }

       check = 1;
        push1(a, &(*t)->r);
       

    }
    else 
    {
        if (check == 0)
        {
            left_height++;
            a.height = left_height;
        }
        check = 1;
        
        push1(a, &(*t)->l);

    }

}



void task1()
{
    tree t;
    t.push(3);
    t.push(5);
    t.push(2);
    t.print();
    t.switch_tree();
    cout << endl;
    t.print();
}
///////////////////////////////Task2////////////////////////

void task2()
{
    tree t;
    t.push(3);
    t.push(5);
    t.push(2);
    t.push(4);
    cout << t.left_height << endl;
    cout << t.right_height << endl;
    cout << endl;
    t.print();
    cout << endl;
    t.delete_leaf();
    t.print();
}
///////////////////////////////Task3////////////////////////

struct dict1
{
   
    int count;
};
struct tree1
{
    struct node
    {
        dict1 info;
        node* l, * r;
    };
    void push(int a);
    void print();
    double evaluate1();
private:
    
    node* tree2 = NULL;
    void push1(dict1 a, node** t);
    void print1(node* t);

    double evaluate(node* root);

};
void tree1::push(int a)
{
    dict1 b;
    b.count = a;
    push1(b, &tree2);
}

void tree1::push1(dict1 a, node** t)
{
    if ((*t) == NULL)
    {
        (*t) = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;

        return;
    }
    if (a.count > (*t)->info.count)
    {
        push1(a, &(*t)->r);

    }
    else push1(a, &(*t)->l);

}
void tree1::print()
{
    print1(tree2);
}
double tree1::evaluate1()
{
   return evaluate(tree2);
}

void tree1::print1(node* t)
{
    if (t == NULL) return;
    else
    {
        print1(t->l);
        
        cout << t->info.count << endl;
       

    }
    print1(t->r);
}

double tree1::evaluate(node* root)
{
    if (root == nullptr) {
        return 0;
    }

    if (root->l == nullptr && root->r == nullptr) {
        return (root->info.count);
    }
    
    double x = evaluate(root->l);
    double y = evaluate(root->r);
    if (root->l == nullptr)
    {
        x = root->info.count;
    }
    if (root->r == nullptr)
    {
        y = root->info.count;
    }
    return x-y;
}




void task3(char *arr, int size)
{
    int c;
    srand(time(NULL));
    tree1 t;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]=='x'||arr[i]=='y')
        {
            if (rand() % 100 > 50)
            {
                arr[i] = '0';
            }
            else arr[i] = '1';
        }
    }
    for (int i = 0; i < size; i++)
    {
        if ((arr[i]== '0'||arr[i]=='1')&&(arr[i-1]!='|'&&arr[i+1]!='|')&& (arr[i - 1] != '&' && arr[i + 1] != '&'))
        {
            
            c = arr[i] - '0';
            t.push(c);
        }
        if (arr[i]=='&')
        {
            int a,b;
            a = arr[i - 1] - '0';
            b = arr[i + 1] - '0';
            a += b;
            t.push(a);
        }
        if (arr[i]=='|')
        {
            if (rand() % 100 > 50)
            {
               c= arr[i-1] - '0';
            }
            else c = arr[i+1] - '1';
            t.push(c);
        }

    }
    t.print();
    
    cout << t.evaluate1() << endl;

}


////////////////////////////////////////////////////Task4///////////////////////

int task4(int **arr, int size)
{
    int check=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size; i++)
        {
            if (arr[i][j]==1)
            {
                check++;
            }
        }
        if (check != 2)
        {
            cout << "������� ��������" << endl;
            return 1;

        }
        else
        {
            check = 0;
        }
    }
    cout << "������� �� ����" << endl;
    return 0;
}



int main()
{
	setlocale(LC_ALL, "rus");
    char arr[20]{ "x|y-x&y" };
    //task3(arr,7);
    int** arr2 = new  int*[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[3];
    }
    arr2[0][0] = 0;
    arr2[0][1] = 1;
    arr2[0][2] = 1;
    arr2[1][0] = 1;
    arr2[1][1] = 0;
    arr2[1][2] = 1;
    arr2[2][0] = 1;
    arr2[2][1] = 1;
    arr2[2][2] = 0;

    task4(arr2, 3);

	return 0;
}


