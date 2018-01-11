---
title: compartilhado (OpenMP) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Shared
dev_langs: C++
helpviewer_keywords: shared OpenMP clause
ms.assetid: 7887dc95-67a2-462f-a3a2-8e0632bf5d04
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 26f8618a0340216215c3432576b6adbba3e70f80
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 Um mais mais variáveis para compartilhar. Se mais de uma variável for especificada, separe os nomes de variável com uma vírgula.  
  
## <a name="remarks"></a>Comentários  
 Outra maneira de compartilhar variáveis entre threads é com o [copyprivate](../../../parallel/openmp/reference/copyprivate.md) cláusula.  
  
 `shared`aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.4 compartilhado](../../../parallel/openmp/2-7-2-4-shared.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [privada](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `shared`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)