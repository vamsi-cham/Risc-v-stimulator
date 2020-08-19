#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <bits/stdc++.h> 
using namespace std;



string removespaces(string s) 
{ 
    int i = 0, j = 0; 
    while (s[i]) 
    { 
        if (s[i] != ' ') 
           s[j++] = s[i]; 
        i++; 
    } 
    s[j] = '\0'; 
    return s; 
} 


void writehexinfile(string hex,long long int pc){

ofstream os;
os.open("mcfile.mc",ios_base::app);
if(!os){
cout<<"error in writing,file mcfile.mc is not found"<<endl;
}
else{

os<<"0x";

char hexaDeciNum[100]; 
      
    int i = 0; 

  if(pc==0){ 
   
     os<<pc;
       } 

    while(pc!=0) 
    {    
        int temp  = 0; 
        temp = pc % 16; 
          
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        pc = pc/16; 
    } 
    for(int j=i-1; j>=0; j--) 
        os << hexaDeciNum[j]; 
os<<" 0x"<<hex<<endl;

}

os.close();    


}


// Function to create map between binary number and its equivalent hexadecimal 
void createMap(unordered_map<string, char> *um) 
{ 
	(*um)["0000"] = '0'; 
	(*um)["0001"] = '1'; 
	(*um)["0010"] = '2'; 
	(*um)["0011"] = '3'; 
	(*um)["0100"] = '4'; 
	(*um)["0101"] = '5'; 
	(*um)["0110"] = '6'; 
	(*um)["0111"] = '7'; 
	(*um)["1000"] = '8'; 
	(*um)["1001"] = '9'; 
	(*um)["1010"] = 'A'; 
	(*um)["1011"] = 'B'; 
	(*um)["1100"] = 'C'; 
	(*um)["1101"] = 'D'; 
	(*um)["1110"] = 'E'; 
	(*um)["1111"] = 'F'; 
} 

// convert a binary number to hexadecimal number
void BinToHexwriteinfile(string bin,int pc) 
{ 
	int l = bin.size(); 
	
	for (int i = 1; i <= (4 - l % 4) % 4; i++) 
		bin = '0' + bin; 
	

	unordered_map<string, char> bin_hex_map; 
	createMap(&bin_hex_map); 
	
	int i = 0; 
	string hex = ""; 
	
	while (1) 
	{ 
		
		hex += bin_hex_map[bin.substr(i, 4)]; 
		i += 4; 
		if (i == bin.size()) 
			break; 
			
		
	} 
	
	writehexinfile(hex,pc);
} 




string addBinary(string a, string b) 
{ 
    string result = ""; 
    int s = 0;          
  
    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    { 
        
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        
        result = char(s % 2 + '0') + result; 
  
        
        s /= 2; 
        i--; j--; 
    } 
    return result; 
} 


