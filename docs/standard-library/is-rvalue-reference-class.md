---
title: Classe is_rvalue_reference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_rvalue_reference
dev_langs:
- C++
helpviewer_keywords:
- is_rvalue_reference class
- is_rvalue_reference
ms.assetid: 40a97072-7b5c-4274-9154-298d3dcf064a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: acba0f78df8cc537aecd5d2fc33380e4674e5721
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38956915"
---
# <a name="isrvaluereference-class"></a>Classe is_rvalue_reference

Testa se o tipo é uma referência rvalue.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_rvalue_reference;
```

### <a name="parameters"></a>Parâmetros

*Ty* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância deste predicado de tipo será verdadeira se o tipo *Ty* é um [referência de rvalue](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md)<br/>
