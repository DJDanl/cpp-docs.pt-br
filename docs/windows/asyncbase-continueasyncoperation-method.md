---
title: 'Método asyncbase:: Continueasyncoperation | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::ContinueAsyncOperation
dev_langs:
- C++
helpviewer_keywords:
- ContinueAsyncOperation method
ms.assetid: ce38181d-2fc3-4579-b0ce-237a3c7648bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a335d379c1797e6152ea1b6011830423082693bb
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648042"
---
# <a name="asyncbasecontinueasyncoperation-method"></a>Método AsyncBase::ContinueAsyncOperation
Determina se a operação assíncrona devam continuar o processamento ou deve parar.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool ContinueAsyncOperation();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o estado atual da operação assíncrona for *iniciado*, que significa que a operação deve continuar. Caso contrário, **falsos**, que significa que a operação deve parar.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)