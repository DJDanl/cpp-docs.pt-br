---
title: Classe is_lvalue_reference
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_lvalue_reference
helpviewer_keywords:
- is_lvalue_reference class
- is_lvalue_reference
ms.assetid: 7f11896b-935c-4de1-9c87-9d0127f904e2
ms.openlocfilehash: e032522e790b7027886ba1a6199ed7fdf86c0936
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351937"
---
# <a name="islvaluereference-class"></a>Classe is_lvalue_reference

Testa se o tipo é uma referência lvalue.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_lvalue_reference;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância deste predicado de tipo será verdadeira se o tipo *Ty* é uma referência a um objeto ou a uma função, caso contrário, será falsa. Observe que *Ty* pode não ser uma referência de rvalue. Para obter mais informações sobre rvalues, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md)<br/>
