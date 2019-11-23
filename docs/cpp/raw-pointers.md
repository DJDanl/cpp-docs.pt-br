---
title: Ponteiros brutos (C++)
description: Como usar ponteiros brutos emC++
ms.date: 11/19/2019
helpviewer_keywords:
- pointers [C++]
ms.openlocfilehash: 9ea498c254bc37dc8dc550232127cb2db3bc0886
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74250656"
---
# <a name="raw-pointers-c"></a>Ponteiros brutos (C++)

Um ponteiro é um tipo de variável que armazena o endereço de um objeto na memória e é usada para acessar esse objeto. Um *ponteiro bruto* é um ponteiro cujo tempo de vida não é controlado por um objeto encapsulamento, como um [ponteiro inteligente](smart-pointers-modern-cpp.md). Um ponteiro bruto pode ser atribuído ao endereço de outra variável que não seja de ponteiro ou pode ser atribuído a um valor de [nullptr](nullptr.md). Um ponteiro que não tenha sido atribuído a um valor contém dados aleatórios.

Um ponteiro também pode ser *desreferenciado* para recuperar o valor do objeto que ele aponta. O *operador de acesso de membro* fornece acesso aos membros de um objeto.

```cpp
    int* p = nullptr; // declare pointer and initialize it
                      // so that it doesn't store a random address
    int i = 5;
    p = &i; // assign pointer to address of object
    int j = *p; // dereference p to retrieve the value at its address

```

