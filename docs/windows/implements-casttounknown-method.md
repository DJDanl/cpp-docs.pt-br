---
title: 'Método Implements:: casttounknown | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements::CastToUnknown
dev_langs:
- C++
helpviewer_keywords:
- CastToUnknown method
ms.assetid: ca3324f7-4136-406b-8698-7389f4f3d3c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 988580a34c030c84c50adfff2741408be4b249cd
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42586352"
---
# <a name="implementscasttounknown-method"></a>Método Implements::CastToUnknown

Obtém um ponteiro para subjacente `IUnknown` interface.

## <a name="syntax"></a>Sintaxe

```cpp
__forceinline IUnknown* CastToUnknown();
```

## <a name="return-value"></a>Valor de retorno

Essa operação for bem-sucedida e retornar sempre o `IUnknown` ponteiro.

## <a name="remarks"></a>Comentários

Função auxiliar interno.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Estrutura Implements](../windows/implements-structure.md)