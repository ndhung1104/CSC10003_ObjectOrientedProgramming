class Array
{
    int* arr, size;

public:
    Array(int sz): arr(new int[sz]), size(sz) {};
    int& operator[](int i)
    {
        return this->arr[i];
    }

    int operator=(int i)
    {

    }


}