---
title: "único | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Single
dev_langs:
- C++
helpviewer_keywords:
- single OpenMP directive
ms.assetid: 85cf94fb-cb9c-4d82-8609-adffa9f552e1
caps.latest.revision: 11
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
ms.openlocfilehash: 7a353009983e0b5a96065fc094dabc0a4afb89e6
ms.lasthandoff: 02/25/2017

---
# <a name="single"></a>single
Permite especificar que uma seção de código deve ser executada em um único thread, não necessariamente o thread principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp single [clauses]   
{  
   code_block   
}  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clause` (opcional)  
 Zero ou mais cláusulas. Consulte a seção de comentários para obter uma lista das cláusulas de suporte **único**.  
  
## <a name="remarks"></a>Comentários  
 O **único** diretiva suporta as seguintes cláusulas OpenMP:  
  
-   [copyprivate](../../../parallel/openmp/reference/copyprivate.md)  
  
-   [firstprivate](../../../parallel/openmp/reference/firstprivate.md)  
  
-   [nowait](../../../parallel/openmp/reference/nowait.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
 O [mestre](../../../parallel/openmp/reference/master.md) diretiva permite especificar que uma seção de código deve ser executada somente no thread principal.  
  
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