void R_format(string s1,string s2,int pc){


int Rarr[32];

int vs1;
vs1=0;
while(vs1!=32){

Rarr[vs1]=-1;
vs1++;
}

//opcode
Rarr[25]=0; Rarr[26]=1; Rarr[27]=1;Rarr[28]=0;Rarr[29]=0;Rarr[30]=1;Rarr[31]=1;


//function3
if(s1=="add"||s1=="sub"||s1=="mul"){

Rarr[17]=0;Rarr[18]=0;Rarr[19]=0;

}

else if(s1=="and"){

Rarr[17]=1;Rarr[18]=1;Rarr[19]=1;

}

else if(s1=="or"){Rarr[17]=1;Rarr[18]=1;Rarr[19]=0;}

else if(s1=="sra"||s1=="srl"){Rarr[17]=1;Rarr[18]=0;Rarr[19]=1;}

else if(s1=="sll"){Rarr[17]=0;Rarr[18]=0;Rarr[19]=1;}

else if(s1=="slt"){Rarr[17]=0;Rarr[18]=1;Rarr[19]=0;}

else if(s1=="xor"){Rarr[17]=1;Rarr[18]=0;Rarr[19]=0;}





//function7
if(s1=="add"||s1=="and"||s1=="or"||s1=="sll"||s1=="slt"||s1=="xor"||s1=="srl"){

int l=0;
while(l!=7){
Rarr[l]=0;
//cout<<Rarr[l];
l++;

}

}


else if(s1=="sra"||s1=="sub"){

int m=0;
while(m!=7){
Rarr[m]=0;
Rarr[1]=1;
//cout<<Rarr[m];
m++;

}

}

else if(s1=="mul"){
int m1=0;
while(m1!=7){
Rarr[m1]=0;
Rarr[6]=1;
//cout<<Rarr[m];
m1++;

}


}





int n=0;

while(s2[n]!='\0'){

if(s2[n]=='x' && (s2[n+2]==','||s2[n+2]=='\0')){

int v;

 v=s2[n+1]-48;
 
 
if(n==0){

int a;  
Rarr[20]=0;Rarr[21]=0;Rarr[22]=0;Rarr[23]=0;Rarr[24]=0;
int q=v;

 for(a=24;q>0;a--){

   Rarr[a]=q%2;

  
    q=q/2;


}


}

if(n==3||n==4){


int c;  
Rarr[12]=0;Rarr[13]=0;Rarr[14]=0;Rarr[15]=0;Rarr[16]=0;
int r=v;
 for(c=16;r>0;c--){

   Rarr[c]=r%2;
    r=r/2;



}


}


if(n==6||n==7||n==8){


int e;  
Rarr[7]=0;Rarr[8]=0;Rarr[9]=0;Rarr[10]=0;Rarr[11]=0;
int s=v;
 for(e=11;s>0;e--){

   Rarr[e]=s%2;
    s=s/2;


}


}


}


else if(s2[n]=='x'&& (s2[n+3]==','||s2[n+3]=='\0')){



int x=s2[n+1]-48;
int y=s2[n+2]-48;
int z=(10*x)+y;


if(n==0){

int b;  
Rarr[20]=0;Rarr[21]=0;Rarr[22]=0;Rarr[23]=0;Rarr[24]=0;
int g=z;
 for(b=24;g>0;b--){

   Rarr[b]=g%2;
    g=g/2;


}

}

if(n==3||n==4){


int d;  
Rarr[12]=0;Rarr[13]=0;Rarr[14]=0;Rarr[15]=0;Rarr[16]=0;
int h=z;

 for(d=16;h>0;d--){

   Rarr[d]=h%2;
    h=h/2;

}

}


if(n==6||n==7||n==8){

int f;  
Rarr[7]=0;Rarr[8]=0;Rarr[9]=0;Rarr[10]=0;Rarr[11]=0;
int p=z;
 for(f=11;p>0;f--){

   Rarr[f]=p%2;
    p=p/2;


}


}








}

n++;


}




string bin;
for(int F: Rarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);




} //end of R_format function


