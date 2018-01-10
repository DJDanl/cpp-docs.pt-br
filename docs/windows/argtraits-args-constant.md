---
title: 'Constante argtraits:: args | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: event/Microsoft::WRL::Details::ArgTraits::args
dev_langs: C++
helpviewer_keywords: args constant
ms.assetid: a68100ab-254b-4571-a0bc-946f1633a46b
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: baf5f0fa0e95498f677615802b250b56fd94afec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="argtraitsargs-constant"></a>Constante ArgTraits::args
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const int args = -1; ;  
```  
  
## <a name="remarks"></a>Comentários  
 Mantém a contagem do número de parâmetros no método Invoke de uma interface de delegado.  
  
## <a name="remarks"></a>Comentários  
 Quando `args` é igual a -1 indica que não pode haver nenhuma correspondência para a assinatura do método Invoke.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ArgTraits](../windows/argtraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)