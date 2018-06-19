---
title: 'Método Asyncbase: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::CurrentStatus
dev_langs:
- C++
helpviewer_keywords:
- CurrentStatus method
ms.assetid: 26ee4c4a-6525-4a5f-b49c-3ca40c365eb6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 75b9a07fd88caa9db7f2f145069b0d8857b79fe9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33859684"
---
# <a name="asyncbasecurrentstatus-method"></a>Método AsyncBase::CurrentStatus
Recupera o status da operação assíncrona atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline void CurrentStatus(  
   Details::AsyncStatusInternal *status  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `status`  
 O local em que essa operação armazena o status atual.  
  
## <a name="remarks"></a>Comentários  
 Esta operação é thread-safe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)   
 [Enumeração AsyncStatusInternal](../windows/asyncstatusinternal-enumeration.md)