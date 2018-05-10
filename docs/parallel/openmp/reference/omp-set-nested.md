---
title: omp_set_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_set_nested
dev_langs:
- C++
helpviewer_keywords:
- omp_set_nested OpenMP function
ms.assetid: fa1cb08c-7b8b-42c9-8654-2c33dcffb5b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6539167b936efdc4c9f407cd951c9c582b0a138
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ompsetnested"></a>omp_set_nested
Permitir o paralelismo aninhado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void omp_set_nested(  
   int val  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `val`  
 Se for diferente de zero, permite o paralelismo aninhado. Se for zero, desabilita o paralelismo aninhado.  
  
## <a name="remarks"></a>Comentários  
 OMP aninhado paralelismo pode ser ativado com `omp_set_nested`, ou definindo o [OMP_NESTED](../../../parallel/openmp/reference/omp-nested.md) variável de ambiente.  
  
 A configuração de `omp_set_nested` substituirá a configuração do `OMP_NESTED` variável de ambiente.  
  
 Quando habilitada, a variável de ambiente pode interromper um programa operacional caso contrário, porque o número de threads aumenta exponencialmente ao aninhar regiões paralelas.  Por exemplo, uma função recurses 6 vezes com o número de threads OMP definido como 4 requer 4.096 (4 à potência de 6) de threads em geral, o desempenho do seu aplicativo prejudicará se o número de threads excede o número de processadores. Uma exceção a isso seria a que e/s associados a aplicativos.  
  
 Use [omp_get_nested](../../../parallel/openmp/reference/omp-get-nested.md) para exibir a configuração atual de `omp_set_nested`.  
  
 Para obter mais informações, consulte [3.1.9 função omp_set_nested](../../../parallel/openmp/3-1-9-omp-set-nested-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_set_nested.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main( )   
{  
    omp_set_nested(1);  
    omp_set_num_threads(4);  
    printf_s("%d\n", omp_get_nested( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_nested( ));  
        }  
}  
```  
  
```Output  
1  
1  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)