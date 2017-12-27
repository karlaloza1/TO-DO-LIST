

/****************************************************************
 ** Name: Karla Lozada
 ** Date: 03/11/2017
 ** Class: CISP 400
 ** Homework: TO DO LIST
 ****************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

/*****************************************************************
 ** This structure is going to hold the information
 ** of the list, is going to hold the list, number of the activity,
 ** user id, and also a condition that would indicate if activity
 ** is completed
 *****************************************************************/

struct insert_activity
{
    int user_id; //id number of the user of the list
    int index;  //number of the activity
    char activity_todo[30]; // list activity
    int completed = 0; // to prove it the ctivity is completed
};

/*****************************************************************
 **
 ** This class is going to hold the data of the entire list
 ** and also the functions that the program need in order to work
 ** also is going to hold the count of each of the activities in
 ** the TODO LIST
 *****************************************************************/

class TODO_info
{
public:
    int product_num;                    // quantity of each activity
    insert_activity base_storage[100];      // hold the information
    
    TODO_info()
    {
        product_num = 0;  //quntity of the activities in the list
    }
    
    
    
    void ins_activity( int id_num, int num, char act_todo[]); // in this function we are going to insert the activity of the list
    
    void erase_activity(int id_num, char act_todo[]); // this function is going to erase one of the activities already inserted
    
    insert_activity *search_activity(int id_num, char act_todo[]); // we are going to search for the activity in the TODO LIST
    
    void activity_update( int id_num, int total,  char act_todo[]); // indicate if the activity is completed in the TODO LIST
    
    void print_activities( int id_num); // this function is going to print all of the activities and show if they are completed or not
};


/*************************************************************************
 ** In this function we are going to insert the activities for the list
 ** in order to do that we need to insert id number of the user, also we need
 ** to inser the number of activity and the activity
 ************************************************************************/

void TODO_info::ins_activity(int id_num, int num,  char act_todo[])
{
    base_storage[product_num].user_id = id_num; //id number of user
    base_storage[product_num].index=num;  //number of the activity
    strcpy(base_storage[product_num].activity_todo,act_todo); //activity
    
    cout << "\n ACTIVITY INSERTED TO THE TO DO LIST SUCESSFULLY  !!!" << endl << endl;
    product_num++; //add to the activities of the list
}

/********************************************************************
 **
 ** In this function we are going to erase or delete  one activities
 ** of the from the TO DO LIST  in order to delete the activity
 ** from the list we need to enter the name of the list
 *******************************************************************/


void TODO_info::erase_activity(int id_num, char act_todo[])
{
    int x;
    for (x=0; x<product_num; x++)
    {
        if ((strcmp(act_todo, base_storage[x].activity_todo)==0) && (base_storage[x].user_id== id_num)) // here if the activity and user number is correct then activity is deleted from the storage of information
            
        {
            base_storage[x].index--; //less the activity from the list
            cout << "\n*-*-* ACTIVITY DELETED FROM THE TO DO LIST SUCESSFULLY *-*-*"<< endl << endl;
            product_num--; //less product_num which is the variable that hold all the actvities from the list
            return;
        } // we are going to erase the activity from the TODO LIST
    }
    
    cout << "\no-o-o SORRY ACTIVITY NOT FOUNDED, TRY AGAIN o-o-o " << endl << endl;
}

/*****************************************************************
 **
 ** In this function we re going to search the activity from the
 ** list in order to see if the activity is already done
 **
 *****************************************************************/

insert_activity * TODO_info::search_activity(int id_num, char act_todo[]) //here we are going to search for only one of the activities from the list
{
    int x;
    
    for (x=0; x<product_num; x++)
    {
        if ((strcmp(act_todo, base_storage[x].activity_todo)==0)&& (base_storage[x].user_id==id_num))
            return &base_storage[x]; //again if the activity name and user id are true then we display the the activity search fot
    }
    return NULL;
}

/*****************************************************************
 **
 ** In this function we are going to mark which activity is alredy
 ** completed and also the ones that are not completed
 **
 *****************************************************************/

void TODO_info::activity_update(  int id_num ,int total, char product_name[]) // in here we ctually mark which activity from the list is completed
{
    insert_activity *product =search_activity(id_num, product_name);
    if (product==NULL)
    {
        cout << "\n SORRY ACTIVITY NOT FOUND, PLEASE TRY AGAIN !!! \n";
        return;
    }
    if (base_storage[total - 1].completed == 0) //prove the condition in order to show is completed
    {
        base_storage[total - 1].completed = 1; //we need to put (-1) because the computer start from 1
        
        cout << "\nThe activity in the TODO LIST is completed " << endl<< endl;
    }
    else
        cout << "\nActivity in the TODO LIST is already completed " << endl << endl;
    
    return;
}

/*****************************************************************
 **
 ** In this function we are going to actually print all of the
 ** activities in the TODO LIST and also are going to show
 ** if the activity is already completed or not
 **
 *****************************************************************/

