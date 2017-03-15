---
title: "padrão (OpenMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- default
dev_langs:
- C++
helpviewer_keywords:
- default OpenMP clause
- defaults, OpenMP clause
ms.assetid: 96055106-a8f0-40b3-8319-e412b6e07bf8
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f8baba165470a7f4ae4b1528966655aafb0f08f4
ms.lasthandoff: 02/25/2017

---
# <a name="default-openmp"></a>default (OpenMP)
Especifica o comportamento de variáveis sem escopo em uma região paralela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
default(shared | none)  
```  
  
## <a name="remarks"></a>Comentários  
 `shared`, que está em vigor se o `default` cláusula não for especificada, significa que qualquer variável em uma região paralela será tratada como se ele tiver sido especificado com o [compartilhado](../../../parallel/openmp/reference/shared-openmp.md) cláusula. `none`significa que todas as variáveis usadas em uma região paralela que não estão no escopo com o [particular](../../../parallel/openmp/reference/private-openmp.md), [compartilhado](../../../parallel/openmp/reference/shared-openmp.md), [redução](../../../parallel/openmp/reference/reduction.md), [firstprivate](../../../parallel/openmp/reference/firstprivate.md), ou [lastprivate](../../../parallel/openmp/reference/lastprivate.md) cláusula causará um erro do compilador.  
  
 `default`aplica-se para as seguintes diretivas:  
  
-   [paralelo](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.5 padrão](../../../parallel/openmp/2-7-2-5-default.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [particular](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `default`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
