---
title: Classe is_error_condition_enum | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- system_error/std::is_error_condition_enum
dev_langs:
- C++
helpviewer_keywords:
- is_error_condition_enum class
ms.assetid: 752bb87a-c61c-4304-9254-5aaf228b59c0
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 43959823df01187961fbb9e113160b026e4d31d4
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<system_error>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[<system_error>](../standard-library/system-error.md)<br/>
