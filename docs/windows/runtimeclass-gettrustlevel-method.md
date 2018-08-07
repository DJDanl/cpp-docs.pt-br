---
title: 'Método runtimeclass:: Gettrustlevel | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetTrustLevel
dev_langs:
- C++
helpviewer_keywords:
- GetTrustLevel method
ms.assetid: bd90407e-6dd7-41c3-9ea0-c402c276014a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 98bd73d2c067e6d5bbb4425782de594bbaa47bc1
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606618"
---
# <a name="runtimeclassgettrustlevel-method"></a>Método RuntimeClass::GetTrustLevel

Obtém o nível de confiança do atual **RuntimeClass** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetTrustLevel)(
    _Out_ TrustLevel* trustLvl
);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*  
Quando essa operação for concluída, o nível de confiança do atual **RuntimeClass** objeto.

## <a name="return-value"></a>Valor de retorno

Sempre S_OK.

## <a name="remarks"></a>Comentários

Um erro de asserção é emitido se &#95; &#95;WRL_STRICT&#95; &#95; ou &#95; &#95;WRL_FORCE_INSPECTABLE_CLASS_MACRO&#95; &#95; não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
 [Classe RuntimeClass](../windows/runtimeclass-class.md)