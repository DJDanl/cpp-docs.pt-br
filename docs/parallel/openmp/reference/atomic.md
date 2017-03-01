---
title: "atômicos | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- atomic
dev_langs:
- C++
helpviewer_keywords:
- atomic OpenMP directive
ms.assetid: 275e0338-cf2f-4525-97b5-696250000df7
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
ms.openlocfilehash: bda7605e611aeac0e3c03def934acf2303a95d3b
ms.lasthandoff: 02/25/2017

---
# <a name="atomic"></a>atomic
Especifica que um local de memória que será atualizado automaticamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp atomic  
   expression  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `expression`  
 A instrução que contém o l-value cujo local de memória que você deseja proteger contra várias gravações. Para obter mais informações sobre formulários de expressão legal, consulte a especificação de OpenMP.  
  
## <a name="remarks"></a>Comentários  
 A `atomic` diretiva oferece suporte a nenhum cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.6.4 atômica construir](../../../parallel/openmp/2-6-4-atomic-construct.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_atomic.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
#define MAX 10  
  
int main() {  
   int count = 0;  
   #pragma omp parallel num_threads(MAX)  
   {  
      #pragma omp atomic  
      count++;  
   }  
   printf_s("Number of threads: %d\n", count);  
}  
```  
  
```Output  
Number of threads: 10  
```  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)
