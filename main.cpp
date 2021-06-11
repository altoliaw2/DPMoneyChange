#include <iostream>
#include <limits>

int fn_FindMinNC(int* ip_Arr, int i_Size, int i_Num);

int main(){
    int ia_Arr[4] = { 1, 3, 5, 7 };
    int i_Size = sizeof(ia_Arr) / sizeof(int);

    int i_Num = -1;
    std::cin>> i_Num;

    int i_NumC = fn_FindMinNC(ia_Arr, i_Size, i_Num);

    if (i_NumC != std::numeric_limits<int>::max()) {
        std::cout << "The minimum number of coins is "
                    << i_NumC;
    }

    return 0;
}

int fn_FindMinNC(int* ip_Arr, int i_Size, int i_Num){
    int ia_Tmp[i_Num + 1] = {};

    for (int i_Ct = 1; i_Ct <= i_Num; i_Ct++){
        ia_Tmp[i_Ct] = std::numeric_limits<int>::max();
        int i_Result = std::numeric_limits<int>::max();

        for (int i_Cat = 0; i_Cat < i_Size; i_Cat++){

            if (i_Ct - ip_Arr[i_Cat] >= 0) {
                i_Result = ia_Tmp[i_Ct - ip_Arr[i_Cat]];
            }

            if (i_Result != std::numeric_limits<int>::max()) {
                ia_Tmp[i_Ct] = std::min(ia_Tmp[i_Ct], i_Result + 1);
            }
        }
    }

    return ia_Tmp[i_Num];
}
