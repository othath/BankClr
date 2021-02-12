#ifndef Bank_Record_H_INCLUDED
#define Bank_Record_H_INCLUDED
#include<string>
class Bank_Record{
	std::string f_name,l_name;
	float account_numb;
	float balance;
    public :
    Bank_Record(): account_numb(0.0),balance(0.0){
	};
   // Bank_Record(char *a,char*b,char* c,char* d);
    Bank_Record(std::string str1, std::string str2, float nbr1, float nbr2) : f_name(str1), l_name(str2), account_numb(nbr1), balance(nbr2) {};
    void setLname(char*);
    void setName(char *);
    void setAcc(float);
    void setBalance(float);
    std::string getName();
    std::string getLname();
    double getAcc();
    float getBalance();
    int load(Bank_Record *);
	void read_data();
    void show_data();
	void write();
	int readfile();
    std::string test();
	std::string search(int,Bank_Record*);
	void modif(int ,Bank_Record*);
	void rewrite(Bank_Record*,int);
    };

#endif // !Bank_Record

