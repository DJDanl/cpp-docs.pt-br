---
title: 'Método Semaphore:: Lock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::Lock
dev_langs:
- C++
helpviewer_keywords:
- Lock method
ms.assetid: 0eef6ede-dc7d-4f09-a6c8-2f7d39d65bfa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 39f2fe48b1e7a1a7c6b875b988d861d5fb48698a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642140"
---
# <a name="semaphorelock-method"></a>Método Semaphore::Lock
Aguarda até que o objeto atual, ou o **semáforo** objeto associado ao identificador especificado, estiver no estado sinalizado ou o intervalo de tempo limite especificado tenha decorrido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLock Lock(  
   DWORD milliseconds = INFINITE  
);  
  
static SyncLock Lock(  
   HANDLE h,  
   DWORD milliseconds = INFINITE  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *milissegundos*  
 O intervalo de tempo limite em milissegundos. O valor padrão é infinito, o que espera indefinidamente.  
  
 *h*  
 Um identificador para um **semáforo** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Um `Details::SyncLockWithStatusT<HandleTraits::SemaphoreTraits>`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe Semaphore](../windows/semaphore-class.md)