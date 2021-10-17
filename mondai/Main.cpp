#include <stdio.h>

/*
【問題】
先ほどのnewとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください。
*/
class Array
{
public:
    Array()
    {
        newArray = nullptr;
    }

    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;

    }

    void Create(int Num)
    {
        newArray = new int[Num];
        num = Num;
    }

    int Get(int get)
    {
        if (get >= 0 && get < num)
        {
            return newArray[get];
        }

        else
        {
            return NULL;
        }
    }

    void Set(int set)
    {
        if (set >= 0 && set < num)
        {
            newArray[set] = set;
        }

        else
        {
            return;
        }
    }

private:
    int* newArray;
    int num;
};
int main()
{
    Array array;

    array.Create(1000);


    for (int i = 0; i < 1000; ++i)
    {
        array.Set(i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        printf("num = %d\n", array.Get(i));
    }

    // 配列外参照しようとした際を確認
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));

}