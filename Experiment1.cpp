#include<iostream>
#include<string>
using namespace std;

void Check_Numeric(){
    cin.ignore();
    string input;
    cout<<"Enter your string : ";
    getline(cin,input);
    bool numeric=true;
    for(int i=0;i<input.length();i++)
    {
        if(input.at(i)<'0' || input.at(i)>'9'){
            numeric=false;
            break;
        }
    }
    if(numeric){
        cout<<"Numeric Number"<<endl;
    }
    else{
        cout<<"Not Numeric"<<endl;
    }
    cout<<"__________________________"<<endl;
    return;
}

void Check_Operator(){
    cin.ignore();
    string input;
    cout<<"Enter your string : ";
    getline(cin,input);
    bool op=false;
    int flag=1;
    string symbol;
    for(int i=0;i<input.length();i++){
        if(input.at(i)=='+' || input.at(i)=='-' || input.at(i)=='*' || input.at(i)=='/'){
            if(input.at(i)=='+')
            {
                symbol="Addition";
            }
            else if(input.at(i)=='-')
            {
                symbol="Subtraction";
            }
            else if(input.at(i)=='*'){
                symbol="Multiplication";
            }
            else{
                symbol="Division";
            }
            cout<<"Operator "<<flag++<<" : "<<input.at(i)<<" ("<<symbol<<")"<<endl;
            op=true;
            cout<<"__________________________"<<endl;
        }
    }
    if(!op){
        cout<<"No Operator"<<endl;
        cout<<"__________________________"<<endl;
        return;
    }
    return;
}

void Check_Comments(){
    cin.ignore();
    string input;
    cout<<"Enter your string : ";
    getline(cin,input);
    for(int i=0;i<input.length()-1;i++){
        if(input.substr(i,2)=="//"){
            cout<<"Single Comment"<<endl;
            cout<<"__________________________"<<endl;
            return;
        }

        else if(input.substr(i,2)=="/*"){
            for(int j=i+2;j<input.length()-1;j++){
                if(input.substr(j,2)=="*/"){
                    cout<<"Multiple Line Comment"<<endl;
                    cout<<"__________________________"<<endl;
                    return;
                }
            }
        }

    }

    cout<<"Not a Comment"<<endl;
}

void Check_identfier(){
    cin.ignore();
    string input;
    cout<<"Enter your identifier : ";
    getline(cin,input);

    if(!(isalpha(input[0]) || input[0]=='_')){
            cout<<"Not a valid Identifier"<<endl;
            cout<<"__________________________"<<endl;
            return;
    }

    for(int i=0;i<input.length();i++){
        if(!(isalnum(input[i]) || input[i]=='_')){
            cout<<"Not a valid Identifier"<<endl;
            cout<<"__________________________"<<endl;
            return;
        }
    }

    cout<<"Valid Identifier"<<endl;
    cout<<"__________________________"<<endl;

}

void Average_array(){
    int size;
    cout<<"Enter the size of Array : ";
    cin>>size;
    float avg[size];
    float addition=0;
    cout<<"Enter Valid Values of the Array : ";
    for(int i=0;i<size;i++){
        cin>>avg[i];
        addition+=avg[i];
    }
    cout<<"Average : "<<addition/size<<endl;
    cout<<"__________________________"<<endl;

}

void Find_minmax(){
    int size;
    cout<<"Enter the size of Array : ";
    cin>>size;
    float input[size];
    float addition=0;
    cout<<"Enter Valid Values of the Array : ";
    for(int i=0;i<size;i++){
        cin>>input[i];
    }
    float min=input[0],max=input[0];
    for(int i=1;i<size;i++){
        if(min>input[i]){
            min=input[i];
        }
        else if(max<input[i]){
            max=input[i];
        }
    }
    cout<<"MINIMUM VALUE : "<<min<<endl;
    cout<<"MAXIMUM VALUE : "<<max<<endl;
    cout<<"__________________________"<<endl;

}
void Merge_name(){
    cin.ignore();
    string first,last;
    cout<<"Enter the first name : ";
    getline(cin,first);
    cout<<"Enter the last name : ";
    getline(cin,last);
    cout<<"Full Name : "<<first+" "+last<<endl;
    cout<<"__________________________"<<endl;
}
int Options(){
    int n;
    cout<<"Which option do you want to check?\n";
    cout<<"1.Check Numeric\n2.Check Operator\n3.Check Comment\n4.Check Identifiers\n5.Find Average\n6.Find Minimum and Maximum\n7.First Name-Last Name\n8.Exit\n";
    cout<<"__________________________"<<endl;
    cout<<"Input : ";
    cin>>n;
    cout<<"__________________________"<<endl;
    switch(n){
    case 1:
        Check_Numeric();
        return 0;
    case 2:
        Check_Operator();
        return 0;
    case 3:
        Check_Comments();
        return 0;
    case 4:
        Check_identfier();
        return 0;
    case 5:
        Average_array();
        return 0;
    case 6:
        Find_minmax();
        return 0;
    case 7:
        Merge_name();
        return 0;
    case 8:
        cout<<"Exit"<<endl;
        return 1;
    default :
        cout<<"Invalid Number\nTry again!"<<endl;
        return 0;
    }
}

int main()
{
     while(true){
        int check=Options();
        if(check==1){
            break;
        }
     }

}
