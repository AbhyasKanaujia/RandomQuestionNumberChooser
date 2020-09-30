#include <iostream>

int previous_prime(int num);
bool isPrime(int num);
void show_completed();
bool *question_done;
int n;

int main()
{
    std::cout << "Enter number of quesitons: ";
    std::cin >> n;
    question_done = new bool[n]{false};
    int serial_number = 0;

    for (int prime = previous_prime(n); prime >= 1; prime = previous_prime(prime))
    {
        int next_question = prime;
        for (int i = 1; next_question <= n; next_question = prime * ++i)
        {
            if (!question_done[next_question - 1])
            {
                getchar();
                show_completed();
                std::cout << ++serial_number << ". Current: " << next_question;
                question_done[next_question - 1] = true;
            }
        }
    }
    std::cout << "\n\nCompleted all questions. Press any key to exit...";
    getchar();
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

void show_completed()
{
    std::cout << "\nCompleted:\n";
    for (int i = 0; i < n; i++)
    {
        if (question_done[i])
            std::cout << i + 1 << "\t";
        else
            std::cout << "_\t";
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
