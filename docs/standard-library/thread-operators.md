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
ms.openlocfilehash: e7321831b9356fdb9ae5ce147319726def69efc7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215563"
---
# <a name="ltthreadgt-operators"></a>Operadores &lt;thread&gt;

||||
|-|-|-|
|[operador! =](#op_neq)|[operador&gt;](#op_gt)|[operador&gt;=](#op_gt_eq)|
|[operador&lt;](#op_lt)|[operador&lt;&lt;](#op_lt_lt)|[operador&lt;=](#op_lt_eq)|
|[operador = =](#op_eq_eq)|

## <a name="operatorgt"></a><a name="op_gt_eq"></a>operador&gt;=

Determina se um objeto `thread::id` é maior ou igual a outro.

```cpp
bool operator>= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Left < Right)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorgt"></a><a name="op_gt"></a>operador&gt;

Determina se um objeto `thread::id` é maior que outro.

```cpp
bool operator> (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`Right < Left`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorlt"></a><a name="op_lt_eq"></a>operador&lt;=

Determina se um objeto `thread::id` é menor ou igual a outro.

```cpp
bool operator<= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Right < Left)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

Determina se um objeto `thread::id` é menor que outro.

```cpp
bool operator<(
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

**`true`** se a *esquerda* precede *Right* a ordem total; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

O operador define uma ordenação total em todos os objetos `thread::id`. Esses objetos podem ser usados como chaves em contêineres associativos.

Essa função não gera exceções.

## <a name="operator"></a><a name="op_neq"></a>operador! =

Compara dois objetos `thread::id` quanto à desigualdade.

```cpp
bool operator!= (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

`!(Left == Right)`

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Compara dois objetos `thread::id` quanto à igualdade.

```cpp
bool operator== (
    thread::id Left,
    thread::id Right) noexcept
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `thread::id` à esquerda.

*Certo*\
O objeto `thread::id` à direita.

### <a name="return-value"></a>Valor retornado

**`true`** Se os dois objetos representarem o mesmo thread de execução ou se nenhum objeto representar um thread de execução; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="operatorltlt"></a><a name="op_lt_lt"></a>operador&lt;&lt;

Insere uma representação de texto de um objeto `thread::id` em um fluxo.

```cpp
template <class Elem, class Tr>
basic_ostream<Elem, Tr>& operator<<(
    basic_ostream<Elem, Tr>& Ostr, thread::id Id);
```

### <a name="parameters"></a>parâmetros

*Ostr*\
Um objeto [basic_ostream](../standard-library/basic-ostream-class.md).

*Sessão*\
Um objeto `thread::id`.

### <a name="return-value"></a>Valor retornado

*OSTR*.

### <a name="remarks"></a>Comentários

Essa função insere a *ID* em *OSTR*.

Se dois objetos `thread::id` forem comparados como iguais, as representações de texto inseridas desses objetos serão as mesmas.

## <a name="see-also"></a>Confira também

[\<thread>](../standard-library/thread.md)
