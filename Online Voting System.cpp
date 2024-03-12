/*
    Online Voting System 
        54 12208021 Anish Dutta
        55 12208152 Ullayam Sai Yagnasree
        56 12208298 Jayanth Vegesna
        57 12209619 Samarth Upadhyay
*/

/*---[ Declaration of Header Files ]----------------*/
#include<iostream>
#include<string>
using namespace std;

/*---[ Variable Declaration ]-----------------------*/

/*---[ Class Declaration ]--------------------------*/
class voter
{
    static int count;
    int voter_id, age;
    string Aadhar;
    string name, area;
    
    const int current_year = 2023, current_month = 11, current_day = 3;
    int voter_year, voter_month, voter_day;

    public:

    voter(string name, string Aadhar, string area,int voter_year=0, int voter_month=0, int voter_day=0)
    {
        ++count;
        this->name = name;
        this->Aadhar=Aadhar;
        this->area=area;
        this->voter_year=voter_year;
        this->voter_month=voter_month;
        this->voter_day=voter_day;
        voter_id=000+get_id();
        Age();
    }
    
    void Age()
    {
        int age1 = current_year - voter_year;
        if (voter_month > current_month)
        {
            age1--;
        }
        else if (voter_month==current_month && voter_day > current_day)
        {
            age1--;
        }
        age=age1;
    }
    static int get_id() { return count;}
};

int voter::count = 0;

