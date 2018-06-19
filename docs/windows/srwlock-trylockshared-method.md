---
title: 'Método: Trylockshared | Microsoft Docs'
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
ms.openlocfilehash: 19ff9324f946f48f201678f9c9e7403ba774b2c0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892277"
---
# <a name="srwlocktrylockshared-method"></a>Método SRWLock::TryLockShared
Tenta adquirir um objeto SRWLock no modo compartilhado para o objeto SRWLock especificado ou atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW SyncLockShared TryLockShared();  
WRL_NOTHROW static SyncLockShared TryLockShared(  
   _In_ SRWLOCK* lock  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lock`  
 Ponteiro para um objeto SRWLock.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um objeto de SRWLock no modo compartilhado e o thread de chamada assume a propriedade do bloqueio. Caso contrário, um SRWLock objeto cujo estado é inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe SRWLock](../windows/srwlock-class.md)