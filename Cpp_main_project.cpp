#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int cid = 0;
string customerinfo[100][11];   
float interestrate;
vector<string> admininfo;
vector<vector<float> > transactions;
vector<vector<string> > messages1;

///////////////////////////
////////////////////////////


void pause(){
    cout << "Press any letter key followed by return key to continue";
    char k;
    cin >> k;
    cin.ignore();
    return;
}

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int adminrequired();
int setupadmininfo();
int setupbankinfo();
int showadmin();
int mainadminportal();
string getpassword();
string getemailid();
string getnumber(int);
string getdate(int , string);
string getemailid();
int InterestPayment();
int shownegativeballanceaccunts();
int showpositiveballanceaccunts();
int sendwarning();
int blockaccounts();
int summary();

int showcustomersignup();
string getusername();
int appendtotable(string name,string username,string password,string emailid,string phonenumber,
                    string SSN,string org,string doj,string dob,string status,string type);

int showcustomer();
int maincustomerportal(int currentuser);
int lastNTransactions(int currentuser);
int showcurrentbalance(int currentuser);
int withdraw(int currentuser);
int deposit(int currentuser);
int transfer(int currentuser);
int inbox(int currentuser);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


int main(){
   adminrequired();
       
    int choice = 0;
    while(choice !=4){
         system("clear");
            cout << "*****Welcome to the EECE1080C/CS1021C Bank******" << endl;;
            cout << "Admin Signin----------------(1)" << endl;
            cout << "Customer Signin-------------(2)" << endl;
            cout << "Customer Signup-------------(3)" << endl;
            cout << "Exit------------------------(4)" << endl;
           
            cout << "Enter your Option: ";
            cin >> choice;
            switch(choice){
                case 1:
                         cout<<"Admin Signin page: " << endl;
                         showadmin();
                         pause();
                         break;
                case 2:
                         cout<<"Customer Signin page: " << endl;
                         showcustomer();
                         pause();
                         break;
                case 3:
                         cout<<"Customer Signup page: " << endl;
                         showcustomersignup();
                         pause();
                         break;
                case 4:  cout<<"Thank You for Using our Bank!" << endl;
                         pause();
                         break;
                default:
                         cout<<"Please enter a valid option: " << endl;
                         pause();
                         break;
               
            }
    }
           
   
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

int adminrequired(){
    cout << "Congratulations For starting your new Venture" << endl;
    cout << "1: Admin Information/Credentials" << endl;
    cout << "2: Interest Rate" << endl;
    cout << "3: Customer Sigup Information Requirement" << endl;
    cout << "4: Maximum Initial Targeted Customer Base" << endl;
    cout << "If you are ready with the information.Press 1 to setup them now or press any other key to come later" << endl;
    int k;
    cin >> k;
    cin.ignore();
    if(k!=1){
       exit(0);
    }
    else
       setupadmininfo();
       for(auto x: admininfo)
          cout << x << endl;
        cout << "Verify Your Information Above";
        pause();
       setupbankinfo();
    pause();
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

int setupadmininfo(){
    system("clear");
    string name;
    cout << "Admin Information Page!" << endl;
    cout << "Please Enter Your Name: ";
    getline(cin,name);
    admininfo.push_back(name);
    cout << "Please Enter Your Username: ";
    string username;
    cin >> username;
    admininfo.push_back(username);
    cout << "Please Enter your Password[Must have a number,upper and lower case letter and minimum length of 6 characters]: ";
    string password;
    password = getpassword();
    admininfo.push_back(password);
    cout << "Please Enter your Email ID: ";
    string emailid;
    emailid = getemailid();
    admininfo.push_back(emailid);
    cout << "Please Enter your Phone Number: ";
    string phonenumber;
    phonenumber = getnumber(10);
    admininfo.push_back(phonenumber);
    cout << "Please Enter Your Government Approval Reference Number: ";
    string referencenumber;
    cin >> referencenumber;
    admininfo.push_back(referencenumber); 

return 0;
}

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

string getpassword(){
    bool valid = false;
    string password;
    while(!valid){
        bool len = false, hasnumber = false, hasupperletter = false, haslowerletter = false;
        cout << "Password: ";
        cin >> password;
        if(password.length() > 6)
           len = true;
        for(int i = 0;i < password.length(); i++){
          if(password[i] >= '0' and password[i] <= '9')
              hasnumber = true;
          if(password[i] >= 'A' and password[i] <= 'Z')
              hasupperletter = true;
          if(password[i] >= 'a' and password[i] <= 'z')
              haslowerletter = true;
          }
        valid = (len && hasnumber && hasupperletter && haslowerletter? true: false);  
        if(!valid)
          cout << "Please Enter a valid password ";
    }
    return password;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

string getemailid(){
 bool valid = false;
    string emailid;
    while(!valid){
        bool hasatsymbol = false;
        cin >> emailid;
        for(int i = 0; i < emailid.length(); i++)
          if(emailid[i] == '@'){
              hasatsymbol = true;
              break;
          }

        valid = (hasatsymbol? true: false); 
        if(!valid)
          cout << "Please Enter a valid emailid";
    }
    return emailid;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

string getnumber(int length1){
 bool valid = false;
    string phonenumber;
    while(!valid){
        bool leng = false, hasallnumber = false;
        if(length1 == 10)
            cout << "Phone Number: ";
        else 
            cout << "SSN Number: ";
        cin >> phonenumber;
        cin.ignore();
        if(phonenumber.length() == length1)
           leng = true;
        for(int i = 0; i < phonenumber.length(); i++)
          if(phonenumber[i] >= '0' and phonenumber[i]<= '9'){
              hasallnumber = true;
          }
          else{
              hasallnumber = false;
              break;
          }
        valid = (leng&&hasallnumber? true: false);  
        if(!valid)
          cout << "Please Enter a valid phone number(number of length " << length1 << ")";
    }
    return phonenumber;
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int setupbankinfo(){
    cout << "Enter interest rate for customer: ";
    cin >> interestrate;
    cout <<"Maximum allowed customers as per government approval is 100" << endl;
    cout << "Follwoing Information is Required by customer to sign in" << endl;
    cout << "1: Name" << endl;
    cout << "2: Username" << endl;
    cout << "3: SSN" << endl;
    cout << "4: Status" << endl;
    cout << "5: Type" << endl;
    cout << "6: Organization" << endl;
    cout << "7: DOJ" << endl;
    cout << "8: DOB" << endl;
    cout << "8: EmailID" << endl;
    cout << "8: Phone Number" << endl;
    cout << "9: Password" << endl;
return 0;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int showadmin(){
    string username;
    string password;
    bool matching = false;
    
    while(!matching){
    cout << "Admin username: ";
    cin >> username;
    cout << endl;
    cout << "Password: ";
    cin >> password;
    cout << endl;
    if(username == admininfo[1])
      if(password == admininfo[2])
         matching = true;
    if(!matching){
         cout<<"Please enter a correct info" << endl;
         cout<<"Try again (1)" << endl;
         cout<<"Go Back (2)" << endl;
         int k;
         cin >> k;
         if(k == 2)
           return 0;
	 }
    
    }
    mainadminportal();
    return 0;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


int mainadminportal(){
    cout << "Main Admin Portal: " << endl;
     int choice = 0;

 while(choice!=7){
         system("clear");
            cout<<"*****Welcome to the EECE1080C/CS1021C Bank******" << endl;
            cout<<"Pay Monthly Interest-----------------------------(1)" << endl;
            cout<<"Check Accounts with -ve Balance------------------(2)" << endl;
            cout<<"Check Accounts with +ve Balance------------------(3)" << endl;
            cout<<"Warning Messages to -ve Balance Accounts---------(4)" << endl;
            cout<<"Repeated -ve Balance Block Account---------------(5)" << endl;
            cout<<"generate Summary Report--------------------------(6)" << endl;
            cout<<"Logout-------------------------------------------(7)" << endl;
           
            cout << "Enter your Option:";
            cin >> choice;
            switch(choice){
                case 1:
                         cout << "Monthly Interest Payment Portal: " << endl;
                         InterestPayment();
                         break;
                case 2:
                         cout << "Accounts with -ve balance: " << endl;
                         shownegativeballanceaccunts(); 
                         break;
                case 3:
                         cout << "Accounts with +ve balance: " << endl;
                         showpositiveballanceaccunts();
                         break;
                case 4:  cout << "Warning messages to -ve balance accounts: " << endl;
                         sendwarning();
                         break;
                case 5:  cout << "Repeated -ve balance Block Account: " << endl;
                         blockaccounts();
                         break;
                case 6:  cout << "Generated Summary Report: " << endl;
                         summary();
                         pause();
                         break;
            
                case 7:  cout << "Thank You!" << endl;
                         break;
            
                default:
                         cout << "Please enter a valid option: " << endl;
                         pause();
                         break;
               
            }
    }
return 0;
   
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int InterestPayment(){
    float totalpaidinterest = 0;
    float positive = 0;
    float negative  = 0;
    for(int i = 0; i < cid ;i ++){
        float newamount = transactions[i].back() + (interestrate*transactions[i].back()) / 100;
        if((interestrate * transactions[i].back()) / 100 < 0)
           negative -=(interestrate*transactions[i].back()) / 100;
        else
           positive += (interestrate*transactions[i].back()) / 100;
        transactions[i].push_back(newamount);
        messages1[i].push_back("Interest of " + to_string((interestrate*transactions[i].back()) / 100) + "has been added to you account");
    }
    cout << "Interest Payment Done" << endl;
    cout << "Total Positive Interest Paid: " << positive << endl;
    cout << "Total Negative Interest Paid: " << negative << endl;
    cout << "Net Interest Paid: " << positive-negative;

    pause();
    return 0;
}

////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int shownegativeballanceaccunts(){
        for(int i = 0; i < cid; i++){
            if(transactions[i].back() < 0){
                cout << customerinfo[i][0] << " has negative balance: " <<transactions[i].back() << endl;
            }
        }
    pause();
    return 0;
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

int showpositiveballanceaccunts(){
   for(int i = 0; i < cid; i++){
            if(transactions[i].back() > 0){
                cout << customerinfo[i][0] << " has Positive balance: " << transactions[i].back() << endl;
            }
   }
    pause();
    return 0;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

int sendwarning(){
   for(int i = 0; i < cid; i++){
       if(transactions[i].back() < 0){
            cout << "Warning Send to " << customerinfo[i][0] <<" with negative balance of: " << transactions[i].back() << endl;
            messages1[i].push_back("Please make your balance positive to avoid account Freezing");
       }
    }
    pause();
    return 0;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

int blockaccounts(){
     for(int i = 0; i < cid; i++){
        if(transactions[i].back() < 0 && transactions[i][transactions[i].size() - 2] < 0){
            cout << "-ve Balance from last two transactions  for " << customerinfo[i][0] << " Account Blocked with current balance 0f: " << transactions[i].back() << endl;
            customerinfo[i][9] = "inactive";
            messages1[i].push_back("Account Freezed");
         }
     }
    pause();
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int summary(){

    cout << "Bank has total Customer base of: " << cid << endl;
    int active = 0;
    int inactive = 0;
    int negative = 0;
    int positive = 0;
    for(int i = 0; i < cid; i++){
        if(customerinfo[i][9] == "active")
            active++;
        else
            inactive++;
        if(transactions[i].back() < 0)
             negative++;
        else 
            positive++;
    
    }
    cout << "Total Active customers: " << active << endl;
    cout << "Total Inactive Customer: " << inactive << endl;
    cout << "Total Positive Balance Accunts: " << positive << endl;
    cout << "Totoal Negative Balance Accounts: " << negative << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// all of this above is for the admin portal part of the project


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


int showcustomersignup(){
    system("clear");
    string customerName;
    cout << "Customer Signup Information Page!" << endl;
    cout << "Please Enter Your Name: " << endl;
    cin.ignore();
    getline(cin,customerName);
    cout << "Please Enter Your Username: ";
    string userName;
    userName = getusername();
    cout << "Please Enter your Password[Must have a number,upper and lower case letter and minimum length of 6 characters]: ";
    string userPassword;
    userPassword = getpassword();
    cout << "Please Enter your Email ID: ";
    string emailid;
    emailid = getemailid();
    cout << "Please Enter your Phone Number: ";
    string phonenumber;
    phonenumber = getnumber(10);
    cout << "Please Enter Your SSN: ";
    string SSN;
    SSN = getnumber(9);
    cout << "Please Enter Your Organization: ";
    string org;
    cin >> org;
    cout << "Please Enter today date DOJ(date of Joiing in format (MM/DD/YYYY)): ";
    string doj;
    cin >> doj;
    cout << "Please Enter today date DOB(date of Birth in format (MM/DD/YYYY)): ";
    string dob;
    cin >> dob;
    string status = "active";
    cout << "This is Business account or Personal: ";
    string accountType;
    cin >> accountType;
    appendtotable(customerName,userName,userPassword,emailid,phonenumber,SSN,org,doj,dob,status,accountType);
    vector<float> trans;
    string id;
    cout << "Please Enter Initial Deposit Amount: ";
    cin >> id;
    trans.push_back(stof(id));
    transactions.push_back(trans);
    vector<string> message;
    message.push_back("Welcome to EECE/CS Bank");
    message.push_back("Intial Deposit of $"+id+"has been deposited");
    messages1.push_back(message);
    return 0;
}



/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

string getusername(){
    string username;
    bool exist = true;
    while(exist){
        exist = false;
        cout<<"Enter Username: ";
        cin>>username;
        for(int i=0;i<cid;i++)
          {if(customerinfo[i][1]==username)
               exist = true;
               break;
          }
          if(exist)
            cout<<"Username already exist please anter a different USername: " << endl;
    }
    return username;

}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int appendtotable(string name, string username, string password, string emailid, string phonenumber, string SSN, 
                    string org, string doj, string dob, string status, string type){  
    if(cid >= 100){
       cout << "Bank Overflow: Unable to register!" << endl;
       return 0;
    
    }
    customerinfo[cid][0] = name;
    customerinfo[cid][1] = username;
    customerinfo[cid][2] = password;
    customerinfo[cid][3] = emailid;
    customerinfo[cid][4] = phonenumber;
    customerinfo[cid][5] = SSN;
    customerinfo[cid][6] = org;
    customerinfo[cid][7] = doj;
    customerinfo[cid][8] = dob;
    customerinfo[cid][9] = status;
    customerinfo[cid][10] = type;
    cout << "Welcome to EECE10180C.CS1021C Bank" << endl << "Your Customer ID is" <<cid+9999999;
    cid++;
    return 0;
}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// this above is for customer sign up

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

int showcustomer(){
    if(cid == 0){
        cout << "Bank has no customer";
        return 0;
    }
    string username;
    string password;
    int i=0;
    bool matching = false;
    while(!matching){
        cout << "Customer username: ";
        cin >> username;
        cout << endl;
        cout << "Password: ";
        cin >> password;
        for(i = 0; i < cid; i++){
            if(customerinfo[i][1] == username)
                if(customerinfo[i][2] == password){
                    matching = true;
                    if(customerinfo[i][9] == "inactive"){
                        cout << "Account Blocked";
                        matching = false;
                    }
                    break;
                }
                else{
                    matching = false;
                    cout << "Username and Password do not match";
                    break;
                }
            }
         if(!matching)
             cout<<"Please enter a correct customer info" << endl;;
        }
    maincustomerportal(i);
    return 0;
}

////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int maincustomerportal(int currentuser){
        int choice = 0;

        cout << "Customer Portal: " << endl;
         while(choice != 7){
         system("clear");
            cout << "*****Welcome to the EECE1080C/CS1021C Bank******" << endl;
            cout << "Statement Summary last N transactions----(1)" << endl;
            cout << "Show Current Balance---------------------(2)" << endl;
            cout << "Withdraw Amount--------------------------(3)" << endl;
            cout << "Deposit Amount---------------------------(4)" << endl;
            cout << "Transfer to another Account--------------(5)" << endl; 
            cout << "Check Inbox------------------------------(6)" << endl;
            cout << "Exit-------------------------------------(7)" << endl;
           
            cout << "Enter your Option:: ";
            cin >> choice;
            switch(choice){
               case 1:
                         cout << "Statement Summary last N transactions: ";
                         lastNTransactions(currentuser);
                         break;
                case 2:
                         cout << "Current Balance: ";
                         showcurrentbalance(currentuser);
                         break;
                case 3:
                         cout << "Withdraw Amount: ";
                         withdraw(currentuser);
                         break;
                case 4:  cout << "Deposit Amount: ";
                         deposit(currentuser);
                         break;
                case 5:  cout << "Transfer to another Account: ";
                         transfer(currentuser);
                         break;
                case 6:  cout << "Check Inbox: ";
                         inbox(currentuser);
                         break;
            
                case 7:  cout << "Thank You: ";
                         break;
            
                default:
                         cout << "Please enter a valid option: ";
                         pause();
                         break;
            }
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int lastNTransactions(int currentuser){
    cout << "Enter the value of N: ";
    int N;
    cin >> N;
    int previousbalance = 0;
    if(N >= transactions[currentuser].size()){
      for(auto x: transactions[currentuser]){
          if(x > previousbalance){
              cout << "Deposit of: $"<< x-previousbalance << endl;
          }
          else{
              cout << "Withdrawal of: $" << x-previousbalance <<endl;
          }
          previousbalance = x;
              
      }
    }
    else{
       previousbalance = transactions[currentuser][transactions[currentuser].size()-N];  
       for(int x=transactions[currentuser].size()-N; x <transactions[currentuser].size(); x++){
          if(transactions[currentuser][x] > previousbalance){
              cout << "Deposit of: $" << transactions[currentuser][x]-previousbalance << endl;
          }
          else{
              cout << "Withdrawal of: $" << transactions[currentuser][x]-previousbalance << endl;
          }
          previousbalance = transactions[currentuser][x];
              
      } 
    }
    pause();
   return 0;   
}

////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

int  showcurrentbalance(int currentuser){
    cout << "Current Balance: " << transactions[currentuser].back() << endl;
    pause();
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int withdraw(int currentuser){
   cout << "Enter amount to withdraw: ";
    float wid = 0;
    while(true){
        cin >> wid;
        if(wid <= 0)
            cout << "Enter positive amount to withdraw" << endl;
        else
            break;
    }
    float currentbal = transactions[currentuser].back();
    if(currentbal < wid){
        messages1[currentuser].push_back("Not Enough Balance :: Overdraft fee of $10 is charged");
        cout << "Not Enough Balance :: Overdraft fee of $10 is charged" << endl;
        wid -=10;
    }
    float newbalance = currentbal - wid;
    transactions[currentuser].push_back(newbalance);
    messages1[currentuser].push_back("Amount Withdrawn: $" +to_string(wid));
    cout<<"Withdrawal Successful"<<endl;;
    pause();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////


int deposit(int currentuser){
    cout << "Enter amount to deposit: ";
    float dep = 0;
    while(dep <= 0){
        cin >> dep;
        cout << "Enter positive amount to deposit" << endl;
    }
    float currentbal = transactions[currentuser].back();
    float newbalance = currentbal + dep;
    transactions[currentuser].push_back(newbalance);
    if(currentbal < 0 && newbalance > 0){
        cout << "Your balance has become positive and accout is in Active state again" << endl;
        customerinfo[currentuser][9] = "active";
    }
    messages1[currentuser].push_back("Amount Deposited:: $" +to_string(dep));
    cout << endl;
    cout<<"Deposit Successful"<<endl;;
    pause();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int transfer(int currentuser){
    cout << "Enter Destination Account number: ";
    int desid;
    do{
        cin >> desid;
        if(desid-9999999 > cid && desid-9999999 < 0){
          cout <<" Destination customer accunt do not exist" << endl;
        }
        else
           break;
    }while(true);
    cout << "Enter Amount to transfer";
    float trans = 0;
    while(trans <= 0){
        cin >> trans;
        cout <<"Enter positive amount to transfer" << endl;
    }
    transactions[currentuser].push_back(transactions[currentuser].back() - trans);
    transactions[desid-9999999].push_back(transactions[desid-9999999].back() + trans);
    messages1[currentuser].push_back("$" + to_string(trans) + " Amount Transfered to " + to_string(desid));
    messages1[desid-9999999].push_back("$" + to_string(trans) + " Amount Recieved from " + to_string(currentuser+9999999));
    if( transactions[desid-9999999].back() > 0){
        cout << "Your Destination balance has become positive and accout is in Active state again" << endl;
        customerinfo[desid-9999999][9] = "active";
    }
    cout << "Transfer Sucessful";
    pause();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

int inbox(int currentuser){
    cout << "How many messages1 you want to read";
    int count;
    cin >> count;
    if(count > messages1[currentuser].size()){
        cout << "Not Enough messages: Reading all messages: " << endl;
        for(auto x: messages1[currentuser])
           cout << x << endl;
    }
    else
    {
        cout << "Reading " << count << " messages:" << endl;
        for(int i=messages1[currentuser].size() - count; i < messages1[currentuser].size(); i++)
           cout << messages1[currentuser][i] << endl;
    }
    pause();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// all of the above is for the customer main page

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
