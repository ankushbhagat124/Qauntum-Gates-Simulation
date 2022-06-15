#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "qheader.h"
// using namespace std;

int log(int base, int x)
{
	int temp=base;
	int count=1;
	while(temp<x)
	{
		temp=temp*base;
		count++;
	}
	return count;
}

void printbitstring(vector<int> v)
{
	for (int i=0;i<v.size();i++)
		cout<<v[i];
}

Complex::Complex()
{
	a=0.0;
	b=0.0;
}
Complex::Complex(double real)
{
	a=real;
	b=0;
}
Complex::Complex(double real, double imaginary)
{
	a=real;
	b=imaginary;
}

//Define = operator
void Complex::operator=(const Complex& c)
{
	this->a = c.a;
	this->b = c.b;
	// return c;
}

//Define * operator
Complex Complex::operator*(const Complex& c)
{
	Complex ans;
	ans.a = this->a * c.a - this->b * c.b;
	ans.b = this->a * c.b + this->b * c.a;
	return ans;
}

// Define the + operator
Complex Complex::operator+(const Complex& c)
{
	Complex ans;
	ans.a = this->a + c.a;
	ans.b = this->b + c.b;
	return ans;
}

// Calculates the absolute value
double Complex::abs()
{
	return sqrt(a*a+b*b);
}

// Calculates the absolute value squared
double Complex::abs_squared()
{
	return a*a+b*b;
}

// Prints the Complex number
void Complex::print()
{
	if(b==0.0)
	{
		cout<<a;
	}
	else if (a==0.0)
	{
		cout<<b<<"i";
	}
	else
	{
		cout<<a<<"+"<<b<<"i";
	}
}

// Creates a Complex object with the given parameters
Complex to_Complex(double real)
{
	Complex c(real);
	return c;
}

// Creates a Complex object with the given parameters
Complex to_Complex(double real, double imaginary)
{
	Complex c(real, imaginary);
	return c;
}

// Calculates the tensor product of two vectors
vector<Complex> tensor(vector<Complex> a, vector<Complex> b)
{
	vector<Complex> out;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			out.push_back(a[i]*b[j]);
		}
	}
	return out;
}

// Calculates the tensor product of two matrices
vector<vector<Complex>> tensor(vector<vector<Complex>> a, vector<vector<Complex>> b)
{
	vector<vector<Complex>> out;
	vector<Complex> temp;

	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			for(int k=0;k<a.size();k++)
			{
				for (int l=0;l<b.size();l++)
				{
					temp.push_back(a[i][k]*b[j][l]);
				}
			}
			out.push_back(temp);
			temp.clear();
		}
	}
	return out;
}
vector<Complex> multiply(vector< vector<Complex> > A, vector<Complex> x)
{
	vector<Complex> out;
	for (int i=0;i<A[0].size();i++)
	{
		Complex temp=to_Complex(0.0);
		for (int j=0;j<A.size();j++)
		{
			Complex temp2=A[j][i]*x[j];
			Complex temp3=temp+temp2;
			temp=temp3;
		}
		out.push_back(temp);
	}
	return out;
}
// Scale a vector by a Complex number, a*v
vector<Complex> scale(Complex a, vector<Complex> v)
{
	vector<Complex> out;
	for (int i=0;i<v.size();i++)
	{
		out.push_back(v[i]*a);
	}
	return out;
}

//Scale a matrix by a Complex number
vector<vector<Complex>> scale(Complex a, vector<vector<Complex>> A)
{
	vector<vector<Complex>> out;
	vector<Complex> temp;
	for (int i=0;i<A.size();i++)
	{
		for (int j=0;j<A.size();j++)
		{
			temp.push_back(A[i][j]*a);
		}
		out.push_back(temp);
		temp.clear();
	}
	return out;
}

