---
title: "Método Criticalsectiontraits: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock
dev_langs: C++
helpviewer_keywords: Unlock method
ms.assetid: 8fb382f5-6eda-407e-9673-71d77bda4962
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f9880364c24b1e2e5889e9e9e2666683c2237f7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="criticalsectiontraitsunlock-method"></a>Método CriticalSectionTraits::Unlock
Um modelo CriticalSection é especializada para que ele dá suporte à propriedade liberar do objeto especificado de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline static void Unlock(  
   _In_ Type cs  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cs`  
 Um ponteiro para um objeto de seção crítica.  
  
## <a name="remarks"></a>Comentários  
 O *tipo* modificador é definido como `typedef CRITICAL_SECTION* Type;`.  
  
 Para obter mais informações, consulte "LeaveCriticalSection função" na seção "Funções de sincronização" a documentação da API do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)