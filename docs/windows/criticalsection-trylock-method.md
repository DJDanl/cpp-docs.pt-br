---
title: "Método: Trylock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::TryLock
dev_langs:
- C++
helpviewer_keywords:
- TryLock method
ms.assetid: 504bb87c-2cd0-4f54-b458-b3efb9789053
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f2bd717e3a91d2e0210adced36e33a89f3752fa8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="criticalsectiontrylock-method"></a>Método CriticalSection::TryLock
As tentativas de inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLock TryLock();  
  
static SyncLock TryLock(  
   _In_ CRITICAL_SECTION* cs  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cs`  
 Um objeto de seção crítica especificado pelo usuário.  
  
## <a name="return-value"></a>Valor de retorno  
 Um valor diferente de zero se a seção crítica for inserida com êxito ou o thread atual já possui a seção crítica. Zero se outro thread já possui a seção crítica.  
  
## <a name="remarks"></a>Comentários  
 A primeira **TryLock** function afeta o objeto atual da seção crítica. A segunda **TryLock** function afeta uma seção crítica especificado pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe CriticalSection](../windows/criticalsection-class.md)