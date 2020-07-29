---
title: 'Ponteiro :::no-loc(this):::'
description: 'O :::no-loc(this)::: ponteiro é um ponteiro gerado pelo compilador para o objeto atual em funções de membro não estático.'
ms.date: 01/22/2020
f1_keywords:
- :::no-loc(this):::_cpp
helpviewer_keywords:
- nonstatic member functions [C++]
- 'pointers, to :::no-loc(class)::: instance'
- ':::no-loc(this)::: pointer'
ms.assetid: 92e3256a-4ad9-4d46-8be1-d77fad90791f
no-loc:
- ':::no-loc(this):::'
- ':::no-loc(class):::'
- ':::no-loc(struct):::'
- ':::no-loc(union):::'
- ':::no-loc(sizeof):::'
- ':::no-loc(const):::'
- ':::no-loc(volatile):::'
ms.openlocfilehash: c851beaba7fe1091ffd7827714f90307303058c1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225820"
---
# <a name="no-locthis-pointer"></a>Ponteiro :::no-loc(this):::

O **`:::no-loc(this):::`** ponteiro é um ponteiro acessível somente dentro das funções de membro não estático de **`:::no-loc(class):::`** um **`:::no-loc(struct):::`** tipo, ou **`:::no-loc(union):::`** . Ele aponta para o objeto para o qual a função de membro é chamada. Funções membro static não têm um **`:::no-loc(this):::`** ponteiro.

## <a name="syntax"></a>Sintaxe

```cpp
:::no-loc(this):::
:::no-loc(this):::->member-identifier
```

## <a name="remarks"></a>Comentários

O ponteiro de um objeto **`:::no-loc(this):::`** não faz parte do próprio objeto. Ele não é refletido no resultado de uma **`:::no-loc(sizeof):::`** instrução no objeto. Quando uma função de membro não estático é chamada para um objeto, o compilador passa o endereço do objeto para a função como um argumento oculto. Por exemplo, a chamada de função a seguir:

```cpp
myDate.setMonth( 3 );
```

pode ser interpretado como:

```cpp
setMonth( &myDate, 3 );
```

O endereço do objeto está disponível de dentro da função membro como o **`:::no-loc(this):::`** ponteiro. A maioria dos **`:::no-loc(this):::`** usos de ponteiro é implícita. É legal, embora desnecessário, usar um explícito **`:::no-loc(this):::`** ao fazer referência a membros do :::no-loc(class)::: . Por exemplo:

```cpp
void Date::setMonth( int mn )
{
   month = mn;            // These three statements
   :::no-loc(this):::->month = mn;      // are equivalent
   (*:::no-loc(this):::).month = mn;
}
```

A expressão **`*:::no-loc(this):::`** é normalmente usada para retornar o objeto atual de uma função de membro:

```cpp
return *:::no-loc(this):::;
```

O **`:::no-loc(this):::`** ponteiro também é usado para proteger contra autoreferência:

```cpp
if (&Object != :::no-loc(this):::) {
// do not execute in cases of self-reference
```

> [!NOTE]
> Como o **`:::no-loc(this):::`** ponteiro não pode ser modificado, as atribuições ao **`:::no-loc(this):::`** ponteiro não são permitidas. As implementações anteriores do C++ permitiram a atribuição **`:::no-loc(this):::`** .

Ocasionalmente, o **`:::no-loc(this):::`** ponteiro é usado diretamente — por exemplo, para manipular Ures de dados autoreferenciais :::no-loc(struct)::: , onde o endereço do objeto atual é necessário.

## <a name="example"></a>Exemplo

