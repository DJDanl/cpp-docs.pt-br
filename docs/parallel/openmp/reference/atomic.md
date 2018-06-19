---
title: Atomic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- atomic
dev_langs:
- C++
helpviewer_keywords:
- atomic OpenMP directive
ms.assetid: 275e0338-cf2f-4525-97b5-696250000df7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bf6287ff3c44d508a3e4293340e652edb201282f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694401"
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