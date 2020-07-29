---
title: Ponteiros brutos (C++)
description: Como usar ponteiros brutos em C++
ms.date: 04/21/2020
helpviewer_keywords:
- pointers [C++]
no-loc:
- ':::no-loc(void):::'
- ':::no-loc(nullptr):::'
- ':::no-loc(const):::'
- ':::no-loc(char):::'
- ':::no-loc(new):::'
- ':::no-loc(delete):::'
ms.openlocfilehash: 53679559888191fe7f2aad7cb5a70d607974ae96
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233646"
---
# <a name="raw-pointers-c"></a>Ponteiros brutos (C++)

Um *ponteiro* é um tipo de variável. Ele armazena o endereço de um objeto na memória e é usado para acessar esse objeto. Um *ponteiro bruto* é um ponteiro cujo tempo de vida não é controlado por um objeto encapsulamento, como um [ponteiro inteligente](smart-pointers-modern-cpp.md). Um ponteiro bruto pode ser atribuído ao endereço de outra variável que não seja de ponteiro ou pode ser atribuído a um valor de [:::no-loc(nullptr):::](:::no-loc(nullptr):::.md) . Um ponteiro que não tenha sido atribuído a um valor contém dados aleatórios.

Um ponteiro também pode ser *desreferenciado* para recuperar o valor do objeto que ele aponta. O *operador de acesso de membro* fornece acesso aos membros de um objeto.

```cpp
    int* p = :::no-loc(nullptr):::; // declare pointer and initialize it
                      // so that it doesn't store a random address
    int i = 5;
    p = &i; // assign pointer to address of object
    int j = *p; // dereference p to retrieve the value at its address
```