Um ponteiro pode apontar para um objeto tipado ou para **void**. Quando um programa aloca um novo objeto no [heap](https://wikipedia.org/wiki/Heap) na memória, ele recebe o endereço desse objeto na forma de um ponteiro. Tais ponteiros são chamados de *ponteiros de propriedade*; um ponteiro de propriedade (ou uma cópia dele) deve ser usado para excluir explicitamente o objeto alocado de heap quando ele não for mais necessário. A falha ao excluir a memória resulta em um *vazamento de memória* e renderiza esse local de memória indisponível para qualquer outro programa no computador. Para obter mais informações, consulte [operadores New e Delete](new-and-delete-operators.md).

```cpp

    MyClass* mc = new MyClass(); // allocate object on the heap
    mc->print(); // access class member
    delete mc; // delete object (please don't forget!)
```

Um ponteiro (se não é declarado como **const**) pode ser incrementado ou diminuído para que ele aponte para um novo local na memória. Isso é chamado de *aritmética de ponteiro* e é usado na programação em estilo C para iterar sobre elementos em matrizes ou outras estruturas de dados. Um ponteiro **const** não pode ser feito para apontar para um local de memória diferente e, nesse sentido, é muito semelhante a uma [referência](references-cpp.md). Para obter mais informações, consulte [ponteiros const e volatile](const-and-volatile-pointers.md).

```cpp
    // declare a C-style string. Compiler adds terminating '\0'.
    const char* str = "Hello world";

    const int c = 1;
    const int* pconst = &c; // declare a non-const pointer to const int
    const int c2 = 2;
    pconst = &c2;  // OK pconst itself isn't const
    const int* const pconst2 = &c; 
    // pconst2 = &c2; // Error! pconst2 is const.
```

Em sistemas operacionais de 64 bits, um ponteiro tem um tamanho de 64 bits; o tamanho de um ponteiro do sistema determina o quanto de memória endereçável ele pode ter. Todas as cópias de um ponteiro apontam para o mesmo local de memória. Ponteiros (juntamente com referências) são usados extensivamente C++ no para passar objetos maiores de e para funções, pois geralmente é muito mais eficiente copiar o endereço de 64 bits de um objeto do que copiar um objeto inteiro. Ao definir uma função, especifique parâmetros de ponteiro como **const** , a menos que você pretenda que a função modifique o objeto. Em geral, as referências **const** são a maneira preferida de passar objetos para funções, a menos que o valor do objeto possivelmente possa ser **nullptr**.

[Ponteiros para funções](#pointers_to_functions) permitem que as funções sejam passadas para outras funções e são usadas para "retornos de chamada" na programação em estilo C. O C++ moderno usa [expressões lambda](lambda-expressions-in-cpp.md) para essa finalidade.

## <a name="initialization-and-member-access"></a>Inicialização e acesso de membro

O exemplo a seguir mostra como declarar um ponteiro bruto e inicializá-lo com um objeto alocado no heap e como usá-lo. Ele também mostra alguns dos perigos associados a ponteiros brutos. (Lembre-se, essa é a programação em estilo C C++e não é moderna!)

```cpp
#include <iostream>
#include <string>

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

// Accepts a MyClass pointer
void func_A(MyClass* mc)
{
    // Modify the object that mc points to.
    // All copies of the pointer will point to
    // the same modified object.
    mc->num = 3;
}

// Accepts a MyClass object
void func_B(MyClass mc)
{
    // mc here is a regular object, not a pointer.
    // Use the "." operator to access members.
    // This statement modifies only the local copy of mc.
    mc.num = 21;
    std::cout << "Local copy of mc:";
    mc.print(); // "Erika, 21"
}


int main()
{
    // Use the * operator to declare a pointer type
    // Use new to allocate and initialize memory
    MyClass* pmc = new MyClass{ 108, "Nick" };

    // Prints the memory address. Usually not what you want.
    std:: cout << pmc << std::endl;

    // Copy the pointed-to object by dereferencing the pointer
    // to access the contents of the memory location.
    // mc is a separate object, allocated here on the stack
    MyClass mc = *pmc;

    // Declare a pointer that points to mc using the addressof operator
    MyClass* pcopy = &mc;

    // Use the -> operator to access the object's public members
    pmc->print(); // "Nick, 108"

    // Copy the pointer. Now pmc and pmc2 point to same object!
    MyClass* pmc2 = pmc;

    // Use copied pointer to modify the original object
    pmc2->name = "Erika";
    pmc->print(); // "Erika, 108"
    pmc2->print(); // "Erika, 108"

    // Pass the pointer to a function.
    func_A(mc);
    pmc->print(); // "Erika, 3"
    pmc2->print(); // "Erika, 3"

    // Dereference the pointer and pass a copy
    // of the pointed-to object to a function
    func_B(*mc);
    pmc->print(); // "Erika, 3" (original not modified by function)

    delete(pmc); // don't forget to give memory back to operating system!
   // delete(pmc2); //crash! memory location was already deleted
}
```

## <a name="pointer-arithmetic-and-arrays"></a>Aritmética de ponteiro e matrizes

Ponteiros e matrizes estão fortemente relacionados. Quando uma matriz é passada por valor para uma função, ela é passada como um ponteiro para o primeiro elemento. O exemplo a seguir demonstra as seguintes propriedades importantes de ponteiros e matrizes:

- o operador `sizeof` retorna o tamanho total em bytes de uma matriz
- para determinar o número de elementos, divida o total de bytes pelo tamanho de um elemento
- Quando uma matriz é passada para uma função, ela *decays* a um tipo de ponteiro
- o operador de `sizeof` quando aplicado a um ponteiro retorna o tamanho do ponteiro, 4 bytes em x86 ou 8 bytes em x64

```cpp
#include <iostream>

void func(int arr[], int length)
{
    // returns pointer size. not useful here.
    size_t test = sizeof(arr);

    for(int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{

    int i[5]{ 1,2,3,4,5 };
    // sizeof(i) = total bytes
    int j = sizeof(i) / sizeof(i[0]);
    func(i,j);
}
```

Determinadas operações aritméticas podem ser executadas em ponteiros não const para que apontem para um novo local da memória. Um ponteiro pode ser incrementado e diminuído usando os operadores **++** , **+=** , **-=** e **--** . Essa técnica pode ser usada em matrizes e é especialmente útil em buffers de dados não tipados. Um **\*void** é incrementado pelo tamanho de um **Char** (1 byte). Um ponteiro tipado é incrementado por tamanho do tipo para o qual ele aponta.

O exemplo a seguir demonstra como a aritmética de ponteiro pode ser usada para acessar pixels individuais em um bitmap no Windows. Observe o uso de **New** e **delete**e o operador de desreferência. 

```cpp
#include <Windows.h>
#include <fstream>

using namespace std;

int main()
{

    BITMAPINFOHEADER header;
    header.biHeight = 100; // Multiple of 4 for simplicity.
    header.biWidth = 100;
    header.biBitCount = 24;
    header.biPlanes = 1;
    header.biCompression = BI_RGB;
    header.biSize = sizeof(BITMAPINFOHEADER);

    constexpr int bufferSize = 30000;
    unsigned char* buffer = new unsigned char[bufferSize];

    BITMAPFILEHEADER bf;
    bf.bfType = 0x4D42;
    bf.bfSize = header.biSize + 14 + bufferSize;
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); //54

    // Create a gray square with a 2-pixel wide outline.
    unsigned char* begin = &buffer[0];
    unsigned char* end = &buffer[0] + bufferSize;
    unsigned char* p = begin;
    constexpr int pixelWidth = 3;
    constexpr int borderWidth = 2;

    while (p < end)
    {
            // Is top or bottom edge?
        if ((p < begin + header.biWidth * pixelWidth * borderWidth)
            || (p > end - header.biWidth * pixelWidth * borderWidth)
            // Is left or right edge?
            || (p - begin) % (header.biWidth * pixelWidth) < (borderWidth * pixelWidth)
            || (p - begin) % (header.biWidth * pixelWidth) > ((header.biWidth - borderWidth) * pixelWidth))
        {
            *p = 0x0; // Black
        }
        else
        {
            *p = 0xC3; // Gray
        }
        p++; // Increment one byte sizeof(unsigned char).
    }

    ofstream wf(R"(box.bmp)", ios::out | ios::binary);

    wf.write(reinterpret_cast<char*>(&bf), sizeof(bf));
    wf.write(reinterpret_cast<char*>(&header), sizeof(header));
    wf.write(reinterpret_cast<char*>(begin), bufferSize);

    delete[] buffer; // Return memory to the OS.
    wf.close();
}
```

## <a name="void-pointers"></a>void * ponteiros

Um ponteiro para **anular** simplesmente aponta para um local de memória bruto. Às vezes, é necessário usar ponteiros **void\*** , por exemplo, ao C++ passar entre as funções Code e C. 

Quando um ponteiro tipado é convertido em um ponteiro void, o conteúdo do local da memória não é alterado, mas as informações de tipo são perdidas, para que você não possa executar operações de incremento ou decréscimo. Um local de memória pode ser convertido, por exemplo, de MyClass * para void * e de volta para MyClass *. Essas operações são inerentemente propensas a erros e exigem muito cuidado para evitar erros. O C++ moderno não incentiva o uso de ponteiros void, a menos que seja absolutamente necessário.

```cpp

//func.c
void func(void* data, int length)
{
    char* c = (char*)(data);

    // fill in the buffer with data
    for (int i = 0; i < length; ++i)
    {
        *c = 0x41;
        ++c;
    }
}

// main.cpp
#include <iostream>

extern "C"
{
    void func(void* data, int length);
}

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

int main()
{
    MyClass* mc = new MyClass{10, "Marian"};
    void* p = static_cast<void*>(mc);
    MyClass* mc2 = static_cast<MyClass*>(p);
    std::cout << mc2->name << std::endl; // "Marian"

    // use operator new to allocate untyped memory block
    void* pvoid = operator new(1000);
    for(char* c = static_cast<char*>(pvoid); pvoid < &pvoid + 1000; ++c)
    {
        *c = 0x00;
    }
    func(pvoid, 1000);
    char ch = static_cast<char*>(pvoid)[0];
    std::cout << ch << std::endl; // 'A'
    operator delete(p);
}
```

## <a name="pointers_to_functions"></a>Ponteiros para funções

Na programação em estilo C, os ponteiros de função são usados principalmente para passar funções para outras funções. Nesse cenário, o chamador pode personalizar o comportamento de uma função sem modificá-la. No moderno C++, as [expressões lambda](lambda-expressions-in-cpp.md) fornecem o mesmo recurso com maior segurança de tipos e outras vantagens.

Uma declaração de ponteiro de função especifica a assinatura que a função indicada para deve ter:

```cpp
// Declare pointer to any function that...

// ...accepts a string and returns a string
string (*g)(string a);

// has no return value and no parameters
void (*x)();

// ...returns an int and takes three parameters
// of the specified types
int (*i)(int i, string s, double d);
```

O exemplo a seguir mostra uma função `combine` que usa como um parâmetro qualquer função que aceita um `std::string` e retorna um `std::string`. Dependendo da função que é passada para `combine` ela precederá ou acrescentará uma cadeia de caracteres.

```cpp
#include <iostream>
#include <string>

using namespace std;

string base {"hello world"};

string append(string s)
{
    return base.append(" ").append(s);
}

string prepend(string s)
{
    return s.append(" ").append(base);
}

string combine(string s, string(*g)(string a))
{
    return (*g)(s);
}

int main()
{
    cout << combine("from MSVC", append) << "\n";
    cout << combine("Good morning and", prepend) << "\n";
}
```

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes](smart-pointers-modern-cpp.md)
[operador de indireção: *](indirection-operator-star.md)<br/>
[Operador endereço de: &](address-of-operator-amp.md)</br>
[Bem-vindo de volta paraC++](welcome-back-to-cpp-modern-cpp.md)