//Scale a matrix by a real number
vector<vector<Complex>> scale(double a, vector<vector<Complex>> A)
{
	vector<vector<Complex>> out;
	vector<Complex> temp;
	for (int i=0;i<A.size();i++)
	{
		for (int j=0;j<A.size();j++)
		{
			temp.push_back(A[i][j]*to_Complex(a));
		}
		out.push_back(temp);
		temp.clear();
	}
	return out;
}
// Turn U gate into CU
vector<vector<Complex>> CU(vector<vector<Complex>> U)
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;

	for (int i=0;i<U.size();i++)
	{
		for (int j=0;j<2*U.size();j++)
		{
			if (i==j)
			{
				temp.push_back(to_Complex(1.0));
			}
			else
			{
				temp.push_back(to_Complex(0.0));
			}
		}
		gate.push_back(temp);
		temp.clear();
	}

	for (int i=0;i<U.size();i++)
	{
		for (int j=0;j<U.size();j++)
		{
			temp.push_back(to_Complex(0.0));
		}
		for (int j=0;j<U.size();j++)
		{
			temp.push_back(U[i][j]);
		}
		gate.push_back(temp);
		temp.clear();
	}

	return gate;
}
// Creates the nxn identity matrix
vector<vector<Complex>> I_gate(int n)
{
	vector<vector<Complex>> mat;
	vector<Complex> temp;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if(i==j)
			{
				temp.push_back(to_Complex(1.0));
			}
			else
			{
				temp.push_back(to_Complex(0.0));
			}
		}
		mat.push_back(temp);
		temp.clear();
	}
	return mat;
}

//Pauli X Gate
vector<vector<Complex>> X_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(0.0));
	temp.push_back(to_Complex(1.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(1.0));
	temp2.push_back(to_Complex(0.0));
	gate.push_back(temp2);
	return gate;
}

//NOT Gate
vector<vector<Complex>> NOT_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(0.0));
	temp.push_back(to_Complex(1.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(1.0));
	temp2.push_back(to_Complex(0.0));
	gate.push_back(temp2);
	return gate;
}

//Pauli Y Gate
vector<vector<Complex>> Y_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(0.0));
	temp.push_back(to_Complex(0.0, 1.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(0.0, -1.0));
	temp2.push_back(to_Complex(0.0));
	gate.push_back(temp2);
	return gate;
}

//Pauli Z Gate
vector<vector<Complex>> Z_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(1.0));
	temp.push_back(to_Complex(0.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(0.0));
	temp2.push_back(to_Complex(-1.0));
	gate.push_back(temp2);
	return gate;
}

//Hadamard Gate
vector<vector<Complex>> H_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(1.0));
	temp.push_back(to_Complex(1.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(1.0));
	temp2.push_back(to_Complex(-1.0));
	gate.push_back(temp2);
	gate=scale(0.70711,gate);
	return gate;
}

//Sqaureroot NOT Gate
vector<vector<Complex>> sqrtNOT_gate()
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(1, 1));
	temp.push_back(to_Complex(1, -1));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(1, -1));
	temp2.push_back(to_Complex(1, 1));
	gate.push_back(temp2);
    gate = scale(0.5, gate);
	return gate;
}

//R-Gate or Rz Gate 
vector<vector<Complex>> R_gate(double phi)
{
	vector< vector<Complex> > gate;
	vector <Complex> temp;
	temp.push_back(to_Complex(1.0));
	temp.push_back(to_Complex(0.0));
	gate.push_back(temp);
	vector <Complex> temp2;
	temp2.push_back(to_Complex(0.0));
    // e^(i*phi) == to_Complex(cos(phi))+to_Complex(0.0,1.0)*to_Complex(sin(phi))
	temp2.push_back(to_Complex(cos(phi))+to_Complex(0.0,1.0)*to_Complex(sin(phi)));
	gate.push_back(temp2);
	return gate;
}
vector<vector<Complex>> CNOT_gate()
{
	vector< vector<Complex> > gate=X_gate();
	gate=CU(gate);
	return gate;
}
vector<vector<Complex>> CX_gate()
{
	vector< vector<Complex> > gate=X_gate();
	gate=CU(gate);
	return gate;
}