void TODO_info::print_activities (int id_num) //really like this function because it took me time to do it :D, this function is going to print all of the activities and put completed in the ones that are alredy done and nothing on the ones that are not completed
{
    for (int x = 0; x < product_num; x++)
    {
        if (base_storage[x].user_id == id_num) // if the id num is the same then is going to print the index which is number activity and the activity name and then if it is completed or not
        {
            cout <<endl << base_storage[x].index << ". " << base_storage[x].activity_todo;
            if (base_storage[x].completed == 1)
                cout << " --- COMPLETED";  // here we have the condition that is going to print if the activity is completed
            cout << endl;
        }
    }
    return;
}


int main()

{
    
    TODO_info TODO;
    char activity_na[30]; // the activity of the TODO LIST
    int activity_num = 0; // the activity number
    int id_nu =0; //id of the user
    
    int choice;
    
    
    /********************************************************************************
     ** In here we have the options for the menu in a do while loop and the switch case
     ** in order of the eleccion the user choose the program is going to execute
     **
     ********************************************************************************/
    
    
    do //basicaly this is the menu that the user would have in order to do not be confused
    {
        cout << "\n*-*-*-*-*- TO DO LIST *-*-*-*-*" << endl<< endl;
        cout << "ooo - Choose one Option - ooo"<< endl<< endl;
        cout <<"Press 1 -ooo-  Add activity to the TO DO LIST" << endl;
        cout <<"Press 2 -ooo-  Delete any activity from the TO DO LIST"<< endl;
        cout <<"Press 3 -ooo-  Display an activity from the TO DO LIST "<< endl;
        cout <<"Press 4 -ooo-  Mark activity as completed in the TO DO LIST " << endl;
        cout <<"Press 5 -ooo-  Show all the activities stored in the TODO LIST" << endl;
        cout <<"Press 6 -ooo-  Exit the program "<< endl<< endl;
        cout <<"Please enter one of the options: ";
        cin >> choice;
        
        switch(choice)
        {
                
                /*****************************************************************
                 **
                 ** we are going to use a swith case to make work the menu option
                 ** this first case is going to make you insert the info about the
                 ** activity you want to add to the TO DO LIST
                 *****************************************************************/
                
            case 1 :
                cout <<"ID number user: "; //insert user id
                cin >>id_nu;              //insert number of activity
                cout << "Activity #: ";
                cin >> activity_num;
                
                cin.getline(activity_na,80);
                cout << "\n Insert activity for the TODO LIST: ";  //insert actual activity
                cin.getline(activity_na,80);
                TODO.ins_activity(id_nu, activity_num, activity_na);
                break;
                
                /*****************************************************************
                 **  This case function is going to erase one of the activities
                 ** from the TO DO LIST
                 **
                 *****************************************************************/
                
            case 2:
                cout <<"ID number user: ";//insert user id
                cin >>id_nu;
                cin.getline(activity_na,80); //activity
                cout << "\n Insert activity to the TODO LIST : ";
                cin.getline(activity_na,80);
                
                TODO.erase_activity(id_nu, activity_na); //then cll the function were the activity is going to be deleted
                break;
                
                /*****************************************************************
                 **
                 ** In this case all the informtion of one activity(only one) of  the
                 ** activities from the TO DO LIST is going to be displayed in the screen
                 **
                 *****************************************************************/
                
            case 3:
                cout <<"ID number user: "; //insert id number
                cin >>id_nu;
                cin.getline(activity_na, 80);
                cout << "\n Insert activity to the TODO LIST: ";
                cin.getline(activity_na,80); //insert the activity
                
                insert_activity *test; // a test which is going to make one of the activity appear
                test = TODO.search_activity(id_nu, activity_na);
                
                if (test != NULL)
                {
                    cout << "\n*-*-*-* Activity from TODO LIST *-*-*-*-*"<< endl;
                    cout << "ooooooo - Activity Displyed   - oooooo"<< endl;
                    cout << "\n ID user number: ";
                    cout << test-> user_id;
                    cout <<"\n Number of activity is: ";
                    cout << test->index;
                    cout << " \n Activity is : ";
                    cout << test->activity_todo;
                    //ewde
                    
                    cout << endl;
                    cout << endl;
                }
                else
                    
                    cout << "\n o-o-o SORRY ACTIVITY WAS UNABLE TO BE  FOUND! Please try again o-o-o" << endl;
                
                break;
                
                /************************************************************************
                 **
                 ** In this case option we are going to actually mark the activity as
                 ** completed in the list
                 **
                 **************************************************************************/
                
            case 4: cout << "\n*-*-*-*-* Complete Activity  *-*-*-*-* "<< endl;
                cout <<"\nID user number ";
                cin >>id_nu;
                cout << "\nInsert activity number: ";
                cin >> activity_num;
                cin.getline(activity_na,80);
                cout << "\nInsert activity to the TODO LIST: ";
                cin.getline(activity_na,80);
                
                TODO.activity_update(id_nu, activity_num, activity_na); //calling the function
                break;
                
                /************************************************************************
                 **
                 ** In this switch case we are going to print all of the activities
                 ** that the user already input into the program and also we are going to
                 ** show if the activity is completed or not
                 **
                 **************************************************************************/
                
            case 5: cout << "\n*-*-*-*-* List Activities *-*-*-*-* ";
                cout << endl;
                cout <<"\nID number "; //insert id numer
                cin >>id_nu;
                TODO.print_activities(id_nu); // call the actual function which is going to print all activities in the TODO LIST
                break;
                
        }
    }
    
    while (choice != 6);
    
    return 0;
}
