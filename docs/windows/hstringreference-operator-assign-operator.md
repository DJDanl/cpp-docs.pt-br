---
title: 'Operador hstringreference:: Operator = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator=
dev_langs:
- C++
ms.assetid: ea100ed3-e566-4c9e-b6a8-f296088dea9c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7045229cc15304a88253f97e1ad3c9f171f139a0
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42597122"
---
# <a name="hstringreferenceoperator-operator"></a>Operador HStringReference::Operator=

Move o valor de outro **HStringReference** objeto atual **HStringReference** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
HStringReference& operator=(HStringReference&& other) throw()  
```

### <a name="parameters"></a>Parâmetros

*other*  
Um existente **HStringReference** objeto.

## <a name="remarks"></a>Comentários

O valor de existente *outras* objeto é copiado para a atual **HStringReference** objeto e, em seguida, o *outros* objeto é destruído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HStringReference](../windows/hstringreference-class.md)