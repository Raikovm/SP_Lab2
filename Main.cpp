#include <iostream>

static int* buble_sort(int* arr, int len)
{
	_asm
	{
		mov ecx, len
		dec ecx
		mov eax, arr
		J3 : mov edx, 0
		J2 : mov ebx, edx
		inc ebx
		mov ebx, [eax + 4 * ebx]
		cmp[eax + 4 * edx], ebx
		jle J1
		mov esi, edx
		inc esi
		mov edi, [eax + 4 * edx]
		mov[eax + 4 * esi], edi
		mov[eax + 4 * edx], ebx
		J1 : inc edx
		cmp edx, ecx
		jl J2
		dec ecx
		cmp ecx, 0
		jg J3
	}
}

int main()
{
    int size = 10;
    int* array;
    array = new int[size]{4, 3, 5, 7, 9, 10, 1, 111, 4, 6};

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

	_asm 
	{
		push size
		push array
		call buble_sort
		mov array, eax
		add esp, 8
	}

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}