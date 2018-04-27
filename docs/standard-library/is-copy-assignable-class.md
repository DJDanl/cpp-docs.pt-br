---
title: Classe is_copy_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_copy_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_copy_assignable
ms.assetid: 3ae6bca1-85fb-4829-9ee9-0183b081ff50
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e6d5d2b6a44805b552b18d82479740fb909baf74
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="iscopyassignable-class"></a>Classe is_copy_assignable

Teste se o tipo pode ser copiado na atribuição.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe com um operador de atribuição de cópia; caso contrário, será falsa. Equivalente a is_assignable\<Ty&, const Ty&>.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
