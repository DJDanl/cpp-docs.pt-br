---
title: 'Método mutex:: Lock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Lock
dev_langs:
- C++
helpviewer_keywords:
- Lock method
ms.assetid: 61d95072-b690-441e-a080-0bf94a733141
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c96ef497331fecf8125c51a7b8bd669ec758927
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39603518"
---
# <a name="mutexlock-method"></a>Método Mutex::Lock
Aguarda até que o objeto atual, ou o **Mutex** objeto associado ao identificador especificado, versões mutex ou o intervalo de tempo limite especificado tiver decorrido.  
  
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
 O identificador de um **Mutex** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](../windows/mutex-class1.md)