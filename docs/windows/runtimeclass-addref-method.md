---
title: 'Método runtimeclass:: AddRef | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::AddRef
dev_langs:
- C++
helpviewer_keywords:
- AddRef method
ms.assetid: 9c705749-680b-4308-bbec-5b601e8e7dbd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3a2f7025d9e367c2a31d14012d9f6b22de3e70f2
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011706"
---
# <a name="runtimeclassaddref-method"></a>Método RuntimeClass::AddRef
Incrementa a contagem de referência para o atual **RuntimeClass** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD_(  
   ULONG,  
   AddRef  
)();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)