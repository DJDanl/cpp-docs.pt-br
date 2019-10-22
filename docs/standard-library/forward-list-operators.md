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
ms.openlocfilehash: 1ddfb56c7ff68ec10c7bb56af3495e4042acb83c
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689681"
---
# <a name="ltforward_listgt-operators"></a>Operadores &lt;forward_list&gt;

## <a name="op_eq_eq"></a>operador = =

Testa se o objeto da lista de encaminhamento à esquerda do operador é igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator==(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="remarks"></a>Comentários

Essa função de modelo sobrecarrega `operator==` para comparar dois objetos do modelo de classe `forward_list`. A função retorna `distance(left.begin(), end()) == distance(right.begin(),right.end()) && equal(left. begin(),left. end(),right.begin())`.

## <a name="op_neq"></a>operador! =

Testa se o objeto da lista de encaminhamento à esquerda do operador não é igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator!=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="return-value"></a>Valor retornado

**true** se as listas não forem iguais; **false** se as listas forem iguais.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(left == right)`.

## <a name="op_lt">Operador </a>&lt;

Testa se o objeto da lista de encaminhamento à esquerda do operador é menor que o objeto da lista de encaminhamento à direita.

```cpp
bool operator<(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Essa função de modelo sobrecarrega `operator<` para comparar dois objetos do modelo de classe `forward_list`. A função retorna `lexicographical_compare(lhs. begin(), lhs. end(), rhs.begin(), rhs.end())`.

## <a name="op_lt_eq"></a>= de &lt; do operador

Testa se o objeto da lista de encaminhamento à esquerda do operador é menor ou igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator<=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `!(right < left)`.

## <a name="op_gt">Operador </a>&gt;

Testa se o objeto da lista de encaminhamento à esquerda do operador é maior que o objeto da lista de encaminhamento à direita.

```cpp
bool operator>(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="return-value"></a>Valor retornado

**true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta função do modelo retorna `right < left`.

## <a name="op_gt_eq"></a>= de &gt; do operador

Testa se o objeto da lista de encaminhamento à esquerda do operador é maior ou igual ao objeto da lista de encaminhamento à direita.

```cpp
bool operator>=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
Um objeto do tipo `forward_list`.

\ *à direita*
Um objeto do tipo `forward_list`.

### <a name="return-value"></a>Valor retornado

**true** se a lista de encaminhamentos no lado esquerdo do operador for maior ou igual à lista de encaminhamento no lado direito do operador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A função do modelo retorna `!(left < right)`.
