#include<iostream>
#include<queue>
using namespace std;
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *lchild,*rchild; 
}bintnode;
typedef bintnode *bintree;

void createbintree(bintree &t)
{
//���������������������У�������������
    int ch;
    cin>>ch;
    if(ch==-1) t=NULL;//�������ո��ַ������������� 
    else
    {
        t=new bintnode;
        t->data=ch;
        createbintree(t->lchild);//������������������������������ÿͻ��˼������� 
        createbintree(t->rchild);//���������������������������� 
    } //�ݹ���ã��Զ�����
}
void preorder(bintree t)
{
    if(t)
    {
        cout<<t->data<<' ';//�ȷ��ʸ���㣬�ٱ��������������������� 
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void inorder(bintree t)
{
    if(t)
	{
        inorder(t->lchild);
        cout<<t->data<<' ';
        inorder(t->rchild);
    }
}
void postorder(bintree t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' ';
    }
}
void levertravel(bintree t)
{
    queue<bintree> q;
    if(t!=NULL)
    q.push(t);
    bintree b;
    while(!q.empty())
    {
        b=q.front();
        cout<<b->data<<' ';
        q.pop();
        if(b->lchild) q.push(b->lchild);
        if(b->rchild) q.push(b->rchild);
	}
}
int main()
{
    bintree t=NULL;
    createbintree(t);
    cout<<"ǰ�����: ";
    preorder(t);
    cout<<endl<<"�������: ";
    inorder(t);
    cout<<endl<<"�������: ";
    postorder(t);
    cout<<endl<<"��α���: ";
    levertravel(t);
    cout<<endl;
    return 0;
}
