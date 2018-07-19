---
title: Operadores &lt;scoped_allocator&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- scoped_allocator/std::operator!=
- scoped_allocator/std::operator==
dev_langs:
- C++
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
ms.openlocfilehash: c2c61e3fce5d1cf58f59bc9dd51920bccc0eb2f3
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38966466"
---
# <a name="ltscopedallocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;

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

*Esquerda* esquerda `scoped_allocator_adaptor` objeto.

*À direita* direita `scoped_allocator_adaptor` objeto.

### <a name="return-value"></a>Valor de retorno

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

*Esquerda* esquerda `scoped_allocator_adaptor` objeto.

*À direita* direita `scoped_allocator_adaptor` objeto.

### <a name="return-value"></a>Valor de retorno

`left.outer_allocator() == right.outer_allocator() && left.inner_allocator() == right.inner_allocator()`

## <a name="see-also"></a>Consulte também

[<scoped_allocator>](../standard-library/scoped-allocator.md)<br/>
