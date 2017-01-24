---
title: "omp_init_lock | Microsoft Docs"
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
  - "omp_init_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_init_lock OpenMP function"
ms.assetid: 7a65e3e2-2e31-4645-964c-c1e82e2a4d0e
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_init_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Inicializa um bloqueio simple.  
  
## Sintaxe  
  
```  
void omp_init_lock(  
   omp_lock_t *lock  
);  
```  
  
#### Parâmetros  
 `lock`  
 Uma variável do tipo [omp\_lock\_t](../../../parallel/openmp/reference/omp-lock-t.md).  
  
## Comentários  
 Para obter mais informações, consulte [3.2.1 omp\_init\_lock and omp\_init\_nest\_lock Functions](../../../parallel/openmp/3-2-1-omp-init-lock-and-omp-init-nest-lock-functions.md).  
  
## Exemplo  
  
```  
// omp_init_lock.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
omp_lock_t my_lock;  
  
int main() {  
   omp_init_lock(&my_lock);  
  
   #pragma omp parallel num_threads(4)  
   {  
      int tid = omp_get_thread_num( );  
      int i, j;  
  
      for (i = 0; i < 5; ++i) {  
         omp_set_lock(&my_lock);  
         printf_s("Thread %d - starting locked region\n", tid);  
         printf_s("Thread %d - ending locked region\n", tid);  
         omp_unset_lock(&my_lock);  
      }  
   }  
  
   omp_destroy_lock(&my_lock);  
}  
```  
  
  **O segmento 0 \- Iniciando bloqueado região**  
**Thread 0 \- terminando bloqueado região**  
**O segmento 0 \- Iniciando bloqueado região**  
**Thread 0 \- terminando bloqueado região**  
**O segmento 0 \- Iniciando bloqueado região**  
**Thread 0 \- terminando bloqueado região**  
**O segmento 0 \- Iniciando bloqueado região**  
**Thread 0 \- terminando bloqueado região**  
**O segmento 0 \- Iniciando bloqueado região**  
**Thread 0 \- terminando bloqueado região**  
**O thread 1 \- Iniciando bloqueado região**  
**Thread 1 \- terminando bloqueado região**  
**O thread 1 \- Iniciando bloqueado região**  
**Thread 1 \- terminando bloqueado região**  
**O thread 1 \- Iniciando bloqueado região**  
**Thread 1 \- terminando bloqueado região**  
**O thread 1 \- Iniciando bloqueado região**  
**Thread 1 \- terminando bloqueado região**  
**O thread 1 \- Iniciando bloqueado região**  
**Thread 1 \- terminando bloqueado região**  
**O thread 2 \- Iniciando bloqueado região**  
**Região do thread 2 \- terminando bloqueado**  
**O thread 2 \- Iniciando bloqueado região**  
**Região do thread 2 \- terminando bloqueado**  
**O thread 2 \- Iniciando bloqueado região**  
**Região do thread 2 \- terminando bloqueado**  
**O thread 2 \- Iniciando bloqueado região**  
**Região do thread 2 \- terminando bloqueado**  
**O thread 2 \- Iniciando bloqueado região**  
**Região do thread 2 \- terminando bloqueado**  
**3 \- Iniciando do thread bloqueado região**  
**Região de thread 3 \- terminando bloqueado**  
**3 \- Iniciando do thread bloqueado região**  
**Região de thread 3 \- terminando bloqueado**  
**3 \- Iniciando do thread bloqueado região**  
**Região de thread 3 \- terminando bloqueado**  
**3 \- Iniciando do thread bloqueado região**  
**Região de thread 3 \- terminando bloqueado**  
**3 \- Iniciando do thread bloqueado região**  
**Região de thread 3 \- terminando bloqueado**   
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)