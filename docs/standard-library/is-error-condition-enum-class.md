---
title: Classe is_error_condition_enum
ms.date: 11/04/2016
f1_keywords:
- system_error/std::is_error_condition_enum
helpviewer_keywords:
- is_error_condition_enum class
ms.assetid: 752bb87a-c61c-4304-9254-5aaf228b59c0
ms.openlocfilehash: c40f8f6eb93a33098cfbcf8133f08c56285abb43
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452598"
---
# <a name="iserrorconditionenum-class"></a>Classe is_error_condition_enum

Representa um predicado de tipo que testa a enumeração [error_condition](../standard-library/error-condition-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <_Enum>
    class is_error_condition_enum;
```

## <a name="remarks"></a>Comentários

Uma instância deste [predicado de tipo](../standard-library/type-traits.md) será verdadeira se o tipo `_Enum` for um valor de enumeração adequado para o armazenamento em um objeto do tipo `error_condition`.

É permitido adicionar especializações a este tipo para tipos definidos pelo usuário.

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
