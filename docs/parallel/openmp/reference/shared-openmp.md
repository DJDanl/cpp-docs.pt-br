---
title: compartilhado (OpenMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Shared
dev_langs:
- C++
helpviewer_keywords:
- shared OpenMP clause
ms.assetid: 7887dc95-67a2-462f-a3a2-8e0632bf5d04
caps.latest.revision: 7
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
ms.openlocfilehash: 2ae11e15a3116b47966746fa550e14848b568161
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="shared-openmp"></a>shared (OpenMP)
Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
shared(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 Variáveis mais um compartilhamento. Se mais de uma variável for especificada, separe os nomes de variáveis com uma vírgula.  
  
## <a name="remarks"></a>Comentários  
 Outra maneira de compartilhar variáveis entre threads é com o [copyprivate](../../../parallel/openmp/reference/copyprivate.md) cláusula.  
  
 `shared`aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [paralelo](../../../parallel/openmp/reference/parallel.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.4 compartilhado](../../../parallel/openmp/2-7-2-4-shared.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [particular](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `shared`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
