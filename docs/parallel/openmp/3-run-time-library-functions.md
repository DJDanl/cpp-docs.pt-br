---
title: 3. Funções da biblioteca em tempo de execução
ms.date: 01/17/2019
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
ms.openlocfilehash: 3eb6dc4110145a6c45dbdd772deaee3023e68e9d
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525041"
---
# <a name="3-run-time-library-functions"></a>3. Funções da biblioteca em tempo de execução

Esta seção descreve as funções da biblioteca de tempo de execução OpenMP C e C++. O cabeçalho  **\<OMP >** declara dois tipos, várias funções que podem ser usadas para controlar e consultar o ambiente de execução paralela e funções que podem ser usadas para sincronizar o acesso aos dados de bloqueio.

O tipo `omp_lock_t` é um tipo de objeto capaz de representar a que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são denominados *bloqueios simples*.

O tipo `omp_nest_lock_t` é um tipo de objeto capaz de representar qualquer um dos que um bloqueio está disponível ou a identidade do thread que possui o bloqueio e um *contagem de aninhamento* (descritos abaixo). Esses bloqueios são denominados *bloqueios aninháveis*.

As funções de biblioteca são funções externas com vínculo "C".

As descrições deste capítulo são divididas nos seguintes tópicos:

- [Funções do ambiente de execução](#31-execution-environment-functions)
- [Funções de bloqueio](#32-lock-functions)
- [Rotinas de tempo](#33-timing-routines)

## <a name="31-execution-environment-functions"></a>3.1 funções do ambiente de execução

As funções descritas nesta seção afetam e monitoram os threads, processadores e o ambiente paralelo:

- [omp_set_num_threads](#311-omp_set_num_threads-function)
- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [omp_get_max_threads](#313-omp_get_max_threads-function)
- [omp_get_thread_num](#314-omp_get_thread_num-function)
- [omp_get_num_procs](#315-omp_get_num_procs-function)
- [omp_in_parallel](#316-omp_in_parallel-function)
- [omp_set_dynamic](#317-omp_set_dynamic-function)
- [omp_get_dynamic](#318-omp_get_dynamic-function)
- [omp_set_nested](#319-omp_set_nested-function)
- [omp_get_nested](#3110-omp_get_nested-function)

### <a name="311-omp_set_num_threads-function"></a>3.1.1 função omp_set_num_threads

O `omp_set_num_threads` função define o número padrão de threads a serem usados para mais tarde regiões em paralelo que não especificam um `num_threads` cláusula. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_num_threads(int num_threads);
```

O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o `omp_set_num_threads` função e o ajuste dinâmico de threads, consulte [seção 2.3](2-directives.md#23-parallel-construct).

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero. Se ele é chamado de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Essa chamada tem precedência sobre o `OMP_NUM_THREADS` variável de ambiente. O valor padrão para o número de threads, o que pode ser estabelecida chamando `omp_set_num_threads` ou definindo o `OMP_NUM_THREADS` variável de ambiente podem ser substituídos explicitamente em uma única `parallel` diretiva especificando o `num_threads` cláusula.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_set_dynamic](#317-omp_set_dynamic-function) function
- [omp_get_dynamic](#318-omp_get_dynamic-function) function
- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente
- [num_threads](2-directives.md#23-parallel-construct) cláusula

### <a name="312-omp_get_num_threads-function"></a>3.1.2 função omp_get_num_threads

O `omp_get_num_threads` função retorna o número de threads atualmente na equipe que está executando a região paralela do qual ele é chamado. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_threads(void);
```

O `num_threads` cláusula, o `omp_set_num_threads` função e o `OMP_NUM_THREADS` variável de ambiente controla o número de threads em uma equipe.

Se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido pela implementação. Essa função é associado a mais próxima circunscrição `parallel` diretiva. Se chamado de uma parte serial de um programa ou de uma região paralela aninhada que é serializada, essa função retorna 1.

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads)
- [num_threads](2-directives.md#23-parallel-construct)
- [parallel](2-directives.md#23-parallel-construct)

### <a name="313-omp_get_max_threads-function"></a>3.1.3 função omp_get_max_threads

O `omp_get_max_threads` função retorna um inteiro que tem garantia de ser pelo menos tão grande quanto o número de threads que seriam usadas para formar uma equipe se uma região parallel sem um `num_threads` cláusula tivesse de ser vista nesse ponto no código. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_max_threads(void);
```

A seguir expressa um limite inferior no valor de `omp_get_max_threads`:

```

threads-used-for-next-team
<= omp_get_max_threads
```

Observe que se paralela outra região usa o `num_threads` cláusula para solicitar um número específico de segmentos, a garantia sobre o limite inferior do resultado da `omp_get_max_threads` nenhuma retenção de longo.

O `omp_get_max_threads` o valor de retorno da função pode ser usado para alocar dinamicamente um armazenamento suficiente para todos os threads da equipe formada na próxima região paralela.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [omp_set_num_threads](#311-omp_set_num_threads-function)
- [omp_set_dynamic](#317-omp_set_dynamic-function)
- [num_threads](2-directives.md#23-parallel-construct)

### <a name="314-omp_get_thread_num-function"></a>3.1.4 função omp_get_thread_num

O `omp_get_thread_num` função retorna o número de threads, dentro de sua equipe do thread executando a função. O reside número de threads entre 0 e `omp_get_num_threads()`-1, inclusivo. O thread mestre da equipe é 0.

O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_thread_num(void);
```

Se for chamado de uma região serial, `omp_get_thread_num` retornará 0. Se chamado de dentro de uma região paralela aninhada que é serializada, essa função retorna 0.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function) função

### <a name="315-omp_get_num_procs-function"></a>3.1.5 função omp_get_num_procs

O `omp_get_num_procs` função retorna o número de processadores que estão disponíveis para o programa no momento em que a função é chamada. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_procs(void);
```

### <a name="316-omp_in_parallel-function"></a>3.1.6 função omp_in_parallel

O `omp_in_parallel` função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região paralela em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_in_parallel(void);
```

Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, incluindo as regiões aninhadas que são serializadas.

### <a name="317-omp_set_dynamic-function"></a>3.1.7 função omp_set_dynamic

O `omp_set_dynamic` função ativa ou desativa o ajuste dinâmico do número de threads disponíveis para a execução de regiões em paralelo. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_dynamic(int dynamic_threads);
```

Se *dynamic_threads* é avaliada como um valor diferente de zero, o número de threads que são usados para execução futuro regiões em paralelo pode ser ajustado automaticamente pelo ambiente de tempo de execução para usar melhor os recursos do sistema. Como consequência, o número de threads especificado pelo usuário é a contagem máxima de threads. O número de threads na execução de uma região parallel equipe permanece fixo para a duração da região paralela e é reportado pelo `omp_get_num_threads` função.

Se *dynamic_threads* é avaliada como 0, o ajuste dinâmico está desabilitado.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero. Se ele é chamado de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Uma chamada para `omp_set_dynamic` tem precedência sobre o `OMP_DYNAMIC` variável de ambiente.

O padrão para o ajuste dinâmico de threads é definido pela implementação. Como resultado, os códigos de usuário que dependem de um número específico de threads para execução correta devem desabilitar explicitamente threads dinâmicos. Implementações não são necessários para fornecer a capacidade de ajustar dinamicamente o número de threads, mas eles são necessários para fornecer a interface para dar suporte à portabilidade entre todas as plataformas.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="318-omp_get_dynamic-function"></a>3.1.8 função omp_get_dynamic

O `omp_get_dynamic` função retorna um valor diferente de zero se o ajuste dinâmico de threads está habilitado e, caso contrário, retornará 0. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_dynamic(void);
```

Se a implementação não implementa o ajuste dinâmico do número de threads, essa função sempre retorna 0.

#### <a name="cross-references"></a>Referências cruzadas

- Para obter uma descrição de ajuste dinâmico de thread, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

### <a name="319-omp_set_nested-function"></a>3.1.9 função omp_set_nested

O `omp_set_nested` função habilita ou desabilita o paralelismo aninhado. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_nested(int nested);
```

Se *aninhada* é avaliada como 0, aninhados paralelismo estiver desabilitado, o que é o padrão e regiões em paralelo aninhadas são serializadas e executadas pelo thread atual. Caso contrário, o paralelismo aninhado está habilitado e regiões em paralelo que estão aninhado podem implantar threads adicionais para formar equipes aninhadas.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero. Se ele é chamado de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Essa chamada tem precedência sobre o `OMP_NESTED` variável de ambiente.

Quando o paralelismo aninhado é habilitado, o número de threads usados para executar as regiões aninhadas paralelas é definido pela implementação. Como resultado, as implementações em conformidade com o OpenMP têm permissão para serializar aninhadas regiões em paralelo, mesmo quando o paralelismo aninhado está habilitado.

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NESTED](4-environment-variables.md#44-omp_nested)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="3110-omp_get_nested-function"></a>3.1.10 função omp_get_nested

O `omp_get_nested` função retorna um valor diferente de zero se o paralelismo aninhado estiver habilitado e 0 se ele estiver desabilitado. Para obter mais informações sobre o paralelismo aninhada, consulte [omp_set_nested](#319-omp_set_nested-function). O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_nested(void);
```

Se uma implementação não implementa o paralelismo aninhado, essa função sempre retorna 0.

## <a name="32-lock-functions"></a>3.2 funções de bloqueio

As funções descritas nesta seção manipulam bloqueios usados para sincronização.

Para as funções a seguir, a variável de bloqueio deve ter tipo `omp_lock_t`. Essa variável deve ser acessada somente por meio dessas funções. Todas as funções de bloqueio exigem um argumento que tem um ponteiro para `omp_lock_t` tipo.

- O [funções omp_init_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) função inicializa um bloqueio simples.
- O [funções omp_destroy_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) função remove um bloqueio simples.
- O [omp_set_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) função aguarda até que um bloqueio simple está disponível.
- O [funções omp_unset_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) função libera um bloqueio simples.
- O [funções omp_test_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) função testa um bloqueio simples.

Para as funções a seguir, a variável de bloqueio deve ter tipo `omp_nest_lock_t`.  Essa variável deve ser acessada somente por meio dessas funções. Todas as funções de bloqueio empilhável exigem um argumento que tem um ponteiro para `omp_nest_lock_t` tipo.

- O [omp_init_nest_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) função inicializa um bloqueio empilhável.
- O [omp_destroy_nest_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) função remove um bloqueio empilhável.
- O [omp_set_nest_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) função aguarda até que um bloqueio empilhável está disponível.
- O [omp_unset_nest_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) função libera um bloqueio empilhável.
- O [omp_test_nest_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) função testa um bloqueio empilhável.

As funções de bloqueio do OpenMP acessam a variável de bloqueio de tal forma que eles sempre leia e atualizam o valor mais atual da variável de bloqueio. Portanto, não é necessária para um programa OpenMP incluem explícita `flush` diretivas para certificar-se de que o valor da variável de bloqueio é consistente entre diferentes threads. (Pode haver a necessidade de `flush` diretivas para tornar os valores de outras variáveis consistentes.)

### <a name="321-omp_init_lock-and-omp_init_nest_lock-functions"></a>3.2.1 funções funções omp_init_lock e omp_init_nest_lock

Essas funções fornecem o único meio de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao parâmetro *bloqueio* para uso em futuras chamadas. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_init_lock(omp_lock_t *lock);
void omp_init_nest_lock(omp_nest_lock_t *lock);
```

O estado inicial é desbloqueado (ou seja, nenhum thread possui o bloqueio). Para obter um bloqueio empilhável, a contagem inicial de aninhamento é zero. Ele está em conformidade para chamar qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializado.

### <a name="322-omp_destroy_lock-and-omp_destroy_nest_lock-functions"></a>3.2.2 funções funções omp_destroy_lock e omp_destroy_nest_lock

Essas funções ter certeza de que a bloquear a variável apontada *bloqueio* não foi inicializada. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_destroy_lock(omp_lock_t *lock);
void omp_destroy_nest_lock(omp_nest_lock_t *lock);
```

Ele não for compatível para chamar qualquer uma dessas rotinas com uma variável de bloqueio que não foi inicializada ou desbloqueada.

### <a name="323-omp_set_lock-and-omp_set_nest_lock-functions"></a>3.2.3 funções funções omp_set_lock e omp_set_nest_lock

Cada uma dessas funções bloqueia o thread de execução da função até o bloqueio especificado está disponível e, em seguida, define o bloqueio. Um bloqueio simples estará disponível se ele for desbloqueado. Um bloqueio empilhável estará disponível se ele está desbloqueado ou se ele já pertence ao thread executando a função. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_lock(omp_lock_t *lock);
void omp_set_nest_lock(omp_nest_lock_t *lock);
```

Para um bloqueio simple, o argumento para o `omp_set_lock` função deve apontar para uma variável inicializada de bloqueio. Propriedade do bloqueio é concedida para o thread de execução da função.

Para um bloqueio empilhável, o argumento para o `omp_set_nest_lock` função deve apontar para uma variável inicializada de bloqueio. A contagem de aninhamento é incrementada e o thread é concedido ou mantém a propriedade do bloqueio.

### <a name="324-omp_unset_lock-and-omp_unset_nest_lock-functions"></a>3.2.4 funções funções omp_unset_lock e omp_unset_nest_lock

Essas funções fornecem os meios de propriedade de um bloqueio de liberação. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_unset_lock(omp_lock_t *lock);
void omp_unset_nest_lock(omp_nest_lock_t *lock);
```

O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializado pelo thread de execução da função de propriedade. O comportamento será indefinido se o thread não possui o bloqueio.

Para obter um bloqueio simple, o `omp_unset_lock` função libera o thread de execução da função de propriedade do bloqueio.

Para obter um bloqueio empilhável, o `omp_unset_nest_lock` função diminui a contagem de aninhamento e versões, o thread de execução da função de propriedade do bloqueio, se a contagem resultante é zero.

### <a name="325-omp_test_lock-and-omp_test_nest_lock-functions"></a>3.2.5 funções funções omp_test_lock e omp_test_nest_lock

Essas funções tentam definir um bloqueio, mas não bloqueiam a execução do thread. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_test_lock(omp_lock_t *lock);
int omp_test_nest_lock(omp_nest_lock_t *lock);
```

O argumento deve apontar para uma variável inicializada de bloqueio. Essas funções tentam definir um bloqueio da mesma maneira como `omp_set_lock` e `omp_set_nest_lock`, exceto que eles não bloqueiam a execução do thread.

Para obter um bloqueio simple, o `omp_test_lock` função retorna um valor diferente de zero se o bloqueio é definido com êxito; caso contrário, retornará zero.

Para obter um bloqueio empilhável, o `omp_test_nest_lock` função retorna a nova contagem de aninhamento se o bloqueio é definido com êxito; caso contrário, retornará zero.

## <a name="33-timing-routines"></a>3.3 rotinas de tempo

As funções descritas nesta seção dão suporte a um temporizador de relógio portátil:

- O [omp_get_wtime](#331-omp_get_wtime-function) função retorna a hora do relógio decorrida.
- O [omp_get_wtick](#332-omp_get_wtick-function) função retorna segundos entre os tiques do relógio sucessivas.

### <a name="331-omp_get_wtime-function"></a>3.3.1 função omp_get_wtime

O `omp_get_wtime` função retorna um valor de ponto flutuante de precisão dupla igual para o tempo do relógio decorrido em segundos desde alguma "hora no passado".  O "tempo no passado" real é arbitrário, mas há garantia de que não seja alterado durante a execução do programa aplicativo. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtime(void);
```

Espera-se que a função será usada para medir o tempo decorrido conforme mostrado no exemplo a seguir:

```cpp
double start;
double end;
start = omp_get_wtime();
... work to be timed ...
end = omp_get_wtime();
printf_s("Work took %f sec. time.\n", end-start);
```

Os tempos retornados são "vezes por thread" por que é destinado a que eles não são necessários para ser consistente globalmente em todos os threads que estejam participando de um aplicativo.

### <a name="332-omp_get_wtick-function"></a>3.3.2 função omp_get_wtick

O `omp_get_wtick` função retorna um valor de ponto flutuante de precisão dupla igual ao número de segundos entre os tiques do relógio sucessivas. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtick(void);
```
