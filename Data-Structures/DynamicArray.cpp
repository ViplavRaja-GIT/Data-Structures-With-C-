#include <iostream>
#include <assert.h>
using namespace std;
class DynamicArray
{
private:
    int size_;
    int max_;
    int *arrayHolder_;

public:
    DynamicArray()
    {
        this->size_ = 0;
        this->max_ = 5;
        this->arrayHolder_ = new int[this->max_];
    }

    ~DynamicArray()
    {
        delete[] this->arrayHolder_;
    }

    int getSize()
    {
        return this->size_;
    }

    int &operator[](int index)
    {
        assert(index < this->size_);
        return this->arrayHolder_[index];
    }

    void add(int number)
    {
        if (this->max_ < this->size_ + 1)
        {
            this->max_ *= 2;
            int *tmp = new int[this->max_];
            for (size_t i = 0; i < this->size_; i++)
            {
                tmp[i] = this->arrayHolder_[i];
            }
            delete[] this->arrayHolder_;
            this->arrayHolder_ = tmp;
            this->arrayHolder_[this->size_] = number;
            this->size_ += 1;
        }
        else
        {
            this->arrayHolder_[this->size_] = number;
            this->size_ += 1;
        }
    }
};

int main(int argc, char **argv)
{
    DynamicArray dArray;
    cout << "Addding 20 elements in Array" << endl;
    for (size_t i = 0; i < 20; i++)
    {
        dArray.add(i);
    }
    cout << "Last element : " << dArray[19] << endl;
    cout << "Array size_ : " << dArray.getSize() << endl;
    return 0;
}