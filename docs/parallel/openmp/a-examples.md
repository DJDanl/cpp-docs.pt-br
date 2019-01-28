---
title: R. Exemplos
ms.date: 01/18/2019
ms.assetid: c0f6192f-a205-449b-b84c-cb30dbcc8b8f
ms.openlocfilehash: 061490d34829175bfbdcd84d6208aa396bb19671
ms.sourcegitcommit: 382e247c0f1b4cb7c2dab837b8b6fdff24bff47a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/28/2019
ms.locfileid: "55087295"
---
# <a name="a-examples"></a>R. Exemplos

A seguir estão exemplos das construções definidos neste documento. Uma declaração de uma diretiva a seguir é composta somente quando necessário, e uma instrução compound-não é recuada em relação uma diretiva que precede.

## <a name="a1-a-simple-loop-in-parallel"></a>A.1 loop simples do r em paralelo

O exemplo a seguir demonstra como paralelizar um loop usando a [paralela para](2-directives.md#251-parallel-for-construct) diretiva. A variável de iteração do loop é privada por padrão, portanto, não é necessário especificá-lo explicitamente em uma cláusula privada.

```cpp
#pragma omp parallel for
    for (i=1; i<n; i++)
        b[i] = (a[i] + a[i-1]) / 2.0;
```

## <a name="a2-conditional-compilation"></a>A.2 de compilação condicional

Os exemplos a seguir ilustram o uso de compilação condicional usando a macro OpenMP [OpenMP](2-directives.md#22-conditional-compilation). Com a compilação de OpenMP, o `_OPENMP` macro torna-se definida.

```cpp
# ifdef _OPENMP
    printf_s("Compiled by an OpenMP-compliant implementation.\n");
# endif
```

O operador de pré-processador definido permite que mais de uma macro a ser testado em uma única diretiva.

```cpp
# if defined(_OPENMP) && defined(VERBOSE)
    printf_s("Compiled by an OpenMP-compliant implementation.\n");
# endif
```

## <a name="a3-parallel-regions"></a>A.3 regiões em paralelo

O [paralela](2-directives.md#23-parallel-construct) diretiva pode ser usada em programas paralelos de alta granularidade. No exemplo a seguir, cada thread na região paralela decide qual parte da matriz global `x` funcione, com base no número de threads:

```cpp
#pragma omp parallel shared(x, npoints) private(iam, np, ipoints)
{
    iam = omp_get_thread_num();
    np =  omp_get_num_threads();
    ipoints = npoints / np;
    subdomain(x, iam, ipoints);
}
```

## <a name="a4-the-nowait-clause"></a>A.4 a cláusula nowait

Se houver muitos loops independentes dentro de uma região paralela, você pode usar o [nowait](2-directives.md#241-for-construct) cláusula para evitar a barreira implícita no final o `for` diretiva, da seguinte maneira:

```cpp
#pragma omp parallel
{
    #pragma omp for nowait
        for (i=1; i<n; i++)
             b[i] = (a[i] + a[i-1]) / 2.0;
    #pragma omp for nowait
        for (i=0; i<m; i++)
            y[i] = sqrt(z[i]);
}
```

## <a name="a5-the-critical-directive"></a>A.5 a diretiva critical

O exemplo a seguir inclui vários [críticos](2-directives.md#262-critical-construct) diretivas. O exemplo ilustra um modelo de enfileiramento de mensagens em que uma tarefa é removida da fila e trabalhou em. Para se proteger contra muitos threads remover da fila a mesma tarefa, a operação remover deve estar em um `critical` seção. Como as duas filas neste exemplo são independentes, eles são protegidos por `critical` com nomes diferentes, as diretivas *numérica de xaxis* e *yaxis*.

```cpp
#pragma omp parallel shared(x, y) private(x_next, y_next)
{
    #pragma omp critical ( xaxis )
        x_next = dequeue(x);
    work(x_next);
    #pragma omp critical ( yaxis )
        y_next = dequeue(y);
    work(y_next);
}
```

## <a name="a6-the-lastprivate-clause"></a>A.6 a cláusula lastprivate

Às vezes, a execução correta depende do valor que a última iteração de um loop atribui a uma variável. Esses programas devem listar todas as variáveis como argumentos para um [lastprivate](2-directives.md#2723-lastprivate) cláusula para que os valores das variáveis são o mesmo que quando o loop é executado em sequência.

```cpp
#pragma omp parallel
{
   #pragma omp for lastprivate(i)
      for (i=0; i<n-1; i++)
         a[i] = b[i] + b[i+1];
}
a[i]=b[i];
```

No exemplo anterior, o valor de `i` será igual ao final da região paralela `n-1`, como no caso sequencial.

## <a name="a7-the-reduction-clause"></a>A.7 a cláusula reduction

O exemplo a seguir demonstra a [redução](2-directives.md#2726-reduction) cláusula:

```cpp
#pragma omp parallel for private(i) shared(x, y, n) \
                         reduction(+: a, b)
    for (i=0; i<n; i++) {
        a = a + x[i];
        b = b + y[i];
    }
```

## <a name="a8-parallel-sections"></a>Seções de a.8 em paralelo

No exemplo a seguir (para [seção 2.4.2](2-directives.md#242-sections-construct)), funções *numérica de xaxis*, *yaxis*, e *zaxis* podem ser executadas simultaneamente. A primeira `section` diretiva é opcional.  Todos os `section` diretivas precisam aparecer na extensão de léxico o `parallel sections` construir.

```cpp
#pragma omp parallel sections
{
    #pragma omp section
        xaxis();
    #pragma omp section
        yaxis();
    #pragma omp section
        zaxis();
}
```

## <a name="a9-single-directives"></a>A.9 diretivas Single

O exemplo a seguir demonstra a [único](2-directives.md#243-single-construct) diretiva. No exemplo, apenas um thread (normalmente, o primeiro thread que encontra o `single` diretiva) imprime a mensagem de progresso. O usuário não deve fazer suposições para qual thread executará o `single` seção. Todos os outros segmentos ignorará a `single` seção e parar na barreira no final do `single` construir. Se outros threads podem prosseguir sem aguardar o thread em execução a `single` seção, uma `nowait` cláusula pode ser especificada no `single` diretiva.

```cpp
#pragma omp parallel
{
    #pragma omp single
        printf_s("Beginning work1.\n");
    work1();
    #pragma omp single
        printf_s("Finishing work1.\n");
    #pragma omp single nowait
        printf_s("Finished work1 and beginning work2.\n");
    work2();
}
```

## <a name="a10-sequential-ordering"></a>A.10 sequencial ordenação

[Ordenado seções](2-directives.md#266-ordered-construct) são úteis para ordenação sequencialmente a saída do trabalho realizado em paralelo. O programa a seguir imprime os índices em ordem sequencial:

```cpp
#pragma omp for ordered schedule(dynamic)
    for (i=lb; i<ub; i+=st)
        work(i);
void work(int k)
{
    #pragma omp ordered
        printf_s(" %d", k);
}
```

## <a name="a11-a-fixed-number-of-threads"></a>A.11 um número fixo de threads

Alguns programas dependem de um número fixo previamente especificado de threads para executar corretamente.  Como a configuração padrão para o ajuste dinâmico do número de threads é definido pela implementação, desses programas podem optar por desativar o recurso dinâmico threads e definir o número de threads explicitamente para manter a portabilidade. O exemplo a seguir mostra como fazer isso usando [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function), e [omp_set_num_threads](3-run-time-library-functions.md#311-omp_set_num_threads-function):

```cpp
omp_set_dynamic(0);
omp_set_num_threads(16);
#pragma omp parallel shared(x, npoints) private(iam, ipoints)
{
    if (omp_get_num_threads() != 16)
      abort();
    iam = omp_get_thread_num();
    ipoints = npoints/16;
    do_by_16(x, iam, ipoints);
}
```

Neste exemplo, o programa seja executado corretamente somente se ele é executado pelo 16 threads. Se a implementação não é capaz de dar suporte a 16 threads, o comportamento deste exemplo é definido pela implementação.

O número de threads de execução de uma região parallel permanece constante durante uma região parallel, independentemente dos threads dinâmicos de configuração. O mecanismo de threads dinâmica determina o número de threads a serem usados no início da região paralela e mantém constante para a duração da região.

## <a name="a12-the-atomic-directive"></a>A.12 a diretiva atomic

O exemplo a seguir evita as condições de corrida (atualizações simultâneas de um elemento de *x* por muitos threads) usando o [atômica](2-directives.md#264-atomic-construct) diretiva:

```cpp
#pragma omp parallel for shared(x, y, index, n)
    for (i=0; i<n; i++)
    {
        #pragma omp atomic
            x[index[i]] += work1(i);
        y[i] += work2(i);
    }
```

A vantagem de usar o `atomic` diretiva neste exemplo é que ele permite que as atualizações de dois elementos diferentes de x ocorram em paralelo. Se um [críticos](2-directives.md#262-critical-construct) diretiva é usada em vez disso, em seguida, todas as atualizações aos elementos da *x* são executadas em série (embora não em qualquer garantia de ordem).

O `atomic` diretiva se aplica somente à instrução C ou C++ imediatamente após ele.  Como resultado, os elementos de *y* não forem atualizados atomicamente neste exemplo.

## <a name="a13-a-flush-directive-with-a-list"></a>A.13 um diretiva flush com uma lista

O exemplo a seguir usa o `flush` diretriz para a sincronização de ponto a ponto de objetos específicos entre pares de threads:

```cpp
int   sync[NUMBER_OF_THREADS];
float work[NUMBER_OF_THREADS];
#pragma omp parallel private(iam,neighbor) shared(work,sync)
{
    iam = omp_get_thread_num();
    sync[iam] = 0;
    #pragma omp barrier

    // Do computation into my portion of work array
    work[iam] = ...;

    //  Announce that I am done with my work
    // The first flush ensures that my work is
    // made visible before sync.
    // The second flush ensures that sync is made visible.
    #pragma omp flush(work)
    sync[iam] = 1;
    #pragma omp flush(sync)

    // Wait for neighbor
    neighbor = (iam>0 ? iam : omp_get_num_threads()) - 1;
    while (sync[neighbor]==0)
    {
        #pragma omp flush(sync)
    }

    // Read neighbor's values of work array
    ... = work[neighbor];
}
```

## <a name="a14-a-flush-directive-without-a-list"></a>A.14 um diretiva flush sem uma lista

O exemplo a seguir (para [seção 2.6.5](2-directives.md#265-flush-directive)) distingue os objetos compartilhados afetados por um `flush` diretiva com nenhuma lista de objetos compartilhados que não são afetados:

```cpp
// omp_flush_without_list.c
#include <omp.h>

int x, *p = &x;

void f1(int *q)
{
    *q = 1;
    #pragma omp flush
    // x, p, and *q are flushed
    //   because they are shared and accessible
    // q is not flushed because it is not shared.
}

void f2(int *q)
{
    #pragma omp barrier
    *q = 2;

    #pragma omp barrier
    // a barrier implies a flush
    // x, p, and *q are flushed
    //   because they are shared and accessible
    // q is not flushed because it is not shared.
}

int g(int n)
{
    int i = 1, j, sum = 0;
    *p = 1;

    #pragma omp parallel reduction(+: sum) num_threads(10)
    {
        f1(&j);
        // i, n and sum were not flushed
        //   because they were not accessible in f1
        // j was flushed because it was accessible
        sum += j;
        f2(&j);
        // i, n, and sum were not flushed
        //   because they were not accessible in f2
        // j was flushed because it was accessible
        sum += i + j + *p + n;
    }
    return sum;
}

int main()
{
}
```

## <a name="a15-the-number-of-threads-used"></a>A.15 o número de threads usados

Considere o seguinte exemplo incorreto (para [seção 3.1.2](3-run-time-library-functions.md#312-omp_get_num_threads-function)):

```cpp
np = omp_get_num_threads(); // misplaced
#pragma omp parallel for schedule(static)
    for (i=0; i<np; i++)
        work(i);
```

O `omp_get_num_threads()` chamar retorna 1 na seção serial do código, então *np* sempre será igual a 1 no exemplo anterior. Para determinar o número de threads que serão implantados para a região paralela, a chamada deve ser dentro da região paralela.

O exemplo a seguir mostra como reescrever esse programa sem a inclusão de uma consulta para o número de threads:

```cpp
#pragma omp parallel private(i)
{
    i = omp_get_thread_num();
    work(i);
}
```

## <a name="a16-locks"></a>A.16 bloqueios

No exemplo a seguir (para [seção 3.2](3-run-time-library-functions.md#32-lock-functions)), o argumento para as funções de bloqueio deve ter tipo `omp_lock_t`, e que não é necessário para liberar a ele.  As funções de bloqueio fazer com que os threads para ficar ocioso enquanto aguarda a entrada para a primeira seção crítica, mas para executar outras tarefas enquanto aguarda a entrada para o segundo.  O `omp_set_lock` blocos de função, mas o `omp_test_lock` não de função, permitindo que o trabalho em `skip()` ser feito.

```cpp
// omp_using_locks.c
// compile with: /openmp /c
#include <stdio.h>
#include <omp.h>

void work(int);
void skip(int);

int main() {
   omp_lock_t lck;
   int id;

   omp_init_lock(&lck);
   #pragma omp parallel shared(lck) private(id)
   {
      id = omp_get_thread_num();

      omp_set_lock(&lck);
      printf_s("My thread id is %d.\n", id);

      // only one thread at a time can execute this printf
      omp_unset_lock(&lck);

      while (! omp_test_lock(&lck)) {
         skip(id);   // we do not yet have the lock,
                     // so we must do something else
      }
      work(id);     // we now have the lock
                    // and can do the work
      omp_unset_lock(&lck);
   }
   omp_destroy_lock(&lck);
}
```

## <a name="a17-nestable-locks"></a>A.17 os bloqueios Aninháveis

O exemplo a seguir (para [seção 3.2](3-run-time-library-functions.md#32-lock-functions)) demonstra como um bloqueio empilhável pode ser usado para sincronizar as atualizações para toda a estrutura e um de seus membros.

```cpp
#include <omp.h>
typedef struct {int a,b; omp_nest_lock_t lck;} pair;

void incr_a(pair *p, int a)
{
    // Called only from incr_pair, no need to lock.
    p->a += a;
}

void incr_b(pair *p, int b)
{
    // Called both from incr_pair and elsewhere,
    // so need a nestable lock.

    omp_set_nest_lock(&p->lck);
    p->b += b;
    omp_unset_nest_lock(&p->lck);
}

void incr_pair(pair *p, int a, int b)
{
    omp_set_nest_lock(&p->lck);
    incr_a(p, a);
    incr_b(p, b);
    omp_unset_nest_lock(&p->lck);
}

void f(pair *p)
{
    extern int work1(), work2(), work3();
    #pragma omp parallel sections
    {
        #pragma omp section
            incr_pair(p, work1(), work2());
        #pragma omp section
            incr_b(p, work3());
    }
}
```

## <a name="a18-nested-for-directives"></a>A.18 aninhado para diretivas

O exemplo a seguir do `for` [aninhamento de diretiva](2-directives.md#29-directive-nesting) está em conformidade porque internas e externas `for` diretivas associar a diferente regiões em paralelo:

```cpp
#pragma omp parallel default(shared)
{
    #pragma omp for
        for (i=0; i<n; i++)
        {
            #pragma omp parallel shared(i, n)
            {
                #pragma omp for
                    for (j=0; j<n; j++)
                        work(i, j);
            }
        }
}
```

Uma variação seguir do exemplo anterior também é compatível com:

```cpp
#pragma omp parallel default(shared)
{
    #pragma omp for
        for (i=0; i<n; i++)
            work1(i, n);
}

void work1(int i, int n)
{
    int j;
    #pragma omp parallel default(shared)
    {
        #pragma omp for
            for (j=0; j<n; j++)
                work2(i, j);
    }
    return;
}
```

## <a name="a19-examples-showing-incorrect-nesting-of-work-sharing-directives"></a>A.19 exemplos que mostram o aninhamento incorreto de compartilhamento de trabalho de diretivas

Os exemplos nesta seção ilustram as [aninhamento de diretiva](2-directives.md#29-directive-nesting) regras.

O exemplo a seguir não está em conformidade porque internas e externas `for` diretivas que estão aninhadas e associar à mesma `parallel` diretiva:

```cpp
void wrong1(int n)
{
  #pragma omp parallel default(shared)
  {
      int i, j;
      #pragma omp for
      for (i=0; i<n; i++) {
          #pragma omp for
              for (j=0; j<n; j++)
                 work(i, j);
     }
   }
}
```

A seguinte versão dinamicamente aninhada do exemplo anterior também está fora de conformidade:

```cpp
void wrong2(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++)
        work1(i, n);
  }
}

void work1(int i, int n)
{
  int j;
  #pragma omp for
    for (j=0; j<n; j++)
      work2(i, j);
}
```

O exemplo a seguir não está em conformidade porque o `for` e `single` diretivas estão aninhadas e eles se ligam para a mesma região paralela:

```cpp
void wrong3(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++) {
        #pragma omp single
          work(i);
      }
  }
}
```

O exemplo a seguir não está em conformidade porque uma `barrier` diretiva dentro de um `for` pode resultar em deadlock:

```cpp
void wrong4(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++) {
        work1(i);
        #pragma omp barrier
        work2(i);
      }
  }
}
```

O exemplo a seguir não está em conformidade porque a `barrier` resulta em deadlock devido ao fato de que apenas um thread por vez pode inserir a seção crítica:

```cpp
void wrong5()
{
  #pragma omp parallel
  {
    #pragma omp critical
    {
       work1();
       #pragma omp barrier
       work2();
    }
  }
}
```

O exemplo a seguir não está em conformidade porque o `barrier` resulta em deadlock devido ao fato de que apenas um thread executa o `single` seção:

```cpp
void wrong6()
{
  #pragma omp parallel
  {
    setup();
    #pragma omp single
    {
      work1();
      #pragma omp barrier
      work2();
    }
    finish();
  }
}
```

## <a name="a20-bind-barrier-directives"></a>A.20 diretivas de barreira de ligação

A associação de diretiva de regras de chamada para um `barrier` diretiva para associar a mais próxima circunscrição `parallel` diretiva. Para obter mais informações sobre associação de diretiva, consulte [seção 2.8](2-directives.md#28-directive-binding).

No exemplo a seguir, a chamada de *principal* para *sub2* está em conformidade porque a `barrier` (no *sub3*) é associado a região paralela em *sub2* . A chamada de *principal* para *sub1* está em conformidade porque as `barrier` liga para a região paralela na sub-rotina *sub2*.  A chamada de *principal* à *sub3* está em conformidade porque o `barrier` não se associa a qualquer região paralela e será ignorado. Além disso, o `barrier` sincroniza somente a equipe de threads na região paralela delimitador e nem todos os threads criados no *sub1*.

```cpp
int main()
{
    sub1(2);
    sub2(2);
    sub3(2);
}

void sub1(int n)
{
    int i;
    #pragma omp parallel private(i) shared(n)
    {
        #pragma omp for
        for (i=0; i<n; i++)
            sub2(i);
    }
}

void sub2(int k)
{
     #pragma omp parallel shared(k)
     sub3(k);
}

void sub3(int n)
{
    work(n);
    #pragma omp barrier
    work(n);
}
```

## <a name="a21-scope-variables-with-the-private-clause"></a>A.21 variáveis de escopo com a cláusula private

Os valores de `i` e `j` no exemplo a seguir não estão definidos na saída da região paralela:

```cpp
int i, j;
i = 1;
j = 2;
#pragma omp parallel private(i) firstprivate(j)
{
  i = 3;
  j = j + 2;
}
printf_s("%d %d\n", i, j);
```

Para obter mais informações sobre o `private` cláusula, consulte [seção 2.7.2.1](2-directives.md#2721-private).

## <a name="a22-the-defaultnone-clause"></a>A.22 a cláusula default (none)

O exemplo a seguir distingue as variáveis que são afetadas pelo `default(none)` cláusula das variáveis que não são:

```cpp
// openmp_using_clausedefault.c
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int x, y, z[1000];
#pragma omp threadprivate(x)

void fun(int a) {
   const int c = 1;
   int i = 0;

   #pragma omp parallel default(none) private(a) shared(z)
   {
      int j = omp_get_num_thread();
             //O.K.  - j is declared within parallel region
      a = z[j];       // O.K.  - a is listed in private clause
                      //      - z is listed in shared clause
      x = c;          // O.K.  - x is threadprivate
                      //      - c has const-qualified type
      z[i] = y;       // C3052 error - cannot reference i or y here

      #pragma omp for firstprivate(y)
         for (i=0; i<10 ; i++) {
            z[i] = y;  // O.K. - i is the loop control variable
                       // - y is listed in firstprivate clause
          }
       z[i] = y;   // Error - cannot reference i or y here
   }
}
```

Para obter mais informações sobre o `default` cláusula, consulte [seção 2.7.2.5](2-directives.md#2725-default).

## <a name="a23-examples-of-the-ordered-directive"></a>A.23 exemplos da diretiva ordered

É possível ter muitas seções ordenadas com uma `for` especificado com o `ordered` cláusula. O primeiro exemplo é em não conformidade porque a API Especifica a regra a seguir:

"Uma iteração de um loop com um `for` constructo não deve executar a mesma `ordered` diretiva mais de uma vez e ele não devem executar mais de um `ordered` diretiva." (Consulte [seção 2.6.6](2-directives.md#266-ordered-construct).)

Neste exemplo não compatível, todas as iterações executar duas seções ordenadas:

```cpp
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    #pragma omp ordered
    { ... }
    ...
    #pragma omp ordered
    { ... }
    ...
}
```

A conformidade de exemplo a seguir mostra um `for` com mais de uma seção ordenada:

```cpp
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    if (i <= 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
    (i > 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
}
```

## <a name="a24-example-of-the-private-clause"></a>A.24 exemplo da cláusula private

O [privada](2-directives.md#2721-private) cláusula de uma região parallel tem efeito somente para a extensão de léxica da região, e não para a extensão dinâmica da região.  Portanto, no exemplo a seguir, quaisquer usos da variável *uma* dentro a `for` loop na rotina *f* refere-se a uma cópia privada do *um*, enquanto um uso em rotina *g* refere-se ao global *um*.

```cpp
int a;

void f(int n)
{
    a = 0;

    #pragma omp parallel for private(a)
    for (int i=1; i<n; i++)
    {
        a = i;
        g(i, n);
        d(a);     // Private copy of "a"
        ...
    }
    ...

void g(int k, int n)
{
    h(k,a); // The global "a", not the private "a" in f
}
```

## <a name="a25-examples-of-the-copyprivate-data-attribute-clause"></a>A.25 exemplos da cláusula de atributo de dados copyprivate

**Exemplo 1:** O [copyprivate](2-directives.md#2728-copyprivate) cláusula pode ser usada para transmitir valores adquiridos por um único thread diretamente a todas as instâncias de variáveis particulares em outros threads.

```cpp
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

**Exemplo 2:** Em contraste com o exemplo anterior, suponha que a leitura deve ser executada por um thread específico, digamos que o thread mestre. Nesse caso, o `copyprivate` cláusula não pode ser usada para fazer a difusão diretamente, mas ele pode ser usado para fornecer acesso a um objeto compartilhado temporário.

```cpp
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

**Exemplo 3:** Suponha que o número de objetos de bloqueio necessários dentro de uma região paralela facilmente não pode ser determinado antes de inseri-la. O `copyprivate` cláusula pode ser usada para fornecer acesso a objetos de bloqueio compartilhado que são alocados nessa região paralela.

```cpp
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

## <a name="a26-the-threadprivate-directive"></a>A.26 a diretiva threadprivate

Os exemplos a seguir demonstram como usar o [threadprivate](2-directives.md#271-threadprivate-directive) diretiva para dar a cada thread um contador separado.

### <a name="example-1"></a>Exemplo 1

```cpp
int counter = 0;
#pragma omp threadprivate(counter)

int sub()
{
    counter++;
    return(counter);
}
```

### <a name="example-2"></a>Exemplo 2

```cpp
int sub()
{
    static int counter = 0;
    #pragma omp threadprivate(counter)
    counter++;
    return(counter);
}
```

## <a name="a27-c99-variable-length-arrays"></a>Matrizes de comprimento variável C99 A.27

O exemplo a seguir demonstra como usar matrizes de comprimento variável C99 (VLAs) em um [firstprivate](2-directives.md#2722-firstprivate) diretiva.

> [!NOTE]
> Atualmente, não há suporte para matrizes de comprimento variável no Visual C++.

```cpp
void f(int m, int C[m][m])
{
    double v1[m];
    ...
    #pragma omp parallel firstprivate(C, v1)
    ...
}
```

## <a name="a28-the-numthreads-clause"></a>A.28 a cláusula num_threads

O exemplo a seguir demonstra a [num_threads](2-directives.md#23-parallel-construct) cláusula. A região paralela é executado com um máximo de 10 threads.

```cpp
#include <omp.h>
main()
{
    omp_set_dynamic(1);
    ...
    #pragma omp parallel num_threads(10)
    {
        ... parallel region ...
    }
}
```

## <a name="a29-work-sharing-constructs-inside-a-critical-construct"></a>A.29 construções de compartilhamento de trabalho em um construto crítico

O exemplo a seguir demonstra o uso de uma construção de compartilhamento de trabalho dentro de um `critical` construir. Este exemplo está em conformidade porque o compartilhamento de trabalho de construir e o `critical` constructo não estão vinculados à mesma região paralela.

```cpp
void f()
{
  int i = 1;
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp critical (name)
      {
        #pragma omp parallel
        {
          #pragma omp single
          {
            i++;
          }
        }
      }
    }
  }
}
```

## <a name="a30-reprivatization"></a>A.30 Reprivatização

O exemplo a seguir demonstra a reprivatização de variáveis. Variáveis privadas podem ser marcadas `private` novamente em uma diretiva aninhada. Você não precisa compartilhar essas variáveis na região paralela delimitador.

```cpp
int i, a;
...
#pragma omp parallel private(a)
{
  ...
  #pragma omp parallel for private(a)
  for (i=0; i<10; i++)
     {
       ...
     }
}
```

## <a name="a31-thread-safe-lock-functions"></a>A.31 funções de bloqueio de Thread-safe

O exemplo C++ a seguir demonstra como inicializar uma matriz de bloqueios em uma região paralela usando [funções omp_init_lock](3-run-time-library-functions.md#321-omp_init_lock-and-omp_init_nest_lock-functions).

```cpp
// A_13_omp_init_lock.cpp
// compile with: /openmp
#include <omp.h>

omp_lock_t *new_locks() {
   int i;
   omp_lock_t *lock = new omp_lock_t[1000];
   #pragma omp parallel for private(i)
   for (i = 0 ; i < 1000 ; i++)
      omp_init_lock(&lock[i]);

   return lock;
}

int main () {}
```
