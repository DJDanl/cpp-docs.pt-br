---
title: 'Método SRWLOCK:: Trylockexclusive | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive
dev_langs:
- C++
helpviewer_keywords:
- TryLockExclusive method
ms.assetid: 661e8b19-3058-4511-8742-c9fbb90412c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 993031604469aa09608f936f260869a3b53dbc9c
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652764"
---
# <a name="srwlocktrylockexclusive-method"></a>Método SRWLock::TryLockExclusive
Tenta adquirir um **SRWLock** objeto no modo exclusivo para o atual ou especificada **SRWLock** objeto. Se a chamada for bem-sucedida, o thread de chamada assume a propriedade do bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLockExclusive TryLockExclusive();  
  
static SyncLockExclusive TryLockExclusive(  
   _In_ SRWLOCK* lock  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lock*  
 Ponteiro para um **SRWLock** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, uma **SRWLock** objeto no modo exclusivo e o thread de chamada assume a propriedade do bloqueio. Caso contrário, uma **SRWLock** objeto cujo estado é inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)