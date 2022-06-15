// #include "qheader.h"
#include "qheader.cpp"
#include <bits/stdc++.h>
using namespace std;
signed main ()
{
    Qstate alice(0);
    Qstate bob(0);
    Qstate info(1);
    Qstate state;

    //Applying Hadamard Gate to Alice's Bit
    alice = H(alice);
    //Getting the tensor product of Alice and Bob and storing it in AB
    Qstate AB = alice*bob;
    //Applying controlled NOT (CNOT) gate from alice to bob, creating an entangled state
    AB = CNOT(AB);
    //Getting the tensor product of info and AB
    state = info*AB;
    //Applying CNOT to state
    state = CNOT(state);
    //Applying hadamard gate to info
    state = H(state);
    //Applying CNOT to alice and bob (1 means to apply to second qbit in the state)
    state = CNOT(state,1);

    //Measure the state, Bob should always measure what "info" originally had
    vector <int> out = state.measure();
    printbitstring(out);
    cout << endl;

}
