---
title: Diretivas OpenMP
ms.date: 10/22/2018
f1_keywords:
- OpenMP directives
- atomic
- barrier
- critical
- flush
- for
- master
- ordered
- parallel
- section
- SECTIONS
- single
- threadprivate
helpviewer_keywords:
- OpenMP directives
- atomic OpenMP directive
- barrier OpenMP directive
- critical OpenMP directive
- flush OpenMP directive
- for OpenMP directive
- master OpenMP directive
- ordered OpenMP directive
- parallel OpenMP directive
- sections OpenMP directive
- single OpenMP directive
- threadprivate OpenMP directive
ms.assetid: 0562c263-344c-466d-843e-de830d918940
ms.openlocfilehash: a61e74bda4e508bac3c4afd183fa2ab204c629d1
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51333235"
---
# <a name="openmp-directives"></a>Diretivas OpenMP

Fornece links para as diretivas usadas na API OpenMP.

Visual C++ suporta as seguintes diretivas OpenMP:

|Diretiva|Descrição|
|---------|-----------|
|[atomic](#atomic)|Especifica que um local de memória que será atualizado atomicamente.|
|[barrier](#barrier)|Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.|
|[critical](#critical)|Especifica que o código só é executado em um thread por vez.|
|[flush](#flush-openmp)|Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.|
|[for](#for-openmp)|Faz com que o trabalho feito um `for` loop dentro de uma região paralela para ser dividido entre threads.|
|[master](#master)|Especifica que somente o thread mestre deve ser executada uma seção do programa.|
|[Ordenado](#ordered-openmp-directives)|Especifica que o código em um em paralelo `for` loop deve ser executado como um loop sequencial.|
|[parallel](#parallel)|Define uma região paralela, que é um código que será executado por vários threads em paralelo.|
|[Seções](#sections-openmp)|Identifica as seções de código a ser dividida entre todos os threads.|
|[single](#single)|Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.|
|[threadprivate](#threadprivate)|Especifica que uma variável privada em um thread.|

## <a name="atomic"></a>Atomic

Especifica que um local de memória que será atualizado atomicamente.

```
#pragma omp atomic
   expression
```

### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
A instrução que tem o lvalue, cujo local de memória que você deseja proteger com mais de uma gravação. Para obter mais informações sobre os formulários de expressão legais, consulte a especificação de OpenMP.

### <a name="remarks"></a>Comentários

O `atomic` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.4 atômica construir](../../../parallel/openmp/2-6-4-atomic-construct.md).

### <a name="example"></a>Exemplo

```
// omp_atomic.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

#define MAX 10

int main() {
   int count = 0;
   #pragma omp parallel num_threads(MAX)
   {
      #pragma omp atomic
      count++;
   }
   printf_s("Number of threads: %d\n", count);
}
```

```Output
Number of threads: 10
```

## <a name="barrier"></a>barreira

Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.

```
#pragma omp barrier
```

### <a name="remarks"></a>Comentários

O `barrier` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.3 diretiva barrier](../../../parallel/openmp/2-6-3-barrier-directive.md).

### <a name="example"></a>Exemplo

Para obter um exemplo de como usar `barrier`, consulte [mestre](#master).

## <a name="critical"></a>Crítico

Especifica que código é ser executado somente em um thread por vez.

```
#pragma omp critical [(name)]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
(Opcional) Um nome para identificar o código critical. Observe que esse nome deve ser colocado entre parênteses.

### <a name="remarks"></a>Comentários

O `critical` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.2 críticos construir](../../../parallel/openmp/2-6-2-critical-construct.md).

### <a name="example"></a>Exemplo

```
// omp_critical.cpp
// compile with: /openmp
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int i;
    int max;
    int a[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand();
        printf_s("%d\n", a[i]);
    }

    max = a[0];
    #pragma omp parallel for num_threads(4)
        for (i = 1; i < SIZE; i++)
        {
            if (a[i] > max)
            {
                #pragma omp critical
                {
                    // compare a[i] and max again because max
                    // could have been changed by another thread after
                    // the comparison outside the critical section
                    if (a[i] > max)
                        max = a[i];
                }
            }
        }

    printf_s("max = %d\n", max);
}
```

```Output
41
18467
6334
26500
19169
15724
11478
29358
26962
24464
max = 29358
```

## <a name="flush-openmp"></a>flush (OpenMP)

Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.

```
#pragma omp flush [(var)]
```

### <a name="parameters"></a>Parâmetros

*var*<br/>
(Opcional) Uma lista separada por vírgulas de variáveis que representam os objetos que você deseja sincronizar. Se `var` não for especificado, toda a memória é liberada.

### <a name="remarks"></a>Comentários

O `flush` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.5 diretiva flush](../../../parallel/openmp/2-6-5-flush-directive.md).

### <a name="example"></a>Exemplo

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

## <a name="for-openmp"></a>para (OpenMP)

Faz com que o trabalho feito um `for` loop dentro de uma região paralela para ser dividido entre threads.

```
#pragma omp [parallel] for [clauses]
   for_statement
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo `for`.

*for_statement*<br/>
Um `for` loop. Um comportamento indefinido resultará se o código do usuário no `for` loop altera a variável de índice.

### <a name="remarks"></a>Comentários

O `for` diretiva suporta as seguintes cláusulas OpenMP:

- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [nowait](openmp-clauses.md#nowait)
- [Ordenado](openmp-clauses.md#ordered-openmp-clauses)
- [private](openmp-clauses.md#private-openmp)
- [reduction](openmp-clauses.md#reduction)
- [schedule](openmp-clauses.md#schedule)

Se `parallel` também for especificado, `clauses` pode ser qualquer cláusula aceitos pela `parallel` ou `for` diretivas, exceto `nowait`.

Para obter mais informações, consulte [2.4.1 constructo for](../../../parallel/openmp/2-4-1-for-construct.md).

### <a name="example"></a>Exemplo

```
// omp_for.cpp
// compile with: /openmp
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_START 1
#define NUM_END 10

int main() {
   int i, nRet = 0, nSum = 0, nStart = NUM_START, nEnd = NUM_END;
   int nThreads = 0, nTmp = nStart + nEnd;
   unsigned uTmp = (unsigned((abs(nStart - nEnd) + 1)) *
                               unsigned(abs(nTmp))) / 2;
   int nSumCalc = uTmp;

   if (nTmp < 0)
      nSumCalc = -nSumCalc;

   omp_set_num_threads(NUM_THREADS);

   #pragma omp parallel default(none) private(i) shared(nSum, nThreads, nStart, nEnd)
   {
      #pragma omp master
      nThreads = omp_get_num_threads();

      #pragma omp for
      for (i=nStart; i<=nEnd; ++i) {
            #pragma omp atomic
            nSum += i;
      }
   }

   if  (nThreads == NUM_THREADS) {
      printf_s("%d OpenMP threads were used.\n", NUM_THREADS);
      nRet = 0;
   }
   else {
      printf_s("Expected %d OpenMP threads, but %d were used.\n",
               NUM_THREADS, nThreads);
      nRet = 1;
   }

   if (nSum != nSumCalc) {
      printf_s("The sum of %d through %d should be %d, "
               "but %d was reported!\n",
               NUM_START, NUM_END, nSumCalc, nSum);
      nRet = 1;
   }
   else
      printf_s("The sum of %d through %d is %d\n",
               NUM_START, NUM_END, nSum);
}
```

```Output
4 OpenMP threads were used.
The sum of 1 through 10 is 55
```

## <a name="master"></a>Mestre

Especifica que somente o thread mestre deve ser executada uma seção do programa.

```
#pragma omp master
{
   code_block
}
```

### <a name="remarks"></a>Comentários

O `master` diretiva dá suporte a nenhuma cláusulas OpenMP.

O [único](#single) diretiva permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.

Para obter mais informações, consulte [2.6.1 constructo de mestre](../../../parallel/openmp/2-6-1-master-construct.md).

### <a name="example"></a>Exemplo

```
// omp_master.cpp
// compile with: /openmp
#include <omp.h>
#include <stdio.h>

int main( )
{
    int a[5], i;

    #pragma omp parallel
    {
        // Perform some computation.
        #pragma omp for
        for (i = 0; i < 5; i++)
            a[i] = i * i;

        // Print intermediate results.
        #pragma omp master
            for (i = 0; i < 5; i++)
                printf_s("a[%d] = %d\n", i, a[i]);

        // Wait.
        #pragma omp barrier

        // Continue with the computation.
        #pragma omp for
        for (i = 0; i < 5; i++)
            a[i] += i;
    }
}
```

```Output
a[0] = 0
a[1] = 1
a[2] = 4
a[3] = 9
a[4] = 16
```

## <a name="ordered-openmp-directives"></a>Ordered (diretivas OpenMP)

Especifica que o código em um em paralelo `for` loop deve ser executado como um loop sequencial.

```
#pragma omp ordered
   structured-block
```

### <a name="remarks"></a>Comentários

O `ordered` diretiva deve estar dentro do extensão dinâmico de um [para](#for-openmp) ou `parallel for` construir com um `ordered` cláusula.

O `ordered` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.6 constructo ordered](../../../parallel/openmp/2-6-6-ordered-construct.md).

### <a name="example"></a>Exemplo

```
// omp_ordered.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

static float a[1000], b[1000], c[1000];

void test(int first, int last)
{
    #pragma omp for schedule(static) ordered
    for (int i = first; i <= last; ++i) {
        // Do something here.
        if (i % 2)
        {
            #pragma omp ordered
            printf_s("test() iteration %d\n", i);
        }
    }
}

void test2(int iter)
{
    #pragma omp ordered
    printf_s("test2() iteration %d\n", iter);
}

int main( )
{
    int i;
    #pragma omp parallel
    {
        test(1, 8);
        #pragma omp for ordered
        for (i = 0 ; i < 5 ; i++)
            test2(i);
    }
}
```

```Output
test() iteration 1
test() iteration 3
test() iteration 5
test() iteration 7
test2() iteration 0
test2() iteration 1
test2() iteration 2
test2() iteration 3
test2() iteration 4
```

## <a name="parallel"></a>Paralelo

Define uma região paralela, que é um código que será executado por vários threads em paralelo.

```
#pragma omp parallel [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas.  Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo `parallel`.

### <a name="remarks"></a>Comentários

O `parallel` diretiva suporta as seguintes cláusulas OpenMP:

- [copyin](openmp-clauses.md#copyin)
- [default](openmp-clauses.md#default-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [if](openmp-clauses.md#if-openmp)
- [num_threads](openmp-clauses.md#num-threads)
- [private](openmp-clauses.md#private-openmp)
- [reduction](openmp-clauses.md#reduction)
- [shared](openmp-clauses.md#shared-openmp)

`parallel` também pode ser usado com o [seções](#sections-openmp) e [para](#for-openmp) diretivas.

Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como definir o número de threads e definir uma região paralela. O número de threads é igual por padrão para o número de processadores lógicos no computador. Por exemplo, se você tiver um computador com um processador físico que tem o hyperthreading habilitado, ele terá dois processadores lógicos e dois threads.

```
// omp_parallel.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
   #pragma omp parallel num_threads(4)
   {
      int i = omp_get_thread_num();
      printf_s("Hello from thread %d\n", i);
   }
}
```

```Output
Hello from thread 0
Hello from thread 1
Hello from thread 2
Hello from thread 3
```

### <a name="comment"></a>Comentário

Observe que a ordem de saída pode variar em computadores diferentes.

## <a name="sections-openmp"></a>seções (OpenMP)

Identifica as seções de código a ser dividida entre todos os threads.

```
#pragma omp [parallel] sections [clauses]
{
   #pragma omp section
   {
      code_block
   }
}
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo `sections`.

### <a name="remarks"></a>Comentários

O `sections` diretiva pode conter zero ou mais `section` diretivas.

O `sections` diretiva suporta as seguintes cláusulas OpenMP:

- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [nowait](openmp-clauses.md#nowait)
- [private](openmp-clauses.md#private-openmp)
- [reduction](openmp-clauses.md#reduction)

Se `parallel` também for especificado, `clauses` pode ser qualquer cláusula aceitos pela `parallel` ou `sections` diretivas, exceto `nowait`.

Para obter mais informações, consulte [2.4.2 constructo sections](../../../parallel/openmp/2-4-2-sections-construct.md).

### <a name="example"></a>Exemplo

```
// omp_sections.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel sections num_threads(4)
    {
        printf_s("Hello from thread %d\n", omp_get_thread_num());
        #pragma omp section
        printf_s("Hello from thread %d\n", omp_get_thread_num());
    }
}
```

```Output
Hello from thread 0
Hello from thread 0
```

## <a name="single"></a>Único

Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.

```
#pragma omp single [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo `single`.

### <a name="remarks"></a>Comentários

O `single` diretiva suporta as seguintes cláusulas OpenMP:

- [copyprivate](openmp-clauses.md#copyprivate)
- [firstprivate](openmp-clauses.md#firstprivate)
- [nowait](openmp-clauses.md#nowait)
- [private](openmp-clauses.md#private-openmp)

O [mestre](#master) diretiva permite que você especifique que uma seção de código deve ser executada somente no thread mestre.

Para obter mais informações, consulte [2.4.3 único construir](../../../parallel/openmp/2-4-3-single-construct.md).

### <a name="example"></a>Exemplo

```cpp
// omp_single.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
   #pragma omp parallel num_threads(2)
   {
      #pragma omp single
      // Only a single thread can read the input.
      printf_s("read input\n");

      // Multiple threads in the team compute the results.
      printf_s("compute results\n");

      #pragma omp single
      // Only a single thread can write the output.
      printf_s("write output\n");
    }
}
```

```Output
read input
compute results
compute results
write output
```

## <a name="threadprivate"></a>threadprivate

Especifica que uma variável privada em um thread.

```
#pragma omp threadprivate(var)
```

### <a name="parameters"></a>Parâmetros

*var*<br/>
Uma lista separada por vírgulas de variáveis que você deseja tornar particular a um thread. `var` deve ser uma variável global - ou no escopo de namespace ou uma variável estática de local.

### <a name="remarks"></a>Comentários

O `threadprivate` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.7.1 diretiva threadprivate](../../../parallel/openmp/2-7-1-threadprivate-directive.md).

O `threadprivate` diretiva se baseia o [thread](../../../cpp/thread.md) de atributo usando a [declspec](../../../cpp/declspec.md) palavra-chave; limites `__declspec(thread)` se aplicam a `threadprivate`.

Não é possível usar `threadprivate` em qualquer DLL que será carregado por meio [LoadLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya).  Esta proibição inclui DLLs carregadas com [/DELAYLOAD (importação de carga com atraso)](../../../build/reference/delayload-delay-load-import.md), que também usa `LoadLibrary`.

Você pode usar `threadprivate` em uma DLL que estaticamente é carregada na inicialização do processo.

Porque `threadprivate` se baseia `__declspec(thread)`, um `threadprivate` variável continuará a existir em qualquer thread iniciado no processo, não apenas os threads que fazem parte de uma equipe de thread gerada por uma região paralela.  Lembre-se dos detalhes da implementação; Você pode observar, por exemplo, que os construtores para um `threadprivate` tipo definido pelo usuário são chamados mais frequentemente e esperado.

Um `threadprivate` variável de um tipo destructable não é garantida para ter seu destruidor chamado.  Por exemplo:

```
struct MyType
{
    ~MyType();
};

MyType threaded_var;
#pragma omp threadprivate(threaded_var)
int main()
{
    #pragma omp parallel
    {}
}
```

Os usuários não tem controle sobre quando os threads que constitui a região paralela serão encerrado.  Se esses threads existirem quando o processo for encerrado, os threads não serão notificados sobre o encerramento do processo e o destruidor não será chamado para `threaded_var` em qualquer thread, exceto o que é encerrado (aqui, o thread primário).  Portanto, código não deve contar com a destruição correta de `threadprivate` variáveis.

### <a name="example"></a>Exemplo

Para obter um exemplo de uso `threadprivate`, consulte [privada](openmp-clauses.md#private-openmp).
