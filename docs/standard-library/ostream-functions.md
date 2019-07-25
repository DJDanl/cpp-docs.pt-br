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
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447188"
---
# <a name="ltostreamgt-functions"></a>Funções &lt;ostream&gt;

Essas são as funções de modelo globais definidas &lt;em&gt;ostream. Para funções de membro, consulte a documentação da [classe basic_ostream](basic-ostream-class.md) .

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

*Elem*\
O tipo de elemento.

*Ostr*\
Um objeto do tipo **basic_ostream**.

*TR*\
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [Put](../standard-library/basic-ostream-class.md#put) (*OSTR*. [ampliar](../standard-library/basic-ios-class.md#widen) (' \n ')) e, em seguida, chama *OSTR*. [liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *OSTR*.

### <a name="example"></a>Exemplo

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

*Elem*\
O tipo de elemento.

*Ostr*\
Um objeto do tipo `basic_ostream`.

*TR*\
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [Put](../standard-library/basic-ostream-class.md#put) (*Elem*(' \ 0 ')). Ele retorna *OSTR*.

### <a name="example"></a>Exemplo

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

*Elem*\
O tipo de elemento.

*Ostr*\
Um objeto do tipo `basic_ostream`.

*TR*\
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *OSTR*. [liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *OSTR*.

### <a name="example"></a>Exemplo

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

*Elem*\
O tipo de elemento.

*TR*\
Características de caractere.

*mantida*\
Uma referência lvalue a um objeto `basic_ostream`.

*Certo*\
Uma referência lvalue a um objeto `basic_ostream`.

### <a name="remarks"></a>Comentários

A função de modelo `swap` executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)
