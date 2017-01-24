---
title: "flush (OpenMP) | Microsoft Docs"
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
  - "Flush"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "flush OpenMP directive"
ms.assetid: 150ca46e-d4f7-4423-b0a4-838df40aeb67
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# flush (OpenMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica que todos os segmentos têm o mesmo modo de exibição de memória para todos os objetos compartilhados.  
  
## Sintaxe  
  
```  
#pragma omp flush [(var)]  
```  
  
## Comentários  
 onde,  
  
 `var`\(opcional\)  
 Uma lista separada por vírgulas de variáveis que representam objetos que você deseja sincronizar.  Se `var` não for especificado, toda a memória seja liberada.  
  
## Comentários  
 O  **liberar** diretiva oferece suporte a cláusulas sem OpenMP.  
  
 Para obter mais informações, consulte [2.6.5 flush Directive](../Topic/2.6.5%20flush%20Directive.md).  
  
## Exemplo  
  
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
  
  **O segmento 0: ler dados**  
**Thread 1: dados de processo**  
**dados \= 2**   
## Consulte também  
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)