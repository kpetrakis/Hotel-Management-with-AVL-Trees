#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>


struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;


// Class gia to avlTree

class avlTree
{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, int );
        void vres(int, avl_node *);
        void display(avl_node *, int);
        void inorder(avl_node *);
        void preorder(avl_node *);
        void postorder(avl_node *);
        avlTree()
        {
            root = NULL;
        }
};

//SE OLA TA VECTOR GINETAI PROSPELASI TWN STOIXEIWN TOUS ME vector.at(i) ANDI GIA vector[i] GIA NA EXW ELEGXO ORIWN

//EXW ILOPOIHSEI OLES TIS LEITOURGIES TWN AVL DENTRWN EKTOS APO ANAZITISI TOU ID(DISPLAY,INORDER,POSTORDE...)

using namespace std;

//klasi pou antiproswpei mia kratisi
class Reservation{
public:
    string name;//oles oi metavlites dilwthikan public kai oxi private gia eukolia anti na xrisimopoiithoun sinartiseis set() kai get()
    string checkinDate;
    int stayDurationDays;
public:
    Reservation(string,string,int);

};
Reservation::Reservation(string onoma,string imerominia,int diarkeia):name(onoma), checkinDate(imerominia), stayDurationDays(diarkeia){}

//klasi pou antiproswpei ena Hotel
class Hotel{
public:
    int id;//oles oi metavlites dilwthikan public kai oxi private gia eukolia anti na xrisimopoiithoun sinartiseis set() kai get()
    string name;
    int stars;
    int numberOfRooms;
    Reservation* reservations;
public:
     bool operator < (const Hotel& str) const//o telestis pou xrisimopoieitai stin sigkrisi meta3i antikeimenwn Hotel otan kalw tin sinartisi sort()
    {
        return (id < str.id);
    }

    Hotel(int,string,int,int,Reservation*);
};

Hotel::Hotel(int tautotita,string onoma,int asteria,int dwmatia,Reservation* kratisi):id(tautotita), name(onoma), stars(asteria), numberOfRooms(dwmatia),reservations(kratisi){}


void load(void);

