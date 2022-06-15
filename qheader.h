#include <bits/stdc++.h>

using namespace std;


//Calculates log(base)(x) rounded up
int log (int base, int x);

//Prints a vector of ints as a number
void printbitstring(vector <int> v);

//Class to hold Complex number
//a -> real part
//b -> imaginary part

class Complex
{
    public:
    double a;
    double b;
    Complex();
    Complex(double real);
    Complex(double real, double imaginary);

    //Define = Operator
    void operator=(const Complex &c);
    //Define * operator
    Complex operator*(const Complex &c);
    //Define + operator
    Complex operator+(const Complex &c);
    //Calculate abs val
    double abs();
    //Calculate the abs val squared
    double abs_squared();

    //Print Complex Number
    void print();
};

//creates a Complex object with the given parameters
Complex to_Complex(double real);
Complex to_Complex(double real, double imaginary);

//Calculates the tensor product of two vectors
vector <Complex> tensor(vector <Complex> a, vector <Complex> b);

//Calculates the tensor product of two matrices
vector <vector <Complex>> tensor(vector <vector <Complex>> a, vector <vector <Complex>> b);

//Multiply a matrix and a vector
vector <Complex> multiply(vector <vector <Complex>> A, vector <Complex> x);

//Scale a vector by a Complex number
vector <Complex> scale( Complex a, vector <Complex> v);
// Scale a matrix by a Complex number, a*A
vector<vector<Complex>> scale(Complex a, vector<vector<Complex>> A);
// Scale a matrix by a real number, a*A
vector<vector<Complex>> scale(double a, vector<vector<Complex>> A);

// Turn U gate into CU
vector<vector<Complex>> CU(vector<vector<Complex>> U);

// Creates the nxn identity matrix
vector<vector<Complex>> I_gate(int n);
// Creates the matrix for the H gate
vector<vector<Complex>> H_gate();

// Creates the matrix for the Pauli-X gate (same as NOT)
vector<vector<Complex>> X_gate();

// Creates the matrix for the NOT gate (same as Pauli-X)
vector<vector<Complex>> NOT_gate();

// Creates the matrix for the Pauli-Y gate
vector<vector<Complex>> Y_gate();

// Creates the matrix for the Pauli-Z gate
vector<vector<Complex>> Z_gate();

// Creates the matrix for the sqrtNOT gate
vector<vector<Complex>> sqrtNOT_gate();

// Creates the matrix for the phase shift gate
vector<vector<Complex>> R_gate(double phi);

// Creates the matrix for the CNOT gate
vector<vector<Complex>> CNOT_gate();

// Creates the matrix for the CX gate
vector<vector<Complex>> CX_gate();

// Creates the matrix for the CY gate
vector<vector<Complex>> CY_gate();

// Creates the matrix for the CZ gate
vector<vector<Complex>> CZ_gate();
// Calculates base^exp
int power(int base, int exp);

class Qstate
{
public:
	vector<Complex> state;
	int dimension;
	int bitlength;
public:

	// Defaults to |0>
	Qstate();

	// Initializes to |init>
	Qstate(int init);

	// Initializes to a custom bitstring
	Qstate(vector<int> init);

	// Initializes to a custom state vector
	Qstate(vector<Complex> init);

	// Return dimension of state vector
	int get_dimension();

	// Return bitlength
	int get_bitlength();

	// Return state vector
	vector<Complex> get_state();

	// Copy constructor
	//Qstate(Qstate init);

	// ~Qstate();

	// Define the = operator
	void operator=(const Qstate& c);

	// Define the * operator (tensor product)
	Qstate operator*(const Qstate& c);

	// Measure the quantum state
	vector<int> measure();

	// Prints the state vector and dimension
	void print();
};

// Calculates the tensor product of two Qstate objects
Qstate tensor(Qstate a, Qstate b);

// Apply a custom gate at the location bit, indexing from 0 (EX. type 1 to apply from 2nd bit, or 0 for 1st bit)
// gate is formatted as a vector of column vectors
Qstate apply_gate(vector< vector<Complex> > gate, Qstate q, int location);

// Apply a custom gate
// gate is formatted as a vector of column vectors
Qstate apply_gate(vector< vector<Complex> > gate, Qstate q);

// Apply Hadamard gate
Qstate H(Qstate q);

// Apply Hadamard gate
Qstate H(Qstate q, int location);

// Apply Pauli-X gate (same as NOT)
Qstate X(Qstate q);

// Apply Pauli-X gate (same as NOT)
Qstate X(Qstate q, int location);

// Apply NOT gate (same as Pauli-X)
Qstate NOT(Qstate q);

// Apply NOT gate (same as Pauli-X)
Qstate NOT(Qstate q, int location);

// Apply Pauli-Y gate
Qstate Y(Qstate q);

// Apply Pauli-Y gate
Qstate Y(Qstate q, int location);

// Apply Pauli-Z gate
Qstate Z(Qstate q);

// Apply Pauli-Z gate
Qstate Z(Qstate q, int location);

// Apply square root of NOT gate
Qstate sqrtNOT(Qstate q);

// Apply square root of NOT gate
Qstate sqrtNOT(Qstate q, int location);

// Apply phase shift gate by phi radians
Qstate R(double phi, Qstate q);

// Apply phase shift gate by phi radians
Qstate R(double phi, Qstate q, int location);

// Apply CNOT gate (same as cX)
Qstate CNOT(Qstate q);

// Apply CNOT gate (same as cX)
Qstate CNOT(Qstate q, int location);

// Apply cX gate (same as CNOT)
Qstate CX(Qstate q);

// Apply cX gate (same as CNOT)
Qstate CX(Qstate q, int location);

// Apply cY gate
Qstate CY(Qstate q);

// Apply cY gate
Qstate CY(Qstate q, int location);

// Apply cZ gate
Qstate CZ(Qstate q);

// Apply cZ gate
Qstate CZ(Qstate q, int location);
