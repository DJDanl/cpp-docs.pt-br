---
title: omp_set_nested | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_set_nested
dev_langs:
- C++
helpviewer_keywords:
- omp_set_nested OpenMP function
ms.assetid: fa1cb08c-7b8b-42c9-8654-2c33dcffb5b6
caps.latest.revision: 13
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
ms.openlocfilehash: d120c4eca49a917cb34fc3b8a873c08f5e2815eb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
 Quando habilitada, a variável de ambiente pode interromper um programa caso contrário operacional porque o número de threads aumenta exponencialmente ao aninhar regiões em paralelo.  Por exemplo, uma função recurses 6 vezes com o número de threads OMP definido como 4 requer 4.096 (4 à potência de 6) threads em geral, poderá degradar o desempenho do seu aplicativo se o número de threads exceder o número de processadores. Uma exceção a isso seria que aplicativos vinculados a e/s.  
  
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
