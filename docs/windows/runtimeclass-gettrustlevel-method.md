---
title: 'Método: Gettrustlevel | Microsoft Docs'
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
ms.openlocfilehash: bc588950cc8752a7c2b8e1ddf00b2193aaf0f395
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="runtimeclassgettrustlevel-method"></a>Método RuntimeClass::GetTrustLevel

Obtém o nível de confiança do objeto RuntimeClass atual.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetTrustLevel)(
    _Out_ TrustLevel* trustLvl
);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*  
Quando essa operação for concluída, o nível de confiança do objeto RuntimeClass atual.

## <a name="return-value"></a>Valor de retorno

Sempre S_OK.

## <a name="remarks"></a>Comentários

Um erro de asserção é emitido se &#95; &#95;WRL_STRICT&#95; &#95; ou &#95; &#95;WRL_FORCE_INSPECTABLE_CLASS_MACRO&#95; &#95; não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)