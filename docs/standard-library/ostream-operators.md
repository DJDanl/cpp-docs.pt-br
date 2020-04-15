---
title: Operadores &lt;ostream&gt;
ms.date: 11/04/2016
f1_keywords:
- ostream/std::operator&lt;&lt;
ms.assetid: 9282a62e-a3d1-4371-a284-fbc9515bb9a2
ms.openlocfilehash: d8b6f4e0f0b5bca41f8d895415fff4003231ad1d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373601"
---
# <a name="ltostreamgt-operators"></a>Operadores &lt;ostream&gt;

||
|-|
|[Operador&lt;&lt;](#op_lt_lt)|

## <a name="operatorltlt"></a><a name="op_lt_lt"></a>Operador&lt;&lt;

Grava vários tipos no fluxo.

```cpp
template <class _Elem, class _Tr>
basic_ostream<_Elem, _Tr>& operator<<(
    basic_ostream<_Elem, _Tr>& _Ostr,
    const Elem* str);

template <class _Elem, class _Tr>
basic_ostream<_Elem, _Tr>& operator<<(
    basic_ostream<_Elem, _Tr>& _Ostr,
    Elem _Ch);

template <class _Elem, class _Tr>
basic_ostream<_Elem, _Tr>& operator<<(
    basic_ostream<_Elem, _Tr>& _Ostr,
    const char* str);

template <class _Elem, class _Tr>
basic_ostream<_Elem, _Tr>& operator<<(
    basic_ostream<_Elem, _Tr>& _Ostr,
    char _Ch);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const char* str);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _ostr,
    char _Ch);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const signed char* str);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    signed char _Ch);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const unsigned char* str);

template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    unsigned char _Ch);

template <class _Elem, class _Tr, class T>
basic_ostream <_Elem, _Tr>& operator<<(
    basic_ostream<_Elem, _Tr>&& _Ostr,
    Ty val);
```

### <a name="parameters"></a>Parâmetros

*_Ch*\
Um caractere.

*_Elem*\
O tipo de elemento.

*_Ostr*\
Um objeto `basic_ostream` .

*Str*\
Uma cadeia de caracteres.

*_Tr*\
Características de caractere.

*Val*\
O tipo

### <a name="return-value"></a>Valor retornado

O fluxo.

### <a name="remarks"></a>Comentários

A classe `basic_ostream` também define vários operadores de inserção. Para obter mais informações, consulte [basic_ostream::operador&lt;](../standard-library/basic-ostream-class.md#basic_ostream_operator_lt_lt).

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _ostr,
    const Elem *str);
```

determina o comprimento `traits_type::`N`str`= [comprimento](../standard-library/char-traits-struct.md#length)( ) da seqüência que começa em *str*, e insere a seqüência. Se N < `_Ostr.`[width](../standard-library/ios-base-class.md#width), a função também insere uma repetição de `_Ostr.width` - N caracteres de preenchimento. A repetição precede a`_Ostr`seqüência se ( . [bandeiras](../standard-library/ios-base-class.md#flags)  &  `adjustfield` != [esquerda](../standard-library/ios-functions.md#left). Caso contrário, a repetição segue a sequência. A função *retorna _Ostr*.

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    Elem _Ch);
```

insere o elemento `_Ch`. Se 1 < `_Ostr.width`, a função também insere uma repetição de `_Ostr.width` - 1 caracteres de preenchimento. A repetição precede a sequência se `_Ostr.flags & adjustfield != left`. Caso contrário, a repetição segue a sequência. Ele retorna *_Ostr.*

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    const char *str);
```

comporta-se da mesma forma que

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    const Elem *str);
```

exceto que cada elemento *_Ch* da seqüência que `Elem` começa `_Ostr.`em *str* `_Ch`é convertido em um objeto de tipo chamando [put](../standard-library/basic-ostream-class.md#put)(`_Ostr.`[widen](../standard-library/basic-ios-class.md#widen)( )).

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    char _Ch);
```

comporta-se da mesma forma que

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    Elem _Ch);
```

exceto que *_Ch* é convertido `Elem` em `_Ostr.put`um `_Ostr.widen` `_Ch`objeto de tipo chamando ( )

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const char *str);
```

comporta-se da mesma forma que

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    const Elem *str);
```

(Ele não precisa ampliar os elementos antes de inseri-los.)

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    char _Ch);
```

comporta-se da mesma forma que

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    Elem _Ch);
```

(Não precisa ampliar *_Ch* antes de inseri-lo.)

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const signed char *str);
```

retorna `_Ostr` `const char *` `str` << .

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    signed char _Ch);
```

retorna `_Ostr` `char` `_Ch` << .

A função de modelo:

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const unsigned char *str);
```

retorna `_Ostr` `const char *` `str` << .

A função de modelo:

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    unsigned char _Ch);
```

retorna `_Ostr` `char` `_Ch` << .

A função de modelo:

```cpp
template <class _Elem, class _Tr, class T>
basic_ostream<_Elem, _Tr>& operator<<(
    basic_ostream<char, _Tr>&& _Ostr,
    T val);
```

retorna `_Ostr` `<<` `val` (e converte um [RValue Reference](../cpp/rvalue-reference-declarator-amp-amp.md) para `_Ostr` para um lvalue no processo).

### <a name="example"></a>Exemplo

Consulte [flush](../standard-library/ostream-functions.md#flush) para ver um exemplo usando `operator<<`.

## <a name="see-also"></a>Confira também

[\<ostream>](../standard-library/ostream.md)