vector<vector<Complex>> CY_gate()
{
	vector< vector<Complex> > gate=Y_gate();
	gate=CU(gate);
	return gate;
}

vector<vector<Complex>> CZ_gate()
{
	vector< vector<Complex> > gate=Z_gate();
	gate=CU(gate);
	return gate;
}

// Calculates base^exp
int power(int base, int exp)
{
	int temp=1;
	for(int i=0;i<exp;i++)
	{
		temp=temp*base;
	}
	return temp;
}
//Defaults to Zero
Qstate::Qstate()
{
	state.push_back(to_Complex(1.0));
	state.push_back(to_Complex(0.0));
	dimension=state.size();
	bitlength=1;
}
// Initializes to |init> ie ket
Qstate::Qstate(int init)
{
	if (init==0)
	{
		state.push_back(to_Complex(1.0));
		state.push_back(to_Complex(0.0));
		dimension=state.size();
	}
	else
	{
		state.push_back(to_Complex(0.0));
		state.push_back(to_Complex(1.0));
		dimension=state.size();
	}
	bitlength=1;
}

// Initializes to a custom bitstring ie custom kets
Qstate::Qstate(vector<int> init)
{
	vector< vector<Complex> > vec;
	for (int i=0;i<init.size();i++)
	{
		if (init[i]==0)
		{
			vector<Complex> temp;
			temp.push_back(to_Complex(1.0));
			temp.push_back(to_Complex(0.0));
			vec.push_back(temp);
		}
		if (init[i]==1)
		{
			vector<Complex> temp;
			temp.push_back(to_Complex(0.0));
			temp.push_back(to_Complex(1.0));
			vec.push_back(temp);
		}
	}	
	vector<Complex> temp=vec[0];
	for (int i=0;i<vec.size()-1;i++){
		temp=tensor(temp,vec[i+1]);
	}
	state=temp;
	dimension=state.size();
	bitlength=init.size();
}
	// Initializes to a custom state vector
Qstate::Qstate(vector<Complex> init)
{
	state=init;
	//cout<<state.size()<<endl;
	dimension=state.size();
	bitlength= (int) (log2(dimension)+0.2);
}

// Return dimension
int Qstate::get_dimension()
{
	return dimension;
}

// Return bitlength
int Qstate::get_bitlength()
{
	return bitlength;
}

//= Operator Overloading
void Qstate::operator=(const Qstate& c)
{
	this->state.clear();
	for(int i=0;i<c.dimension;i++)
	{
		this->state.push_back(c.state[i]);
	}
	this->dimension=c.dimension;
	this->bitlength=c.bitlength;
	// return c;
}

//* Operator Overloading
Qstate Qstate::operator*(const Qstate& c)
{
	vector<Complex> out;
	for(int i=0;i<this->dimension;i++)
	{
		for(int j=0;j<c.dimension;j++)
		{
			out.push_back(this->state[i]*c.state[j]);
		}
	}
	Qstate temp(out);
	return temp;
}

// Return state vector
vector<Complex> Qstate::get_state()
{
	return state;
}


// Measure the quantum state
vector<int> Qstate::measure()
{
	std::srand((unsigned)time(NULL));
	vector<int> v;
	int count=0;
	double num=(double) rand()/RAND_MAX;
	for (int i=0;i<dimension;i++)
	{
		if (num<=state[i].abs_squared())
		{
			break;
		}
		else
		{
			if (i==dimension-1)
			{
				break;
			}
			num-=state[i].abs_squared();
			count++;
		}
	}
	for (int i=0;i<dimension;i++)
	{
		if(i==count)
		{
			state[i]=to_Complex(1.0);
		}
		else
		{
			state[i]=to_Complex(0.0);
		}
	}
	vector<int> ans;
	for(int i=0;i<bitlength;i++)
	{
		if(count>=power(2,bitlength-i-1))
		{
			ans.push_back(1);
			count-=power(2,bitlength-i-1);
		}
		else
		{
			ans.push_back(0);
		}
	}
	return ans;
}

