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
ms.openlocfilehash: 28a9ab0661140f59946fadb7ed6492f222429e9d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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