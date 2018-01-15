---
title: "Método Criticalsectiontraits: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue
dev_langs: C++
helpviewer_keywords: GetInvalidValue method
ms.assetid: 665f30a6-ca9c-4968-8c03-8f84e6b2329b
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 55bf0dedc286ed5dac8f48c7e8a2d43aa7741eff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="criticalsectiontraitsgetinvalidvalue-method"></a>Método CriticalSectionTraits::GetInvalidValue
Um modelo CriticalSection é especializada para que o modelo sempre é inválido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline static Type GetInvalidValue();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Sempre retorna um ponteiro para uma seção crítica inválida.  
  
## <a name="remarks"></a>Comentários  
 O *tipo* modificador é definido como `typedef CRITICAL_SECTION* Type;`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)