void S_format(string s1, string s2,int pc){
 int Sarr[32];
 int neg;
 for(int y=0;y<32;y++){
  Sarr[y]=0;
 }
 Sarr[25]=0;Sarr[26]=1;Sarr[27]=0;Sarr[28]=0;Sarr[29]=0;Sarr[30]=1;Sarr[31]=1;
 
 if(s1=="sb"){
   Sarr[17]=0; Sarr[18]=0; Sarr[19]=0;
 }
 else if(s1=="sw"){
   Sarr[17]=0; Sarr[18]=1; Sarr[19]=0;
 }
 else if(s1=="sd"){
  Sarr[17]=0; Sarr[18]=1; Sarr[19]=1; 
 }
 else{
  Sarr[17]=0; Sarr[18]=0; Sarr[19]=1; 
 }
 int n1=0;

while(s2[n1]!='\0'){

if(s2[n1]=='x' && (s2[n1+2]==','||s2[n1+2]==')')){

int v1;

 v1=s2[n1+1]-48;
 
 
if(n1==0){

int a1;  

int q1=v1;

 for(a1=11;q1>0;a1--){

   Sarr[a1]=q1%2;

  
    q1=q1/2;


}
}

int c1;  

int r1=v1;
 for(c1=16;r1>0;c1--){

   Sarr[c1]=r1%2;
    r1=r1/2;
}



}
else if(s2[n1]=='x'&& (s2[n1+3]==','||s2[n1+3]==')')){



int x1=s2[n1+1]-48;
int y1=s2[n1+2]-48;
int z1=(10*x1)+y1;


if(n1==0){

int b1;  

int g1=z1;
 for(b1=11;g1>0;b1--){

   Sarr[b1]=g1%2;
    g1=g1/2;


}

}

int d1;  

int h1=z1;

 for(d1=16;h1>0;d1--){

   Sarr[d1]=h1%2;
    h1=h1/2;

}


}
else if(s2[n1]==',') {

int P1=0;
int sum1=0;
int num1[100];
while(s2[n1]!='('){

if(s2[n1]!=','){

if(s2[n1]=='-'){

//num[P]=s2[n+1]-48;
neg=1;

}
else{
num1[P1]=s2[n1]-48;
P1++;
}

}

n1=n1+1;


}



P1--;
int K1=0;
while(P1>=0){

sum1=sum1+(pow(10,P1)*num1[K1]);
K1++;
P1--;
}


int M1=24;

while(sum1>0){

Sarr[M1] = sum1%2;
sum1=sum1/2;
if(M1==20){

M1=7;
}
M1--;


}

}


n1++;
}

int T[12];

if(neg==1){

int l=0;
int vv=0;
 while(vv!=25){

  if((Sarr[vv]==0)){

   T[l]=1;
  }
  
 else if((Sarr[vv]==1)){

    T[l]=0;

 }
 if(vv==6){

   vv=19;
   }
 //cout<<T[vv];
 vv++;
  l++;
 }

//cout<<endl;

 string U;
 U="1";
 string SSarr;
for(int F: T){

   SSarr.push_back(F+'0');

}

string vam;
vam=addBinary(SSarr,U);

int W=0;
int e=0;
while(W!=25){

//cout<<vam[W];
Sarr[W]=vam[e]-48;
//W++;
if(W==6)W=19;
W++;
e++;
}

}
string bin;
for(int F: Sarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);



} //end of S_format