Um ponteiro pode apontar para um objeto tipado ou para **`:::no-loc(void):::`** . Quando um programa aloca um objeto no [heap](https://wikipedia.org/wiki/Heap) na memória, ele recebe o endereço desse objeto na forma de um ponteiro. Tais ponteiros são chamados de *ponteiros de propriedade*. Um ponteiro de propriedade (ou uma cópia dele) deve ser usado para liberar explicitamente o objeto alocado de heap quando ele não for mais necessário. A falha na liberação da memória resulta em um *vazamento de memória*e renderiza esse local de memória indisponível para qualquer outro programa no computador. A memória alocada usando o **`:::no-loc(new):::`** deve ser liberada usando **`:::no-loc(delete):::`** (ou ** :::no-loc(delete)::: \[ ]**). Para obter mais informações, consulte [ :::no-loc(new)::: e :::no-loc(delete)::: operadores](:::no-loc(new):::-and-:::no-loc(delete):::-operators.md).

```cpp
    MyClass* mc = :::no-loc(new)::: MyClass(); // allocate object on the heap
    mc->print(); // access class member
    :::no-loc(delete)::: mc; // :::no-loc(delete)::: object (please don't forget!)
```

Um ponteiro (se não for declarado como **`:::no-loc(const):::`** ) pode ser incrementado ou diminuído para apontar para outro local na memória. Essa operação é chamada de *aritmética de ponteiro*. Ele é usado na programação C-Style para iterar sobre elementos em matrizes ou outras estruturas de dados. **`:::no-loc(const):::`** Não é possível estabelecer um ponteiro para apontar para um local de memória diferente e, nesse sentido, é semelhante a uma [referência](references-cpp.md). Para obter mais informações, consulte [ :::no-loc(const)::: e ponteiros voláteis](:::no-loc(const):::-and-volatile-pointers.md).

```cpp
    // declare a C-style string. Compiler adds terminating '\0'.
    :::no-loc(const)::: :::no-loc(char):::* str = "Hello world";

    :::no-loc(const)::: int c = 1;
    :::no-loc(const)::: int* p:::no-loc(const)::: = &c; // declare a non-:::no-loc(const)::: pointer to :::no-loc(const)::: int
    :::no-loc(const)::: int c2 = 2;
    p:::no-loc(const)::: = &c2;  // OK p:::no-loc(const)::: itself isn't :::no-loc(const):::
    :::no-loc(const)::: int* :::no-loc(const)::: p:::no-loc(const):::2 = &c;
    // p:::no-loc(const):::2 = &c2; // Error! p:::no-loc(const):::2 is :::no-loc(const):::.
```

Em sistemas operacionais de 64 bits, um ponteiro tem um tamanho de 64 bits. O tamanho de um ponteiro do sistema determina o quanto de memória endereçável ele pode ter. Todas as cópias de um ponteiro apontam para o mesmo local de memória. Ponteiros (juntamente com referências) são usados extensivamente em C++ para passar objetos maiores de e para funções. Isso porque geralmente é mais eficiente copiar o endereço de um objeto do que copiar o objeto inteiro. Ao definir uma função, especifique parâmetros de ponteiro como **`:::no-loc(const):::`** , a menos que você pretenda a função para modificar o objeto. Em geral, **`:::no-loc(const):::`** as referências são a maneira preferida de passar objetos para funções, a menos que o valor do objeto possivelmente possa ser **`:::no-loc(nullptr):::`** .

[Ponteiros para funções](#pointers_to_functions) permitem que as funções sejam passadas para outras funções e são usadas para "retornos de chamada" na programação em estilo C. O C++ moderno usa [expressões lambda](lambda-expressions-in-cpp.md) para essa finalidade.

## <a name="initialization-and-member-access"></a>Inicialização e acesso de membro

O exemplo a seguir mostra como declarar, inicializar e usar um ponteiro bruto. Ele é inicializado usando **`:::no-loc(new):::`** para apontar um objeto alocado no heap, que você deve explicitamente **`:::no-loc(delete):::`** . O exemplo também mostra alguns dos perigos associados a ponteiros brutos. (Lembre-se, este exemplo é a programação em estilo C e não C++ moderno!)

```cpp
#include <iostream>
#include <string>

class MyClass
{
public:
    int num;
    std::string name;
    :::no-loc(void)::: print() { std::cout << name << ":" << num << std::endl; }
};

// Accepts a MyClass pointer
:::no-loc(void)::: func_A(MyClass* mc)
{
    // Modify the object that mc points to.
    // All copies of the pointer will point to
    // the same modified object.
    mc->num = 3;
}

// Accepts a MyClass object
:::no-loc(void)::: func_B(MyClass mc)
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
    // Use :::no-loc(new)::: to allocate and initialize memory
    MyClass* pmc = :::no-loc(new)::: MyClass{ 108, "Nick" };

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
    func_A(pmc);
    pmc->print(); // "Erika, 3"
    pmc2->print(); // "Erika, 3"

    // Dereference the pointer and pass a copy
    // of the pointed-to object to a function
    func_B(*pmc);
    pmc->print(); // "Erika, 3" (original not modified by function)

    :::no-loc(delete):::(pmc); // don't forget to give memory back to operating system!
   // :::no-loc(delete):::(pmc2); //crash! memory location was already :::no-loc(delete):::d
}
```

## <a name="pointer-arithmetic-and-arrays"></a>Aritmética de ponteiro e matrizes

Ponteiros e matrizes estão fortemente relacionados. Quando uma matriz é passada por valor para uma função, ela é passada como um ponteiro para o primeiro elemento. O exemplo a seguir demonstra as seguintes propriedades importantes de ponteiros e matrizes:

- o **`sizeof`** operador retorna o tamanho total em bytes de uma matriz
- para determinar o número de elementos, divida o total de bytes pelo tamanho de um elemento
- Quando uma matriz é passada para uma função, ela *decays* a um tipo de ponteiro
- o **`sizeof`** operador quando aplicado a um ponteiro retorna o tamanho do ponteiro, 4 bytes em x86 ou 8 bytes em x64

```cpp
#include <iostream>

:::no-loc(void)::: func(int arr[], int length)
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

Determinadas operações aritméticas podem ser usadas em não :::no-loc(const)::: ponteiros para torná-las apontadas para outro local de memória. Os ponteiros são incrementados e decrementados usando os **++** **+=** operadores, **-=** e **--** . Essa técnica pode ser usada em matrizes e é especialmente útil em buffers de dados não tipados. Um **:::no-loc(void):::\*** é incrementado pelo tamanho de um **`:::no-loc(char):::`** (1 byte). Um ponteiro tipado é incrementado por tamanho do tipo para o qual ele aponta.

O exemplo a seguir demonstra como a aritmética de ponteiro pode ser usada para acessar pixels individuais em um bitmap no Windows. Observe o uso de **`:::no-loc(new):::`** e e **`:::no-loc(delete):::`** o operador de desreferência.

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

    :::no-loc(const):::expr int bufferSize = 30000;
    unsigned :::no-loc(char):::* buffer = :::no-loc(new)::: unsigned :::no-loc(char):::[bufferSize];

    BITMAPFILEHEADER bf;
    bf.bfType = 0x4D42;
    bf.bfSize = header.biSize + 14 + bufferSize;
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); //54

    // Create a gray square with a 2-pixel wide outline.
    unsigned :::no-loc(char):::* begin = &buffer[0];
    unsigned :::no-loc(char):::* end = &buffer[0] + bufferSize;
    unsigned :::no-loc(char):::* p = begin;
    :::no-loc(const):::expr int pixelWidth = 3;
    :::no-loc(const):::expr int borderWidth = 2;

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
        p++; // Increment one byte sizeof(unsigned :::no-loc(char):::).
    }

    ofstream wf(R"(box.bmp)", ios::out | ios::binary);

    wf.write(reinterpret_cast<:::no-loc(char):::*>(&bf), sizeof(bf));
    wf.write(reinterpret_cast<:::no-loc(char):::*>(&header), sizeof(header));
    wf.write(reinterpret_cast<:::no-loc(char):::*>(begin), bufferSize);

    :::no-loc(delete):::[] buffer; // Return memory to the OS.
    wf.close();
}
```

## <a name="no-locvoid-pointers"></a>:::no-loc(void):::* ponteiros

Um ponteiro para **`:::no-loc(void):::`** simplesmente aponta para um local de memória bruto. Às vezes, é necessário usar **:::no-loc(void):::\*** ponteiros, por exemplo, ao passar entre o código C++ e as funções C.

Quando um ponteiro tipado é convertido em um :::no-loc(void)::: ponteiro, o conteúdo do local da memória não é alterado. No entanto, as informações de tipo são perdidas, para que você não possa fazer operações de incrementar ou decrementar. Um local de memória pode ser convertido, por exemplo, de `MyClass*` para **`:::no-loc(void):::*`** e de volta para `MyClass*` . Essas operações são inerentemente propensas a erros e exigem muito cuidado com :::no-loc(void)::: erros. O C++ moderno desencoraja o uso de :::no-loc(void)::: ponteiros em quase todas as circunstâncias.

```cpp

//func.c
:::no-loc(void)::: func(:::no-loc(void):::* data, int length)
{
    :::no-loc(char):::* c = (:::no-loc(char):::*)(data);

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
    :::no-loc(void)::: func(:::no-loc(void):::* data, int length);
}

class MyClass
{
public:
    int num;
    std::string name;
    :::no-loc(void)::: print() { std::cout << name << ":" << num << std::endl; }
};

int main()
{
    MyClass* mc = :::no-loc(new)::: MyClass{10, "Marian"};
    :::no-loc(void):::* p = static_cast<:::no-loc(void):::*>(mc);
    MyClass* mc2 = static_cast<MyClass*>(p);
    std::cout << mc2->name << std::endl; // "Marian"

    // use operator :::no-loc(new)::: to allocate untyped memory block
    :::no-loc(void):::* p:::no-loc(void)::: = operator :::no-loc(new):::(1000);
    :::no-loc(char):::* p:::no-loc(char)::: = static_cast<:::no-loc(char):::*>(p:::no-loc(void):::);
    for(:::no-loc(char):::* c = p:::no-loc(char):::; c < p:::no-loc(char)::: + 1000; ++c)
    {
        *c = 0x00;
    }
    func(p:::no-loc(void):::, 1000);
    :::no-loc(char)::: ch = static_cast<:::no-loc(char):::*>(p:::no-loc(void):::)[0];
    std::cout << ch << std::endl; // 'A'
    operator :::no-loc(delete):::(p);
}
```

## <a name="pointers-to-functions"></a><a name="pointers_to_functions"></a>Ponteiros para funções

Na programação em estilo C, os ponteiros de função são usados principalmente para passar funções para outras funções. Essa técnica permite que o chamador Personalize o comportamento de uma função sem modificá-la. No C++ moderno, as [expressões lambda](lambda-expressions-in-cpp.md) fornecem o mesmo recurso com maior segurança de tipos e outras vantagens.

Uma declaração de ponteiro de função especifica a assinatura que a função indicada para deve ter:

```cpp
// Declare pointer to any function that...

// ...accepts a string and returns a string
string (*g)(string a);

// has no return value and no parameters
:::no-loc(void)::: (*x)();

// ...returns an int and takes three parameters
// of the specified types
int (*i)(int i, string s, double d);
```

O exemplo a seguir mostra uma função `combine` que usa como um parâmetro qualquer função que aceita um `std::string` e retorna um `std::string` . Dependendo da função que é passada para `combine` , ela precede ou acrescenta uma cadeia de caracteres.

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

## <a name="see-also"></a>Confira também

[Ponteiros inteligentes](smart-pointers-modern-cpp.md) 
 [Operador de indireção: *](indirection-operator-star.md)<br/>
[Operador address-of: &](address-of-operator-amp.md)</br>
[Bem-vindo de volta ao C++](welcome-back-to-cpp-modern-cpp.md)
