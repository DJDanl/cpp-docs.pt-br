---
title: "Funções &lt;ostream&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ostream/std::swap
- ostream/std::endl
- ostream/std::ends
- ostream/std::flush
ms.assetid: d6e56cc0-c8df-4dbe-be10-98e14c35ed3a
caps.latest.revision: 
manager: ghogen
helpviewer_keywords:
- std::swap [C++]
- std::endl [C++]
- std::ends [C++]
- std::flush [C++]
ms.openlocfilehash: 4693e33563048807cdef1c81cb4d47d4fb455137
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltostreamgt-functions"></a>Funções &lt;ostream&gt;

Essas são as funções de modelo global definidas no &lt;ostream&gt;. Para funções de membro, consulte o [classe basic_ostream](basic-ostream-class.md) documentação.

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

*Elem*  
O tipo de elemento.

*Ostr*  
Um objeto do tipo **basic_ostream**.

*Tr*  
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

As chamadas manipulator *Ostr*.[ colocar](../standard-library/basic-ostream-class.md#put)(*Ostr*.[ Ampliar](../standard-library/basic-ios-class.md#widen)('\n')) e, em seguida, chama *Ostr*.[ liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *Ostr*.

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

*Elem*  
O tipo de elemento.

*Ostr*  
Um objeto do tipo **basic_ostream**.

*Tr*  
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

As chamadas manipulator *Ostr*.[ colocar](../standard-library/basic-ostream-class.md#put)(*Elem*('\0')). Ele retorna *Ostr*.

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

*Elem*  
O tipo de elemento.

*Ostr*  
Um objeto do tipo **basic_ostream**.

*Tr*  
Características de caractere.

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo **basic_ostream**.

### <a name="remarks"></a>Comentários

As chamadas manipulator *Ostr*.[ liberar](../standard-library/basic-ostream-class.md#flush). Ele retorna *Ostr*.

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

Troca os valores de dois **basic_ostream** objetos.

```cpp
template <class Elem, class Tr>
void swap(
   basic_ostream<Elem, Tr>& left,
   basic_ostream<Elem, Tr>& right);
```

### <a name="parameters"></a>Parâmetros

*Elem*  
O tipo de elemento.

*Tr*  
Características de caractere.

*left*  
Uma referência de lvalue para um **basic_ostream** objeto.

*right*  
Uma referência de lvalue para um **basic_ostream** objeto.

### <a name="remarks"></a>Comentários

A função de modelo **permuta** executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)  
