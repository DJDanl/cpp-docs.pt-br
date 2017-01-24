---
title: "A.25   Examples of the copyprivate Data Attribute Clause | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 7b1cb6a5-5691-4b95-b3ac-d7543ede6405
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.25   Examples of the copyprivate Data Attribute Clause
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Exemplo 1:** a `copyprivate` cláusula \([seção 2.7.2.8](../Topic/2.7.2.8%20copyprivate.md) na página 32\) pode ser usado para transmitir valores adquiridos por um único thread diretamente para todas as instâncias das variáveis particulares em outros threads.  
  
```  
float x, y;  
#pragma omp threadprivate(x, y)  
  
void init( )   
{  
    float a;  
    float b;  
  
    #pragma omp single copyprivate(a,b,x,y)  
    {  
        get_values(a,b,x,y);  
    }  
  
    use_values(a, b, x, y);  
}  
```  
  
 Se a rotina  *init* é chamado de uma região serial, o seu comportamento não é afetado pela presença das diretivas.  Após a chamada para o  *get\_values* rotina foi executada por um segmento, nenhum thread deixa a construção até que os objetos particulares designados por  *um*,  *b*,  *x*, e  *y* em todos os threads tornam\-se definido com os valores lidos.  
  
 **Exemplo 2:** em comparação com o exemplo anterior, suponha que a leitura deve ser realizada por um segmento específico, digamos que o thread mestre.  Nesse caso, o `copyprivate` cláusula não pode ser usada para fazer a difusão diretamente, mas ele pode ser usado para fornecer acesso a um objeto compartilhado temporário.  
  
```  
float read_next( )   
{  
    float * tmp;  
    float return_val;  
  
    #pragma omp single copyprivate(tmp)  
    {  
        tmp = (float *) malloc(sizeof(float));  
    }  
  
    #pragma omp master  
    {  
        get_float( tmp );  
    }  
  
    #pragma omp barrier  
    return_val = *tmp;  
    #pragma omp barrier  
  
    #pragma omp single  
    {  
       free(tmp);  
    }  
  
    return return_val;  
}  
```  
  
 **Exemplo 3:** suponha que o número de objetos de bloqueio necessários dentro de uma região paralela não pode ser facilmente determinado antes para digitá\-la.  O `copyprivate` cláusula pode ser usada para fornecer acesso a objetos de bloqueio compartilhado que são alocados dentro daquela região paralela.  
  
```  
#include <omp.h>  
  
omp_lock_t *new_lock()  
{  
    omp_lock_t *lock_ptr;  
  
    #pragma omp single copyprivate(lock_ptr)  
    {  
        lock_ptr = (omp_lock_t *) malloc(sizeof(omp_lock_t));  
        omp_init_lock( lock_ptr );  
    }  
  
    return lock_ptr;  
}  
```