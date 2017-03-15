---
title: omp_get_wtime | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_get_wtime
dev_langs:
- C++
helpviewer_keywords:
- omp_get_wtime OpenMP function
ms.assetid: c8dee105-ec1b-42e5-a6e3-edeedcf9854c
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
ms.openlocfilehash: eaf83132da9ce5d348e5ed9a5bbd1e1afcd67ebd
ms.lasthandoff: 02/25/2017

---
# <a name="ompgetwtime"></a>omp_get_wtime
Retorna que um valor em segundos do tempo decorrido desde algum ponto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double omp_get_wtime( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna que um valor em segundos do tempo decorrido desde o momento de alguns arbitrário, mas consistente.  
  
## <a name="remarks"></a>Comentários  
 Esse ponto permanecerá consistente durante a execução do programa, possibilitando comparações subsequentes.  
  
 Para obter mais informações, consulte [3.3.1 função omp_get_wtime](../../../parallel/openmp/3-3-1-omp-get-wtime-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_get_wtime.cpp  
// compile with: /openmp  
#include "omp.h"  
#include <stdio.h>  
#include <windows.h>  
  
int main() {  
    double start = omp_get_wtime( );  
    Sleep(1000);  
    double end = omp_get_wtime( );  
    double wtick = omp_get_wtick( );  
  
    printf_s("start = %.16g\nend = %.16g\ndiff = %.16g\n",  
             start, end, end - start);  
  
    printf_s("wtick = %.16g\n1/wtick = %.16g\n",  
             wtick, 1.0 / wtick);  
}  
```  
  
```Output  
start = 594255.3671159324  
end = 594256.3664474116  
diff = 0.9993314791936427  
wtick = 2.793651148400146e-007  
1/wtick = 3579545  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)
