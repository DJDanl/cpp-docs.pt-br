---
title: liberar (OpenMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Flush
dev_langs:
- C++
helpviewer_keywords:
- flush OpenMP directive
ms.assetid: 150ca46e-d4f7-4423-b0a4-838df40aeb67
caps.latest.revision: 10
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
ms.openlocfilehash: 30a713da7c1096043b3e48db2453b647717cb163
ms.lasthandoff: 02/25/2017

---
# <a name="flush-openmp"></a>flush (OpenMP)
Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp flush [(var)]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var` (opcional)  
 Uma lista separada por vírgulas de variáveis que representam os objetos que você deseja sincronizar. Se `var` não for especificado, toda a memória é liberada.  
  
## <a name="remarks"></a>Comentários  
 O **liberar** diretiva oferece suporte a nenhum cláusulas OpenMP.  
  
 Para obter mais informações, consulte [2.6.5 diretiva flush](../../../parallel/openmp/2-6-5-flush-directive.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_flush.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
void read(int *data) {  
   printf_s("read data\n");  
   *data = 1;  
}  
  
void process(int *data) {  
   printf_s("process data\n");  
   (*data)++;  
}  
  
int main() {  
   int data;  
   int flag;  
  
   flag = 0;  
  
   #pragma omp parallel sections num_threads(2)  
   {  
      #pragma omp section  
      {  
         printf_s("Thread %d: ", omp_get_thread_num( ));  
         read(&data);  
         #pragma omp flush(data)  
         flag = 1;  
         #pragma omp flush(flag)  
         // Do more work.  
      }  
  
      #pragma omp section   
      {  
         while (!flag) {  
            #pragma omp flush(flag)  
         }  
         #pragma omp flush(data)  
  
         printf_s("Thread %d: ", omp_get_thread_num( ));  
         process(&data);  
         printf_s("data = %d\n", data);  
      }  
   }  
}  
```  
  
```Output  
Thread 0: read data  
Thread 1: process data  
data = 2  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
