---
title: Atomic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: atomic
dev_langs: C++
helpviewer_keywords: atomic OpenMP directive
ms.assetid: 275e0338-cf2f-4525-97b5-696250000df7
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 92804b2bdcc243bde6e536004cda73d7f5087b1d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="atomic"></a>atomic
Especifica que um local de memória que será atualizado de forma atômica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp atomic  
   expression  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `expression`  
 A instrução que contém o lvalue cujo local de memória que você deseja proteger contra várias gravações. Para obter mais informações sobre os formulários de expressão válido, consulte a especificação de OpenMP.  
  
## <a name="remarks"></a>Comentários  
 O `atomic` diretiva dá suporte a nenhuma cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.6.4 atômico construir](../../../parallel/openmp/2-6-4-atomic-construct.md).  
  
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