---
title: 'Método WeakReference:: Decrementstrongreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::DecrementStrongReference
dev_langs:
- C++
helpviewer_keywords:
- DecrementStrongReference method
ms.assetid: 97d70d9f-41b8-4f8d-a6fa-4137cc4f9029
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b3620a4b82aabb0058773f68938f545119f90791
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605592"
---
# <a name="weakreferencedecrementstrongreference-method"></a>Método WeakReference::DecrementStrongReference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
ULONG DecrementStrongReference();
```

## <a name="remarks"></a>Comentários

Diminui a contagem de referência forte do atual **WeakReference** objeto.

Quando a contagem de referência forte se torna zero, a referência forte é definida como **nullptr**.

## <a name="return-value"></a>Valor de retorno

A contagem de referência forte decrementado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe WeakReference](../windows/weakreference-class1.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)