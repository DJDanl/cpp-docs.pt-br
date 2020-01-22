---
title: Ponteiro this
description: O ponteiro de this é um ponteiro gerado pelo compilador para o objeto atual em funções de membro não estático.
ms.date: 01/22/2020
f1_keywords:
- this_cpp
helpviewer_keywords:
- nonstatic member functions [C++]
- pointers, to class instance
- this pointer
ms.assetid: 92e3256a-4ad9-4d46-8be1-d77fad90791f
no-loc:
- this
- class
- struct
- union
- sizeof
- const
- volatile
ms.openlocfilehash: 58bba2edd7a457c624b747b5a65d209995852848
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518329"
---
# <a name="opno-locthis-pointer"></a>Ponteiro this

O ponteiro de **this** é um ponteiro acessível somente dentro das funções de membro não estático de um **class** , **struct** ou tipo de **union** . Ele aponta para o objeto para o qual a função de membro é chamada. Funções membro static não têm um ponteiro **this** .

## <a name="syntax"></a>Sintaxe

```cpp
this
this->member-identifier
```

## <a name="remarks"></a>Comentários

O ponteiro de **this** de um objeto não faz parte do próprio objeto. Ele não é refletido no resultado de uma instrução **sizeof** no objeto. Quando uma função de membro não estático é chamada para um objeto, o compilador passa o endereço do objeto para a função como um argumento oculto. Por exemplo, a chamada de função a seguir:

```cpp
myDate.setMonth( 3 );
```

pode ser interpretado como:

```cpp
setMonth( &myDate, 3 );
```

O endereço do objeto está disponível de dentro da função membro como o ponteiro **this** . A maioria das **this** usos do ponteiro são implícitos. É legal, embora desnecessário, usar um **this** explícito ao fazer referência aos membros da class. Por exemplo:

```cpp
void Date::setMonth( int mn )
{
   month = mn;            // These three statements
   this->month = mn;      // are equivalent
   (*this).month = mn;
}
```

A expressão `*this` é geralmente usada para retornar o objeto atual de uma função de membro:

```cpp
return *this;
```

O ponteiro de **this** também é usado para proteção contra autoreferência:

```cpp
if (&Object != this) {
// do not execute in cases of self-reference
```

> [!NOTE]
> Como o ponteiro de **this** não pode ser modificado, as atribuições para o ponteiro de **this** não são permitidas. Implementações anteriores C++ de atribuição permitida para **this** .

Ocasionalmente, o ponteiro de **this** é usado diretamente — por exemplo, para manipular estruturas de dados de autorreferência, onde o endereço do objeto atual é necessário.

## <a name="example"></a>Exemplo

```cpp
// this_pointer.cpp
// compile with: /EHsc

#include <iostream>
#include <string.h>

using namespace std;

class Buf
{
public:
    Buf( char* szBuffer, size_t sizeOfBuffer );
    Buf& operator=( const Buf & );
    void Display() { cout << buffer << endl; }

private:
    char*   buffer;
    size_t  sizeOfBuffer;
};

Buf::Buf( char* szBuffer, size_t sizeOfBuffer )
{
    sizeOfBuffer++; // account for a NULL terminator

    buffer = new char[ sizeOfBuffer ];
    if (buffer)
    {
        strcpy_s( buffer, sizeOfBuffer, szBuffer );
        sizeOfBuffer = sizeOfBuffer;
    }
}

Buf& Buf::operator=( const Buf &otherbuf )
{
    if( &otherbuf != this )
    {
        if (buffer)
            delete [] buffer;

        sizeOfBuffer =  strlen( otherbuf.buffer ) + 1;
        buffer = new char[sizeOfBuffer];
        strcpy_s( buffer, sizeOfBuffer, otherbuf.buffer );
    }
    return *this;
}

int main()
{
    Buf myBuf( "my buffer", 10 );
    Buf yourBuf( "your buffer", 12 );

    // Display 'my buffer'
    myBuf.Display();

    // assignment operator
    myBuf = yourBuf;

    // Display 'your buffer'
    myBuf.Display();
}
```

```Output
my buffer
your buffer
```

## <a name="type-of-the-opno-locthis-pointer"></a>Tipo do ponteiro de this

O tipo do ponteiro de **this** pode ser modificado na declaração de função pelas palavras-chave **const** e **volatile** . Para declarar uma função que tenha qualquer um desses atributos, adicione as palavras-chave após a lista de argumentos da função.

Considere um exemplo:

```cpp
// type_of_this_pointer1.cpp
class Point
{
    unsigned X() const;
};
int main()
{
}
```

O código anterior declara uma função de membro, `X`, na qual o ponteiro de **this** é tratado como um ponteiro de **const** para um objeto **const** . As combinações de opções *CV-mod-List* podem ser usadas, mas sempre modificam o objeto apontado pelo ponteiro de **this** , não pelo ponteiro em si. A declaração a seguir declara a função `X`, onde o ponteiro de **this** é um ponteiro **const** para um objeto **const** :

```cpp
// type_of_this_pointer2.cpp
class Point
{
    unsigned X() const;
};
int main()
{
}
```

O tipo de **this** em uma função de membro é descrito pela sintaxe a seguir. A *lista CV-Qualifier-* é determinada do Declarador da função membro. Pode ser **const** ou **volatile** (ou ambos). *classtipo* é o nome do class:

[*CV-Qualifier-List*]\* *declasstipo* **const this**

Em outras palavras, o ponteiro de **this** é sempre um ponteiro de const. Ele não pode ser reatribuído.  Os qualificadores **const** ou **volatile** usados na declaração da função membro se aplicam à instância de class o ponteiro de **this** aponta para o escopo dessa função.

A tabela a seguir explica mais sobre como esses modificadores funcionam.

### <a name="semantics-of-opno-locthis-modifiers"></a>Semântica de modificadores de this

|Modificador|Significado|
|--------------|-------------|
|**const**|Não é possível alterar os dados do membro; Não é possível invocar funções de membro que não são **const** .|
|**volatile**|Os dados do membro são carregados da memória toda vez que são acessados; desabilita determinadas otimizações.|

É um erro passar um objeto **const** para uma função membro que não é **const** .

Da mesma forma, também é um erro para passar um objeto de **volatile** para uma função de membro que não é **volatile** .

Funções de membro declaradas como **const** não podem alterar dados de membro — nessas funções, o ponteiro de **this** é um ponteiro para um objeto **const** .

> [!NOTE]
> Construtores e destruidores não podem ser declarados como **const** ou **volatile** . No entanto, eles podem ser invocados em objetos **const** ou **volatile** .

## <a name="see-also"></a>Veja também

[Palavras-chave](../cpp/keywords-cpp.md)
