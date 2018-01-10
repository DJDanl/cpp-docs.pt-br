---
title: "Método CriticalSection: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::CriticalSection::Lock
dev_langs: C++
helpviewer_keywords: Lock method
ms.assetid: 37cb184c-e13c-49ef-b6a0-13908a956414
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: af996faeebd0fcddb85993badd71ceecd32d494e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="criticalsectionlock-method"></a>Método CriticalSection::Lock
Esperas de propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLock Lock();  
  
   static SyncLock Lock(  
   _In_ CRITICAL_SECTION* cs  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cs`  
 Um objeto de seção crítica especificado pelo usuário.  
  
## <a name="return-value"></a>Valor de retorno  
 Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.  
  
## <a name="remarks"></a>Comentários  
 A primeira **bloqueio** function afeta o objeto atual da seção crítica. A segunda **bloqueio** function afeta uma seção crítica especificado pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe CriticalSection](../windows/criticalsection-class.md)