---
title: "Método: Trylockexclusive | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive
dev_langs: C++
helpviewer_keywords: TryLockExclusive method
ms.assetid: 661e8b19-3058-4511-8742-c9fbb90412c7
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ebeaae465bd387d3939f9588be3c4a8e5eaf507b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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