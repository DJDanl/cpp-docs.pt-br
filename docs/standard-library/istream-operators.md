---
title: Operadores &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::operator&gt;&gt;
ms.assetid: 7174da41-f301-4a34-b631-0ab918b188d2
ms.openlocfilehash: 5ac5c61488530f99cdad38ca1bfca365b6ac0f8c
ms.sourcegitcommit: 4b0928a1a497648d0d327579c8262f25ed20d02e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2019
ms.locfileid: "72890171"
---
# <a name="ltistreamgt-operators"></a>Operadores &lt;istream&gt;

## <a name="op_gt_gt"></a>  operator&gt;&gt;

Extrai caracteres e cadeias de caracteres do fluxo.

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr,
    Elem* str);

template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr,
    Elem& Ch);

template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,
    signed char* str);

template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,
    signed char& Ch);

template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,
    unsigned char* str);

template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,
    unsigned char& Ch);

template <class Elem, class Tr, class Type>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<char, Tr>&& Istr,
    Type& val);
```

### <a name="parameters"></a>Parâmetros

*Ch* \
Um caractere.

\ *ISTR*
Um fluxo.

\ de *Str*
Uma cadeia de caracteres.

*valor* \
Um tipo.

### <a name="return-value"></a>Valor retornado

O fluxo

### <a name="remarks"></a>Comentários

A classe `basic_istream` também define vários operadores de extração. Para obter mais informações, consulte [basic_istream::operator>>](../standard-library/basic-istream-class.md#op_gt_gt).

O modelo de função:

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem* str);
```

extrai até `N - 1` elementos e os armazena na matriz, começando em *Str*. Se `Istr.`[largura](../standard-library/ios-base-class.md#width) for maior que zero, *N* será `Istr.width`; caso contrário, é o tamanho da maior matriz de `Elem` que pode ser declarada. A função sempre armazena o valor `Elem()` após qualquer elemento extraído que ele armazena. A extração pára no final do arquivo, em um caractere com valor `Elem(0)` (que não é extraído) ou em qualquer elemento (que não é extraído) que seria Descartado pelo [WS](../standard-library/istream-functions.md#ws). Se a função extrair nenhum elemento, ela chamará `Istr.`[`setstate`](../standard-library/basic-ios-class.md#setstate)`(failbit)`. Em qualquer caso, ele chama `Istr.width(0)` e retorna *ISTR*.

**Observação de segurança** A cadeia de caracteres terminada em nulo que está sendo extraída do fluxo de entrada não deve exceder o tamanho do *Str*de buffer de destino. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

O modelo de função:

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem& Ch);
```

extrai um elemento, se possível, e o armazena em *ch*. Caso contrário, ele chama `is.`[`setstate`](../standard-library/basic-ios-class.md#setstate)`(failbit)`. Em qualquer caso, retorna *ISTR*.

O modelo de função:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char* str);
```

Retorna `Istr >> ( char * ) str`.

O modelo de função:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char& Ch);
```

Retorna `Istr >> ( char& ) Ch`.

O modelo de função:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char* str);
```

Retorna `Istr >> ( char * ) str`.

O modelo de função:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char& Ch);
```

Retorna `Istr >> ( char& ) Ch`.

O modelo de função:

```cpp
template <class Elem, class Tr, class Type>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<char, Tr>&& Istr,
    Type& val);
```

Retorna `Istr >> val` (e converte uma referência rvalue para `Istr` em um lvalue no processo).

### <a name="example"></a>Exemplo

```cpp
// istream_op_extract.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main( )
{
   ws( cin );
   char c[10];

   cin.width( 9 );
   cin >> c;
   cout << c << endl;
}
```

## <a name="see-also"></a>Consulte também

[\<istream>](../standard-library/istream.md)
