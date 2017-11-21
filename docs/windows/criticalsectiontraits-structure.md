---
title: Estrutura CriticalSectionTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits
dev_langs: C++
helpviewer_keywords: CriticalSectionTraits structure
ms.assetid: c515a1b5-4eb0-40bc-9035-c4d9352c9de7
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 95428e0513193c78f135157b09a354e050014f23
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="criticalsectiontraits-structure"></a>Estrutura CriticalSectionTraits
É o especialista de um objeto CriticalSection para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CriticalSectionTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Type`|Um `typedef` que define um ponteiro para uma seção crítica. `Type`é definido como `typedef CRITICAL_SECTION* Type;`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método CriticalSectionTraits::GetInvalidValue](../windows/criticalsectiontraits-getinvalidvalue-method.md)|Um modelo CriticalSection é especializada para que o modelo sempre é inválido.|  
|[Método CriticalSectionTraits::Unlock](../windows/criticalsectiontraits-unlock-method.md)|Um modelo CriticalSection é especializada para que ele dá suporte à propriedade liberar do objeto especificado de seção crítica.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CriticalSectionTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)