int main(int argc, char* argv[])
{


    int vrethike=0;//metavliti pou xrisimopoieitai ws flag gia tis anazitiseis
    int search_id;//To id pou dinei o xristis gia anazitisi stis epilogi 3
    int epilogi;//metavliti gia to poia anazitis tha xrisimopoiisoume



    vector<vector<string> > values;//distiastato vector pou xrisimopoieitai gia na diavasw to file
    vector<string> valueline;//vector pou diavazei kathe grammi
    ifstream fin("data.csv");
    string item;
    for (string line; getline(fin, line); )
    {
        istringstream in(line);

        while (getline(in, item, ';'))
        {
            valueline.push_back(item);//diavazw ena ena ta stoixeia pou diaxwrizondai me ; apo kathe grammi
        }

        values.push_back(valueline);//prosthetw kathe "grammi" ston distiato vector(exei tin diataksi pou exei kai to arxeio)
        valueline.clear();
    }

  vector<Reservation> arr;//vector pou krata ta reservations
  vector<Hotel> hot;//vector pou apothikeuw ta antikeimena Hotel

for (int i=1;i<values.size();i++){ // Epeidi oi kratiseis 3ekinoun apo tin thesi 4 kai meta 3ekinaw to j apo 6 wste na
                                    // pernw ta 3 kelia kathe fora pou antistoixoun sta stoixeia tou kathe pelati
for(int j=6;j<values[i].size();j+=3){
    arr.push_back(Reservation(values.at(i).at(j-2),values.at(i).at(j-1),atoi(values.at(i).at(j).c_str()))); //arxika pernw ta stoixiea stis theseis 4 5 kai 6
                                                                                                            //meta ta stoixeia tou 2ou pelati stis theseis 7 8 kai 9
           }
        }
int k=0;
for(int i=1;i<values.size();i++){ //epeidi thelw mono ti stiles 0-3 gia ta ksenodoxeia se kathe perasma exw l=3 wste na pernw ta stoixeia tou kathe 3enodoxeiou
        int l=3;
        hot.push_back(Hotel(atoi(values.at(i).at(l-3).c_str()),values.at(i).at(l-2),atoi(values.at(i).at(l-1).c_str()),atoi(values.at(i).at(l).c_str()),&arr.at(k)));
        k+=16; // epeidi gia kathe 3enodoxeio exw 16 kratiseis kathe fora pou allazw 3enodoxeio o deiktis se Reservation deixnei stin prwti kratisi tis epomenis grammis

    }
int menu;
while(1){
    cout <<"\n\n\n";
    cout << "To menu epilogwn einai: " << endl;
    cout << "1.Load Hotels and Reservations from file" << endl;
    cout << "2.Add a Hotel" << endl;
    cout << "3.Search and Display a Hotel by id" << endl;
    cout << "4.Search a Hotel by id with AVL tree implementation" << endl;
    cout << "5.Display Reservations by surname search" << endl;
    cout << "6.Exit"<<endl;
    cout << "Dwste tin epilogi sas: ";
    cin>> menu;


if(menu==1){cout << "To arxeio fortwthike epitixws"<<endl;}

else if(menu==3){//search and display a Hotel by id
    cout << "Epilogi anazitisis: (1.grammiki 2.binary search 3.interpolation search) Dwste tin epilogi sas: ";
cin >> epilogi;



if(epilogi==1){//grammiki anazitisi
        cout << "Dwse mou to id gia anazitisi : ";
        cin >> search_id;
    for(int k=0;k<hot.size();k++){
       if(search_id==hot.at(k).id){
         cout << "To ksenodoxeio vrethike sti thesi " << k << " kai einai to: " << endl;
        cout << hot.at(k).id << " " << hot.at(k).name << " " << hot.at(k).stars << " " << hot.at(k).numberOfRooms;
         vrethike=1;//flag
       }
                        }
    if(!vrethike) cout << "To ksenodoceio me to sigkekrimeno id den iparxei";

}

else if (epilogi==2){//binary search
cout << "Dwse mou to id gia anazitisi: ";
cin >> search_id;
sort(hot.begin(), hot.end());//den xreiaetai ta3inomisi giati ta id einai idi taksinomimena alla tinkanoume etsi ki alliws
int mid=0;
int left=0;
int pos=-1;
int right=hot.size();
    while(left<right && pos==-1){
            mid=left+(right-left)/2;
            if(search_id>hot.at(mid).id){
              left=mid+1;
            }
            else if(search_id<hot.at(mid).id){
                right=mid;
            }
            else {
                 pos=mid;       }

                }
    if(pos!=-1){
cout << "To ksenodoxeio vrethike sti thesi " << pos << " kai einai to: " << endl;
        cout << hot.at(pos).id << " " << hot.at(pos).name << " " << hot.at(pos).stars << " " << hot.at(pos).numberOfRooms;
                                                                                    }
else cout << "To ksenodoceio me to sigkekrimeno id den iparxei";

}

else if (epilogi==3){//interpolation search
cout << "Dwse mou to id gia anazitisi: ";
cin >> search_id;
int left=0;
int right=hot.size()-1;
int mid;
int pos=-1;
sort(hot.begin(), hot.end());//den xreiaetai taksinomisi giati ta id einai idi taksinomimena alla tin kanoume etsi ki alliws
    while(hot.at(left).id<=search_id && hot.at(right).id>=search_id && pos==-1){
        mid= ((search_id-hot.at(left).id)/(hot.at(right).id-hot.at(left).id))*(right-left) + left;//vima interpolation search
        if(hot.at(mid).id<search_id){
            left=mid+1;
        }
        else if(hot.at(mid).id>search_id){
            left=mid-1;
        }
        else{ pos=mid; }

    }

if(pos!=-1){
cout << "To ksenodoxeio vrethike sti thesi " << pos << " kai einai to: " << endl;
        cout << hot.at(pos).id << " " << hot.at(pos).name << " " << hot.at(pos).stars << " " << hot.at(pos).numberOfRooms;
                                                                                    }
else cout << "To ksenodoceio me to sigkekrimeno id den iparxei";

                }

        }

else if(menu==2){//add a hotel
    string id,asteria,onoma,kratiseis;
    cout <<"Dwse mou ta stoixeia gia to ksenodoxeio pou tha eisagw: "<<endl;
    cout <<"Dwse mou to id: ";
    cin >>id;
    cout <<"Dwse mou to onoma: "<<endl;
    cin >>onoma;
    cout <<"Dwse mou ta asteria: "<<endl;
    cin >>asteria;
    cout <<"Dwse mou ton arithmo twn kratisewn: "<<endl;
    cin >>kratiseis;

    vector<string> temp;//prwsorino vector pou xrisimopoieitai gia na grapsoume ta stoixeia tou ksenodoxeiou pou eisagei o xristis sto arxeio
    temp.push_back(id);
    temp.push_back(onoma);
    temp.push_back(asteria);
    temp.push_back(kratiseis);
    ofstream output_file("data.csv",ios::app);//epeidi thelw na prostethoun(append) ta dedomena xrisimopoiw to ios::app
    ostream_iterator<string> output_iterator(output_file, ";");
    copy(temp.begin(), temp.end(), output_iterator);//grafw ta stoixeia tou vector temp sto file me diaxwristi to ;
    output_file <<endl;//afinw mia keni grammi wste tixon kainouria eisagwgi apo ton xristi na graftei se nea seira kai oxi dipla apo tin proigoumeni
    hot.push_back(Hotel(atoi(temp.at(0).c_str()),temp.at(1),atoi(temp.at(2).c_str()),atoi(temp.at(3).c_str()),&arr.at(4))); //pernaw ta stoixeia pou eisagei o xristis sto vector me ta antikeimena Hotel
        }                                                                                                                   //wste na borw na simperilavw kai ta kainouria ksenodoxeia se kapoia endexomeni anazitisi


else if(menu==4){//Anazitisi me tin xrisi AVL
    int dokimi;

    int choice;
    int value;
    avlTree avl;

    for(int i=1;i<hot.size();i++){ //fortwnw ta id sto avl dentro
                root = avl.insert(root, hot.at(i).id);

            }
    while (1)
    {
        cout <<"\n\n";
        cout <<"To menu gia to AVL dentro einai: "<<endl;
        cout<<"1.Display Balanced AVL Tree"<<endl;
        cout<<"2.InOrder traversal"<<endl;
        cout<<"3.PreOrder traversal"<<endl;
        cout<<"4.PostOrder traversal"<<endl;
        cout<<"5.Search "<<endl;
        cout<<"6.Exit apo to AVL menu"<<endl;
        cout<<"Enter your Choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 2:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Preorder Traversal:"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder(root);
            cout<<endl;
            break;
        case 6:
            break;
        case 5:
            cout <<"Dwse mou to id gia psaximo: ";
            cin>> dokimi;
            avl.vres(dokimi,root);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }break; //gia na epanerthw sto menu epilogwn
    }

    }
else if(menu==5){//Display Reservation by surname search
 int flag=1;
 string epwnimo;
 cout <<"Dwse mou to epwnimo pou tha psaksw: ";
 cin >>epwnimo;
 for (int i=1;i<arr.size();i++){
    if(arr.at(i).name==epwnimo){
            cout << "Vrethike kratisi me to sigkekrimeno epwnimo: "<<endl;
            cout <<arr.at(i).name<< " " << arr.at(i).checkinDate << " " << arr.at(i).stayDurationDays <<endl;
            flag=0;//flag gia to an vrethike to epwnimo i oxi
        }

        }
    if(flag)cout<< "Den vrethike kratisi me to sigkekrimeno epwnimo" << endl;

    }
else if(menu==6){
   break;
    }
else cout <<"Wrong Chooise"<<endl;
    }

