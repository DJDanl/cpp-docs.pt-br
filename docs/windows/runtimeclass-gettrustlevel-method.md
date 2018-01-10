---
title: "Método: Gettrustlevel | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClass::GetTrustLevel
dev_langs: C++
helpviewer_keywords: GetTrustLevel method
ms.assetid: bd90407e-6dd7-41c3-9ea0-c402c276014a
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 89a00c052ec1191cd57057f52401954397169b88
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

Um erro de asserção é emitido se &#95; &#95; WRL_STRICT #95; &#95; ou &#95; &#95; WRL_FORCE_INSPECTABLE_CLASS_MACRO #95; &#95; não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Namespace:** Microsoft:: wrl

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)