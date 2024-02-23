#include<iostream>


using namespace std;

void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();

int loopExitSignal = 0;
char ch;
char prompt = '$';

int main(){

    cout << "Calculator" << endl;


    do{

        cout << prompt << " Operation(+,-,*,/) : ";
        cin >> ch;

        if(ch=='x'){
            break;
        }
        
        switch (ch)
        {
        case '+':
            performAddition();
            break;
        case '-':
            performSubtraction();
            break;
        case '*':
            performMultiplication();
            break;
        case '/':
            performDivision();
            break;
        case 'x':
            loopExitSignal = 1;
        default:
            cout << prompt << " Please enter correct symbol to perform operations!" << endl;
            cout << prompt << " Enter 'x' to exit the loop!" << endl;
            
            break;
        }
    }while(!loopExitSignal);


    return 0;
}

void performAddition(){
    float x,y;

    cout << prompt << " Enter two numbers : ";
    cin >> x >> y;

    cout << prompt << " " << "Sum of the two numbers is " << x+y << endl;
}

void performSubtraction(){
    float x,y;

    cout << prompt << " Enter two numbers : ";
    cin >> x >> y;

    cout << prompt << " " << "Difference of the two numbers is " << x-y << endl;

}

void performMultiplication(){

    float x,y;

    cout << prompt << " Enter two numbers : ";
    cin >> x >> y;

    cout << prompt << " " << "Product of the two numbers is " << x*y << endl;
}

void performDivision(){

    int x,y;

    cout << prompt << " Enter two numbers : ";
    cin >> x >> y;

    cout << prompt << " " << "Quotient of the two numbers is " << (float)(x/y) << endl;
}