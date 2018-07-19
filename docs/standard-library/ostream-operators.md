---
title: Operadores &lt;ostream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- ostream/std::operator&lt;&lt;
dev_langs:
- C++
ms.assetid: 9282a62e-a3d1-4371-a284-fbc9515bb9a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4819f5b5d5d6a16720bce29dd176fd0eb873014a
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955927"
---
# <a name="ltostreamgt-operators"></a>Operadores &lt;ostream&gt;

||
|-|
|[operator&lt;&lt;](#op_lt_lt)|

## <a name="op_lt_lt"></a>  operator&lt;&lt;

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

*CH* um caractere.

*_Elem* o tipo de elemento.

*_Ostr* um `basic_ostream` objeto.

*STR* uma cadeia de caracteres.

*_Tr* características de caractere.

*Val* o tipo

### <a name="return-value"></a>Valor de retorno

O fluxo.

### <a name="remarks"></a>Comentários

A classe `basic_ostream` também define vários operadores de inserção. Para obter mais informações, consulte [basic_ostream::operator&lt;&lt;](../standard-library/basic-ostream-class.md#basic_ostream_operator_lt_lt).

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _ostr,
    const Elem *str);
```

Determina o tamanho de N = `traits_type::` [comprimento](../standard-library/char-traits-struct.md#length)(`str`) do início da sequência no *str*e insere a sequência. Se N < `_Ostr.`[width](../standard-library/ios-base-class.md#width), a função também insere uma repetição de `_Ostr.width` - N caracteres de preenchimento. A repetição precede a sequência se (`_Ostr`. [flags](../standard-library/ios-base-class.md#flags) & `adjustfield` != [left](../standard-library/ios-functions.md#left). Caso contrário, a repetição segue a sequência. A função retornará *_Ostr*.

A função do modelo

```cpp
template <class _Elem, class _Tr>
basic_ostream<Elem, _Tr>& operator<<(
    basic_ostream<Elem, _Tr>& _Ostr,
    Elem _Ch);
```

insere o elemento `_Ch`. Se 1 < `_Ostr.width`, a função também insere uma repetição de `_Ostr.width` - 1 caracteres de preenchimento. A repetição precede a sequência se `_Ostr.flags & adjustfield != left`. Caso contrário, a repetição segue a sequência. Ele retorna *_Ostr*.

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

exceto pelo fato de cada elemento *CH* do início da sequência em *str* é convertido em um objeto do tipo `Elem` chamando `_Ostr.` [colocar](../standard-library/basic-ostream-class.md#put)(`_Ostr.` [widen](../standard-library/basic-ios-class.md#widen)(`_Ch`)).

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

exceto que *CH* é convertido em um objeto do tipo `Elem` chamando `_Ostr.put`( `_Ostr.widen`( `_Ch`)).

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

(Ele não precisa ampliar *CH* antes de inseri-lo.)

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const signed char *str);
```

Retorna `_Ostr` << (`const char *`) `str`.

A função do modelo

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    signed char _Ch);
```

Retorna `_Ostr` << (`char`) `_Ch`.

A função de modelo:

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    const unsigned char *str);
```

Retorna `_Ostr` << (`const char *`) `str`.

A função de modelo:

```cpp
template <class _Tr>
basic_ostream<char, _Tr>& operator<<(
    basic_ostream<char, _Tr>& _Ostr,
    unsigned char _Ch);
```

Retorna `_Ostr` << (`char`) `_Ch`.

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

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)<br/>