void I_format(string s1,string s2,int pc){


int iarr[32];

int neg;
int vs2;
vs2=0;
while(vs2!=32){

iarr[vs2]=0;
vs2++;
}
if(s1=="addi" || s1=="andi" || s1=="ori"){
//opcode
iarr[25]=0; iarr[26]=0; iarr[27]=1;iarr[28]=0;iarr[29]=0;iarr[30]=1;iarr[31]=1;


//function3
if(s1=="addi"){

iarr[17]=0;iarr[18]=0;iarr[19]=0;

}

else if(s1=="andi"){

iarr[17]=1;iarr[18]=1;iarr[19]=1;

}

else if(s1=="ori"){iarr[17]=1;iarr[18]=1;iarr[19]=0;}
}
else if(s1=="lb" ||s1=="ld" || s1=="lh" || s1=="lw"){
       iarr[25]=0; iarr[26]=0; iarr[27]=0;iarr[28]=0;iarr[29]=0;iarr[30]=1;iarr[31]=1;
       if(s1=="lb"){

        iarr[17]=0;iarr[18]=0;iarr[19]=0;

        }

        else if(s1=="ld"){

        iarr[17]=0;iarr[18]=1;iarr[19]=1;

         }

        else if(s1=="lh"){iarr[17]=0;iarr[18]=0;iarr[19]=1;}
        else if(s1=="lw"){iarr[17]=0;iarr[18]=1;iarr[19]=0;}
        }
else if(s1=="jalr"){
    iarr[25]=1; iarr[26]=1; iarr[27]=0;iarr[28]=0;iarr[29]=0;iarr[30]=1;iarr[31]=1;
    iarr[17]=0;iarr[18]=0;iarr[19]=0;
}





if(s1=="addi"||s1=="andi"||s1=="ori"){

int n=0;

while(s2[n]!='\0'){

if(s2[n]=='x' && (s2[n+2]==','||s2[n+2]=='\0')){

int v;

 v=s2[n+1]-48;
 
 
if(n==0){

int a;  
iarr[20]=0;iarr[21]=0;iarr[22]=0;iarr[23]=0;iarr[24]=0;
int q=v;

 for(a=24;q>0;a--){

   iarr[a]=q%2;

  
    q=q/2;


}


}

if(n==3||n==4){


int c;  
iarr[12]=0;iarr[13]=0;iarr[14]=0;iarr[15]=0;iarr[16]=0;
int r=v;
 for(c=16;r>0;c--){

   iarr[c]=r%2;
    r=r/2;



}


}
}
else if(s2[n]=='x'&& (s2[n+3]==','||s2[n+3]=='\0')){



int x=s2[n+1]-48;
int y=s2[n+2]-48;
int z=(10*x)+y;


if(n==0){

int b;  
iarr[20]=0;iarr[21]=0;iarr[22]=0;iarr[23]=0;iarr[24]=0;
int g=z;
 for(b=24;g>0;b--){

   iarr[b]=g%2;
    g=g/2;


}

}

if(n==3||n==4){


int d;  
iarr[12]=0;iarr[13]=0;iarr[14]=0;iarr[15]=0;iarr[16]=0;
int h=z;

 for(d=16;h>0;d--){

   iarr[d]=h%2;
    h=h/2;

}

}
}
else if(s2[n]==',') {

if(n==5||n==6||n==7){
int P=0;
int sum=0;
int num[100];
while(s2[n]!='\0'){

if(s2[n]!=','){

if(s2[n]=='-'){

//num[P]=s2[n+1]-48;
neg=1;

}
else{
num[P]=s2[n]-48;
P++;
}

}

n=n+1;


}



P--;
int K=0;
while(P>=0){

sum=sum+(pow(10,P)*num[K]);
K++;
P--;
}


int M=11;

while(sum>0){

iarr[M] = sum%2;
sum=sum/2;
M--;


}
}
}


n++;
}
}

else if(s1=="lb"||s1=="lw"||s1=="lh"||s1=="ld"||s1=="jalr"){




int n1=0;

while(s2[n1]!='\0'){

if(s2[n1]=='x' && (s2[n1+2]==','||s2[n1+2]==')')){

int v1;

 v1=s2[n1+1]-48;
 
 
if(n1==0){

int a1;  
iarr[20]=0;iarr[21]=0;iarr[22]=0;iarr[23]=0;iarr[24]=0;
int q1=v1;

 for(a1=24;q1>0;a1--){

   iarr[a1]=q1%2;

  
    q1=q1/2;


}
}

int c1;  
iarr[12]=0;iarr[13]=0;iarr[14]=0;iarr[15]=0;iarr[16]=0;
int r1=v1;
 for(c1=16;r1>0;c1--){

   iarr[c1]=r1%2;
    r1=r1/2;
}



}
else if(s2[n1]=='x'&& (s2[n1+3]==','||s2[n1+3]==')')){



int x1=s2[n1+1]-48;
int y1=s2[n1+2]-48;
int z1=(10*x1)+y1;


if(n1==0){

int b1;  
iarr[20]=0;iarr[21]=0;iarr[22]=0;iarr[23]=0;iarr[24]=0;
int g1=z1;
 for(b1=24;g1>0;b1--){

   iarr[b1]=g1%2;
    g1=g1/2;


}

}

int d1;  
iarr[12]=0;iarr[13]=0;iarr[14]=0;iarr[15]=0;iarr[16]=0;
int h1=z1;

 for(d1=16;h1>0;d1--){

   iarr[d1]=h1%2;
    h1=h1/2;

}


}
else if(s2[n1]==',') {

int P1=0;
int sum1=0;
int num1[100];
while(s2[n1]!='('){

if(s2[n1]!=','){

if(s2[n1]=='-'){

//num[P]=s2[n+1]-48;
neg=1;

}
else{
num1[P1]=s2[n1]-48;
P1++;
}

}

n1=n1+1;


}



P1--;
int K1=0;
while(P1>=0){

sum1=sum1+(pow(10,P1)*num1[K1]);
K1++;
P1--;
}


int M1=11;

while(sum1>0){

iarr[M1] = sum1%2;
sum1=sum1/2;
M1--;


}

}


n1++;
}




}

int T[12];

if(neg==1){

int vv=0;
 while(vv!=12){

  if((iarr[vv]==0)){

   T[vv]=1;
  }
  
 else if((iarr[vv]==1)){

    T[vv]=0;

 }
 
 //cout<<T[vv];
 vv++;
 }

//cout<<endl;

 string U;
 U="1";
 string Iarr;
for(int F: T){

   Iarr.push_back(F+'0');

}

string vam;
vam=addBinary(Iarr,U);

int W=0;
while(W!=12){

//cout<<vam[W];
iarr[W]=vam[W]-48;
//W++;
W++;
}

}

string bin;
for(int F: iarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);


} //end of I_format





