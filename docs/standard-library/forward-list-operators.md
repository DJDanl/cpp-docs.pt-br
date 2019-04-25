---
title: Operadores &lt;forward_list&gt;
ms.date: 11/04/2016
f1_keywords:
- forward_list/std::operator!=
- forward_list/std::operator==
- forward_list/std::operatoroperator&gt;
- forward_list/std::operatoroperator&gt=;
- forward_list/std::operatoroperator&lt;
- forward_list/std::operatoroperator&lt;=
ms.assetid: 57492e09-3836-4dbc-9ae5-78ecf506c190
helpviewer_keywords:
- std::operator!= (forward_list)
- std::operator== (forward_list)
- std::operatoroperator&gt; (forward_list)
- std::operatoroperator&gt=; (forward_list)
- std::operatoroperator&lt; (forward_list)
- std::operatoroperator&lt;= (forward_list)
ms.openlocfilehash: 4126b81f61bd37a7a12e0621c323ec832c5b2ab7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62159425"
---
# <a name="ltforwardlistgt-operators"></a>Operadores &lt;forward_list&gt;

||||
|-|-|-|
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|
|[operator&lt;](#op_lt)|[operator&lt;=](#op_lt_eq)|[operator==](#op_eq_eq)|

## <a name="op_eq_eq"></a>  operator==

Testa se o objeto da lista de encaminhamento à esquerda do operador é igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator==(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="remarks"></a>Comentários

Esta função de modelo sobrecarrega `operator==` para comparar dois objetos da classe de modelo `forward_list`. A função retorna `distance(left.begin(), end()) == distance(right.begin(),right.end()) && equal(left. begin(),left. end(),right.begin())`.

## <a name="op_neq"></a>  operator!=

Testa se o objeto da lista de encaminhamento à esquerda do operador não é igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator!=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="return-value"></a>Valor de retorno

**true** se as listas não forem iguais; **false** se as listas forem iguais.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(left == right)`.

## <a name="op_lt"></a>  operator&lt;

Testa se o objeto da lista de encaminhamento à esquerda do operador é menor que o objeto da lista de encaminhamento à direita.

```cpp
bool operator<(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função de modelo sobrecarrega `operator<` para comparar dois objetos da classe de modelo `forward_list`. A função retorna `lexicographical_compare(lhs. begin(), lhs. end(), rhs.begin(), rhs.end())`.

## <a name="op_lt_eq"></a>  operator&lt;=

Testa se o objeto da lista de encaminhamento à esquerda do operador é menor ou igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator<=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(right < left)`.

## <a name="op_gt"></a>  operator&gt;

Testa se o objeto da lista de encaminhamento à esquerda do operador é maior que o objeto da lista de encaminhamento à direita.

```cpp
bool operator>(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="return-value"></a>Valor de retorno

**true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `right < left`.

## <a name="op_gt_eq"></a>  operator&gt;=

Testa se o objeto da lista de encaminhamento à esquerda do operador é maior ou igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator>=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Um objeto do tipo `forward_list`.|
|*right*|Um objeto do tipo `forward_list`.|

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a lista de encaminhamento no lado esquerdo do operador for maior que ou igual à lista de encaminhamento à direita do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

A função do modelo retorna `!(left < right)`.

## <a name="see-also"></a>Consulte também

[<forward_list>](../standard-library/forward-list.md)<br/>
