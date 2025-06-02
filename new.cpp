#include<iostream>
using namespace std;
#include<cmath>
class ism{
    public:
        int phone_no;
        string name;
};


class iit{
    public:
    int i_d;
    int dob;
    int yoo;
    
    // constructor fns
    iit(int i_d_, int dob_, int yoo_){
        i_d=i_d_;
        dob=dob_;
        yoo=yoo_;
    }

    //obj fns
    bool check_false(){
        if (i_d== 1){
            return true;
        }
        else{
            return false;
        };
    };

};
int main(){
    
    ism stud1;
    stud1.phone_no=1233333;
    stud1.name="vishal";
    
    iit stud2(1,3,4);


    string me= "yash";
    cout<<"cumbakk karega "<< me <<" lol" << endl;
    bool met= true;
    double lol=2.33;
    cout<< lol<<" "<< met <<" "<< me.length() <<endl;
    int kk= floor(1.1);
    int oo= ceil(1.1);
    int y= fmax(2,3);
    string yea="2";
    //getline(cin, yea);
    cout<<yea;
    // fns, if statements,while, for loops, arrays same as in c
    string* m= &me;
    cout<< *m<< endl;

    cout<<stud2.check_false();
    return 1;
}