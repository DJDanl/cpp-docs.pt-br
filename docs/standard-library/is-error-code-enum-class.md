---
title: Classe is_error_code_enum
ms.date: 11/04/2016
f1_keywords:
- system_error/std::is_error_code_enum
helpviewer_keywords:
- is_error_code_enum class
ms.assetid: cee5be2d-7c20-4cec-a352-1ab8b7d32601
ms.openlocfilehash: d890eb6a1b7c93f9ae5b87018c3bf1d6eeae8abb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62336474"
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

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<system_error>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[<system_error>](../standard-library/system-error.md)<br/>
