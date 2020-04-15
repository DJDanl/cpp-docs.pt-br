---
title: Operadores &lt;scoped_allocator&gt;
ms.date: 11/04/2016
f1_keywords:
- scoped_allocator/std::operator!=
- scoped_allocator/std::operator==
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
ms.openlocfilehash: 45da89793c3f4ea131404fc3392413e7aea9ef3e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373389"
---
# <a name="ltscoped_allocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;

|||
|-|-|
|[operador!=](#op_neq)|[operador==](#op_eq_eq)|

## <a name="operator"></a><a name="op_neq"></a>operador!=

Testa dois objetos `scoped_allocator_adaptor` quanto à desigualdade.

```cpp
template <class Outer, class... Inner>
bool operator!=(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `scoped_allocator_adaptor` à esquerda.

*Certo*\
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor retornado

`!(left == right)`

## <a name="operator"></a><a name="op_eq_eq"></a>operador==

Testa dois objetos `scoped_allocator_adaptor` quanto à igualdade.

```cpp
template <class Outer, class... Inner>
bool operator==(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto `scoped_allocator_adaptor` à esquerda.

*Certo*\
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor retornado

`left.outer_allocator() == right.outer_allocator() && left.inner_allocator() == right.inner_allocator()`

## <a name="see-also"></a>Confira também

[<>scoped_allocator](../standard-library/scoped-allocator.md)
