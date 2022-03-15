// օգտագործել եմ merge sort-ի մեջի 2 սորտավորված մասիվների merge անելը

#include <iostream>

int main()
{
    int n, negative, positive, number, pos_index, neg_index;

    //մուտքագրվող մասիվի դրական և բացասական տարրերի քանակը
    positive = 0;
    negative = 0;

    // օգտագործողը մուտքագրում է մասիվի չափը
    std::cout << "Print array lenght: ";
    std::cin >> n;
    int arr[n];
    int sorted_arr[n];
    
    // օգտագործողը մուտքագրում է մասիվի տարրերը
    std::cout << "Print array numbers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> number;
        arr[i] = number;

        // հաշվենք մասիվի դրական և բացասական տարրերի քանակը
        if(number >= 0)
        {
            positive = positive + 1;
        }
        else if(number < 0)
        {
            negative = negative + 1;
        }
    }
    std::cout << std:: endl;
    
    // ստեղծենք դրական և բացասական թվերի քառակուսիների մասիվներ
    int positive_numbers[positive];
    int negative_numbers[negative];
    
    pos_index = 0;
    neg_index = negative - 1;
    
    // ստանանք դրական և բացասական թվերի քառակուսիների մասիվների, միաժամանակ սորտավորելով
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] >= 0)
        {
            positive_numbers[pos_index] = arr[i]*arr[i];
            pos_index += 1;
        }
        else
        {
            negative_numbers[neg_index] = arr[i]*arr[i];
            neg_index -= 1; 
        }
    }
    
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    
    // միացնենք իրար դրական և բացասական մասիվները(merge 2 sorted arrays)
    while (i < positive && j < negative)
    {
        if (positive_numbers[i] <= negative_numbers[j]) 
        {
            sorted_arr[k] = positive_numbers[i];
            ++i;
        } 
        else 
        {
            sorted_arr[k] = negative_numbers[j];
            ++j;
        }
        ++k;
    }
    
    // դրական մասիվի մնացորդը ավելացնենք վերջնական մասիվի մեջ
    while (i < positive) 
    {
        sorted_arr[k] = positive_numbers[i];
        ++i;
        ++k;
    } 

    // բացասական մասիվի մնացորդը ավելացնենք վերջնական մասիվի մեջ
    while (j < negative) 
    {
        sorted_arr[k] = negative_numbers[j];
        ++j;
        ++k;
    }
    
    // արտածենք սորտավորված մասիվը
    std::cout << "Sorted array numbers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cout << sorted_arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
