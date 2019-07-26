---
title: Classe is_error_code_enum
ms.date: 11/04/2016
f1_keywords:
- system_error/std::is_error_code_enum
helpviewer_keywords:
- is_error_code_enum class
ms.assetid: cee5be2d-7c20-4cec-a352-1ab8b7d32601
ms.openlocfilehash: 4080c62034b224a9553eca2787aa1c2f2cf69ab8
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454619"
---
# <a name="iserrorcodeenum-class"></a>Classe is_error_code_enum

Representa um predicado de tipo que testa a enumeração [error_code](../standard-library/error-code-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <_Enum>
    class is_error_code_enum;
```

## <a name="remarks"></a>Comentários

Uma instância deste [predicado de tipo](../standard-library/type-traits.md) será verdadeira se o tipo `_Enum` for um valor de enumeração adequado para o armazenamento em um objeto do tipo `error_code`.

É permitido adicionar especializações a este tipo para tipos definidos pelo usuário.

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
