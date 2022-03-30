#include "Header.h"

void Init_Container(Container* Head, Container* Tail) {
    Head->Cont = Tail->Cont = NULL;
    Head->Next = Tail->Next = NULL; 
    Head->Prev = Tail->Prev = NULL;
    Head->Len = Tail->Len = 0;
}

void In_Container(Container* Head, Container* Tail, ifstream& ifst) {
    Container* Temp;
    int Len = 0; 

    while (!ifst.eof()) {
        Temp = new Container(); 
        Temp->Next = NULL;
        Temp->Prev = NULL;
        
        if (!Len) {
            if ((Head->Cont = In_Car(ifst))) {
                Tail = Head;
                Len++;
            }
        }
        else {
            if ((Temp->Cont = In_Car(ifst))) {
                Tail->Next = Temp;
                Temp->Prev = Tail;
                Tail = Temp;
                Len++;
            }
        }
    }

   
    for (int i = 0; i < Len; i++) {
        Head->Len = Len;
        if (Head->Next) {
            Head = Head->Next;
        }
    }
}

void Out_Container(Container* Head, ofstream& ofst) {
    ofst << "Container contains " << Head->Len
        << " elements." << endl << endl;

    Container* Temp = Head; 

    for (int i = 0; i < Head->Len; i++) {
        ofst << i << ": ";
        Out_Car(Temp->Cont, ofst);

        if (Temp->Next) {
            Temp = Temp->Next;
        }
    }
}

void Clear_Container(Container* Head, Container* Tail) {
    Container* Temp = Head;
    
    for (int i = 0; i < Head->Len; i++) {
        free(Temp->Cont);
        Temp->Len = 0;
        
        if (Temp->Next) {
            Temp = Temp->Next;
            free(Temp->Prev);
        }

    }

    Head->Len = 0;
}

Car* In_Car(ifstream& ifst) {
    Car* C; 
    int K;

    ifst >> K; 

    if (K == 1) {
       
        C = (Car*)In_Truck(ifst); 

        C->K = TRUCK; 

        return C;
    }
    else if (K == 2) {
        C = (Car*)In_Bus(ifst); 

        C->K = BUS; 

        return C;
    }
    else {
        return 0;
    }
}

void Out_Car(Car* C, ofstream& ofst) {
    if (C->K == TRUCK) {
        Out_Truck((Truck*)C, ofst); 
    }
    else if (C->K == BUS) {
        Out_Bus((Bus*)C, ofst); 
    }
    else {
        ofst << "Incorrect element!" << endl;
    }
}

Truck* In_Truck(ifstream& ifst) {
    Truck* T = new Truck();

    ifst >> T->Motor_power;
    ifst >> T->Load_cap;
    ifst >> T->Fuel;

    return T;
}


void Out_Truck(Truck* T, ofstream& ofst) {
    ofst << "Truck with motor power = " << T->Motor_power<< endl;
    ofst << "Load capacity is " << T->Load_cap << endl;
    ofst << "Fuel is " << T->Fuel << endl << endl;
}

Bus* In_Bus(ifstream& ifst) {
    Bus* B = new Bus();

    ifst >> B->Motor_power;
    ifst >> B->Passenger_cap;
    ifst >> B->Fuel;

    return B;
}

void Out_Bus(Bus* B, ofstream& ofst) {
    ofst << "Bus with motor power = " << B->Motor_power << endl;
    ofst << "Passenger capacity is " << B->Passenger_cap << endl;
    ofst << "Fuel is " << B->Fuel << endl << endl;
}