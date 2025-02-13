#include <iostream>
using namespace std;

struct Check{
    int CheckNum=0;
    string CheckMemo;
    float CheckAmount;
};

class CheckBook{
public:
    static const int N=5;
    Check check[N];
    CheckBook(): balance(0), numofChecks(0), checklimit(N){};
    CheckBook(int initalbalance){
        balance = initalbalance;
        numofChecks=0;
    }
    void deposit(float amt);
    void displayChecks();
    bool writeCheck(float amt);
private:
    //int n=5;
    float balance, lastDeposit;

    int numofChecks, checklimit =N;

};

int main() {
 CheckBook user1(300);
float depamt, checkamt;
cout << "how much do you want to deposit?";
cin >> depamt;
 user1.deposit(depamt);
 cout << "How much would you want to write the check for?";
 cin>> checkamt;
 user1.writeCheck(checkamt);
 user1.displayChecks();
//Test 2
    cout << "how much do you want to deposit?";
    cin >> depamt;
    user1.deposit(depamt);
    cout << "How much would you want to write the check for?";
    cin>> checkamt;
    user1.writeCheck(checkamt);
    user1.displayChecks();




    return 0;
}




void CheckBook::deposit(float amt){
    balance= balance+amt;
    lastDeposit = amt;
    cout<< "deposit success! Your current balance is: "<<balance<< endl;
}


bool CheckBook::writeCheck(float amt){
    //takes less than balance, if less r equal ask about details and position of chech array
    if (amt <= balance){
        string memo;
        cout << "Please enter a memo: ";
        cin >> memo;

        check[numofChecks].CheckNum = numofChecks+1;
        check[numofChecks].CheckMemo = memo;
        check[numofChecks].CheckAmount = amt;
        balance = balance-amt;
        numofChecks++;
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
        cout<< "Check #" <<check[i].CheckNum<<"\t"<< endl;
        cout <<"Check amount: "<<check[i].CheckAmount<< endl;
        cout<< "Memo: " <<check[i].CheckMemo<< endl;
        cout <<"***************"<<endl;
    }
}