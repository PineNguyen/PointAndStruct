#include <bits/stdc++.h>
using namespace std;

struct node{
	float heso;
	int mu;
	node *next;
};

void Inp(node *&L)
{ 
	node *P,*C;
	do {
		P= new node;
		cout<<"He so:";
		cin>>P->heso;
		cout<<"So mu:";
		cin>>P->mu;
		P->next=NULL;
		if (L==NULL)
		{
			L=P;
			C=P;
		}
		else {
			C->next=P;
			C=P;
		}
	} while (P->mu!=0);
}

void Outp(node *L)
{
	node *P;
	P=L;
	while (L!=NULL)
	{
		if (P->mu>0) cout<<P->heso<<"x^"<<P->mu;
		else cout<<P->heso;
		if (P->next!=NULL) cout<<" + ";
		P=P->next;
	}
}

void congdt(node *L1,node *L2,node *LC)
{
	while (L1->next && L2->next) {
        if (L1->mu > L2->mu) {
            LC->mu = L1->mu;
            LC->heso = L1->heso;
            L1 = L1->next;
        }
        else if (L1->mu < L2->mu) {
            LC->mu = L2->mu;
            LC->heso = L2->heso;
            L2 = L2->next;
        }
        else {
            LC->mu = L1->mu;
            LC->heso = L1->heso + L2->heso;
            L1 = L1->next;
            L2 = L2->next;
        }	
        LC->next= (struct node*)malloc(sizeof(struct node));
        LC= LC->next;
        LC->next = NULL;
	}
    while (L1->next || L2->next) {
        if (L1->next) {
            LC->mu = L1->mu;
            LC->heso = L1->heso;
            L1 = L1->next;
        }
        if (L2->next) {
            LC->mu= L2->mu;
            LC->heso= L2->heso;
            L2 = L2->next;
        }
        LC->next= (node*)malloc(sizeof(node));
        LC = LC->next;
        LC->next = NULL;
    }
}

void trudt(node *L1,node *L2,node *LT)
{
    while (L1->next && L2->next) {
        if (L1->mu > L2->mu) {
            LT->mu = L1->mu;
            LT->heso = L1->heso;
            L1 = L1->next;
        }
        else if (L1->mu < L2->mu) {
            LT->mu = L2->mu;
            LT->heso = L2->heso;
            L2 = L2->next;
        }
        else {
            LT->mu = L1->mu;
            LT->heso = L1->heso - L2->heso;
            L1 = L1->next;
            L2 = L2->next;
        }
        LT->next= (node*)malloc(sizeof(node));
        LT = LT->next;
        LT->next = NULL;
    }
    while (L1->next || L2->next) {
        if (L1->next) {
            LT->mu = L1->mu;
            LT->heso = L1->heso;
            L1 = L1->next;
        }
        if (L2->next) {
            LT->mu = L2->mu;
            LT->heso = L2->heso;
            L2 = L2->next;
        }
        LT->next=(node*)malloc(sizeof(node));
        LT = LT->next;
        LT->next = NULL;
    }
}

main()
{
	node *L1=NULL,*L2=NULL,*LC=NULL,*LT=NULL;
	cout<<"Nhap da thuc A:"<<endl;
	Inp(L1);
	cout<<"Nhap da thuc B:"<<endl;
	Inp(L2);
	cout<<"A=";
	Outp(L1);
	cout<<endl;
	cout<<"B=";
	Outp(L2);
	cout<<endl;
	LC=(node*)malloc(sizeof(node));
    congdt(L1, L2, LC);
	Outp(LC);
	cout<<endl;
	LT= (node*)malloc(sizeof(node));
    trudt(L1, L2, LT);
	Outp(LT);
	return 0;
}
