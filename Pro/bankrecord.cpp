#include"Bankrecord.h"
#include<iostream>
#include<cstdlib>//atof
#include<fstream>
using namespace std;
void Bank_Record::read_data(){
	cout<<"Enter your first name"<<endl;
	cin>>f_name;
	cout<<"enter your last name"<<endl;
	cin>>l_name;
	cout<<"enter your balance"<<endl;
	cin>>balance;
	cout<<"enter you account number"<<endl;
	cin>>account_numb;
	
}
void Bank_Record::show_data(){
    
    cout<< "Name is "<< f_name <<" "<< l_name<<endl;
    cout<<"account Number "<<account_numb<<endl;
    cout<<"Balance is "<<balance<<endl;
	}
void Bank_Record:: write(){
	
   	ofstream fileout;
    fileout.open("prok.txt",ios::app);
    fileout<<f_name <<" "<< l_name<<" ";
    fileout<<account_numb;
    fileout<<" "<<balance<<endl;
	fileout.close();

	
}
void Bank_Record::rewrite(Bank_Record  *T,int k){
	ofstream fileout;
	int i=0;
	fileout.open("prok.txt",ios::out);
	while(i<k){
	if(fileout.eof()) break;
	fileout<<T[i].getName() <<" "<<T[i].getLname()<<" ";
    fileout<<T[i].getAcc();
    fileout<<" "<<T[i].getBalance()<<endl;
    i++;
}
	fileout.close();
	
}
int Bank_Record::readfile(){
	string line;
    int i=0;
	ifstream infile;
	infile.open("prok.txt",ios::binary);//cuz read and write used for binary files 
	if(!infile){
		cout<<"error in opening file";
	}
	while(!infile.eof()){ //if(x) mean if x is true;
	getline(infile,line);
	if(infile.eof()) break; // daroooooori to not print an empty line on the end
    cout<< line <<endl;
    i++;
	}
    infile.close();
    return i;
   }
   

    
/*void Bank_Record::search2(){
	
    ifstream infile;
    infile.open("prok.txt",ios::binary);
    int l,n,k;
    string line;
    infile.seekg(0,ios::end);//to place it in the end of file
    k=infile.tellg()/80;// to know how many data are tellg tell us the position after openning the file which we set it in the end and we divise it by size
    //84 is the size of one block when stored name account numb balance;
    cout<<endl;
	cout<<"there is "<<k<<"record"<<endl;
    cout<<"enter the number of record wanted"<<endl;
    cin>>n;
    infile.seekg((n-1)*80,ios::beg);//place it to the niem record (n-1 cuz we start on 0 and *sizeof cuz lignes) 84 size of one block  
    k=infile.tellg();//to tell us the position of the niem record
	for(l=k;l<k+4;l++){ //k the actual position of niem record k+4 we have 4 lignes per block of data 
    getline(infile,line);
	cout<< line <<endl;
}
    infile.close();
	
}*/
void Bank_Record::setName(char *b){
	f_name=b;
}
void Bank_Record::setLname(char *b){
	l_name=b;
}
void Bank_Record::setAcc(float b){
	account_numb=b;
}
void Bank_Record::setBalance(float b){
	balance=b;
}
string Bank_Record::getName(){
	return f_name;
}
string Bank_Record::getLname(){
	return l_name;
}
double Bank_Record::getAcc(){
	return account_numb;
}
float Bank_Record::getBalance(){
	return balance;
}
/*Bank_Record::Bank_Record(char *a,char*b,char* c,char* d){
	f_name=a;
	l_name=b;
	account_numb=atof(c);
	balance=atof(d);
}*/
int Bank_Record::load(Bank_Record *T){
	ifstream infile;
	int i=0;
	string store[10];
	infile.open("prok.txt");
	while(!infile.eof()){
		infile>>store[0]>>store[1]>>store[2]>>store[3];
	   T[i]=Bank_Record(store[0],store[1],atof(store[2].c_str()),atof(store[3].c_str())); 
	    /*T[i].setName(store[0]);
	    T[i].setLname(store[1]);
	    T[i].setAcc(atof(store[2]));
	    T[i].setBalance(atof(store[3]));*/
	    if(infile.eof()) break;
	    i++;
	}
	
	infile.close();
	return i;
}

string Bank_Record::search(int k,Bank_Record *T){
	double n;
	cout<<"enter your acc number"<<endl;
	cin>>n;
	int count=0;
	for(int i=0;i<k;i++){
		if(n==T[i].getAcc()){
			cout<<"****************"<<endl;
			cout<<"Welcome "<<T[i].getName()<<" "<<T[i].getLname()<<endl;
			cout<<"your balance is :"<<T[i].getBalance()<<endl;
			cout<<"****************"<<endl;	
		 count++;
		}
	}
	if(!count) cout<<"account not found"<<endl;
	return T->getLname();
}
/*void Bank_Record::modif(){
	fstream modifile;
	int n;
	float k;
	modifile.open("prok.txt",ios::in|ios::out);
	if(!modifile){
		cout<<"error in opening file";
		}
	modifile.seekg(0,ios::end);
	k=modifile.tellg()/80;
	cout<<"there is "<<k<<"record"<<endl;
	cout<<"which record you wanna  modify"<<endl;
	cin>>n;
	modifile.seekp(n*80,ios::beg);// to place it to the record we want to modify
	k=modifile.tellp();
	cout<<k<<endl;
	cout<<"enter the data modified"<<endl;
	read_data();
	modifile<<endl;
	modifile<< "Name is "<< f_name <<" "<< l_name<<endl;
    modifile<<"account Number "<<account_numb<<endl;
    modifile<<"Balance is "<<balance<<endl;
    modifile<<"************************"<<endl;
	modifile.close();
	}*/
	void Bank_Record::modif(int k,Bank_Record *T){
		int n,b;
		char w[10],e[10];
		float s;
		do{
		cout<<"there is "<<k<<"Record"<<endl;
		cout<<"enter the record to modify"<<endl;
		cin>>n;}
		while(n>k || n<0);
		do{
		cout<<"what do you want to modify"<<endl;
		cout<<"1-> name"<<endl;
		cout<<"2->balance"<<endl;
		cout<<"0->back"<<endl;
		cin>>b;
		
		switch(b){
			case 1:
				cout<<"enter first name"<<endl;
				cin>>w;
				cout<<"enter last name"<<endl;
				cin>>e;
				T[n-1].setName(w);
				T[n-1].setLname(e);
				break;
			
			case 2:
				cout<<"enter Balance"<<endl;
				cin>>s;
				T[n-1].setBalance(s);
				break;
			
			
	}
	}while(b);
	
	}
string Bank_Record:: test() {
		ifstream infile;
		int i = 0;
		string store[10];
		infile.open("prok.txt");
	       infile>>store[0]>>store[1]>>store[2];
		return store[1];
	}
