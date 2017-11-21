---
title: "único | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Single
dev_langs: C++
helpviewer_keywords: single OpenMP directive
ms.assetid: 85cf94fb-cb9c-4d82-8609-adffa9f552e1
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 898a175963698d1f44f90f08c21015a765892017
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="single"></a>single
Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp single [clauses]   
{  
   code_block   
}  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clause` (opcional)  
 Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas de suporte **único**.  
  
## <a name="remarks"></a>Comentários  
 O **único** diretiva suporta as seguintes cláusulas OpenMP:  
  
-   [copyprivate](../../../parallel/openmp/reference/copyprivate.md)  
  
-   [firstprivate](../../../parallel/openmp/reference/firstprivate.md)  
  
-   [nowait](../../../parallel/openmp/reference/nowait.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
 O [mestre](../../../parallel/openmp/reference/master.md) diretiva permite que você especifique que uma seção de código deve ser executada somente no thread principal.  
  
 Para obter mais informações, consulte [2.4.3 único construir](../../../parallel/openmp/2-4-3-single-construct.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_single.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
int main() {  
   #pragma omp parallel num_threads(2)  
   {  
      #pragma omp single  
      // Only a single thread can read the input.  
      printf_s("read input\n");  
  
      // Multiple threads in the team compute the results.  
      printf_s("compute results\n");  
  
      #pragma omp single  
      // Only a single thread can write the output.  
      printf_s("write output\n");  
    }  
}  
```  
  
```Output  
read input  
compute results  
compute results  
write output  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)