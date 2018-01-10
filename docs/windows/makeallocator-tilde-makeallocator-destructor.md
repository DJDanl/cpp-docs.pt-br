---
title: 'MakeAllocator:: ~ MakeAllocator destruidor | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::MakeAllocator::~MakeAllocator
dev_langs: C++
helpviewer_keywords: ~MakeAllocator, destructor
ms.assetid: f1299c5f-cc6b-4d4e-85d4-aee1be0e2b0a
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b56dd9c45aee094d32acb654e32cf5f24a3beb10
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="makeallocatormakeallocator-destructor"></a>Destruidor MakeAllocator::~MakeAllocator
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
~MakeAllocator();  
```  
  
## <a name="remarks"></a>Comentários  
 Deinitializes a instância atual da classe MakeAllocator.  
  
 Este destruidor também exclui a memória alocada subjacente, se necessário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe MakeAllocator](../windows/makeallocator-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)