#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;




bool isNumber(const string& s){
  for (char const &c: s) {
    if(std::isdigit(c) == 0){
      return false;
    }
  }
  return true;
}






// this function will store the users name and
// both checkings and savings informtion that way we can read
// from the users file to continue to add money to it
// we need to add the users pin to this
// we also need to replace the users current checking and savings
// with there new one that they are sending through to this function
// we cannot simply just keep adding the same user b/c we dont want
// to run into duplicates
void storeBankInformation(string user,string pin, int checking, int savings)
{
  ofstream storeBankInfo;
  ifstream replaceBankInfo;
  string grabInfo;
  string user_Checking;
  string user_Savings;
  replaceBankInfo.open("useraccountfile.txt");
  storeBankInfo.open("useraccountfile.txt", fstream::app);
  // this line puts information into the file
  while(replaceBankInfo >> grabInfo){
    if (grabInfo == user){
      getline(replaceBankInfo, grabInfo);
      istringstream istrm(grabInfo);
      istrm >> user_Checking; // clients checking account amount                                                                                                                 
      istrm >> user_Savings;// clients savings account amount

      
      
      
    }

    if(replaceBankInfo.eof()){
      break;
    }
    else{
      storeBankInfo << pin + "         " << user + "                  " << checking << savings + "\n";
      cout << "Information stored succesfully" << endl;
    }
  }
  storeBankInfo.close();
  replaceBankInfo.close();
}





// this function will display the users account
// the account will have checkings and savings
// it will also have the option to withdraw money
// and deposit money
// we might need the users ID to be sent into
// heere as well
void UsersAccount(string User, string pin){
  int Cbalance = 0;
  int Sbalance = 0;
  string user_info;
  long int user_moneyC;
  long int user_moneyS;
  string choice;
  string choice2;
  string str1, str2, strC, strS;
  //vector<string> Account_info;
  ifstream user_account;
  user_account.open("useraccountfile.txt");
  // we were coding here

  int user_number;
  int test_v;
  
  while(user_account >> user_info){
    if (user_info == User){
      getline(user_account, user_info);
      istringstream istrm(user_info);
      istrm >> str1; // clients checking account amount
      istrm >> str2;// clients savings account amount
    }
    
    if(user_account.eof()){
      break;
    }
  }
  Cbalance = stoi(str1);
  Sbalance = stoi(str2);
  // below here i was gonna hard code the strings
  // for checking and saving but i need to convert them
  // into an integer then display them below
  cout << "Welcome to your account: " + User <<  endl;
  cout << "Here is your Checking Balance: " << Cbalance << endl;// this needs to be updated with the users info
  cout << "Here is your Savings Balance: " << Sbalance << endl;  // this needs to be updated with users info
  cout << "                             " << endl;
  cout << "Would you like to make a deposit? " << endl;
  cin >> choice;
  if (choice == "y"){
    cout << "Should we deposit in your checkings or savings(Chose C or S): ";
    cin >> choice2;
    while(choice2 == "C"){
      cout << "How much money do you want to Deposit in your checking?(Multiples of 5 only): ";
      cin >> user_moneyC;
      Cbalance = Cbalance + user_moneyC;
      break;
    }
    while(choice2 == "S"){
        cout << "How much money do you want to Deposit in your Savings?(Multiples of 5 only): ";
        cin >> user_moneyS;
        Sbalance = Sbalance + user_moneyS;
	break;
    }
    
  }
  
  
  
  storeBankInformation(User, pin , Cbalance, Sbalance);
  user_account.close();
}




///// The function here creates an account and password for the user
void createAccount(string choice){
   string User_name1;
   string password1;
   string digits;
   ofstream createAccount;
  while(choice == "y"){
    createAccount.open("account.txt", fstream::app);// this is so it can just keep adding data to the text file without overwrite
    cout <<"Username: ";
    cin >> User_name1;
    cout << "Password: ";
    cin >> password1;
    cout << "Enter 3 Digit Pin: ";
    cin >> digits;
    createAccount << digits + " " + User_name1 + " " + password1;
    cout << "account created" << endl;
    break;
  }
  createAccount.close();
}




// THis account checks if the username and password are valid
void UpdateInfo(string choice){
  vector<string> Account_info;
  string info;
  string check_name;
  string check_pass;
  string all_u_p_d;
  string three_digit_pin;
  ifstream check_cred("account.txt");
   while (true){
    getline(check_cred,info);
    Account_info.push_back(info.c_str());
    if(check_cred.eof()){
      break;
    }
  }
  while(choice == "y"){
    cout << "Username: ";
    cin >> check_name;
    cout << "Password: ";
    cin >> check_pass;
    cout << "For Security Purposes Please Enter Your Three Digit Pin: ";
    cin >> three_digit_pin;//  the file to what the user typed in
    all_u_p_d = three_digit_pin + " " + check_name + " " + check_pass;
    for (int i = 0; i < sizeof(Account_info); i++){
      if (all_u_p_d  == Account_info[i]){
	cout << "Account Verified" << endl;
	UsersAccount(check_name,three_digit_pin);
	// once the account is verified go ahead and displau users account
	exit(1);
      }
    }
    //counter = counter + 1;
  }
  check_cred.close();
}


//this function will display the menu options to the user
void accountMenu(){
  string User_select;
  string User_select2;
  cout << "High Welcome to Automated Account Service" << endl;
  cout << "Do you have an account with us (y/n)" << endl;
  cin >> User_select;
  if (User_select == "y"){
    UpdateInfo(User_select);
  }
  else{
    cout << "Would you like to make an account with us (y/n)" << endl;
    cin >> User_select2;
    if (User_select2 == "y"){
      createAccount(User_select2); // if the user doesnt have one
                                   // then create one for them
    }
    else if(User_select2 == "n"){
      cout << "Ok have a nice day" << endl; 
                                       
      exit(1);
    }
  }
}







// we have to create two char arrays that will hold
// the username and password and we have to
// send that arrary through the functions
// what if i make the arrays static that way all the
// functions can access them 

int main(){
  accountMenu();

  return 0;
}
