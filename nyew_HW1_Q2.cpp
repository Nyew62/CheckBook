#include <iostream>
using namespace std;
static int number=0;
class Check{
public:
    Check(){
        CheckNum =0;
        CheckAmt =0;
        CheckMemo =" ";
        number++;
    }

    int getchecknum(){return CheckNum;}
    float getcheckamt(){return CheckAmt;}
    string getMemo(){return CheckMemo;}
    //set
   void setCheckNum(int checknum){CheckNum=checknum;};
    void setCheckAmt(float checkAmt){CheckAmt=checkAmt;};
    void setMemo(string cMemo){CheckMemo=cMemo;};

private:
    int CheckNum;
    string CheckMemo;
    float CheckAmt;
    //static int number;

};
static int allChecks=0;
class CheckBook{
public:
    static const int N =5;
    Check check[N];
    CheckBook(): balance(0), numofChecks(0), checklimit(N){}
    CheckBook(float initalbalance):balance(initalbalance), numofChecks(0){}
    void deposit(float amt);
    void displayChecks();
    bool writeCheck(float amt);
    //2b
    static int getallCheck(){return allChecks;}

private:

    float balance, lastDeposit;

    int numofChecks, checklimit =5;

};


//MAIN
int main() {
    CheckBook cb1(1000), cb2(500);
    for(int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();
    cout<<cb1.getallCheck()<<endl;
    cout<<cb2.getallCheck()<<endl;

    return 0;
}
//MAIN



void CheckBook::deposit(float amt){
    balance= balance+amt;
    lastDeposit = amt;
    cout<< "Deposit success! Your current balance is: "<<balance<< endl;
}


bool CheckBook::writeCheck(float amt){
    //takes less than balance, if less or equal ask about details and position of check array
    if (amt <= balance && numofChecks<N && allChecks <10){
        string memo;
        cout << "Please enter a memo: ";
        cin >> memo;

        check[numofChecks].setCheckNum(numofChecks+1);
        check[numofChecks].setMemo(memo);
        check[numofChecks].setCheckAmt(amt);
        balance = balance-amt;
        numofChecks++;
        allChecks++;
        cout << "Remaining balance: "<< balance<< endl;

        return true;
    }else{
        cout << "Insufficient funds"<< endl;
        return false;
    }

}
void CheckBook::displayChecks(){
    //displays checks in chrono order
    for(int i=numofChecks-1; i>=0; i--){
        cout <<"***************"<<endl;
        cout<< "Check #" <<check[i].getchecknum()<<"\t"<< endl;
        cout <<"Check amount: "<<check[i].getcheckamt()<< endl;
        cout<< "Memo: " <<check[i].getMemo()<< endl;
        cout <<"***************"<<endl;
    }
}