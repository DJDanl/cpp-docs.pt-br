---
title: Funções &lt;ostream&gt;
ms.date: 11/04/2016
f1_keywords:
- ostream/std::swap
- ostream/std::endl
- ostream/std::ends
- ostream/std::flush
ms.assetid: d6e56cc0-c8df-4dbe-be10-98e14c35ed3a
helpviewer_keywords:
- std::swap [C++]
- std::endl [C++]
- std::ends [C++]
- std::flush [C++]
ms.openlocfilehash: 8d93e46b0323058d93c6d0bd8c1ee566998aef61
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78874780"
---
# <a name="ltostreamgt-functions"></a>Funções &lt;ostream&gt;

Essas são as funções de modelo globais definidas em &lt;ostream&gt;. Para funções de membro, consulte a documentação da [classe basic_ostream](basic-ostream-class.md) .

||||
|-|-|-|
|[endl](#endl)|[ends](#ends)|[flush](#flush)|
|[swap](#swap)|

## <a name="endl"></a>endl

Termina uma linha e libera o buffer.

```cpp
template class<Elem, Tr>
basic_ostream<Elem, Tr>& endl(
   basic_ostream<Elem, Tr>& Ostr);
```

### <a name="parameters"></a>Parâmetros

\ *elem*
O tipo de elemento.

\ *OSTR*
Um objeto do tipo **basic_ostream**.

*Tr*\
Características de caractere.

### <a name="return-value"></a>Valor retornado

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [Put](../standard-library/basic-ostream-class.md#put)(*OSTR*.[ Amplie](../standard-library/basic-ios-class.md#widen)(' \n ')) e, em seguida, chama *OSTR*. [liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *OSTR*.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// ostream_endl.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout << "testing" << endl;
}
```

```Output
testing
```

## <a name="ends"></a>extremidades

Termina uma cadeia de caracteres.

```cpp
template class<Elem, Tr>
basic_ostream<Elem, Tr>& ends(
   basic_ostream<Elem, Tr>& Ostr);
```

### <a name="parameters"></a>Parâmetros

\ *elem*
O tipo de elemento.

\ *OSTR*
Um objeto do tipo `basic_ostream`.

*Tr*\
Características de caractere.

### <a name="return-value"></a>Valor retornado

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [Put](../standard-library/basic-ostream-class.md#put)(*elem*(' \ 0 ')). Ele retorna *OSTR*.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// ostream_ends.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout << "a";
   cout << "b" << ends;
   cout << "c" << endl;
}
```

```Output
ab c
```

## <a name="flush"></a>flush

Libera o buffer.

```cpp
template class<Elem, Tr>
basic_ostream<Elem, Tr>& flush(
   basic_ostream<Elem, Tr>& Ostr);
```

### <a name="parameters"></a>Parâmetros

\ *elem*
O tipo de elemento.

\ *OSTR*
Um objeto do tipo `basic_ostream`.

*Tr*\
Características de caractere.

### <a name="return-value"></a>Valor retornado

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *OSTR*.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// ostream_flush.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout << "testing" << flush;
}
```

```Output
testing
```

## <a name="swap"></a>swap

Troca os valores de dois objetos `basic_ostream`.

```cpp
template <class Elem, class Tr>
void swap(
   basic_ostream<Elem, Tr>& left,
   basic_ostream<Elem, Tr>& right);
```

### <a name="parameters"></a>Parâmetros

\ *elem*
O tipo de elemento.

*Tr*\
Características de caractere.

\ *à esquerda*
Uma referência lvalue a um objeto `basic_ostream`.

\ *à direita*
Uma referência lvalue a um objeto `basic_ostream`.

### <a name="remarks"></a>Comentários

A função de modelo `swap` executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)
