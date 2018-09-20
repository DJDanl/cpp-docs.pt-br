---
title: Operador hstringreference::&lt; operador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator<
dev_langs:
- C++
ms.assetid: 55aa48e8-7c96-4123-9ebe-42b4cd8b9377
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 17acdca8af1250b1f88fa8a6858ffa1854f8ca8c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426400"
---
# <a name="hstringreferenceoperatorlt-operator"></a>Operador hstringreference::&lt; operador

Indica se o primeiro parâmetro é menor do que o segundo parâmetro.

## <a name="syntax"></a>Sintaxe

```cpp
inline bool operator<(
    const HStringReference& lhs,
    const HStringReference& rhs) throw()  
```

### <a name="parameters"></a>Parâmetros

*LHS*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma referência a um **HStringReference**.

*rhs*<br/>
O segundo parâmetro a ser comparado.  *rhs* pode ser uma referência a um **HStringReference**.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* parâmetro é menor do que o *rhs* parâmetro; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HStringReference](../windows/hstringreference-class.md)