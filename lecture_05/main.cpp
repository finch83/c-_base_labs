#include <iostream>
#include <random>

int add(int n1, int n2) { return n1 + n2; }

int divide(int n1, int n2)
{    if (0 == n2){
        std::cout << "Devision by 0\n";
        return std::numeric_limits<int>::min();
    }
    return n1 / n2;
}

int multiply(int n1, int n2) { return n1 * n2; }

int subtract(int n1, int n2) { return n1 - n2; }

typedef int (*func_t)(int,int);
struct operation_t {
    char operation;
    func_t func;
};


int main()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distrib(0, 9);
    int n1{}, n2{};

    operation_t operations[] {
    {'+', &add},
    {'/', &divide},
    {'*', &multiply},
    {'-', &subtract}
    };

    for (auto op : operations) {
        n1 = distrib(generator);
        n2 = distrib(generator);
        std:: cout << "Arg1: "<< n1
                   << " Arg2: " << n2
                   << " Operation '"
                   << op.operation
                   << "' Result: "
                   <<op.func(n1, n2)
                  << std::endl;
    }

    return 0;
}




