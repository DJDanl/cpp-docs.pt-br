---
title: 'Método runtimeclass:: Getweakreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetWeakReference
dev_langs:
- C++
helpviewer_keywords:
- GetWeakReference method
ms.assetid: 26656ace-7f20-4364-87c9-4a75dd30912e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bb0d5e6ca19749a4647ec85311e1fce0e7561b59
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39608528"
---
# <a name="runtimeclassgetweakreference-method"></a>Método RuntimeClass::GetWeakReference
Obtém um ponteiro para o objeto de referência fraca para a atual **RuntimeClass** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   GetWeakReference  
)(_Deref_out_ IWeakReference **weakReference);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *weakReference*  
 Quando essa operação for concluída, um ponteiro para um objeto de referência fraca.  
  
## <a name="return-value"></a>Valor de retorno  
 Sempre S_OK.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)