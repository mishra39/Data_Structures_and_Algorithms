#include <iostream>
#include <string.h>
using namespace std;

void starHelper(char str[], int start) 
{ 
  
    // Base condition 
    // if the string is empty 
    // or of length one 
    if (str[start] == '\0' || str[start] == '\0') { 
        return; 
    } 
  
    // Getting the answer from 
    // recursion for the smaller 
    // problem 
    starHelper(str, start + 1); 
  
    // Small calculation part 
    // if the first character is 'p' 
    // and the first character of the part 
    // passed to recursion is 'i' then replace 
    // "pi" with "3.14" 
    if (str[start] == str[start + 1]) { 
  
        // Shifting the characeters to 
        // right side to put 3.14 in 
        // the character array 
        for (int i = strlen(str); i >= start + 1; i--) { 
            str[i + 1] = str[i]; 
        }
        
        str[start + 1] = '*'; 
    } 
} 
  
// Function to replace pi with 3.14 
void pairStar(char str[]) 
{ 
    starHelper(str, 0); 
} 
  
int main() 
{ 
    char input[100];
    cin.getline(input,100);
    pairStar(input);
    cout << input << endl;
}