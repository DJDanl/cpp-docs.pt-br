---
title: 'Método SRWLOCK:: Trylockshared | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockShared
dev_langs:
- C++
helpviewer_keywords:
- TryLockShared method
ms.assetid: 10cc198d-39a0-4d18-aa78-706744948668
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 289fa1fbec61140e213bef7219e440c8177e19e5
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645806"
---
# <a name="srwlocktrylockshared-method"></a>Método SRWLock::TryLockShared
Tenta adquirir um **SRWLock** objeto no modo compartilhado para o atual ou especificada **SRWLock** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW SyncLockShared TryLockShared();  
WRL_NOTHROW static SyncLockShared TryLockShared(  
   _In_ SRWLOCK* lock  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lock*  
 Ponteiro para um **SRWLock** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, uma **SRWLock** objeto no modo compartilhado e o thread de chamada assume a propriedade do bloqueio. Caso contrário, uma **SRWLock** objeto cujo estado é inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)