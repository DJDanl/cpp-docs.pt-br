---
title: Operadores &lt;thread&gt;
ms.date: 11/04/2016
f1_keywords:
- thread/std::operator!=
- thread/std::operator&gt;
- thread/std::operator&gt;=
- thread/std::operator&lt;
- thread/std::operator&lt;&lt;
- thread/std::operator&lt;=
- thread/std::operator==
ms.assetid: e6bb6c0f-64f9-4cb2-9ff2-05b88a6ba7ac
helpviewer_keywords:
- std::operator!= (thread)
- std::operator&gt; (thread)
- std::operator&gt;= (thread)
- std::operator&lt; (thread)
- std::operator&lt;&lt; (thread)
- std::operator&lt;= (thread)
- std::operator== (thread)
ms.openlocfilehash: 6312d14dc681736ee396d5c7af6c50ba8d72cd3a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375828"
---
# <a name="ltthreadgt-operators"></a>Operadores &lt;thread&gt;

||||
|-|-|-|
|[operador!=](#op_neq)|[Operador&gt;](#op_gt)|[Operador&gt;=](#op_gt_eq)|
|[Operador&lt;](#op_lt)|[Operador&lt;&lt;](#op_lt_lt)|[Operador&lt;=](#op_lt_eq)|
|[operador==](#op_eq_eq)|

## <a name="operatorgt"></a><a name="op_gt_eq"></a>Operador&gt;=

Determina se um objeto `thread::id` é maior ou igual a outro.

```cpp
bool operator>= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Left < Right)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorgt"></a><a name="op_gt"></a>Operador&gt;

Determina se um objeto `thread::id` é maior que outro.

```cpp
bool operator> (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`Right < Left`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorlt"></a><a name="op_lt_eq"></a>Operador&lt;=

Determina se um objeto `thread::id` é menor ou igual a outro.

```cpp
bool operator<= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Right < Left)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorlt"></a><a name="op_lt"></a>Operador&lt;

Determina se um objeto `thread::id` é menor que outro.

```cpp
bool operator<(
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

**verdade** se *a esquerda* precede a *direita* na ordem total; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

O operador define uma ordenação total em todos os objetos `thread::id`. Esses objetos podem ser usados como chaves em contêineres associativos.

Essa função não gera exceções.

## <a name="operator"></a><a name="op_neq"></a>operador!=

Compara dois objetos `thread::id` quanto à desigualdade.

```cpp
bool operator!= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Left == Right)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operator"></a><a name="op_eq_eq"></a>operador==

Compara dois objetos `thread::id` quanto à igualdade.

```cpp
bool operator== (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

**verdade** se os dois objetos representam o mesmo fio de execução ou se nenhum dos objetos representa um fio de execução; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorltlt"></a><a name="op_lt_lt"></a>Operador&lt;&lt;

Insere uma representação de texto de um objeto `thread::id` em um fluxo.

```cpp
template <class Elem, class Tr>
basic_ostream<Elem, Tr>& operator<<(
    basic_ostream<Elem, Tr>& Ostr, thread::id Id);
```

### <a name="parameters"></a>Parâmetros

*Ostr*\
Um objeto [basic_ostream](../standard-library/basic-ostream-class.md).

*Id*\
Um objeto `thread::id` .

### <a name="return-value"></a>Valor retornado

*Ostr.*

### <a name="remarks"></a>Comentários

Esta função insere *ID* no *Ostr*.

Se dois objetos `thread::id` forem comparados como iguais, as representações de texto inseridas desses objetos serão as mesmas.

## <a name="see-also"></a>Confira também

[\<thread>](../standard-library/thread.md)
