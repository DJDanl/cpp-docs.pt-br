---
title: Operadores &lt;scoped_allocator&gt;
ms.date: 11/04/2016
f1_keywords:
- scoped_allocator/std::operator!=
- scoped_allocator/std::operator==
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
ms.openlocfilehash: 071fc3b73cd3378b110d6d412bb7575e35a77478
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78876329"
---
# <a name="ltscoped_allocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;

|||
|-|-|
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|

## <a name="op_neq"></a>  operator!=

Testa dois objetos `scoped_allocator_adaptor` quanto à desigualdade.

```cpp
template <class Outer, class... Inner>
bool operator!=(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O objeto `scoped_allocator_adaptor` à esquerda.

\ *à direita*
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor retornado

`!(left == right)`

## <a name="op_eq_eq"></a>  operator==

Testa dois objetos `scoped_allocator_adaptor` quanto à igualdade.

```cpp
template <class Outer, class... Inner>
bool operator==(
    const scoped_allocator_adaptor<Outer, Inner...>& left,
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O objeto `scoped_allocator_adaptor` à esquerda.

\ *à direita*
O objeto `scoped_allocator_adaptor` à direita.

### <a name="return-value"></a>Valor retornado

`left.outer_allocator() == right.outer_allocator() && left.inner_allocator() == right.inner_allocator()`

## <a name="see-also"></a>Consulte também

[<scoped_allocator>](../standard-library/scoped-allocator.md)
