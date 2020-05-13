---
title: Operadores &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::operator&gt;&gt;
ms.assetid: 7174da41-f301-4a34-b631-0ab918b188d2
ms.openlocfilehash: 3b9521fde1b5a03389bfc1ad3e35fa407d9d6ac0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363032"
---
# <a name="ltistreamgt-operators"></a>Operadores &lt;istream&gt;

## <a name="operatorgtgt"></a><a name="op_gt_gt"></a>Operador&gt;&gt;

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

*Ch*\
Um caractere.

*Istr*\
Um fluxo.

*Str*\
Uma cadeia de caracteres.

*Val*\
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

extrai até `N - 1` elementos e os armazena na matriz a partir de *str*. Se `Istr.` [a largura](../standard-library/ios-base-class.md#width) for maior que zero, *N* é; `Istr.width` caso contrário, é o tamanho da `Elem` maior matriz do que pode ser declarado. A função sempre `Elem()` armazena o valor após quaisquer elementos extraídos que armazena. A extração pára no início do `Elem(0)` arquivo, em um caractere com valor (que não é extraído), ou em qualquer elemento (que não é extraído) que seria descartado por [ws](../standard-library/istream-functions.md#ws). Se a função não extrai `Istr.` [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)`elementos, ela chama . Em todo caso, `Istr.width(0)` ele liga e retorna *Istr*.

**Nota de segurança** A seqüência de terminais nula que está sendo extraída do fluxo de entrada não deve exceder o tamanho do *buffer str*de destino . Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

O modelo de função:

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem& Ch);
```

extrai um elemento, se possível, e armazena-o em *Ch*. Caso contrário, `is.` [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)`ele chama . Em todo caso, ele retorna *Istr*.

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

retorna `Istr >> val` (e converte uma `Istr` referência de valor para um valor no processo).

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

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)
