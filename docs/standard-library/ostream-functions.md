---
title: Funções &lt;ostream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
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
ms.openlocfilehash: 494c750ec80000ef9090824e0436f6e443593847
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44107589"
---
# <a name="ltostreamgt-functions"></a>Funções &lt;ostream&gt;

Essas são as funções de modelo global definidas &lt;ostream&gt;. Para funções de membro, consulte o [classe basic_ostream](basic-ostream-class.md) documentação.

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

*Elem*<br/>
O tipo de elemento.

*Ostr*<br/>
Um objeto do tipo **basic_ostream**.

*Tr*<br/>
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

O manipulador chama *Ostr*.[ Coloque](../standard-library/basic-ostream-class.md#put)(*Ostr*.[ widen](../standard-library/basic-ios-class.md#widen)('\n')) e, em seguida, chama *Ostr*.[ liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *Ostr*.

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

*Elem*<br/>
O tipo de elemento.

*Ostr*<br/>
Um objeto do tipo `basic_ostream`.

*Tr*<br/>
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *Ostr*.[ Coloque](../standard-library/basic-ostream-class.md#put)(*Elem*('\0')). Ele retorna *Ostr*.

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

*Elem*<br/>
O tipo de elemento.

*Ostr*<br/>
Um objeto do tipo `basic_ostream`.

*Tr*<br/>
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O manipulador chama *Ostr*.[ liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *Ostr*.

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

*Elem*<br/>
O tipo de elemento.

*Tr*<br/>
Características de caractere.

*left*<br/>
Uma referência lvalue a um objeto `basic_ostream`.

*right*<br/>
Uma referência lvalue a um objeto `basic_ostream`.

### <a name="remarks"></a>Comentários

A função de modelo `swap` executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)
