---
title: Operadores &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::operator&gt;&gt;
ms.assetid: 7174da41-f301-4a34-b631-0ab918b188d2
ms.openlocfilehash: c10692194c80051b10ecbe776c7d23a03860d508
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447791"
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

*CH*\
Um caractere.

*Istr*\
Um fluxo.

*Str*\
Uma cadeia de caracteres.

*Val*\
Um tipo.

### <a name="return-value"></a>Valor de retorno

O fluxo

### <a name="remarks"></a>Comentários

A classe `basic_istream` também define vários operadores de extração. Para obter mais informações, consulte [basic_istream::operator>>](../standard-library/basic-istream-class.md#op_gt_gt).

A função de modelo:

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem* str);
```

extrai até *N* - 1 elementos e os armazena na matriz que começa em _ *Str*. Se `Istr`. [width](../standard-library/ios-base-class.md#width) for maior que zero, *N* será `Istr`. **largura**; caso contrário, é o tamanho da maior matriz de `Elem` que pode ser declarado. A função sempre armazena o valor `Elem()` após qualquer elemento extraído que ele armazena. A extração é interrompida prematuramente no final do arquivo, em um caractere com valor **Elem**(0) (que não é extraído) ou em qualquer elemento (que não é extraído) que seria descartado por [ws](../standard-library/istream-functions.md#ws). Se a função não extrair nenhum elemento, ela chamará `Istr`. [setstate](../standard-library/basic-ios-class.md#setstate)(**failbit**). Em qualquer caso, chamará `Istr`. **largura** (0) e retorna *ISTR*.

**Observação de segurança** A cadeia de caracteres terminada em nulo que está sendo extraída do fluxo de entrada não deve exceder o tamanho do *Str*de buffer de destino. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/desktop/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

A função de modelo:

```cpp
template <class Elem, class Tr>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem& Ch);
```

extrai um elemento, se for possível, e o armazena em *ch*. Caso contrário, chama **is**. [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, retorna *ISTR*.

A função de modelo:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char* str);
```

Retorna `Istr >> ( char * ) str`.

A função de modelo:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char& Ch);
```

Retorna `Istr >> ( char& ) Ch`.

A função de modelo:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char* str);
```

Retorna `Istr >> ( char * ) str`.

A função de modelo:

```cpp
template <class Tr>
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char& Ch);
```

Retorna `Istr >> ( char& ) Ch`.

A função de modelo:

```cpp
template <class Elem, class Tr, class Type>
basic_istream<Elem, Tr>& operator>>(
    basic_istream<char, Tr>&& Istr,
    Type& val);
```

retorna `Istr >> val` (e converte uma `Istr` referência rvalue em um lvalue no processo).

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
