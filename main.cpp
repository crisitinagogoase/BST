#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
int ascending[100],descending[100],a,d,Hufflepuff,  Gryffindor,  Ravenclaw,  Slytherin;;
//recursive definition
template<typename T> class BinarySearchTree {
    public:
        //current node has references to: root, left child, right child, parent
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        //current node info
        T *pinfo;

        //constructor
        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        ///insert function depends on the value that we want to insert
        ///if it should be on the left / right subtree
        void insert_rec(T x) {
            int next_son;
			if (x <= (*pinfo))
                next_son = 0;
            else
                next_son = 1;

            if (next_son == 0)
            {
                if (left_son == NULL)
                { ///left son
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                }
                else
                    left_son->insert_rec(x);

            }
            else
            { /// right son
                if (right_son == NULL)
                {
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                }
                else
                    right_son->insert_rec(x);
            }
        }

		BinarySearchTree<T>* find(T x) {
            BinarySearchTree<T> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo) == x)
                return this;

            if (x <= (*pinfo))
            {
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            }
            else
            {
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }


		void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL)
            {
                if (parent == NULL)
                { /// this == root
                    delete this->pinfo;
                    root->pinfo = NULL;
                }
                else ///leaf
                {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            }
            else
            {
                if (left_son != NULL)
                {
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                }
                else
                { /// right_son != NULL
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal() {
            if (left_son != NULL)
                left_son->inOrderTraversal();

            //cout<<*pinfo<<" ";
            ascending[a++]=*pinfo;

            if (right_son != NULL)
                right_son->inOrderTraversal();
        }


        void preOrderTraversal(){
            cout<<*pinfo<<" ";
            if (left_son != NULL)
                left_son->preOrderTraversal();

            if (right_son != NULL)
                right_son->preOrderTraversal();
        }

        void postOrderTraversal(){
            if (left_son != NULL){
                left_son->postOrderTraversal();}

            if (right_son != NULL){
                right_son->postOrderTraversal();}

            //cout<<*pinfo<<" ";
            descending[d++]=*pinfo;
        }
        bool ZeroTwo(){

        if (left_son == NULL && right_son != NULL)
            return 0;
        if(right_son == NULL && left_son != NULL)
            return 0;
        if (left_son != NULL)
            left_son->ZeroTwo();

        if (right_son != NULL)
            right_son->ZeroTwo();

        return 1;

        }

};
class Wizard {
    public:
        string last_name, first_name, house;
        int score;


        //constructor
        Wizard() {
        }

        void setLastName( string LN)
        {
            last_name= LN;
        }

        void setFirstName( string FN)
        {
            first_name= FN;
        }

        void setScore( int S)
        {
            score= S;
        }

        void setHouse( string H)
        {
            house= H;
        }

        string getLastName()
        {
            return last_name;
        }
        string getFirstName()
        {
            return first_name;
        }
        int getScore()
        {
            return score;
        }
        string getHouse()
        {
            return house;
        }
        void details();
};
void Wizard::details()
{

        cout<<"Name: "<< first_name<< " "<< last_name<< "                   Score: "<< score<< endl;
}
int main(){
    Wizard WizardList[20];
    //Wizard Cedric,Harry,Hermione,Luna,Draco,Severus;
    WizardList[1].first_name="Cedric";
    WizardList[1].last_name="Diggory";
    WizardList[1].score=2000;
    WizardList[1].details();
    WizardList[2].first_name="Harry";
    WizardList[2].last_name="Potter";
    WizardList[2].score=10000;
    WizardList[2].details();
    WizardList[3].first_name="Hermione";
    WizardList[3].last_name="Granger";
    WizardList[3].score=17000;
    WizardList[3].details();
    WizardList[4].first_name="Luna";
    WizardList[4].last_name="Lovegood";
    WizardList[4].score=31000;
    WizardList[4].details();
    WizardList[5].first_name="Draco";
    WizardList[5].last_name="Malfoy";
    WizardList[5].score=60000;
    WizardList[5].details();
    WizardList[6].first_name="Severus";
    WizardList[6].last_name="Snape";
    WizardList[6].score=150000;
    WizardList[6].details();
    cout<<endl;
    BinarySearchTree<int> *r = new BinarySearchTree<int>();

    r->insert(WizardList[1].getScore());
    r->insert(WizardList[2].getScore());
    r->insert(WizardList[3].getScore());
    r->insert(WizardList[4].getScore());
    r->insert(WizardList[5].getScore());
    r->insert(WizardList[6].getScore());

    int option;
    cout<<"The menu of options:"<<endl;
    cout<<"Option 1: Display the wizards sorted in ascending order by their score."<<endl;
    cout<<"Option 2: Display the total score of a house."<<endl;
    cout<<"Option 3: Display each member of a Hogwarts house grouped by category."<<endl;
    cout<<"Option 4: See if we can play Quidditch."<<endl;
    cout<<"Option 5: See if the sequence exists."<<endl;
    cout<<"Your choice is: ";
    cin>>option;
    cout<<endl;
    r->inOrderTraversal();
    r->postOrderTraversal();
    string name;
    if(option==1)
    {
        cout<<"The wizards are in this ascending order:"<<endl;
        //ascending order display
        for(int i=0;i<a;i++)
            for(int j=1;j<=6;j++)
                   if(ascending[i]==WizardList[j].getScore())
                        cout<<WizardList[j].getFirstName()<<" " <<WizardList[j].getLastName()<<endl;
        cout<<endl;
    }
    else
        if(option==2)
        {
            for(int j=1;j<=6;j++)
               if(WizardList[j].getScore()<5000)
                    Hufflepuff+=WizardList[j].getScore();
               else
                    if(WizardList[j].getScore()<20000 && WizardList[j].getScore()>=5000)
                        Gryffindor+=WizardList[j].getScore();
                    else
                        if(WizardList[j].getScore()>=20000 && WizardList[j].getScore()<50000)
                            Ravenclaw+=WizardList[j].getScore();
                        else
                            if(WizardList[j].getScore()>=50000)
                                Slytherin+=WizardList[j].getScore();
                cout<<"Enter the name of the house:"<<endl;
                cin>>name;
                if(name=="Hufflepuff")
                    cout<<"The score for House Hufflepuff is: "<<Hufflepuff<<endl;
                else
                    if(name=="Gryffindor")
                        cout<<"The score for House Gryffindor is: "<<Gryffindor<<endl;
                    else
                        if(name=="Ravenclaw")
                            cout<<"The score for House Ravenclaw is: "<<Ravenclaw<<endl;
                        else
                            if(name=="Slytherin")
                                cout<<"The score for House Slytherin is: "<<Slytherin<<endl;

                cout<<endl;
            }
        else
            if(option==3)
            {
                for(int j=1;j<=6;j++)
                   if(WizardList[j].getScore()<5000)
                        WizardList[j].setHouse("Hufflepuff");
                   else
                        if(WizardList[j].getScore()<20000 && WizardList[j].getScore()>=5000)
                            WizardList[j].setHouse("Gryffindor");
                        else
                            if(WizardList[j].getScore()>=20000 && WizardList[j].getScore()<50000)
                                WizardList[j].setHouse("Ravenclaw");
                            else
                                if(WizardList[j].getScore()>=50000)
                                    WizardList[j].setHouse("Slytherin");
                    cout<<"Hufflepuff house: ";
                    for(int j=1;j<=6;j++)
                               if(WizardList[j].getHouse()=="Hufflepuff")
                                    cout<<WizardList[j].getFirstName()<<" " <<WizardList[j].getLastName()<<" "<<WizardList[j].getScore()<<"; ";
                    cout<<endl<<"Gryffindor house: ";
                    for(int j=1;j<=6;j++)
                               if(WizardList[j].getHouse()=="Gryffindor")
                                    cout<<WizardList[j].getFirstName()<<" " <<WizardList[j].getLastName()<<" "<<WizardList[j].getScore()<<"; ";
                    cout<<endl<<"Ravenclaw house: ";
                    for(int j=1;j<=6;j++)
                               if(WizardList[j].getHouse()=="Ravenclaw")
                                    cout<<WizardList[j].getFirstName()<<" " <<WizardList[j].getLastName()<<" "<<WizardList[j].getScore()<<"; ";
                    cout<<endl<<"Slytherin house: ";
                    for(int j=1;j<=6;j++)
                               if(WizardList[j].getHouse()=="Slytherin")
                                    cout<<WizardList[j].getFirstName()<<" " <<WizardList[j].getLastName()<<" "<<WizardList[j].getScore()<<"; ";
            }
            else
                if(option==4)
                {
                    if(r->ZeroTwo()==0)
                        cout<<"We cannot play Quidditch because some nodes have 1 child only."<<endl;
                    else
                        cout<<"We can play Quidditch."<<endl;
                }
                else
                    if(option==5)
                    {

                    }

}


