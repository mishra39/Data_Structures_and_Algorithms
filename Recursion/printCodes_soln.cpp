char options[]={'`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void printAllPossibleCodes(string input, string outputSoFar="")
{
if(input.length()==0)                                                   //Base Case          
{
    cout<<outputSoFar<<endl;
    return;
}

int index1=stoi(input.substr(0,1));                                     //index1 will surely be a single digit int

printAllPossibleCodes(input.substr(1),outputSoFar+options[index1]);     //Recursion call 1

if(input[1]!='\0')
{
    int index2=stoi(input.substr(0,2));
    
    if(index2<27)                                                       //Only if this index2 < 27 we can have a character corresp.to it
     printAllPossibleCodes(input.substr(2),outputSoFar+options[index2]);//Recursion Call 2 where outputSoFar contains character corresp to first two digits
}

}