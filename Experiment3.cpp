#include <iostream>
#include <string>
#include<fstream>
using namespace std;

string Keyword[]={
    "int","float","char","void","string",
    "if","else","for","while","return",
    "main","cin","cout","endl","getline"
};

string Operator[] = {
    "+","-","*","/","%","=","==","!=",
    ">","<",">=","<=","&&","||","!",
    "++","--"
};

string Punctuation[] = {
    ";",",","(",")","{","}","[","]","\"","<<",">>"
};

void tokenize(string line){

    string token="";
    line+=" ";

    for(int k=0;k<line.length();k++){

        if(line[k]!=' '){
            token+=line[k];
        }
        else{

            if(token==""){
                continue;
            }

            bool found=false;

            //Keyword
            int keySize=sizeof(Keyword)/sizeof(Keyword[0]);
            for(int i=0;i<keySize;i++){
                if(token==Keyword[i]){
                    cout<<token<<" --> Keyword"<<endl;
                    found=true;
                    break;
                }
            }



            //Operator
            if(!found){
                int opSize=sizeof(Operator)/sizeof(Operator[0]);
                for(int i=0;i<opSize;i++){
                    if(token==Operator[i]){
                        cout<<token<<" --> Operator"<<endl;
                        found=true;
                        break;
                    }
                }
            }

            //Punctuation
            if(!found){
                int punSize=sizeof(Punctuation)/sizeof(Punctuation[0]);
                for(int i=0;i<punSize;i++){
                    if(token==Punctuation[i]){
                        cout<<token<<" --> Punctuation"<<endl;
                        found=true;
                        break;
                    }
                }
            }

            //Numeric
            if(!found){
                bool numeric=true;
                int dot=0;

                for(int i=0;i<token.length();i++){
                    if(token[i]=='.'){
                        dot++;
                        if(dot>1){
                            numeric=false;
                            break;
                        }
                    }
                    else if(!isdigit(token[i])){
                        numeric=false;
                        break;
                    }
                }

                if(numeric){
                    cout<<token<<" --> Numeric"<<endl;
                    found=true;
                }
            }

            //Identifier
            if(!found){
                bool identifier=true;

                if(!(isalpha(token[0])||token[0]=='_')){
                    identifier=false;
                }

                for(int i=1;i<token.length();i++){
                    if(!(isalnum(token[i]) || token[i]=='_')){
                        identifier=false;
                        break;
                    }
                }

                if(identifier){
                    cout<<token<<" --> Identifier"<<endl;
                    found=true;
                }
            }

            //Lexical Error
            if(!found){
                cout<<token<<" --> Lexical Error"<<endl;
            }

            token="";
        }
    }
}

int main(){
    string myText;
    ifstream Myfile("Code.txt");
    while(getline(Myfile,myText)){
        tokenize(myText);
    }
    Myfile.close();
}
