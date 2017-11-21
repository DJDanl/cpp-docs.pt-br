---
title: "Método Runtimeclass: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClass::GetRuntimeClassName
dev_langs: C++
helpviewer_keywords: GetRuntimeClassName method
ms.assetid: f6388163-fe65-4948-a4bc-ae6826f480e7
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c82a3ae65ae65dfe43cb0ed645f802161f7a17f6
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="runtimeclassgetruntimeclassname-method"></a>Método RuntimeClass::GetRuntimeClassName

Obtém o nome de classe de tempo de execução do objeto RuntimeClass atual.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*  
Quando a operação for concluída, o nome de classe de tempo de execução.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Um erro de asserção é emitido se &#95; &#95; WRL_STRICT #95; &#95; ou &#95; &#95; WRL_FORCE_INSPECTABLE_CLASS_MACRO #95; &#95; não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Namespace:** Microsoft:: wrl

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)