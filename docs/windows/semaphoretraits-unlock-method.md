---
title: 'Método Semaphoretraits: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits::Unlock
dev_langs:
- C++
helpviewer_keywords:
- Unlock method
ms.assetid: 4e0ea808-b70d-43f7-81ef-998c3b34e3a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0914c6ff83e881f92963fc8a548ddeff587db75e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892241"
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