/*---[ Main Program ]-------------------------------*/
int main()
{
    int choice;
    string name, area, Aadhar, Username, Password, username_check, password_check;
    int prince_count=0, nirmaljeet_count=0, mugdha_count=0, ifthakar_count=0, anish_count=0, yagna_count=0, jayanth_count=0, samarath_count=0;
    int DOB;    
    while(1)
    {
        main_menu:
        system("cls");
        main_menu2:
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"-------- Welcome to the Voting Managment System --------"<<endl;
        cout<<"------------ Todays Date: November 3rd 2023 ------------"<<endl;
        cout<<"----------------------- Main Menu ----------------------"<<endl;
        cout<<"1. Registration"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Results"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Please enter what you wish to do: "<<endl;
        cin>>choice;
        validation_1:
        if(0<choice && choice<7) {system("cls");}
        switch(choice)
        {
/*---[ Registration ]-------------------------------*/
            case 1:
                {
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"------------------- Registration Menu ------------------"<<endl;
                cout<<"Enter the following details to generate login username and password"<<endl;
                cout<<"Name: ";
                cin>>name;
                cout<<"Aadhar Number: "<<endl;
                cin>>Aadhar;
                cout<<"DOB (dd/mm/year with no spaces): "<<endl;
                cin>>DOB;
                cout<<"Area (North/South/East/West): "<<endl;
                cin>>area;
                cout<<"The generated Username and Password is: "<<endl;
                string firstFourLetters = name.substr(0, 4);
                string firstFourNumbers = Aadhar.substr(0, 4);
                Username = firstFourLetters.append(firstFourNumbers);
                Password = to_string(DOB);
                cout<<"Username: "<<Username<<endl;
                cout<<"Password: "<<Password<<endl;
                cout<<"Registration is Complete! Please procced to Login"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"Enter 0 to return main menu"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cin>>choice;
                if (choice==0) {goto main_menu;}
                break;
                }
/*---[ Login ]--------------------------------------*/
            case 2:
                {
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"------------------------- Login ------------------------"<<endl;
                cout<<"Enter the following details provided during registration:"<<endl;
                cout<<"Username: "<<endl;
                cin>>username_check;
                cout<<"Password: "<<endl;
                cin>>password_check;
                if(Username == username_check && Password == password_check)
                {
                selection_menu:
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"-------------------- Selection Menu --------------------"<<endl;
                cout<<"1. Update Profile"<<endl;
                cout<<"2. Choose Positions for Voting"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"Enter 0 to return main menu"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cin>>choice;
                validation_2:
                if (choice==0) {goto main_menu;}
                if(0<choice && choice<2) {system("cls");}
                switch(choice)
                {
/*---[ Profile Updation ]---------------------------*/
                    case 1:
                        system("cls");
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"----------------- Profile Updation Menu ----------------"<<endl;
                        cout<<"1. Change password"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"Enter 0 to go back"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cin>>choice;
                        validation_4:
                        if (choice==0) {goto selection_menu;}
                        if (choice==1)
                        {
                            cout<<"Please enter new password"<<endl;
                            cin>>Password;
                            cout<<"Your password has been updated, Returning to main menu"<<endl;
                            goto main_menu2;
                        }
                        else 
                        {
                            cout<<"--------------------------------------------------------"<<endl;
                            cout<<"Please enter a valid option: "<<endl;
                            cin>>choice;
                            goto validation_4;
                        }
                    break;
/*---[ Position Selection]--------------------------*/
                    case 2:
                        pselection_menu:
                        system("cls");
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"---------------- Position Selection Menu ---------------"<<endl;
                        cout<<"1. President"<<endl;
                        cout<<"2. Vice President"<<endl;
                        cout<<"3. General Secretary"<<endl;
                        cout<<"4. Treasuer"<<endl;
                        cout<<"5. Please enter 5 to finish voting"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"Enter 0 to go back"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cin>>choice;
                        validation_3:
                        if (choice==0) {goto selection_menu;}
/*---[ Vote ]---------------------------------------*/
                        if(0<choice && choice<5) {system("cls");}
                        switch(choice)
                        {
                            case 1:
                                cout<<"Please select your vote for president"<<endl;
                                cout<<"1. Prince Varma"<<endl;
                                cout<<"2. Nirmaljeet Kaur"<<endl;
                                cin>>choice;
                                if (choice==1)
                                    prince_count++;
                                else if (choice==2)
                                    nirmaljeet_count++;
                                else
                                {
                                    cout<<"No option selected, returning to position selection menu"<<endl;
                                }
                                goto pselection_menu;
                                break;
                            case 2:
                                cout<<"Please select your vote for vice president"<<endl;
                                cout<<"1. Mugdha"<<endl;
                                cout<<"2. Ifthkar"<<endl;
                                cin>>choice;
                                if (choice==1)
                                    mugdha_count++;
                                else if (choice==2)
                                    ifthakar_count++;
                                else
                                {
                                    cout<<"No option selected, returning to position selection menu"<<endl;
                                }
                                goto pselection_menu;
                                break;
                            case 3:
                                cout<<"Please select your vote for general secretary"<<endl;
                                cout<<"1. Yagna"<<endl;
                                cout<<"2. Anish"<<endl;
                                cin>>choice;
                                if (choice==1)
                                    yagna_count++;
                                else if (choice==2)
                                    anish_count++;
                                else
                                {
                                    cout<<"No option selected, returning to position selection menu"<<endl;
                                }
                                goto pselection_menu;
                                break;
                            case 4:
                                cout<<"Please select your vote for Treasuer"<<endl;
                                cout<<"1. Jayanth"<<endl;
                                cout<<"2. Samrath"<<endl;
                                cin>>choice;
                                if (choice==1)
                                    jayanth_count++;
                                else if (choice==2)
                                    samarath_count++;
                                else
                                {
                                    cout<<"No option selected, returning to position selection menu"<<endl;
                                }
                                goto pselection_menu;
                                break;
                            case 5:
                                cout<<"Your vote has been cast, please check results to see vote count"<<endl;
                                goto main_menu2;
                            default:
                                cout<<"--------------------------------------------------------"<<endl;
                                cout<<"Please enter a valid option: "<<endl;
                                cin>>choice;
                                goto validation_3;
                        }
                        break;
                    default:
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"Please enter a valid option: "<<endl;
                        cin>>choice;
                        goto validation_2;
                }
                break;
                }
                else 
                {
                    cout<<"--------------------------------------------------------"<<endl; 
                    cout<<"The username or password entered is incorrect"<<endl;
                    cout<<"Returning to main menu"<<endl;
                    cout<<"--------------------------------------------------------"<<endl;
                    goto main_menu2;
                }  
                break;
                }
            case 3:
                {
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"---------------------- Result Menu ---------------------"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"The current count of the votes for each position are as folows:"<<endl;
                cout<<"President:"<<endl;
                cout<<"     Prince Varma:    "<<prince_count<<endl;
                cout<<"     Nirmaljeet Kaur: "<<nirmaljeet_count<<endl;
                cout<<"Vice President:"<<endl;
                cout<<"     Mugdha:          "<<mugdha_count<<endl;
                cout<<"     Ifthkar:         "<<ifthakar_count<<endl;
                cout<<"General Secretary:"<<endl;
                cout<<"     Yagna:           "<<yagna_count<<endl;;
                cout<<"     Anish:           "<<anish_count<<endl;
                cout<<"Treasuer:"<<endl;
                cout<<"     Jayanth:         "<<jayanth_count<<endl;
                cout<<"     Samarath:        "<<samarath_count<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"Enter 0 to return main menu"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                cin>>choice;
                if (choice==0) {goto main_menu;}
                break;
                }
/*---[ Exit ]---------------------------------------*/
            case 4:
                exit(0);
                break;
            default:
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"Please enter a valid option: "<<endl;
                cin>>choice;
                goto validation_1;
        }
    }
}