#include <iostream> 
#include <iomanip> 
#include <fstream> 
using namespace std; 

int arr[50]; //Create array to store code for accessing payroll
string names[50]; //Create arrays to store the payroll info for emplyoees 
double hourlywage[50]; 
double hour[50]; 
double check[50]; 
int m = 1;
int i = 1;  

void addemploy(double &wage, int &hours, string *name, double *payments); //Create functions with a passing by reference as well as pointers 
void access(double &wage, int &hours, string *name, double *paymen); 
void display(); 
void compare(int x); //function overload
void compare(string y); 

ofstream obj1("IshreetCompanyPayroll.DAT", ios::app); //create a txt file that can be opened and has the contents saved 

int main() {
    int number; //Define variables to pass by reference 
    int hours; 
    double wage; 
    int pass; 
    string output;
    string name; 
    double payment; 

    while(output != "stop") { //While loop that runs forver unless stoped 
        cout << "Welcome to Ishreet's Company Payroll! Would you like to: " << endl; //Give options for what the employee or manager can access
        cout << "1. Add employes " << endl; 
        cout << "2. Access YOUR payroll " << endl; 
        cout << "3. Display the info for all employees " << endl; 
        cout << "4. Compare Employees " << endl; 
        cout << "(Enter a number from 1-4) " << endl; 
        cin >> number; 

        if(number == 1) {
            addemploy(wage,hours,&name, &payment); //Call on function

        }
        else if(number == 2) {
            access(wage, hours, &name, &payment); //Call on function

        }
        else if(number == 3) { //Call on function
            cout << "To access these files, you have to be the manager " << endl; 
            cout << "Please type in the manager PASSWORD "; 
            cin >> pass; 
            if(pass == 7789) { //THIS IS THE PASSWORD FOR THE MANAGER TO ENTER. code will not work unless this is entered 
                display(); //Call on function

            }
        }
        else if(number == 4) {
            cout << "To compare employees payroll you must be the manager. Please type in the password: "; 
            cin >> pass; 
            if(pass == 7789) {
                string output = "yes"; 
                int number; 
                string someone; 
                
                while(output == "yes") { //This is to compare the employees and see thier rankings 
                    cout << "Choose what you would like to know: " << endl; 
                    cout << "1. Who has the highest paycheck this month " << endl; 
                    cout << "2. Who has the highest hourly wage: " << endl;
                    cout << "3. Who has worked the most hours " << endl; 
                    cout << "Choose a number from 1-3 " << endl; 
                    cin >> number; 
                    compare(number); //Call on function
                    cout << "Would you like to compare more of the employees(type 'yes' to continue) "; 
                    cin >> output; 
            }
            cout << "You can type in a name to see what is their rank in terms of pay (type a number if you would not like to know this) "; 
            cin >> someone; //Types in a person to find out the rank of their pay in compared to other employees
            compare(someone); //Call on function
        }
    }
        cout << "Would you like to find out more info or stop the code? (Type 'stop' to end the code) "; //To stop the code 
        cin >> output; 
}
return 0; 
}
void addemploy(double &wage, int &hours, string *name, double *payment) { //This function is able to add employees 
    
    string answer = "yes"; 

    while(answer == "yes") { //Loop will run over and over again unless you enter anything other than "yes"
        cout << "Enter your full name " << endl; 
        cin.ignore(); 
        getline(cin,*name); 
        names[i] = *name; //recive name and store is the names array 
        obj1 << i << ":" << names[i] << endl; //Write on the ofstream file 

        cout << "Enter your hourly wage "; 
        cin >> wage; 
        hourlywage[i] = wage; //recive wage and store is the hourlywage array 
        obj1 << "Wage: " << hourlywage[i] << endl; //Write on file 

        cout << "Enter the numbers of hours you have worked this month "; 
        cin >> hours; 
        hour[i] = hours; //recive hours and store is the hour array 
        obj1 << "Hours Worked: " << hour[i] << endl; //Write on file 

        *payment = wage*hours; //Calculate the final paycheck for the month 
        check[i] = *payment;  //calculate paycheck and store is the check array 
        obj1 << "Total months Payment: " << check[i] << endl; //Write on the file 
        cout << "Your total pay is " << check[i] << " for this month " << endl; 
    
        int v1 = rand() % 100 + 1; //Choose a random number from 1-100
        arr[m] = v1; //Store the number in the array 
        cout << "If you would like to ever access your code be sure to remember this code: " << v1 << endl; //This code will be given to the employee everytime someone new is added 
        cout << "Be sure to rememeber that you are in position: " << m << endl; //The position of the employee is also needed in order to access other information
        m++; 
        
        cout << "Do you have more workers to add?(Enter 'yes' if so) "; //To stop the code 
        cin >> answer;
        i++; 
    }
}
void access(double &wage, int &hours, string *name, double *payment) { //This is so the employee can access their payroll 
    int pos; 
    int code; 
    ifstream infile; //To be able to read from the file 

    cout << "What position are you in? "; 
    cin >> pos; 
    cout << "Enter your code please: "; 
    cin >> code; 
    if(code == arr[pos]) {
        infile >> names[pos]; //Read from the file 
        cout << names[pos] << endl; 
        infile >> hourlywage[pos]; //Read from the file 
        cout << "Your wage is: $" << hourlywage[pos] << endl; 

        infile >> hour[pos];  //Read from the file 
        cout << "You have worked " << hour[pos] << " hours" << endl; 

        infile >> check[pos]; //Read from the file 
        cout << "You payment for the month is: " << check[pos] << endl; 
    }
}
void display() { //This prints all the employees payrolls 
    cout << ifstream("IshreetCompanyPayroll.DAT").rdbuf(); //print everything that is in the file 
}
void compare(int x) { //this function compares the employees paychecks, hours worked, and hourlywage
    int largest, largest3; //Define varaibles 
    double largest2; 
    string result, result2, result3;  
   
    if(x == 1) {  //If the first option is chosen FROM MAIN...
        largest = check[1];  
        for(int j = 1; j < 50; j++) {
            if(largest < check[j]) { //Finds the person with the largest paycheck and the largest paycheck itself 
                largest = check[j]; 
                result = names[j]; 
            }
        }
        cout << "The largest paycheck this month is " << largest << " and " << result << " has the highest pay " << endl; 
}
else if(x == 2) { //If the second option is chosen FROM MAIN...
    largest2 = hourlywage[1];  
        for(int f = 1; f < 50; f++) { //Finds the person with the largest hourlywage and the largest hourlywage itself 
            if(largest2 < hourlywage[f]) {
                largest2 = hourlywage[f]; 
                result2 = names[f]; 
            }
        }
        cout << "The highest hourly wage is " << largest2 << " and " << result2 << " has the highest hourly wage " << endl; 
}
else if(x == 3) { //If the third option is chosen FROM MAIN...
    largest3 = hour[1];  
        for(int k = 1; k < 50; k++) { //Finds the person with the most hours worked and the number of hours worked itself 
            if(largest3 < hour[k]) {
                largest3 = hour[k]; 
                result3 = names[k]; 
            }
        }
        cout << "The highest hours worked this month is " << largest3 << " and " << result3 << " has worked the most hours this month " << endl; 
}
}
void compare(string y) { //Recives the name by pass by reference 
    int rank = 1; 
    int u; 

    for(u = 1; u < 51; u++) {
        if(names[u] == y) { //First find out with index of the array corresponds to the name of the person  
            break; 
        }
    }
    for(int b = 1; b < 51; b++) {
        if(check[u] < check[b]) { //If the amount that the PERSON gets pain is LESS than other employees...
            rank = rank + 1; //add 1 everytime to track the RANK
        }
    }
    if(rank == 1) { //if rank is zero that means that this person has the highest pay 
        cout << y << " has the highest pay! " << endl; 
    }
    else {
        cout << y << " has the " << rank << " highest pay " << endl; //If not display rank in terms of HIGHEST PAY
    }
}