#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node *start,*last,*nn,*pt,*temp,*ppt;
struct node *makenode(int);
void insertnode(void);
void traverser(void);
void deletenode(void);
struct node *makenode(int n)
{
	struct node *pp;
	pp=(struct node *)malloc(sizeof(struct node));
	pp->num=n;
	pp->next=NULL;
	return pp;
}
void insertnode()
{
	int n;
	while(1)
	{
		cout<<"\n Enter a number to add : ";cin>>n;
		if(n==0)
			break;
		nn=makenode(n);
		if(start==NULL)
			start=last=nn;
		else
		{
			last->next=nn;
			last=nn;
		}
	}
}
void traverser()
{
	for(pt=start;pt!=NULL;pt=pt->next)
	cout<<"\n"<<pt->num;
}
void deletenode()
{
	int delnum;
	cout<<"Enter a node to delete : ";cin>>delnum;
	for(ppt=pt=start;pt!=NULL && pt->num!=delnum;ppt=pt,pt=pt->next);
	if(pt==NULL)
	cout<<"Delete node not found!! ";
	else if(pt==start)
	{
		temp=start;
		if(start==last)
		{
			start=last=NULL;
		}
		else
		{
			start=start->next;
		}
		printf("Delete node : %d",*temp);
		free(temp);
	}
	else if(pt==last)
	{
		temp=pt;
		ppt->next=NULL;
		last=ppt;
		printf("%d",*temp);
		free(temp);
	}
	else
	{
		temp=pt;
		ppt->next = pt->next;
	}
}
void main()
{
	int ch;
	while(4)
	{
		cout<<"\n1. Add node";
		cout<<"\n2. Traverser";
		cout<<"\n3. Delete node";
		cout<<"\n4. Exit";
		cout<<"\nChoose an option from above : ";cin>>ch;

		if(ch==4)
		break;
		switch(ch)
		{
			case 1:
				insertnode();
				break;
			case 2:
				traverser();
				break;
			case 3:
				if(start==NULL)
				cout<<"Empty list";
				else
				deletenode();
				break;
			case 4:
				break;
			default:
				cout<<"Invalid Choice!!";
		}
	}
}