void U_format(string s1, string s2,int pc){
int Uarr[32];
	 
Uarr[31]=1;
Uarr[30]=1;
Uarr[29]=1;
Uarr[28]=0;
Uarr[27]=1;
Uarr[26]=1;
Uarr[25]=0;

int a;
int i=24;
while(i>=0){

Uarr[i]=0;

i--;
}




if(s1=="auipc"){
 
	Uarr[26]=0;

}

if(s2[2]==','){


a=s2[1]-48;

}

if(s2[3]==','){

int x,y;

x=s2[2]-48;
y=s2[1]-48;

a=10*y+x;

}

int j=24;

for(j=24;a>0;j--){

   Uarr[j]=a%2;

 
	a=a/2;
}
int z=0;


while(s2[z]!=','){

z++;

}

string s3 =  s2.substr(z+1,s2.length());



stringstream imm(s3);




int var;

imm>>var;

int b;

for(b=19;var>0;b--){

Uarr[b]=var%2;

var=var/2;

}
string bin;
for(int F: Uarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);


} //end of U format


int UJ_format( string S, int pc,string asmfile){
int UJarr[32];

int i=0;
while(i<32){
UJarr[i]=0;
i++;
      	}

UJarr[31]=1;
UJarr[30]=1;
UJarr[29]=1;
UJarr[28]=1;
UJarr[27]=0;
UJarr[26]=1;
UJarr[25]=1;

int n=0;
int kk;
while(S[n]!='\0'){

if(S[n]=='x' && (S[n+2]==','||S[n+2]=='\0')){

int v;

 v=S[n+1]-48;
 
int a;  

 for(a=24;v>0;a--){

   UJarr[a]=v%2;

 
	v=v/2;
          	}

   	}

else if(S[n]=='x' && S[n+3]==','){

int x=S[n+1]-48;
int y=S[n+2]-48;
int z=(10*x)+y;
int q;  

 for(q=24;z>0;q--){

   UJarr[q]=z%2;

 
	z=z/2;
          	}

   	}

 if(S[n]==','){
  kk=n+1;
 
 
 	 
 	}
    
 
 
n++;
}
string s3= S.substr(kk,S.length());

int aaa;



fstream new_file; 	//searchimg for label

int pc2;
int cor;  
int cor1;
new_file.open(asmfile,ios::in);   
if(!new_file)
cout<<"No such file";  else {
 string s;
int pc1=-4;
while (getline(new_file,s)) {

while(s.length()==0){

  getline(new_file,s);

}


   
string S1;

S1=removespaces(s);

int j=0;
while(S1[j]!='\0'){


//cout<<S1[0];
  
if(S1[1]=='t') cor=1;

if(S1[j]==':'){

aaa=j;

   int xx=0 ; int yy=0;

while(s3[xx]!='\0'){

  	if(s3[xx]==S1[xx]) {

                 	yy++;
                	 
                       	}
             	xx++;
              	}

   	if(xx==yy){
         	pc2=pc1-pc;
                 cor1=1;
         	 
          	}
    



}
j++;
}
 
 
   if(cor==1){      	 
pc1=pc1+4;}
}

if(cor1!=1){cout<<"label not found for";
           cout<<pc;
           cout<<"th pc instruction"<<endl;
           return 0;}

}
                     	//end of searching

new_file.close();


int jj=0;

int array[20];

  while(jj<=20){
  array[jj]=0;
	jj++;
   }



if(pc2>0){
int ii=0;

while(pc2>0){

  array[ii]=pc2%2;

   pc2=pc2/2;
ii++;
  }
}

if(pc2<0){

pc2=-pc2;
int iij=0;

while(pc2>0){

  array[iij]=pc2%2;

   pc2=pc2/2;
iij++;
  }
int iii=0;

int vv=0;

while(iii<=20){
 if(array[iii]==1){
    
	vv=iii;
    

 	}

  iii++;
}

int jjj=vv+1;
          	 
 	while(jjj<=20){
     	if(array[jjj]==1){
	 
         	array[jjj]=0;
        	}
        	else{

         	array[jjj]=1;

        	}
    	jjj++; }

}






UJarr[0]=array[20];
UJarr[1]=array[10];
UJarr[2]=array[9];
UJarr[3]=array[8];
UJarr[4]=array[7];
UJarr[5]=array[6];
UJarr[6]=array[5];
UJarr[7]=array[4];
UJarr[8]=array[3];
UJarr[9]=array[2];
UJarr[10]=array[1];
UJarr[11]=array[11];
UJarr[12]=array[19];
UJarr[13]=array[18];
UJarr[14]=array[17];
UJarr[15]=array[16];
UJarr[16]=array[15];
UJarr[17]=array[14];
UJarr[18]=array[13];
UJarr[19]=array[12];



string bin;
for(int F: UJarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);


}                                                  	//end of UJ_function