// Prints the state vector and dimension
void Qstate::print()
{
	cout<<"State: ";
	for (int i=0;i<dimension;i++)
	{
		state[i].print();
		cout<<" ";
	}
	cout<<endl<<"Dimension: "<<dimension<<"     Bits: "<<bitlength<<endl;
}

//Calculates the tensor product of two Qstates
Qstate tensor(Qstate a, Qstate b)
{
	vector<Complex> out;
	for(int i=0;i<a.get_dimension();i++)
	{
		for(int j=0;j<b.get_dimension();j++)
		{
			out.push_back(a.get_state()[i]*b.get_state()[j]);
		}
	}
	Qstate temp(out);
	return temp;
}

Qstate apply_gate(vector< vector<Complex> > gate, Qstate q, int location)
{
	vector< vector<Complex> > temp=gate;
	for (int i=0;i<location;i++)
	{
		temp=tensor(I_gate(2),temp);
	}
	for (int i=0;i<q.get_bitlength()-( ((int) (log2(gate.size())+0.1)) + location);i++)
	{
		temp=tensor(temp,I_gate(2));
	}
	vector<Complex> ans = multiply(temp,q.get_state());
	Qstate out(ans);
	return out;
}
// Apply a custom gate at location=0
// gate is formatted as a vector of column vectors
Qstate apply_gate(vector< vector<Complex> > gate, Qstate q)
{
	return apply_gate(gate, q, 0);
}

// Apply Hadamard gate
Qstate H(Qstate q)
{
	Qstate out=apply_gate(H_gate(), q.get_state());
	return out;
}

// Apply Pauli-X gate (same as NOT)
Qstate X(Qstate q)
{
	Qstate out=apply_gate(X_gate(), q.get_state());
	return out;
}

// Apply NOT gate (same as Pauli-X)
Qstate NOT(Qstate q)
{
	Qstate out=apply_gate(NOT_gate(), q.get_state());
	return out;
}

// Apply Pauli-Y gate
Qstate Y(Qstate q)
{
	Qstate out=apply_gate(Y_gate(), q.get_state());
	return out;
}

// Apply Pauli-Z gate
Qstate Z(Qstate q)
{
	Qstate out=apply_gate(Z_gate(), q.get_state());
	return out;
}

// Apply square root of NOT gate
Qstate sqrtNOT(Qstate q)
{
	Qstate out=apply_gate(sqrtNOT_gate(), q.get_state());
	return out;
}

// Apply phase shift gate by phi radians
Qstate R(double phi, Qstate q)
{
	Qstate out=apply_gate(R_gate(phi), q.get_state());
	return out;
}

// Apply CNOT gate (same as cX)
Qstate CNOT(Qstate q)
{
	Qstate out=apply_gate(CNOT_gate(), q.get_state());
	return out;
}

Qstate CNOT(Qstate q, int location)
{
	Qstate out=apply_gate(CNOT_gate(), q.get_state(), location);
	return out;
}
// Apply cX gate (same as CNOT)
Qstate CX(Qstate q)
{
	Qstate out=apply_gate(CX_gate(), q.get_state());
	return out;
}

// Apply cX gate (same as CNOT)
Qstate CX(Qstate q, int location)
{
	Qstate out=apply_gate(CX_gate(), q.get_state(), location);
	return out;
}

// Apply cY gate
Qstate CY(Qstate q)
{
	Qstate out=apply_gate(CY_gate(), q.get_state());
	return out;
}

// Apply cY gate
Qstate CY(Qstate q, int location)
{
	Qstate out=apply_gate(CY_gate(), q.get_state(), location);
	return out;
}

// Apply cZ gate
Qstate CZ(Qstate q)
{
	Qstate out=apply_gate(CZ_gate(), q.get_state());
	return out;
}

// Apply cZ gate
Qstate CZ(Qstate q, int location)
{
	Qstate out=apply_gate(CZ_gate(), q.get_state(), location);
	return out;
}