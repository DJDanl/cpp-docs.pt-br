---
title: Exemplos A.25 do dados de atributo cláusula copyprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7b1cb6a5-5691-4b95-b3ac-d7543ede6405
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c92d9ce6f22c2d53a2e65d7b67c22e4f080f162c
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691684"
---
# <a name="a25---examples-of-the-copyprivate-data-attribute-clause"></a>A.25   Exemplos da cláusula de atributo de dados copyprivate
**Exemplo 1:** o `copyprivate` cláusula ([seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32) pode ser usado para transmitir valores adquiridos por um único thread diretamente para todas as instâncias das variáveis privadas em outros threads.  
  
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
  
 Se a rotina *init* é chamado de uma região de série, seu comportamento não é afetado pela presença das diretivas. Após a chamada para o *get_values* rotina foi executada por um thread, nenhum thread deixa a construção até que os objetos particulares designados pelo *um*, *b*, *x*, e *y* em todos os threads se tornam definidos com os valores lidos.  
  
 **Exemplo 2:** em contraste com o exemplo anterior, suponha que a leitura deve ser executada por um determinado thread, significa que o thread principal. Nesse caso, o `copyprivate` cláusula não pode ser usada para fazer a transmissão diretamente, mas pode ser usado para fornecer acesso a um objeto compartilhado temporário.  
  
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
  
 **Exemplo 3:** suponha que o número de objetos de bloqueio necessário em uma região parallel facilmente não pode ser determinado antes de inseri-la. O `copyprivate` cláusula pode ser usada para fornecer acesso a objetos de bloqueio compartilhado são alocados nessa região paralela.  
  
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