
#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;

int width = 1350;
int height = 900;
int radius = 25;
int h = 30;

struct Node { ///first, build a structure to have different types of data types bundled together and named it as Node
    int data; /// here we define a data variable of int type and this contains the data of the node

     Node *left;///every node has a basic characteristic that it contains left node and right node and since
     Node *right;/// the left node and right node are also nodes therefore its type is Node
    Node(int data1) ///constructer to inittialise the node
    {
        data = data1; ///assigning value to data
        left = NULL; ///left pointer is initialised as Null to avoid any segementation fault
        right = NULL;///similarly right pointer is also initialised as Null
    }
};
void Delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
}

void graph(int i, int Y, int X, int data)  // X= 1350, Y= 30
{
	
	if(i==0)///left
	{
		circle(X/2,Y,radius);
		
		//line(X/2-radius,Y-radius);
		
		char dataCon[2];
		settextstyle(1,0,2);
		sprintf(dataCon, "%d", data); 
		outtextxy(X/2-16,Y-15,dataCon);
	}
	
}
int diff = 38;
int i = 10;

//topH = 30, Hor = 1350
void Inorder(Node * node, int topH, int Hor) ///we define a recursive function that takes the Node type argument, since its inorder we print in this way->left, root, right
{
    if(node == NULL) ///then check the NULL for pointer, as NULL depicts that there is no further child from that node.
    {
        return; ///its an exit statement from the recursive function and shows that we have reached the end of tree
    }
    
    i-- ;
    if(node->left !=NULL)
    	line(Hor/2-radius/1.41,topH+radius/1.41,(Hor-100-diff*i)/2+radius/1.41,topH+80-radius/1.41);
    Inorder(node->left,topH+80,Hor-100-diff*i); ///as we have used Inorder traversal we first traverse the left subtree and goes to depth
	Delay(3);
    graph(0,topH,Hor,node->data);//cout<<node->data<<" , ";///if inorder() returns because of node == null condition then we print the data of that node;
	if(node->right !=NULL)
    	line(Hor/2+radius/1.41,topH+radius/1.41,(Hor+120+diff*i)/2-radius/1.41,topH+80-radius/1.41);
    Inorder(node->right,topH+80,Hor+120+diff*i);///once the left subtree is fully traversed then we traverse the right subtree	
}

int j =10;
void Inorder2(Node * node, int topH, int Hor) ///we define a recursive function that takes the Node type argument, since its inorder we print in this way->left, root, right
{
    if(node == NULL) ///then check the NULL for pointer, as NULL depicts that there is no further child from that node.
    {
        return; ///its an exit statement from the recursive function and shows that we have reached the end of tree
    }
    
    j-- ;
    if(node->left !=NULL)
    	line(Hor/2-radius/1.41,topH+radius/1.41,(Hor-100-diff*j)/2+radius/1.41,topH+80-radius/1.41);
    Inorder2(node->left,topH+80,Hor-100-diff*j); ///as we have used Inorder traversal we first traverse the left subtree and goes to depth
    graph(0,topH,Hor,node->data);//cout<<node->data<<" , ";///if inorder() returns because of node == null condition then we print the data of that node;
	if(node->right !=NULL)
    	line(Hor/2+radius/1.41,topH+radius/1.41,(Hor+120+diff*j)/2-radius/1.41,topH+80-radius/1.41);
    Inorder2(node->right,topH+80,Hor+120+diff*j);///once the left subtree is fully traversed then we traverse the right subtree	
}

int main()
{
	int gd=0,gm;
	initwindow(width,height);
	initgraph(&gd,&gm,NULL);
    cout<<"enter the height of binary tree starting from 0 as root\n";
    int n;
    cin>>n;
    int height = n;
    n = pow(2,n+1)-1; //number of nodes
    cout<<n<<endl;
    int arry[n];
    system("cls");
    cout<<endl<<"enter the node value using 2n+1 and 2n+2 rule...enter 0 if there is no child node of a node\n";
    for(int i = 0;i<n;i++)
    {
        cin>>arry[i];
        cout<<endl;
    }
    system("cls");
	Node *node[n];
	
	for(int i = 0;i<n;i++)
	{
		node[i] = new Node(arry[i]);
	}
	
	for(int i=0;i<(pow(2,height)-1);i++)
	{
		node[i]->left = node[2*i+1];
		node[i]->right = node[2*i+2];
	}
	system("cls");
    Delay(10);
    Inorder2(node[0],30,1350);
    outtextxy(280,300,"Traversing Binary tree using DFS inorder traversal method");
    Delay(3);
    Inorder(node[0],350,1350);
	//makeLine(node,30,1350);
	closegraph();
	getch();
	
	return 0;
}
