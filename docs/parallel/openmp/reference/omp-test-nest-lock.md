---
title: "omp_test_nest_lock | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "omp_test_nest_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_test_nest_lock OpenMP function"
ms.assetid: 4c909bbe-80e0-4100-aca6-d415d7dc5294
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_test_nest_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Tenta definir um bloqueio de nestable, mas não bloqueia a execução da thread.  
  
## Sintaxe  
  
```  
int omp_test_nest_lock(  
   omp_nest_lock_t *lock  
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_nest\_lock\_t](../Topic/omp_nest_lock_t.md) que foi inicializado com [omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md).  
  
## Comentários  
 Para obter mais informações, consulte [3.2.5 omp\_test\_lock and omp\_test\_nest\_lock Functions](../Topic/3.2.5%20omp_test_lock%20and%20omp_test_nest_lock%20Functions.md).  
  
## Exemplo  
  
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
  
  **O thread 1 \- adquirido a nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**Novamente para o thread 1 \- adquirido a nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**O thread 1 \- lançado nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**O thread 1 \- lançado nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**Thread 3 \- adquirida a nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**Novamente para o segmento 3 \- adquirido a nestable\_lock**  
**Thread 0 \- Falha ao adquirir nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O thread 3 \- lançado nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O thread 3 \- lançado nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O segmento 0 \- adquirido a nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**Novamente para o segmento 0 \- adquirido a nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O segmento 0 \- lançado nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O segmento 0 \- lançado nestable\_lock**  
**Thread 2 \- Falha ao adquirir nestable\_lock**  
**O thread 2 \- adquirido a nestable\_lock**  
**Novamente para o thread 2 \- adquirida a nestable\_lock**  
**O thread 2 \- lançado nestable\_lock**  
**O thread 2 \- lançado nestable\_lock**   
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)