int SB_format(string s1, string s2, string S, int pc,string asmfile){
int SBarr[32];
int i=0;
while(i<32){
SBarr[i]=0;
i++;
}
int kk;
SBarr[31]=1;
SBarr[30]=1;
SBarr[29]=0;
SBarr[28]=0;
SBarr[27]=0;
SBarr[26]=1;
SBarr[25]=1;
if(s1=="beq"){
  SBarr[17]=0; SBarr[18]=0; SBarr[19]=0;
}
else if(s1=="bne"){
 SBarr[17]=0; SBarr[18]=0; SBarr[19]=1;
}
else if(s1=="bge"){
 SBarr[17]=1; SBarr[18]=1; SBarr[19]=1; 
}
else if(s1=="blt"){
 SBarr[17]=1; SBarr[18]=0; SBarr[19]=0; 
}
 if(s2[0]=='x'){
  if(s2[2]==','){
   int v = s2[1]-48;
   for(int a=16;v>0;a--){
    SBarr[a]=v%2;
    v=v/2;   
   }  
  }
  else if(s2[3]==','){
   int x=s2[1]-48;
   int y=s2[2]-48;
   int z=(10*x)+y;
   
   for(int a=16;z>0;a--){
    SBarr[a]=z%2;
    z=z/2;   
   }     
  }
 }
 if(s2[3]=='x'){
  if(s2[5]==','){
   int v = s2[4]-48;
   for(int a=11;v>0;a--){
    SBarr[a]=v%2;
    v=v/2;   
   }
  }
  else if(s2[6]==','){
   int x=s2[4]-48;
   int y=s2[5]-48;
   int z=(10*x)+y;
   
   for(int a=11;z>0;a--){
    SBarr[a]=z%2;
    z=z/2;   
   }  
  }
 } 
 else if(s2[4]=='x'){
  if(s2[6]==','){
   int v = s2[5]-48;
   for(int a=11;v>0;a--){
    SBarr[a]=v%2;
    v=v/2;   
   }
  }
  else if(s2[7]==','){
   int x=s2[5]-48;
   int y=s2[6]-48;
   int z=(10*x)+y;
   
   for(int a=11;z>0;a--){
    SBarr[a]=z%2;
    z=z/2;   
   }  
  } 
 }
 if(s2[5]==',')
  kk=6;
 else if(s2[6]==',')
  kk=7;
 else if(s2[7]==',')
  kk=8;
string s3= s2.substr(kk,s2.length());

int aaa;
int pc2;
int cor;
int cor1;
fstream new_file; 	//searchimg for label

new_file.open(asmfile,ios::in);  
if(!new_file)
cout<<"No such file";  else {
 string s;
int pc1=-4;
while (getline(new_file,s)) {
while(s.length()==0){
  getline(new_file,s);
}

  
string S1;
S1=removespaces(s);
int j=0;
while(S1[j]!='\0'){

//cout<<S1[0];

if(S1[1]=='t') cor=1;	

if(S1[j]==':'){
aaa=j;
   int xx=0 ; int yy=0;
while(s3[xx]!='\0'){
  	if(s3[xx]==S1[xx]) {
                 	yy++;
                 	
                       	}
             	xx++;
              	}
   	if(xx==yy){
                cor1=1;
         	pc2=pc1-pc;
       	
   	}
 
}
j++;
}
           	
if(cor==1){pc1=pc1+4;}
}

if(cor1!=1){cout<<"label not found for ";
           cout<<pc;
           cout<<"th pc instruction"<<endl;
           return 0;}

}
                     	//end of searching
new_file.close();
//cout<<pc2;
int jj=0;
int array[13];
  while(jj<13){
  array[jj]=0;
	jj++;
   }



if(pc2>0){
int ii=0;

while(pc2>0){

  array[ii]=pc2%2;

   pc2=pc2/2;
ii++;
  }
}

if(pc2<0){

pc2=-pc2;
int iij=0;

while(pc2>0){

  array[iij]=pc2%2;

   pc2=pc2/2;
iij++;
  }
int iii=0;

int vv=0;

while(iii<=12){
 if(array[iii]==1){
    
	vv=iii;
    

 	}

  iii++;
}

int jjj=vv+1;
          	 
 	while(jjj<=12){
     	if(array[jjj]==1){
	 
         	array[jjj]=0;
        	}
        	else{

         	array[jjj]=1;

        	}
    	jjj++; }


}


SBarr[0]=array[12];
SBarr[24]=array[11];
SBarr[1]=array[10];
SBarr[2]=array[9];
SBarr[3]=array[8];
SBarr[4]=array[7];
SBarr[5]=array[6];
SBarr[6]=array[5];
SBarr[20]=array[4];
SBarr[21]=array[3];
SBarr[22]=array[2];
SBarr[23]=array[1];

string bin;
for(int F: SBarr){

   bin.push_back(F+'0');

}


BinToHexwriteinfile(bin,pc);


}    //end of sb format




