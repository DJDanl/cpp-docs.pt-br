---
title: omp_test_nest_lock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_test_nest_lock
dev_langs:
- C++
helpviewer_keywords:
- omp_test_nest_lock OpenMP function
ms.assetid: 4c909bbe-80e0-4100-aca6-d415d7dc5294
caps.latest.revision: 12
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
ms.openlocfilehash: 61f1a227400354a9d8c22f87e14093e6992a950e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="omptestnestlock"></a>omp_test_nest_lock
As tentativas de definir um bloqueio aninháveis, mas não bloqueia a execução de thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_test_nest_lock(  
   omp_nest_lock_t *lock  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp_nest_lock_t ()](../../../parallel/openmp/reference/omp-nest-lock-t.md) que foi inicializado com [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md).  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.2.5 funções omp_test_lock e omp_test_nest_lock](../../../parallel/openmp/3-2-5-omp-test-lock-and-omp-test-nest-lock-functions.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_test_nest_lock.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
omp_nest_lock_t nestable_lock;      
  
int main() {  
   omp_init_nest_lock(&nestable_lock);  
  
   #pragma omp parallel num_threads(4)  
   {  
      int tid = omp_get_thread_num();  
      while (!omp_test_nest_lock(&nestable_lock))  
         printf_s("Thread %d - failed to acquire nestable_lock\n",  
                tid);  
  
      printf_s("Thread %d - acquired nestable_lock\n", tid);  
  
      if (omp_test_nest_lock(&nestable_lock)) {  
         printf_s("Thread %d - acquired nestable_lock again\n",  
                tid);  
         printf_s("Thread %d - released nestable_lock\n",   
                tid);  
         omp_unset_nest_lock(&nestable_lock);  
      }  
  
      printf_s("Thread %d - released nestable_lock\n", tid);  
      omp_unset_nest_lock(&nestable_lock);  
   }  
  
   omp_destroy_nest_lock(&nestable_lock);  
}  
```  
  
```Output  
Thread 1 - acquired nestable_lock  
Thread 0 - failed to acquire nestable_lock  
Thread 1 - acquired nestable_lock again  
Thread 0 - failed to acquire nestable_lock  
Thread 1 - released nestable_lock  
Thread 0 - failed to acquire nestable_lock  
Thread 1 - released nestable_lock  
Thread 0 - failed to acquire nestable_lock  
Thread 3 - acquired nestable_lock  
Thread 0 - failed to acquire nestable_lock  
Thread 3 - acquired nestable_lock again  
Thread 0 - failed to acquire nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 3 - released nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 3 - released nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 0 - acquired nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 0 - acquired nestable_lock again  
Thread 2 - failed to acquire nestable_lock  
Thread 0 - released nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 0 - released nestable_lock  
Thread 2 - failed to acquire nestable_lock  
Thread 2 - acquired nestable_lock  
Thread 2 - acquired nestable_lock again  
Thread 2 - released nestable_lock  
Thread 2 - released nestable_lock  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)
