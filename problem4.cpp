#include <iostream>
#include <ctime>

int getSize();

int main()
{
    int size = 10;
    size = getSize();
    
    int matrix[size][size];
    
    //fill matrix with random numbers and display it
    std::cout << "\nYour random matrix with size " << size << ":\n\n";
    srand(time(0));
    int randomNumber = 0;
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            int randomNumber = rand() % 10;
            matrix[i][j] = randomNumber;
            std::cout << randomNumber << "  ";
        }
        std::cout << std::endl;
    }
    
    //rotate matrix
    std::cout << "\n\nRotated matrix:" << ":\n\n";
    for(int i = 0; i < size / 2; ++i)
    {
        for(int j = i; j < size - i - 1; ++j)
        {
            int tmp = matrix[i][j];
            
            matrix[i][j] = matrix[size - 1 - j][i];
            matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
            matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
            
            matrix[j][size - 1 - i] = tmp;
        }
    }
    
    //display rotated matrix
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

int getSize()
{
    int size = 10; 
    
    
    do{
        std::cout << "Enter the size of the square matrix: ";
        std::cin >> size;
    }
    while(size > 10 || size < 0);
        
    return size;
}
