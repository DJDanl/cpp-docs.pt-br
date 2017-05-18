---
title: barreira | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- barrier
dev_langs:
- C++
helpviewer_keywords:
- barrier OpenMP directive
ms.assetid: 5c73ad4f-c768-443a-8f9e-4fd8bc2253c7
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0a88f6b3d84476f22f54d3e48668616de118e698
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="barrier"></a>barrier
Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp barrier  
```  
  
## <a name="remarks"></a>Comentários  
 A `barrier` diretiva oferece suporte a nenhum cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.6.3 diretiva barrier](../../../parallel/openmp/2-6-3-barrier-directive.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo de como usar `barrier`, consulte [mestre](../../../parallel/openmp/reference/master.md).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
