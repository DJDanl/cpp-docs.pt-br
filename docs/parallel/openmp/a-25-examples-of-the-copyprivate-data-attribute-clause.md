---
title: A.25   Exemplos da cláusula de atributo de dados copyprivate
ms.date: 11/04/2016
ms.assetid: 7b1cb6a5-5691-4b95-b3ac-d7543ede6405
ms.openlocfilehash: 6c3c174780023f17cc2aa47a54bff14fccf99306
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50493880"
---
# <a name="a25---examples-of-the-copyprivate-data-attribute-clause"></a>A.25   Exemplos da cláusula de atributo de dados copyprivate

**Exemplo 1:** as `copyprivate` cláusula ([seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32) pode ser usado para transmitir valores adquiridos por um único thread diretamente a todas as instâncias de variáveis particulares em outros threads.

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

Se a rotina *init* é chamado de uma região serial, seu comportamento não é afetado pela presença das diretivas. Após a chamada para o *get_values* rotina tiver sido executada por um thread, nenhum thread deixa a construção até que os objetos privados designados pelo *um*, *b*, *x*, e *y* em todos os threads se tornam definidos com os valores de leitura.

**Exemplo 2:** em contraste com o exemplo anterior, suponha que a leitura deve ser executada por um thread específico, digamos que o thread mestre. Nesse caso, o `copyprivate` cláusula não pode ser usada para fazer a difusão diretamente, mas ele pode ser usado para fornecer acesso a um objeto compartilhado temporário.

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

**Exemplo 3:** suponha que o número de objetos de bloqueio necessários dentro de uma região paralela facilmente não pode ser determinado antes de inseri-la. O `copyprivate` cláusula pode ser usada para fornecer acesso a objetos de bloqueio compartilhado que são alocados nessa região paralela.

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