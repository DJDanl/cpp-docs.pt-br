---
title: "Método Semaphoretraits: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits::Unlock
dev_langs: C++
helpviewer_keywords: Unlock method
ms.assetid: 4e0ea808-b70d-43f7-81ef-998c3b34e3a0
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 819f7d7e4e4d5b6182da6172bd91a1e799379b52
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="semaphoretraitsunlock-method"></a>Método SemaphoreTraits::Unlock
Controle de versões de um recurso compartilhado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline static void Unlock(  
   _In_ Type h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `h`  
 Identificador de um objeto de semáforo.  
  
## <a name="remarks"></a>Comentários  
 Se a operação de desbloqueio for bem-sucedida, Unlock() emite um erro que indica a causa da falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura SemaphoreTraits](../windows/semaphoretraits-structure.md)