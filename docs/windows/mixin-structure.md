---
title: Estrutura MixIn | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::MixIn
dev_langs: C++
helpviewer_keywords: MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 883e952dde579cce3f5a65ba4a453f98ddbb4740
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mixin-structure"></a>Estrutura MixIn
Garante que uma classe de tempo de execução deriva de tempo de execução do Windows, se houver e a clássico, em seguida, COM interfaces.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename Derived,  
   typename MixInType,  
   bool hasImplements = __is_base_of(Details::ImplementsBase,  
   MixInType)  
>  
struct MixIn;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Derived`  
 Um tipo derivado de [implementa](../windows/implements-structure.md) estrutura.  
  
 `MixInType`  
 Um tipo base.  
  
 `hasImplements`  
 `true`Se `MixInType` é derivado do tipo base; a implementação atual `false` caso contrário.  
  
## <a name="remarks"></a>Comentários  
 Se uma classe é derivada de tempo de execução do Windows e interfaces de classe COM, a lista de declaração de classe deve listar primeiro as interfaces de tempo de execução do Windows e, em seguida, qualquer clássico COM interfaces. Mesclado assegura que as interfaces são especificadas na ordem correta.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `MixIn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)