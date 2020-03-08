---
title: Diretivas (OpenMP)
ms.date: 03/20/2019
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
ms.openlocfilehash: 4db341cf58884263e414e24aacf888c8c88e57cc
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78882883"
---
# <a name="openmp-directives"></a>Diretivas (OpenMP)

Fornece links para diretivas usadas na API de OpenMP.

O C++ Visual dá suporte às seguintes diretivas de OpenMP.

Para compartilhamento de trabalho paralelo:

|Directive|Descrição|
|---------|-----------|
|[parallel](#parallel)|Define uma região paralela, que é o código que será executado por vários threads em paralelo.|
|[for](#for-openmp)|Faz com que o trabalho feito em um loop de `for` dentro de uma região paralela seja dividido entre threads.|
|[as](#sections-openmp)|Identifica as seções de código a serem divididas entre todos os threads.|
|[single](#single)|Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.|

Para mestre e sincronização:

|Directive|Descrição|
|---------|-----------|
|[master](#master)|Especifica que somente o thread mestre deve executar uma seção do programa.|
|[critical](#critical)|Especifica que o código é executado somente em um thread por vez.|
|[barrier](#barrier)|Sincroniza todos os threads em uma equipe; todos os threads são pausados na barreira, até que todos os threads executem a barreira.|
|[atomic](#atomic)|Especifica que um local de memória que será atualizado atomicamente.|
|[flush](#flush-openmp)|Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.|
|[ordenados](#ordered-openmp-directives)|Especifica que o código em um loop de `for` paralelizado deve ser executado como um loop sequencial.|

Para o ambiente de dados:

|Directive|Descrição|
|---------|-----------|
|[threadprivate](#threadprivate)|Especifica que uma variável é privada para um thread.|

## <a name="atomic"></a>atômica

Especifica que um local de memória que será atualizado atomicamente.

```cpp
#pragma omp atomic
   expression
```

### <a name="parameters"></a>Parâmetros

*expression*<br/>
A instrução que tem o *lvalue*, cujo local de memória você deseja proteger contra mais de uma gravação.

### <a name="remarks"></a>Comentários

A diretiva `atomic` não dá suporte a cláusulas.

Para obter mais informações, consulte [2.6.4 Atomic Construct](../../../parallel/openmp/2-6-4-atomic-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="barrier"></a>obstáculo

Sincroniza todos os threads em uma equipe; todos os threads são pausados na barreira, até que todos os threads executem a barreira.

```cpp
#pragma omp barrier
```

### <a name="remarks"></a>Comentários

A diretiva `barrier` não dá suporte a cláusulas.

Para obter mais informações, consulte [diretiva de barreira 2.6.3](../../../parallel/openmp/2-6-3-barrier-directive.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo de como usar `barrier`, consulte [Master](#master).

## <a name="critical"></a>drasticamente

Especifica que o código só será executado em um thread por vez.

```cpp
#pragma omp critical [(name)]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
Adicional Um nome para identificar o código crítico. O nome deve ser colocado entre parênteses.

### <a name="remarks"></a>Comentários

A diretiva `critical` não dá suporte a cláusulas.

Para obter mais informações, consulte [construção crítica 2.6.2](../../../parallel/openmp/2-6-2-critical-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="flush-openmp"></a>Libere

Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.

```cpp
#pragma omp flush [(var)]
```

### <a name="parameters"></a>Parâmetros

*var*<br/>
Adicional Uma lista separada por vírgulas de variáveis que representam objetos que você deseja sincronizar. Se *var* não for especificado, toda a memória será liberada.

### <a name="remarks"></a>Comentários

A diretiva `flush` não dá suporte a cláusulas.

Para obter mais informações, consulte a [diretiva de liberação do 2.6.5](../../../parallel/openmp/2-6-5-flush-directive.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="for-openmp"></a>fins

Faz com que o trabalho feito em um loop de `for` dentro de uma região paralela seja dividido entre threads.

```cpp
#pragma omp [parallel] for [clauses]
   for_statement
```

### <a name="parameters"></a>Parâmetros

*cláusulas*<br/>
Adicional Zero ou mais cláusulas, consulte a seção **comentários** .

*for_statement*<br/>
Um loop de `for`. O comportamento indefinido será resultado se o código do usuário no loop de `for` alterar a variável de índice.

### <a name="remarks"></a>Comentários

A diretiva `for` dá suporte às seguintes cláusulas:

- [private](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [reduction](openmp-clauses.md#reduction)
- [ordenados](openmp-clauses.md#ordered-openmp-clauses)
- [schedule](openmp-clauses.md#schedule)
- [nowait](openmp-clauses.md#nowait)

Se `parallel` também for especificado, `clauses` poderá ser qualquer cláusula aceita pelas diretivas `parallel` ou `for`, exceto `nowait`.

Para obter mais informações, consulte [2.4.1 for Construct](../../../parallel/openmp/2-4-1-for-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="master"></a>vários

Especifica que somente o thread mestre deve executar uma seção do programa.

```cpp
#pragma omp master
{
   code_block
}
```

### <a name="remarks"></a>Comentários

A diretiva `master` não dá suporte a cláusulas.

A [única](#single) diretiva permite especificar que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.

Para obter mais informações, consulte [2.6.1 Master Construct](../../../parallel/openmp/2-6-1-master-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="ordered-openmp-directives"></a>ordenados

Especifica que o código em um loop de `for` paralelizado deve ser executado como um loop sequencial.

```cpp
#pragma omp ordered
   structured-block
```

### <a name="remarks"></a>Comentários

A diretiva `ordered` deve estar dentro da extensão dinâmica de uma construção [for](#for-openmp) ou `parallel for` com uma cláusula `ordered`.

A diretiva `ordered` não dá suporte a cláusulas.

Para obter mais informações, consulte [construção ordenada 2.6.6](../../../parallel/openmp/2-6-6-ordered-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="parallel"></a>completa

Define uma região paralela, que é o código que será executado por vários threads em paralelo.

```cpp
#pragma omp parallel [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*cláusulas*<br/>
Adicional Zero ou mais cláusulas, consulte a seção **comentários** .

### <a name="remarks"></a>Comentários

A diretiva `parallel` dá suporte às seguintes cláusulas:

- [if](openmp-clauses.md#if-openmp)
- [private](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [default](openmp-clauses.md#default-openmp)
- [compartilhado](openmp-clauses.md#shared-openmp)
- [copyin](openmp-clauses.md#copyin)
- [reduction](openmp-clauses.md#reduction)
- [num_threads](openmp-clauses.md#num-threads)

`parallel` também pode ser usado com as diretivas [for](#for-openmp) e [Sections](#sections-openmp) .

Para obter mais informações, consulte [construção paralela 2,3](../../../parallel/openmp/2-3-parallel-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra como definir o número de threads e definir uma região paralela. O número de threads é igual por padrão ao número de processadores lógicos no computador. Por exemplo, se você tiver um computador com um processador físico com hyperthreading habilitado, ele terá dois processadores lógicos e dois threads. A ordem de saída pode variar em computadores diferentes.

```cpp
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

## <a name="sections-openmp"></a>as

Identifica as seções de código a serem divididas entre todos os threads.

```cpp
#pragma omp [parallel] sections [clauses]
{
   #pragma omp section
   {
      code_block
   }
}
```

### <a name="parameters"></a>Parâmetros

*cláusulas*<br/>
Adicional Zero ou mais cláusulas, consulte a seção **comentários** .

### <a name="remarks"></a>Comentários

A diretiva `sections` pode conter zero ou mais diretivas de `section`.

A diretiva `sections` dá suporte às seguintes cláusulas:

- [private](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [reduction](openmp-clauses.md#reduction)
- [nowait](openmp-clauses.md#nowait)

Se `parallel` também for especificado, `clauses` poderá ser qualquer cláusula aceita pelas diretivas `parallel` ou `sections`, exceto `nowait`.

Para obter mais informações, consulte [2.4.2 Sections Construct](../../../parallel/openmp/2-4-2-sections-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
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

## <a name="single"></a>exclusivo

Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.

```cpp
#pragma omp single [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*cláusulas*<br/>
Adicional Zero ou mais cláusulas, consulte a seção **comentários** .

### <a name="remarks"></a>Comentários

A diretiva `single` dá suporte às seguintes cláusulas:

- [private](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [copyprivate](openmp-clauses.md#copyprivate)
- [nowait](openmp-clauses.md#nowait)

A diretiva [mestre](#master) permite que você especifique que uma seção de código deve ser executada somente no thread mestre.

Para obter mais informações, consulte [2.4.3 single Construct](../../../parallel/openmp/2-4-3-single-construct.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

Especifica que uma variável é privada para um thread.

```cpp
#pragma omp threadprivate(var)
```

### <a name="parameters"></a>Parâmetros

*var*<br/>
Uma lista separada por vírgulas de variáveis que você deseja tornar particulares a um thread. o *var* deve ser uma variável global ou de escopo de namespace ou uma variável estática local.

### <a name="remarks"></a>Comentários

A diretiva `threadprivate` não dá suporte a cláusulas.

A diretiva `threadprivate` é baseada no atributo [thread](../../../cpp/thread.md) usando a palavra-chave [__declspec](../../../cpp/declspec.md) ; os limites no `__declspec(thread)` se aplicam ao `threadprivate`. Por exemplo, uma variável `threadprivate` existirá em qualquer thread iniciado no processo, não apenas aqueles threads que fazem parte de uma equipe de thread gerada por uma região paralela. Lembre-se desse detalhe de implementação; Você pode observar que os construtores para um tipo de `threadprivate` definido pelo usuário são chamados com mais frequência esperado.

Você pode usar `threadprivate` em uma DLL que é carregada estaticamente na inicialização do processo, no entanto, não é possível usar `threadprivate` em qualquer DLL que será carregada por meio de [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) , como DLLs carregadas com [/DELAYLOAD (atraso na importação de carga)](../../../build/reference/delayload-delay-load-import.md), que também usa `LoadLibrary`.

Uma variável `threadprivate` de um tipo *destrutíveis* não tem garantia de ter seu destruidor chamado. Por exemplo:

```cpp
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

Os usuários não têm controle sobre quando os threads que constituem a região paralela serão encerrados. Se esses threads existirem quando o processo for encerrado, os threads não serão notificados sobre a saída do processo e o destruidor não será chamado para `threaded_var` em nenhum thread, exceto aquele que sair (aqui, o thread principal). Portanto, o código não deve contar com a destruição adequada das variáveis de `threadprivate`.

Para obter mais informações, consulte [diretiva 2.7.1 threadprivate](../../../parallel/openmp/2-7-1-threadprivate-directive.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter uma amostra de como usar `threadprivate`, consulte [privado](openmp-clauses.md#private-openmp).
