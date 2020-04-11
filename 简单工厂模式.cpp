#include <iostream>
#include <stdio.h>
using namespace std;
class Operation
{
    private:
        double _numberA;
        double _numberB;

    public:
        double GetNumberA()
        {
            return _numberA;
        }
        double GetNumberB()
        {
            return _numberB;
        }
        void SetNumberA(double A)
        {
            _numberA = A;
        }
        void SetNumberB(double B)
        {
            _numberB = B;
        }

        virtual double GetResult() = 0;
};

class OperationAdd: public Operation
{
    public:
        double GetResult() 
        {
            return GetNumberA() + GetNumberB();
        }
};

class OperationSub: public Operation
{
    public:
        double GetResult() 
        {
            return GetNumberA() - GetNumberB();
        }
};

class OperationMul: public Operation
{
    public:
        double GetResult() 
        {
            return GetNumberA() * GetNumberB();
        }
};

class OperationDiv: public Operation
{
    public:
        double GetResult() 
        {   
            if (0 == GetNumberB())
            {
                return 0;
            }
            return GetNumberA() / GetNumberB();
        }
};

class OperationFactory
{
    public:
        static Operation* createOperate(string operate)
        {
            if(operate == "+")
            {
                return new OperationAdd();
            }
            else if(operate == "-")
            {
                return new OperationSub();
            }
            else if(operate == "*")
            {
                return new OperationMul();
            }
            else if(operate == "/")
            {
                return new OperationDiv();
            }
            else
            {
                return NULL;
            }


        }
};

int main(int argc, char** argv)
{
    OperationFactory fac;
    Operation* oper = fac.createOperate("+");
    oper->SetNumberA(10);
    oper->SetNumberB(20);
    printf("%f\n", oper->GetResult());
    return 0;
}
