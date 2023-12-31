﻿#include <iostream>
#include <vector>
using namespace std;

class Set
{
private:
    int* s_array;
	int size;

public:
    Set(initializer_list<int> list)
    {
        size = list.size();
        s_array = new int[size];
        int j = 0;
        for (auto i = list.begin(); i != list.end(); i++)
        {
            if (!SetCheck(*i))
            {
               s_array[j] = *i;
            }
            else
            {
                s_array[j] = 0;
                cout << "Error! Repeated integer (index: " << j << ")" << endl;
            }
            j++;
        }
    }
    Set() : s_array(nullptr), size(0) {}

    Set(int size) : s_array(new int[size]), size(size) {}

    Set(const Set& other)
    {
       size = other.size;
       s_array = new int[other.size];

       for (int i = 0; i < other.size; i++)
       {
           s_array[i] = other.s_array[i];
       }
    }


    bool SetCheck(int el) const
    {
        for (int i = 0; i < size; i++)
        {
            if (s_array[i] == el)
            {
                return true;
            }
        }
        return false;
    }


     Set& operator=(const Set& other)
     {
        if (this != &other) 
        {
            delete[] s_array;
            size = other.size;
            s_array = new int[size];
            for (int i = 0; i < size; ++i) 
            {
                s_array[i] = other.s_array[i];
            }
        }
        return *this;
     }



     Set& operator-=(int num) 
     {
         for (int i = 0; i < size; i++) 
         { 
             if (s_array[i] == num) 
             {
                 for (int j = i; j < size - 1; j++) 
                 {
                     s_array[j] = s_array[j + 1];
                 }
                 size--;
                 break;
             }
         }
         return *this;
     }


     Set& operator-=(const Set& other)
     {
         for (int i = 0; i < other.size; ++i) 
         {
             for (int j = 0; j < size; ++j) 
             {
                 if (s_array[j] == other.s_array[i]) 
                 {
                     for (int k = j; k < size - 1; ++k) 
                     {
                         s_array[k] = s_array[k + 1];
                     }
                     --size;
                     break;
                 }
             }
         }
         return *this;
     }


     Set operator-(const Set& other) const
     {
         Set result(*this);
         result -= other;
         return result;
     }


     Set operator-(int num) const
     {
         Set result(*this);
         result -= num;
         return result;
     }



     Set& operator+=(const Set& other) 
     {
         for (int i = 0; i < other.size; i++) 
         {
             if (!SetCheck(other.s_array[i])) 
             {
                 int* new_array = new int[size + 1];
                 for (int j = 0; j < size; j++) 
                 {
                     new_array[j] = s_array[j];
                 }
                 new_array[size] = other.s_array[i];
                 delete[] s_array;
                 s_array = new_array;
                 size++;
             }
         }
         return *this;
     }


     Set& operator+=(int num) 
     {
         for (int i = 0; i < size; i++)
         {
             if (!SetCheck(num))
             {
                 int* new_array = new int[size + 1];
                 for (int j = 0; j < size; j++)
                 {
                     new_array[j] = s_array[j];
                 }
                 new_array[size] = num;
                 delete[] s_array;
                 s_array = new_array;
                 size++;
                 break;
             }
         }
         return *this;
     }


     Set operator+(const Set& other) const
     {
         Set result(*this);
         result += other;
         return result;
     }


     Set operator+(int num)
     {
         Set result(*this);
         result += num;
         return result;
     }


     Set operator*(const Set& other) const 
     {
         int n_size = 0;
         for (int i = 0; i < size; i++)
         {
             if (other.SetCheck(s_array[i]))
             {
                 n_size++;
             }
         }

         Set result(n_size);
         n_size = 0;
         for (int i = 0; i < size; i++)
         {
             if (other.SetCheck(s_array[i]))
             {
                 result.s_array[n_size] = s_array[i];
                 n_size++;
             }
         }
         return result;
     }

     Set operator*=(const Set& other)
     {
         Set result = *this * other;
         *this = result;
         return *this;
     }


     bool operator==(const Set& other) const 
     {
         if (size != other.size) 
         {
             return false;
         }
         for (int i = 0; i < size; i++) 
         {

             if (s_array[i] != other.s_array[i]) 
             {
                 return false;
             }
         }
         return true;
     }


     friend ostream& operator<<(ostream& os, const Set& set) 
     {
         for (int i = 0; i < set.size; i++) 
         {
             os << set.s_array[i];
             if (i < set.size - 1) {
                 os << ", ";
             }
         }
         return os;
     }

     void getset()
     {
         for (int i = 0; i < size; i++)
         {
             cout << s_array[i] << " ";
         }
     }

     ~Set()
     {
         delete[] s_array;
         s_array = nullptr;
     }
};




int main()
{
    Set A = {9, 40, 77, 65, 52};
    Set B = {15, 83, 70, 11, 2, 35, 77};
    Set C = {9, 8, 77};

    A += C;
    cout << A << endl;

    Set s1 = A - B;
    cout << s1 << endl;

    Set D = { 74, 43, 76, 63, 51 };
    D -= 63;
    cout << D << endl;

    A *= C;
    cout << A << endl;

    A = D;
    if (A == D)
    {
        cout << "True!" << endl;
    }
}

