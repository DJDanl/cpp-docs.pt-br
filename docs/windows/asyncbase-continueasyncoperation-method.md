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
ms.openlocfilehash: e7b5d2b10b571a3517beab98eaa839d5c7fd86c2
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39460827"
---
# <a name="asyncbasecontinueasyncoperation-method"></a>Método AsyncBase::ContinueAsyncOperation
Determina se a operação assíncrona devam continuar o processamento ou deve parar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline bool ContinueAsyncOperation();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o estado atual da operação assíncrona for *iniciado*, que significa que a operação deve continuar. Caso contrário, **falsos**, que significa que a operação deve parar.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)