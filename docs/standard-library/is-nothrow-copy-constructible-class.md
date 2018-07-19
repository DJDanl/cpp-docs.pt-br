---
title: Classe is_nothrow_copy_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_nothrow_copy_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_copy_constructible
ms.assetid: f13a0bea-63b1-492a-9a45-d445df35c282
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc4f839ed955048b96f6327c63cd2cc82fef8aca
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953765"
---
# <a name="isnothrowcopyconstructible-class"></a>Classe is_nothrow_copy_constructible

Testa se o tipo tem um construtor de cópia **nothrow**.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_nothrow_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* tem um nothrow; construtor de cópia, caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