int assembler_directives(string asmfile){


fstream new_file;

new_file.open(asmfile,ios::in);   
if(!new_file)
cout<<"No such file";  else {
 string s;
long long int adr=268435456;
while (getline(new_file,s)) {

while(s.length()==0){

  getline(new_file,s);

}




 
string S1;

S1=removespaces(s);

//cout<<S1;
int byte[8];
int word[32];
int a=0,b=0;
while(a<=7){
byte[a]=0;
a++;
}
while(b<=32){
word[b]=0;
b++;
}

   
   string str1 = ".word";
   string str2 = ".byte";
   string str3 = ".asciiz";

 
    
	size_t found = S1.find(str1);
	if (found != string::npos) {
  	 
	int k =found+5;
  // cout<<S1.length();
	string dec = S1.substr(k,S1.length());
    
int bb=0;


stringstream imm(dec);

int x;
imm>>x;
//cout<<x;
b=b-2;
while(x>0){

word[b]=x%2;
x=x/2;
b=b-1;

}
int word1[31-b];


int i=0;
int j=b+1;
while(j!=32){

word1[i]=word[j];

i++;
j++;
}


//word1[i]='\0';
//int ii=0;

/*while(ii<32){

cout<< word[ii];
ii++;

}*/

string bin;
for(int F: word1){

   bin.push_back(F+'0');

}

BinToHexwriteinfile(bin,adr);

adr = adr +4;

}


	size_t found1 = S1.find(str2);
	if (found1 != string::npos) {
	 
 	found1=found1+5;
   // cout<<found1;  
  	string dec1 = S1.substr(found1,S1.length());
	//cout<< dec1;
   stringstream imm2(dec1);

  int y;
  imm2>>y;
a=a-1;
while(y>0){
byte[a]=y%2;
y=y/2;

a--;
}

int byte1[7-a];


int k=0;
int l=a+1;
while(l!=8){

byte1[k]=byte[l];

k++;
l++;
}
/*int jj=0;

while(jj<8){

cout<< byte[jj];
jj++;

}*/
string bin;
for(int F: byte1){

   bin.push_back(F+'0');

}



BinToHexwriteinfile(bin,adr);
adr=adr+1;

}



//cout<<endl;
}


}
new_file.close();    
return 0;
}      	//end of AD





