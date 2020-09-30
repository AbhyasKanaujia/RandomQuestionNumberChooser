#include <iostream>

int previous_prime(int num);
bool isPrime(int num);

int main()
{
    int n;
    std::cout << "Enter number of quesitons: ";
    std::cin >> n;
    bool *question_done = new bool[n]{false};
    std::cout << "question_done[0]: " << question_done[0] << std::endl;
    int serial_number = 0;

    for (int prime = previous_prime(n); prime >= 1; prime = previous_prime(prime))
    {
        int next_question = prime;
        for (int i = 1; next_question <= n; next_question = prime * ++i)
            if (question_done[next_question - 1] == false)
            {
                std::cout << ++serial_number << ". " << next_question << std::endl;
                question_done[next_question - 1] = true;
            }
    }
}

int previous_prime(int num)
{
    while (!isPrime(--num))
        ;
    return num;
}

bool isPrime(int num)
{
    if (num < 0)
    {
        std::cout << "Unexpected error!!";
        exit(1);
    }
    for (int i = 2; i < num / 2 + 1; i++)
        if (num % i == 0)
            return false;
    return true;
}