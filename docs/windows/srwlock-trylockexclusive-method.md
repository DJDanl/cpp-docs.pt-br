---
title: 'Método: Trylockexclusive | Microsoft Docs'
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
ms.openlocfilehash: 1cc9ee8a63d7403c3de408c924eeab07f1d0efa1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892651"
---
# <a name="srwlocktrylockexclusive-method"></a>Método SRWLock::TryLockExclusive
Tenta adquirir um objeto SRWLock em modo exclusivo para o objeto SRWLock especificado ou atual. Se a chamada for bem-sucedida, o thread de chamada assume a propriedade do bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLockExclusive TryLockExclusive();  
  
static SyncLockExclusive TryLockExclusive(  
   _In_ SRWLOCK* lock  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lock`  
 Ponteiro para um objeto SRWLock.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um objeto de SRWLock no modo exclusivo e o thread de chamada assume a propriedade do bloqueio. Caso contrário, um SRWLock objeto cujo estado é inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)