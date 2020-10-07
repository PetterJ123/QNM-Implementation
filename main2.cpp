#include <iostream>

void compute(double Di, double Z)
{
    double Qi[100]; //Queue length at node i
    double Rprime[100]; //Residence time
    double X[100]; //Throughput

    int m = 5;      // # of queuing node
    int n = 50;     // # of customers

    //double Di = 0.11114;   // service demand
    //double Z = 2.0;     // think time

    /*if (argc == 2) {
        Di = *argv[1];
        Z = *argv[2];
    }*/

    Qi[0] = 0.0;

    for (int i = 1; i < n; i++) {
        Rprime[i] = Di * (1.0 + Qi[i - 1]);
        X[i] = i / (Z + Rprime[i]);
        Qi[i] = X[i] * Rprime[i];

        double Ui = X[i] * Di * 100;
        double Ri = Di / (1.0 - Ui * 0.01);

        std::cout << "i=" << i << "\tUi=" << Ui << "\tRprime[i]=" << Rprime[i] << "\tRi= " << Ri << "\tX[n]=" << X[i] << "\tQ[i]=" << Qi[i] << "\n===========================\n";
    }
}

int main(int argc, char *argv[]){
    //double Qi[100]; //Queue length at node i
    //double Rprime[100]; //Residence time
    //double X[100]; //Throughput

    //int m = 5;      // # of queuing node
    //int n = 50;     // # of customers

    //double Di = 0.11114;   // service demand
    //double Z = 2.0;     // think time

    //if (argc == 2) {
    //    Di = *argv[1];
    //    Z = *argv[2];
    //}

    //Qi[0] = 0.0;

    //for (int i=1; i<n; i++){
    //    Rprime[i] = Di*(1.0 + Qi[i - 1]);
    //    X[i] = i/(Z + Rprime[i]);
    //    Qi[i] = X[i]*Rprime[i];

    //    double Ui = X[i] * Di * 100;
    //    double Ri = Di/(1.0 - Ui * 0.01);

    //    std::cout << "i=" << i << "\tUi=" << Ui << "\tRprime[i]=" << Rprime[i] << "\tRi= " << Ri << "\tX[n]=" << X[i] << "\tQ[i]=" << Qi[i] << "\n===========================\n";
    //}

    
    compute(0.11114, 2.0);

    return 0;
}

