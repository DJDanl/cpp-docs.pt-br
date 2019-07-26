---
title: Classe is_trivially_destructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_destructible
helpviewer_keywords:
- is_trivially_destructible
ms.assetid: 3f7a787d-2448-40c5-ac51-a228318e02ce
ms.openlocfilehash: 6a978b7cc32e6de3d4b1d811b9aa6f52cf0370d7
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459632"
---
# <a name="istriviallydestructible-class"></a>Classe is_trivially_destructible

Testa se o tipo é comumente destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_destructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for um tipo destrutíveis e o destruidor for conhecido pelo compilador para não usar nenhuma operação trivial. Caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