int main()
{
fstream new_file; 
string asmfile;

cin>>asmfile;
new_file.open(asmfile,ios::in);   
if(!new_file) 
cout<<"No such file";  else {
 string s; 


while(getline(new_file,s)){

if(s[0]=='.'&& s[1]=='d'){

assembler_directives(asmfile);

} 
}
new_file.close();  
new_file.open(asmfile,ios::in);
while (getline(new_file,s)) {
if(s[1]=='t'){
int pc=0;
while (getline(new_file,s)) {

while(s.length()==0){

  getline(new_file,s);

}

//cout << s<<"\n";   

//cout << 
string S;

S=removespaces(s);

int k=1;
while(S[k]!='x'){

k++;

}


string s3 = S.substr(0,k);
string s2 = S.substr(k,S.length());


int m=0;
int mm=0;

while(s3[m]!='\0'){

if(s3[m]==':'){

	mm=m+1; 	 

   	}
  m++;
}

string s1= s3.substr(mm,s3.length());


int op=1;
//cout<<s1<<endl;
//cout<<s2;

if(s1=="add"||s1=="and"||s1=="or"||s1=="sll"||s1=="slt"||s1=="sra"||s1=="srl"||s1=="sub"||s1=="xor"||s1=="mul"||s1=="div"||s1=="rem"){

    R_format(s1,s2,pc);
   

   }

if(s1=="addi"||s1=="andi"|| s1=="ori" ||s1=="lb"||s1== "ld"||s1== "lh" ||s1== "lw" ||s1== "jalr"){

   if(s1=="lb"||s1== "ld"||s1== "lh" ||s1== "lw"){

       int mm=0; 
       
      while(s2[mm]!='\0'){
                 
            if(s2[mm]=='(') op=0;
            
            mm++;
 
             }

  if(op==0){ I_format(s1,s2,pc);}
  else {cout<<"error in writing ";
         cout<<pc;
        cout<<"thpc instruction in .text"<<endl;}
}

else{ 

 int mn=0; 
       
      while(s2[mn]!='\0'){
                 
            if(s2[mn]=='x') op=op+1;
            
            mn++;
 
             }
//cout<<op<<endl;
  if(op==3){ I_format(s1,s2,pc);}
  else {cout<<"error in writing ";
         cout<<pc;
        cout<<"thpc instruction in .text"<<endl;}

};
}
if(s1=="sb"||s1=="sw"||s1=="sd"||s1=="sh"){
int ml=0; 
       
      while(s2[ml]!='\0'){
                 
            if(s2[ml]=='(') op=0;
            
            ml++;
 
             }

  if(op==0){ S_format(s1,s2,pc);}
  else {cout<<"error in writing ";
         cout<<pc;
        cout<<"thpc instruction in .text"<<endl;}



}
if(s1=="beq"||s1== "bne"||s1== "bge"||s1== "blt"){
   SB_format(s1,s2,S,pc,asmfile);

}
if(s1=="auipc"||s1== "lui"){
 
U_format(s1,s2,pc);

}

if(s1=="jal"){
UJ_format(S,pc,asmfile);


}

pc=pc+4;

}
  }

}
  }
new_file.close();
return 0;
}