return 0;
}



//sinartisi anazitis tou id
void avlTree::vres(int kleidi,avl_node *ptr)
{
    if(ptr==NULL){cout <<"To ksenodoxeio me to sigkekrimeno id den vrethike";
    }
    else if(kleidi<ptr->data){
        vres(kleidi,ptr->left);
    }
    else if(kleidi>ptr->data){
        vres(kleidi,ptr->right);
    }
    else if(kleidi==ptr->data){cout <<"To ksenodoxeio me to sigkekrimeno id vrethike";}



}
// Height of AVL Tree

int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}


// Height Difference

int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


// Right- Right Rotation

avl_node *avlTree::rr_rotation(avl_node *parent)//mia aristeri peristrofi
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation

avl_node *avlTree::ll_rotation(avl_node *parent)//mia deksia peristrofi
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


// Left - Right Rotation

avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);//aristeri peristrofi girw apo to apo to aristero paidi tou parent
    return ll_rotation (parent);//kai meta mia deksia peristrofi girw apo ton parent
}


// Right- Left Rotation

avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);//deksia peristrofi girw apo to deksi paidi tou parent
    return rr_rotation (parent);//kai meta mia aristeri peristrofi girw apo ton parent
}


// Balancing AVL Tree

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);//To hb tou komvou
    if (bal_factor > 1)//to dentro gernei aristera
    {
        if (diff (temp->left) > 0)//exw 2 aristera paidia
            temp = ll_rotation (temp);
        else                      //exw prwta aristero paidi kai meta deksio
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)//to dentro gernei deksia
    {
        if (diff (temp->right) > 0)//exw prwta deksio paidi kai meta aristero
            temp = rl_rotation (temp);
        else                       //exw 2 deksia paidia
            temp = rr_rotation (temp);
    }
    return temp;
}


// Insert Element sto dentro

avl_node *avlTree::insert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}


// Display AVL Tree

void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}


// Inorder Traversal of AVL Tree

void avlTree::inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

// Preorder Traversal of AVL Tree

void avlTree::preorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


//  Postorder Traversal of AVL Tree

void avlTree::postorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}



