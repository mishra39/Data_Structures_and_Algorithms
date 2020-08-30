#include <iostream>

using namespace std;

class Polynomial {
public:

    int *degCoeff; // Name of your array (Don't change this)
    int capacity;  // Size of the array     

	// Default Constructor
	Polynomial()
	{
		capacity = 10;
		degCoeff = new int[10];
		// Initialize array to zero
		for (int i = 0; i < capacity; i++)
		{
			degCoeff[i] = 0;
		}

	}

	// Copy Constructor
	Polynomial(Polynomial const  &P1)
	{
		this -> degCoeff = new int [P1.capacity];
		this -> capacity =  P1.capacity;

		// Deep Copy elements to new array
		for (int i = 0; i < capacity; i++)
		{
			this -> degCoeff[i] = P1.degCoeff[i];
		}
	}

	void setCoefficient(int degree, int coeff)
	{
		if (degree < capacity)
		{
			this -> degCoeff[degree] = coeff;
		}

		else
		{	
			int *newdegCoeff = new int[2*degree]{0};
			for (int i = 0; i < capacity; i++)
			{
				newdegCoeff[i] = degCoeff[i]; 
			}

			delete [] degCoeff;
			newdegCoeff[degree] = coeff;
			degCoeff = newdegCoeff;
            capacity=2*degree;
		}
	}

	void print() const
	{
		for (int i = 0; i < capacity; i++)
		{
			if (degCoeff[i]!=0)
			{
				cout << degCoeff[i] << "x" << i << " ";
			}
		}
	}


   Polynomial(int capacity)
    {
        degCoeff = new int[capacity];
        for(int i=0 ; i< capacity;i++)
        degCoeff[i] = 0;
        this -> capacity = capacity;
    }

	Polynomial operator+(Polynomial const &P1)
	{
		Polynomial newP(max(P1.capacity, this-> capacity));
		for (int i = 0; i < min(P1.capacity, capacity); i++)
		{
				newP.degCoeff[i] = P1.degCoeff[i] + this -> degCoeff[i];
		}

		for (int i = min(P1.capacity, this-> capacity); i < newP.capacity; i++)
		{    if(P1.capacity>capacity){
				newP.degCoeff[i] = P1.degCoeff[i];
    		}
         	else{
                newP.degCoeff[i] = degCoeff[i];
    		
            }
			
		}
		return newP;
	}

	Polynomial operator-(Polynomial const &P1)
	{
		Polynomial newP(max(P1.capacity, this-> capacity));
		for (int i = 0; i < min(P1.capacity, capacity); i++)
		{
				newP.degCoeff[i] = this -> degCoeff[i] - P1.degCoeff[i];
		}

		for (int i = min(P1.capacity, this-> capacity); i < newP.capacity; i++)
		{    if(P1.capacity>capacity){
				newP.degCoeff[i] = -P1.degCoeff[i];
    		}
         	else{
                newP.degCoeff[i] = degCoeff[i];
    		
            }
			
		}
		return newP;
	}

	Polynomial operator*(Polynomial const &P1)
	{
		Polynomial newP(P1.capacity*capacity);
		for (int i = 0; i < (capacity); i++)
		{
			for (int j = 0; j < P1.capacity; j++)
			{
				int prod = this->degCoeff[i]*P1.degCoeff[j];
				newP.degCoeff[i+j] += prod; 
			}
		}
        
		/*for (int i = min(P1.capacity, this-> capacity); i < newP.capacity; i++)
		{
			for (int j = 0; j < this->capacity; j++)
			{
				int prod = this->degCoeff[i]*P1.degCoeff[j];
				newP.degCoeff[i+j] += prod; 
			}
		}*/
		return newP;
	}

	void operator=(Polynomial const &P1)
	{
		this -> degCoeff = new int [P1.capacity];
		this -> capacity =  P1.capacity;

		// Deep Copy elements to new array
		for (int i = 0; i < capacity; i++)
		{
			this -> degCoeff[i] = P1.degCoeff[i];
		}

	}
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    first.print();

    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    second.print();


    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break; 
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
    }
    
    return 0;
}


/*tumhe newP ki capacity ko max(p1.capa,cap) leni hai

then run for loop from i=0;i<min(cap,P1,cap);i++ 
newP.degCoeff[i] = P1.degCoeff[i] + this -> degCoeff[i];

and another loop from i=min(cap,P1.cap);i<max(cap,P1.cap);i++

you there?

similarly in operator-,*/