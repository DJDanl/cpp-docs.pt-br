---
title: 3. Funções da biblioteca em tempo de execução
ms.date: 05/13/2019
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
ms.openlocfilehash: 6155eb87bd7a1a0533caf99afb3db8417854df30
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142950"
---
# <a name="3-run-time-library-functions"></a>3. funções de biblioteca de tempo de execução

Esta seção descreve as funções de biblioteca C++ de tempo de execução e C do OpenMP. O cabeçalho **\<OMP. h >** declara dois tipos, várias funções que podem ser usadas para controlar e consultar o ambiente de execução paralela e bloquear funções que podem ser usadas para sincronizar o acesso aos dados.

O tipo `omp_lock_t` é um tipo de objeto capaz de representar que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são chamados de *bloqueios simples*.

O tipo `omp_nest_lock_t` é um tipo de objeto capaz de representar se um bloqueio está disponível ou a identidade do thread que possui o bloqueio e uma *contagem de aninhamento* (descrita abaixo). Esses bloqueios são chamados de *bloqueios aninhados*.

As funções de biblioteca são funções externas com vínculo "C".

As descrições neste capítulo são divididas nos seguintes tópicos:

- [Funções de ambiente de execução](#31-execution-environment-functions)
- [Bloquear funções](#32-lock-functions)
- [Rotinas de tempo](#33-timing-routines)

## <a name="31-execution-environment-functions"></a>3,1 funções de ambiente de execução

As funções descritas nesta seção afetam e monitoram threads, processadores e o ambiente paralelo:

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

### <a name="311-omp_set_num_threads-function"></a>função de omp_set_num_threads 3.1.1

A função `omp_set_num_threads` define o número padrão de threads a serem usados para regiões paralelas posteriores que não especificam uma cláusula `num_threads`. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_num_threads(int num_threads);
```

O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende de se o ajuste dinâmico do número de threads está habilitado. Para obter um conjunto abrangente de regras sobre a interação entre a função `omp_set_num_threads` e o ajuste dinâmico de threads, consulte a [seção 2,3](2-directives.md#23-parallel-construct).

Essa função tem os efeitos descritos acima quando chamado de uma parte do programa em que a função `omp_in_parallel` retorna zero. Se ele for chamado de uma parte do programa em que a função `omp_in_parallel` retornar um valor diferente de zero, o comportamento dessa função será indefinido.

Essa chamada tem precedência sobre a variável de ambiente `OMP_NUM_THREADS`. O valor padrão para o número de threads, que pode ser estabelecido chamando `omp_set_num_threads` ou definindo a variável de ambiente `OMP_NUM_THREADS`, pode ser explicitamente substituído em uma única diretiva de `parallel` especificando a cláusula `num_threads`.

Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- função [omp_set_dynamic](#317-omp_set_dynamic-function)
- função [omp_get_dynamic](#318-omp_get_dynamic-function)
- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente
- cláusula [num_threads](2-directives.md#23-parallel-construct)

### <a name="312-omp_get_num_threads-function"></a>função de omp_get_num_threads 3.1.2

A função `omp_get_num_threads` retorna o número de threads atualmente na equipe que executa a região paralela da qual ele é chamado. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_threads(void);
```

A cláusula `num_threads`, a função `omp_set_num_threads` e a variável de ambiente `OMP_NUM_THREADS` controlam o número de threads em uma equipe.

Se o número de threads não tiver sido explicitamente definido pelo usuário, o padrão será definido pela implementação. Essa função é associada à diretiva de `parallel` de fechamento mais próxima. Se chamado de uma parte serial de um programa ou de uma região paralela aninhada que é serializada, essa função retornará 1.

Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads)
- [num_threads](2-directives.md#23-parallel-construct)
- [parallel](2-directives.md#23-parallel-construct)

### <a name="313-omp_get_max_threads-function"></a>função de omp_get_max_threads 3.1.3

A função `omp_get_max_threads` retorna um inteiro que é garantido que seja pelo menos tão grande quanto o número de threads que seriam usados para formar uma equipe se uma região paralela sem uma cláusula `num_threads` fosse vista nesse ponto no código. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_max_threads(void);
```

O seguinte expressa um limite inferior no valor de `omp_get_max_threads`:

> *threads-usados para <= da próxima equipe* `omp_get_max_threads`

Observe que, se outra região paralela usar a cláusula `num_threads` para solicitar um número específico de threads, a garantia no limite inferior do resultado de `omp_get_max_threads` não será mais mantida.

O valor de retorno da função `omp_get_max_threads` pode ser usado para alocar dinamicamente o armazenamento suficiente para todos os threads na equipe formada na próxima região paralela.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [omp_set_num_threads](#311-omp_set_num_threads-function)
- [omp_set_dynamic](#317-omp_set_dynamic-function)
- [num_threads](2-directives.md#23-parallel-construct)

### <a name="314-omp_get_thread_num-function"></a>função de omp_get_thread_num 3.1.4

A função `omp_get_thread_num` retorna o número do thread, dentro de sua equipe, do thread que executa a função. O número do thread está entre 0 e `omp_get_num_threads()`-1, inclusive. O thread mestre da equipe é o thread 0.

O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_thread_num(void);
```

Se chamado de uma região serial, `omp_get_thread_num` retornará 0. Se chamado de dentro de uma região paralela aninhada que é serializada, essa função retornará 0.

#### <a name="cross-references"></a>Referências cruzadas

- função [omp_get_num_threads](#312-omp_get_num_threads-function)

### <a name="315-omp_get_num_procs-function"></a>função de omp_get_num_procs 3.1.5

A função `omp_get_num_procs` retorna o número de processadores que estão disponíveis para o programa no momento em que a função é chamada. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_procs(void);
```

### <a name="316-omp_in_parallel-function"></a>função de omp_in_parallel 3.1.6

A função `omp_in_parallel` retornará um valor diferente de zero se ele for chamado dentro da extensão dinâmica de uma região paralela em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_in_parallel(void);
```

Essa função retorna um valor diferente de zero quando chamado de dentro de uma região em execução em paralelo, incluindo regiões aninhadas que são serializadas.

### <a name="317-omp_set_dynamic-function"></a>função de omp_set_dynamic 3.1.7

A função `omp_set_dynamic` habilita ou desabilita o ajuste dinâmico do número de threads disponíveis para execução de regiões paralelas. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_dynamic(int dynamic_threads);
```

Se *dynamic_threads* for avaliada como um valor diferente de zero, o número de threads usados para executar futuras regiões paralelas poderá ser ajustado automaticamente pelo ambiente de tempo de execução para usar melhor os recursos do sistema. Como consequência, o número de threads especificado pelo usuário é a contagem máxima de threads. O número de threads na equipe que executam uma região paralela permanece fixo pela duração da região paralela e é relatado pela função `omp_get_num_threads`.

Se *dynamic_threads* for avaliada como 0, o ajuste dinâmico será desabilitado.

Essa função tem os efeitos descritos acima quando chamado de uma parte do programa em que a função `omp_in_parallel` retorna zero. Se ele for chamado de uma parte do programa em que a função `omp_in_parallel` retornar um valor diferente de zero, o comportamento dessa função será indefinido.

Uma chamada para `omp_set_dynamic` tem precedência sobre a variável de ambiente `OMP_DYNAMIC`.

O padrão para o ajuste dinâmico de threads é definido pela implementação. Como resultado, os códigos de usuário que dependem de um número específico de threads para a execução correta devem desabilitar explicitamente os threads dinâmicos. As implementações não são necessárias para fornecer a capacidade de ajustar dinamicamente o número de threads, mas elas são necessárias para fornecer a interface para dar suporte à portabilidade em todas as plataformas.

#### <a name="microsoft-specific"></a>Específico da Microsoft

O suporte atual de `omp_get_dynamic` e `omp_set_dynamic` é o seguinte:

O parâmetro de entrada para `omp_set_dynamic` não afeta a política de threading e não altera o número de threads. `omp_get_num_threads` sempre retorna o número definido pelo usuário, se estiver definido, ou o número de thread padrão. Na implementação atual da Microsoft, `omp_set_dynamic(0)` desativa o encadeamento dinâmico para que o conjunto existente de threads possa ser reutilizado para a seguinte região paralela. `omp_set_dynamic(1)` ativa o Threading dinâmico descartando o conjunto existente de threads e criando um novo conjunto para a próxima região paralela. O número de threads no novo conjunto é o mesmo que o conjunto antigo e é baseado no valor de retorno de `omp_get_num_threads`. Portanto, para obter um melhor desempenho, use `omp_set_dynamic(0)` para reutilizar os threads existentes.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="318-omp_get_dynamic-function"></a>função de omp_get_dynamic 3.1.8

A função `omp_get_dynamic` retornará um valor diferente de zero se o ajuste dinâmico de threads estiver habilitado e retornará 0 caso contrário. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_dynamic(void);
```

Se a implementação não implementar o ajuste dinâmico do número de threads, essa função sempre retornará 0. Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- Para obter uma descrição do ajuste de thread dinâmico, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

### <a name="319-omp_set_nested-function"></a>função de omp_set_nested 3.1.9

A função `omp_set_nested` habilita ou desabilita o paralelismo aninhado. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_nested(int nested);
```

Se o *aninhado* for avaliado como 0, o paralelismo aninhado será desabilitado, que é o padrão, e as regiões paralelas aninhadas serão serializadas e executadas pelo thread atual. Caso contrário, o paralelismo aninhado será habilitado e as regiões paralelas aninhadas poderão implantar threads adicionais para formar equipes aninhadas.

Essa função tem os efeitos descritos acima quando chamado de uma parte do programa em que a função `omp_in_parallel` retorna zero. Se ele for chamado de uma parte do programa em que a função `omp_in_parallel` retornar um valor diferente de zero, o comportamento dessa função será indefinido.

Essa chamada tem precedência sobre a variável de ambiente `OMP_NESTED`.

Quando o paralelismo aninhado está habilitado, o número de threads usados para executar regiões paralelas aninhadas é definido pela implementação. Como resultado, as implementações em conformidade com OpenMP têm permissão para serializar regiões paralelas aninhadas mesmo quando o paralelismo aninhado está habilitado.

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NESTED](4-environment-variables.md#44-omp_nested)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="3110-omp_get_nested-function"></a>função de omp_get_nested 3.1.10

A função `omp_get_nested` retornará um valor diferente de zero se o paralelismo aninhado estiver habilitado e 0 se estiver desabilitado. Para obter mais informações sobre paralelismo aninhado, consulte [omp_set_nested](#319-omp_set_nested-function). O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_nested(void);
```

Se uma implementação não implementar o paralelismo aninhado, essa função sempre retornará 0.

## <a name="32-lock-functions"></a>3,2 bloquear funções

As funções descritas nesta seção manipulam os bloqueios usados para sincronização.

Para as funções a seguir, a variável de bloqueio deve ter o tipo `omp_lock_t`. Essa variável só deve ser acessada por meio dessas funções. Todas as funções de bloqueio exigem um argumento que tenha um ponteiro para `omp_lock_t` tipo.

- A função [omp_init_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) Inicializa um bloqueio simples.
- A função [omp_destroy_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) remove um bloqueio simples.
- A função [omp_set_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) aguarda até que um bloqueio simples esteja disponível.
- A função [omp_unset_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) libera um bloqueio simples.
- A função [omp_test_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) testa um bloqueio simples.

Para as funções a seguir, a variável de bloqueio deve ter o tipo `omp_nest_lock_t`.  Essa variável só deve ser acessada por meio dessas funções. Todas as funções de bloqueio aninhadas exigem um argumento que tenha um ponteiro para `omp_nest_lock_t` tipo.

- A função [omp_init_nest_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) Inicializa um bloqueio aninhado.
- A função [omp_destroy_nest_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) remove um bloqueio aninhado.
- A função [omp_set_nest_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) aguarda até que um bloqueio aninhado esteja disponível.
- A função [omp_unset_nest_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) libera um bloqueio aninhado.
- A função [omp_test_nest_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) testa um bloqueio aninhado.

As funções de bloqueio de OpenMP acessam a variável de bloqueio de forma que elas sempre leiam e atualizem o valor mais atual da variável de bloqueio. Portanto, não é necessário que um programa de OpenMP inclua diretivas de `flush` explícitas para garantir que o valor da variável de bloqueio seja consistente entre diferentes threads. (Pode haver a necessidade de `flush` diretivas para tornar os valores de outras variáveis consistentes.)

### <a name="321-omp_init_lock-and-omp_init_nest_lock-functions"></a>3.2.1 funções de omp_init_lock e omp_init_nest_lock

Essas funções fornecem o único meio de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao *bloqueio* de parâmetro para uso em chamadas futuras. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_init_lock(omp_lock_t *lock);
void omp_init_nest_lock(omp_nest_lock_t *lock);
```

O estado inicial é desbloqueado (ou seja, nenhum thread possui o bloqueio). Para um bloqueio aninhado, a contagem de aninhamento inicial é zero. Não há conformidade para chamar qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializada.

### <a name="322-omp_destroy_lock-and-omp_destroy_nest_lock-functions"></a>funções de omp_destroy_lock e omp_destroy_nest_lock 3.2.2

Essas funções verificam se o *bloqueio* de variável apontado para bloqueio não foi inicializado. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_destroy_lock(omp_lock_t *lock);
void omp_destroy_nest_lock(omp_nest_lock_t *lock);
```

Não é compatível chamar nenhuma dessas rotinas com uma variável de bloqueio que não foi inicializada ou desbloqueada.

### <a name="323-omp_set_lock-and-omp_set_nest_lock-functions"></a>funções de omp_set_lock e omp_set_nest_lock 3.2.3

Cada uma dessas funções bloqueia o thread que executa a função até que o bloqueio especificado esteja disponível e, em seguida, defina o bloqueio. Um bloqueio simples estará disponível se for desbloqueado. Um bloqueio aninhado estará disponível se for desbloqueado ou se já pertencer ao thread que está executando a função. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_lock(omp_lock_t *lock);
void omp_set_nest_lock(omp_nest_lock_t *lock);
```

Para um bloqueio simples, o argumento para a função `omp_set_lock` deve apontar para uma variável de bloqueio inicializada. A propriedade do bloqueio é concedida ao thread que executa a função.

Para um bloqueio aninhado, o argumento para a função `omp_set_nest_lock` deve apontar para uma variável de bloqueio inicializada. A contagem de aninhamento é incrementada e o thread é concedido ou mantém a propriedade do bloqueio.

### <a name="324-omp_unset_lock-and-omp_unset_nest_lock-functions"></a>funções de omp_unset_lock e omp_unset_nest_lock 3.2.4

Essas funções fornecem o meio de liberar a propriedade de um bloqueio. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_unset_lock(omp_lock_t *lock);
void omp_unset_nest_lock(omp_nest_lock_t *lock);
```

O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializada de Propriedade do thread que executa a função. O comportamento será indefinido se o thread não possuir esse bloqueio.

Para um bloqueio simples, a função `omp_unset_lock` libera o thread que executa a função da Propriedade do bloqueio.

Para um bloqueio aninhado, a função `omp_unset_nest_lock` decrementa a contagem de aninhamento e libera o thread que executa a função da Propriedade do bloqueio se a contagem resultante for zero.

### <a name="325-omp_test_lock-and-omp_test_nest_lock-functions"></a>funções de omp_test_lock e omp_test_nest_lock 3.2.5

Essas funções tentam definir um bloqueio, mas não bloqueiam a execução do thread. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_test_lock(omp_lock_t *lock);
int omp_test_nest_lock(omp_nest_lock_t *lock);
```

O argumento deve apontar para uma variável de bloqueio inicializada. Essas funções tentam definir um bloqueio da mesma maneira que `omp_set_lock` e `omp_set_nest_lock`, exceto que eles não bloqueiam a execução do thread.

Para um bloqueio simples, a função `omp_test_lock` retornará um valor diferente de zero se o bloqueio for definido com êxito; caso contrário, retornará zero.

Para um bloqueio aninhado, a função `omp_test_nest_lock` retornará a nova contagem de aninhamento se o bloqueio for definido com êxito; caso contrário, retornará zero.

## <a name="33-timing-routines"></a>3,3 rotinas de tempo

As funções descritas nesta seção dão suporte a um temporizador portátil de relógio de parede:

- A função [omp_get_wtime](#331-omp_get_wtime-function) retorna o tempo de relógio de parede decorrido.
- A função [omp_get_wtick](#332-omp_get_wtick-function) retorna segundos entre tiques de relógio sucessivos.

### <a name="331-omp_get_wtime-function"></a>função de omp_get_wtime 3.3.1

A função `omp_get_wtime` retorna um valor de ponto flutuante de precisão dupla igual ao tempo de relógio de parede decorrido em segundos desde um "tempo no passado".  O verdadeiro "tempo no passado" é arbitrário, mas é garantido que não seja alterado durante a execução do programa do aplicativo. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtime(void);
```

É esperado que a função seja usada para medir os tempos decorridos, conforme mostrado no exemplo a seguir:

```cpp
double start;
double end;
start = omp_get_wtime();
... work to be timed ...
end = omp_get_wtime();
printf_s("Work took %f sec. time.\n", end-start);
```

Os tempos retornados são "períodos por thread", pelos quais isso significa que eles não precisam ser globalmente consistentes em todos os threads que participam de um aplicativo.

### <a name="332-omp_get_wtick-function"></a>função de omp_get_wtick 3.3.2

A função `omp_get_wtick` retorna um valor de ponto flutuante de precisão dupla igual ao número de segundos entre os tiques de relógio sucessivos. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtick(void);
```
