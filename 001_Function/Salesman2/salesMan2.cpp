
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    int years=0;
    double monthIncome=0, soldAmount=0, bonus=0, addBonus=0;
    const double fristBar=0.03, secondBar=0.06;;
    
    cout<<"Enter years worked: ";
    cin>>years;
    if(cin.fail()){
        cout<<"Something went wrong ...";
        return 1;
    }
    cout<<"Enter monthly salary: ";
    cin>>monthIncome;
    if(cin.fail()){
        cout<<"We both know that ’s not a valid salary..."<<endl;
        return 1;
    }
    cout<<"Enter sales amount: ";
    cin>>soldAmount;
    if(cin.fail()){
        cout<<"Are you giving away things for free?!?!?!"<<endl;
        return 1;
    }
    //math for year-based commission
    if (years>=5) {
        bonus=20*years;
    }
    //math for additional commission
    if(soldAmount>5000&&soldAmount<10000){
        addBonus = soldAmount * fristBar;
    }else if (soldAmount>=10000){
        addBonus = soldAmount * secondBar;
    }
    //combine year-based and additional commission
    bonus=bonus+addBonus;
    double FinalSalary=monthIncome+bonus;
    
    cout<<left<<setw(20)<<"Years worked";
    cout<<setw(16)<<setfill(' ')<<right<<years<<endl;
    cout<<left<<setw(20)<<setfill('.')<<"Base salary........."<<"$";
    cout<<setw(15)<<setfill(' ')<<right<<fixed<<setprecision(2)<<monthIncome<<endl;
    cout<<left<<setw(20)<<setfill('.')<<"Bonus..............."<<"$";
    cout<<setw(15)<<setfill(' ')<<right<<fixed<<setprecision(2)<<bonus<<endl;
    cout<<left<<setw(20)<<setfill('.')<<"Amount sold........."<<"$";
    cout<<setw(15)<<setfill(' ')<<right<<fixed<<setprecision(2)<<soldAmount<<endl;
    cout<<left<<setw(20)<<setfill('.')<<"Salary w/ bonus"<<"$";
    cout<<setw(15)<<setfill(' ')<<right<<fixed<<setprecision(2)<<FinalSalary<<endl;
    return 0;
}
