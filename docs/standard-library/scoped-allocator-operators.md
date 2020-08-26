---
title: Operadores &lt;scoped_allocator&gt;
ms.date: 11/04/2016
f1_keywords:
- scoped_allocator/std::operator!=
- scoped_allocator/std::operator==
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
ms.openlocfilehash: 907772069c192b3ef75c7366e079b1da1dd36f8d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846245"
---
# <a name="ltscoped_allocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;

[operador! =](#op_neq)\
[operador = =](#op_eq_eq)

## <a name="operator"></a><a name="op_neq"></a> operador! =

Testa dois objetos `scoped_allocator_adaptor` quanto à desigualdade.

```cpp
template <class Outer, class... Inner>
bool operator!=(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>parâmetros

*mantida*\
O objeto `scoped_allocator_adaptor` à esquerda.

*Certo*\
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor Retornado

`!(left == right)`

## <a name="operator"></a><a name="op_eq_eq"></a> operador = =

Testa dois objetos `scoped_allocator_adaptor` quanto à igualdade.

```cpp
template <class Outer, class... Inner>
bool operator==(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>parâmetros

*mantida*\
O objeto `scoped_allocator_adaptor` à esquerda.

*Certo*\
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor Retornado

`left.outer_allocator() == right.outer_allocator() && left.inner_allocator() == right.inner_allocator()`

## <a name="see-also"></a>Confira também

[<scoped_allocator>](../standard-library/scoped-allocator.md)