```cpp
// :::no-loc(this):::_pointer.cpp
// compile with: /EHsc

#include <iostream>
#include <string.h>

using namespace std;

:::no-loc(class)::: Buf
{
public:
    Buf( char* szBuffer, size_t sizeOfBuffer );
    Buf& operator=( :::no-loc(const)::: Buf & );
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

Buf& Buf::operator=( :::no-loc(const)::: Buf &otherbuf )
{
    if( &otherbuf != :::no-loc(this)::: )
    {
        if (buffer)
            delete [] buffer;

        sizeOfBuffer =  strlen( otherbuf.buffer ) + 1;
        buffer = new char[sizeOfBuffer];
        strcpy_s( buffer, sizeOfBuffer, otherbuf.buffer );
    }
    return *:::no-loc(this):::;
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

## <a name="type-of-the-no-locthis-pointer"></a>Tipo do :::no-loc(this)::: ponteiro

O **`:::no-loc(this):::`** tipo do ponteiro pode ser modificado na declaração da função pelas **`:::no-loc(const):::`** **`:::no-loc(volatile):::`** palavras-chave e. Para declarar uma função que tenha qualquer um desses atributos, adicione as palavras-chave após a lista de argumentos da função.

Considere um exemplo:

```cpp
// type_of_:::no-loc(this):::_pointer1.cpp
:::no-loc(class)::: Point
{
    unsigned X() :::no-loc(const):::;
};
int main()
{
}
```

O código anterior declara uma função de membro, `X` , na qual o **`:::no-loc(this):::`** ponteiro é tratado como um **`:::no-loc(const):::`** ponteiro para um **`:::no-loc(const):::`** objeto. As combinações de opções *CV-mod-List* podem ser usadas, mas sempre modificam o objeto apontado pelo **`:::no-loc(this):::`** ponteiro, não pelo próprio ponteiro. A declaração a seguir declara a função `X` , onde o **`:::no-loc(this):::`** ponteiro é um **`:::no-loc(const):::`** ponteiro para um **`:::no-loc(const):::`** objeto:

```cpp
// type_of_:::no-loc(this):::_pointer2.cpp
:::no-loc(class)::: Point
{
    unsigned X() :::no-loc(const):::;
};
int main()
{
}
```

O tipo de **`:::no-loc(this):::`** em uma função de membro é descrito pela sintaxe a seguir. A *lista CV-Qualifier-* é determinada do Declarador da função membro. Ele pode ser **`:::no-loc(const):::`** ou **`:::no-loc(volatile):::`** (ou ambos). * :::no-loc(class)::: -Type* é o nome do :::no-loc(class)::: :

[*CV-Qualifier-List*] * :::no-loc(class)::: -tipo* ** \* :::no-loc(const)::: :::no-loc(this)::: **

Em outras palavras, o **`:::no-loc(this):::`** ponteiro é sempre um :::no-loc(const)::: ponteiro. Ele não pode ser reatribuído.  Os **`:::no-loc(const):::`** **`:::no-loc(volatile):::`** qualificadores ou usados na declaração da função membro se aplicam à :::no-loc(class)::: instância **`:::no-loc(this):::`** apontada pelo ponteiro em, no escopo dessa função.

A tabela a seguir explica mais sobre como esses modificadores funcionam.

### <a name="semantics-of-no-locthis-modifiers"></a>Semântica de :::no-loc(this)::: modificadores

|Modificador|Significado|
|--------------|-------------|
|**`:::no-loc(const):::`**|Não é possível alterar os dados do membro; Não é possível invocar funções de membro que não são **`:::no-loc(const):::`** .|
|**`:::no-loc(volatile):::`**|Os dados do membro são carregados da memória toda vez que são acessados; desabilita determinadas otimizações.|

É um erro passar um **`:::no-loc(const):::`** objeto para uma função membro que não é **`:::no-loc(const):::`** .

Da mesma forma, também é um erro passar um **`:::no-loc(volatile):::`** objeto para uma função de membro que não é **`:::no-loc(volatile):::`** .

Funções de membro declaradas como **`:::no-loc(const):::`** não podem alterar dados de membro — nessas funções, o **`:::no-loc(this):::`** ponteiro é um ponteiro para um **`:::no-loc(const):::`** objeto.

> [!NOTE]
> Con :::no-loc(struct)::: ORS e de :::no-loc(struct)::: ORS não podem ser declarados como **`:::no-loc(const):::`** ou **`:::no-loc(volatile):::`** . No entanto, eles podem ser invocados em **`:::no-loc(const):::`** **`:::no-loc(volatile):::`** objetos ou.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
