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
- parallel
- section
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
ms.openlocfilehash: 569419b3422b155afc6e9692efaecd4e5a06f188
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366442"
---
# <a name="openmp-directives"></a>Diretivas (OpenMP)

Fornece links para diretivas usadas na API OpenMP.

O Visual C++ suporta as seguintes diretivas OpenMP.

Para compartilhamento paralelo de trabalho:

|Diretiva|Descrição|
|---------|-----------|
|[parallel](#parallel)|Define uma região paralela, que é o código que será executado por vários segmentos em paralelo.|
|[for](#for-openmp)|Faz com que `for` o trabalho feito em um loop dentro de uma região paralela seja dividido entre os segmentos.|
|[Seções](#sections-openmp)|Identifica seções de código a serem divididas entre todos os segmentos.|
|[single](#single)|Permite especificar que uma seção de código deve ser executada em um único segmento, não necessariamente no segmento mestre.|

Para mestre e sincronização:

|Diretiva|Descrição|
|---------|-----------|
|[master](#master)|Especifica que apenas o segmento mestre deve executar uma seção do programa.|
|[Crítico](#critical)|Especifica que o código só é executado em um segmento de cada vez.|
|[barrier](#barrier)|Sincroniza todos os segmentos em uma equipe; todos os segmentos pausam na barreira, até que todos os segmentos executem a barreira.|
|[atômica](#atomic)|Especifica que um local de memória que será atualizado atomicamente.|
|[flush](#flush-openmp)|Especifica que todos os segmentos têm a mesma visão de memória para todos os objetos compartilhados.|
|[Ordenou](#ordered-openmp-directives)|Especifica que o código `for` sob um loop paralelizado deve ser executado como um loop seqüencial.|

Para o ambiente de dados:

|Diretiva|Descrição|
|---------|-----------|
|[threadprivate](#threadprivate)|Especifica que uma variável é privada para um segmento.|

## <a name="atomic"></a><a name="atomic"></a>Atômica

Especifica que um local de memória que será atualizado atomicamente.

```cpp
#pragma omp atomic
   expression
```

### <a name="parameters"></a>Parâmetros

*expressão*<br/>
A declaração que tem o *valor lvalue*, cujo local de memória você deseja proteger contra mais de uma gravação.

### <a name="remarks"></a>Comentários

A `atomic` diretiva não suporta cláusulas.

Para obter mais informações, consulte [2.6.4 construção atômica](../../../parallel/openmp/2-6-4-atomic-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="barrier"></a><a name="barrier"></a>Barreira

Sincroniza todos os segmentos em uma equipe; todos os segmentos pausam na barreira, até que todos os segmentos executem a barreira.

```cpp
#pragma omp barrier
```

### <a name="remarks"></a>Comentários

A `barrier` diretiva não suporta cláusulas.

Para obter mais informações, consulte [a diretiva de barreira 2.6.3](../../../parallel/openmp/2-6-3-barrier-directive.md).

### <a name="example"></a>Exemplo

Para obter uma amostra `barrier`de como usar, consulte [master](#master).

## <a name="critical"></a><a name="critical"></a>Crítico

Especifica que o código só é executado em um segmento de cada vez.

```cpp
#pragma omp critical [(name)]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
(Opcional) Um nome para identificar o código crítico. O nome deve ser incluído entre parênteses.

### <a name="remarks"></a>Comentários

A `critical` diretiva não suporta cláusulas.

Para obter mais informações, consulte [2.6.2 construção crítica](../../../parallel/openmp/2-6-2-critical-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="flush"></a><a name="flush-openmp"></a>Flush

Especifica que todos os segmentos têm a mesma visão de memória para todos os objetos compartilhados.

```cpp
#pragma omp flush [(var)]
```

### <a name="parameters"></a>Parâmetros

*Var*<br/>
(Opcional) Uma lista separada por comma de variáveis que representam objetos que você deseja sincronizar. Se *o VAR* não for especificado, toda a memória é liberada.

### <a name="remarks"></a>Comentários

A `flush` diretiva não suporta cláusulas.

Para obter mais informações, consulte [2.6.5 diretiva flush](../../../parallel/openmp/2-6-5-flush-directive.md).

### <a name="example"></a>Exemplo

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

## <a name="for"></a><a name="for-openmp"></a>Para

Faz com que `for` o trabalho feito em um loop dentro de uma região paralela seja dividido entre os segmentos.

```cpp
#pragma omp [parallel] for [clauses]
   for_statement
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas, consulte a seção **Observações.**

*for_statement*<br/>
Um `for` loop. O comportamento indefinido resultará `for` se o código do usuário no loop mudar a variável de índice.

### <a name="remarks"></a>Comentários

A `for` diretiva suporta as seguintes cláusulas:

- [particulares](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [reduction](openmp-clauses.md#reduction)
- [Ordenou](openmp-clauses.md#ordered-openmp-clauses)
- [schedule](openmp-clauses.md#schedule)
- [Nowait](openmp-clauses.md#nowait)

Se `parallel` também for `clauses` especificado, pode ser `parallel` `for` qualquer cláusula `nowait`aceita pelas diretivas ou diretivas, exceto .

Para obter mais informações, consulte [2.4.1 para construir](../../../parallel/openmp/2-4-1-for-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="master"></a><a name="master"></a>Mestre

Especifica que apenas o segmento mestre deve executar uma seção do programa.

```cpp
#pragma omp master
{
   code_block
}
```

### <a name="remarks"></a>Comentários

A `master` diretiva não suporta cláusulas.

A [diretiva única](#single) permite especificar que uma seção de código deve ser executada em um único segmento, não necessariamente no segmento mestre.

Para obter mais informações, consulte [2.6.1 construção superior](../../../parallel/openmp/2-6-1-master-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="ordered"></a><a name="ordered-openmp-directives"></a>Ordenou

Especifica que o código `for` sob um loop paralelizado deve ser executado como um loop seqüencial.

```cpp
#pragma omp ordered
   structured-block
```

### <a name="remarks"></a>Comentários

A `ordered` diretiva deve estar dentro da `parallel for` extensão `ordered` dinâmica de um [para](#for-openmp) ou construir com uma cláusula.

A `ordered` diretiva não suporta cláusulas.

Para obter mais informações, consulte [2.6.6 construção ordenada](../../../parallel/openmp/2-6-6-ordered-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="parallel"></a><a name="parallel"></a>Paralelo

Define uma região paralela, que é o código que será executado por vários segmentos em paralelo.

```cpp
#pragma omp parallel [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas, consulte a seção **Observações.**

### <a name="remarks"></a>Comentários

A `parallel` diretiva suporta as seguintes cláusulas:

- [if](openmp-clauses.md#if-openmp)
- [particulares](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [Padrão](openmp-clauses.md#default-openmp)
- [Compartilhado](openmp-clauses.md#shared-openmp)
- [copyin](openmp-clauses.md#copyin)
- [reduction](openmp-clauses.md#reduction)
- [num_threads](openmp-clauses.md#num-threads)

`parallel`também pode ser usado com as diretivas [de for](#for-openmp) e [seções.](#sections-openmp)

Para obter mais informações, consulte [2.3 construção paralela](../../../parallel/openmp/2-3-parallel-construct.md).

### <a name="example"></a>Exemplo

A amostra a seguir mostra como definir o número de segmentos e definir uma região paralela. O número de threads é igual por padrão ao número de processadores lógicos na máquina. Por exemplo, se você tem uma máquina com um processador físico que tem hiperthreading ativado, ele terá dois processadores lógicos e dois threads. A ordem de saída pode variar em diferentes máquinas.

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

## <a name="sections"></a><a name="sections-openmp"></a>Seções

Identifica seções de código a serem divididas entre todos os segmentos.

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

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas, consulte a seção **Observações.**

### <a name="remarks"></a>Comentários

A `sections` diretiva pode conter `section` zero ou mais diretivas.

A `sections` diretiva suporta as seguintes cláusulas:

- [particulares](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [lastprivate](openmp-clauses.md#lastprivate)
- [reduction](openmp-clauses.md#reduction)
- [Nowait](openmp-clauses.md#nowait)

Se `parallel` também for `clauses` especificado, pode ser `parallel` `sections` qualquer cláusula `nowait`aceita pelas diretivas ou diretivas, exceto .

Para obter mais informações, consulte [2.4.2 seções de construção](../../../parallel/openmp/2-4-2-sections-construct.md).

### <a name="example"></a>Exemplo

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

## <a name="single"></a><a name="single"></a>Único

Permite especificar que uma seção de código deve ser executada em um único segmento, não necessariamente no segmento mestre.

```cpp
#pragma omp single [clauses]
{
   code_block
}
```

### <a name="parameters"></a>Parâmetros

*Cláusulas*<br/>
(Opcional) Zero ou mais cláusulas, consulte a seção **Observações.**

### <a name="remarks"></a>Comentários

A `single` diretiva suporta as seguintes cláusulas:

- [particulares](openmp-clauses.md#private-openmp)
- [firstprivate](openmp-clauses.md#firstprivate)
- [copyprivate](openmp-clauses.md#copyprivate)
- [Nowait](openmp-clauses.md#nowait)

A diretiva [mestre](#master) permite especificar que uma seção de código deve ser executada apenas no segmento mestre.

Para obter mais informações, consulte [2.4.3 single construct](../../../parallel/openmp/2-4-3-single-construct.md).

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

## <a name="threadprivate"></a><a name="threadprivate"></a>Threadprivate

Especifica que uma variável é privada para um segmento.

```cpp
#pragma omp threadprivate(var)
```

### <a name="parameters"></a>Parâmetros

*Var*<br/>
Uma lista separada por comma de variáveis que você deseja tornar privadas para um segmento. *var* deve ser uma variável global ou com escopo de namespace ou uma variável estática local.

### <a name="remarks"></a>Comentários

A `threadprivate` diretiva não suporta cláusulas.

A `threadprivate` diretiva é baseada no atributo [thread](../../../cpp/thread.md) usando a [palavra-chave __declspec;](../../../cpp/declspec.md) limites `__declspec(thread)` em `threadprivate`aplicar a . Por exemplo, `threadprivate` uma variável existirá em qualquer segmento iniciado no processo, não apenas os segmentos que fazem parte de uma equipe de segmentos gerada por uma região paralela. Esteja atento a esse detalhe de implementação; você pode notar que os `threadprivate` construtores para um tipo definido pelo usuário são chamados com mais freqüência do que o esperado.

Você pode `threadprivate` usar em uma DLL que está carregada estáticamente na `threadprivate` inicialização do processo, no entanto, você não pode usar em qualquer DLL que será carregada `LoadLibrary`via [LoadLibrary,](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) como DLLs que são carregados com [/DELAYLOAD (importação de carga de atraso)](../../../build/reference/delayload-delay-load-import.md), que também usa .

Uma `threadprivate` variável de um tipo *de destruição* não é garantida para ter seu destruidor chamado. Por exemplo:

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

Os usuários não têm controle sobre quando os segmentos que compõem a região paralela serão encerrados. Se esses segmentos existirem quando o processo sair, os segmentos não serão notificados sobre a saída do `threaded_var` processo, e o destructor não será solicitado em nenhum segmento, exceto aquele que sai (aqui, o segmento principal). Então o código não deve contar `threadprivate` com a destruição adequada de variáveis.

Para obter mais informações, consulte [diretiva privada thread2.7.1](../../../parallel/openmp/2-7-1-threadprivate-directive.md).

### <a name="example"></a>Exemplo

Para obter uma `threadprivate`amostra de uso, consulte [private](openmp-clauses.md#private-openmp).
