---
title: 3. Funções da biblioteca em tempo de execução
ms.date: 05/13/2019
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
ms.openlocfilehash: 767c006b0a2d81af4d1f8f2e23f84d7847326f31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370280"
---
# <a name="3-run-time-library-functions"></a>3. Funções de biblioteca em tempo de execução

Esta seção descreve as funções de biblioteca de tempo de execução OpenMP C e C++. O cabeçalho ** \<omp.h>** declara dois tipos, várias funções que podem ser usadas para controlar e consultar o ambiente de execução paralela, e funções de bloqueio que podem ser usadas para sincronizar o acesso aos dados.

O `omp_lock_t` tipo é um tipo de objeto capaz de representar que um bloqueio está disponível, ou que um segmento possui uma fechadura. Essas fechaduras são referidas como *fechaduras simples.*

O `omp_nest_lock_t` tipo é um tipo de objeto capaz de representar que um bloqueio está disponível, ou tanto a identidade do segmento que possui o bloqueio e uma *contagem de aninhamento* (descrito abaixo). Essas fechaduras são referidas como *fechaduras nestable*.

As funções da biblioteca são funções externas com ligação "C".

As descrições deste capítulo estão divididas nos seguintes tópicos:

- [Funções do ambiente de execução](#31-execution-environment-functions)
- [Funções de bloqueio](#32-lock-functions)
- [Rotinas de cronometragem](#33-timing-routines)

## <a name="31-execution-environment-functions"></a>3.1 Funções do ambiente de execução

As funções descritas nesta seção afetam e monitoram os segmentos, processadores e o ambiente paralelo:

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

### <a name="311-omp_set_num_threads-function"></a><a name="311-omp_set_num_threads-function"></a>3.1.1 função omp_set_num_threads

A `omp_set_num_threads` função define o número padrão de threads a serem usados para regiões paralelas posteriores que não especificam uma `num_threads` cláusula. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_num_threads(int num_threads);
```

O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está ativado. Para obter um conjunto abrangente de `omp_set_num_threads` regras sobre a interação entre a função e o ajuste dinâmico dos segmentos, consulte [a seção 2.3](2-directives.md#23-parallel-construct).

Esta função tem os efeitos descritos acima quando `omp_in_parallel` chamada de uma parte do programa onde a função retorna zero. Se for chamado de uma parte do `omp_in_parallel` programa onde a função retorna um valor não zero, o comportamento desta função é indefinido.

Esta chamada tem precedência sobre a `OMP_NUM_THREADS` variável ambiente. O valor padrão para o número de threads, `omp_set_num_threads` que pode `OMP_NUM_THREADS` ser estabelecido por chamada ou definindo `parallel` a variável `num_threads` de ambiente, pode ser explicitamente substituído em uma única diretiva, especificando a cláusula.

Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- [função omp_set_dynamic](#317-omp_set_dynamic-function)
- [função omp_get_dynamic](#318-omp_get_dynamic-function)
- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente
- [cláusula num_threads](2-directives.md#23-parallel-construct)

### <a name="312-omp_get_num_threads-function"></a><a name="312-omp_get_num_threads-function"></a>3.1.2 função omp_get_num_threads

A `omp_get_num_threads` função retorna o número de threads atualmente na equipe executando a região paralela da qual é chamada. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_threads(void);
```

A `num_threads` cláusula, `omp_set_num_threads` a função `OMP_NUM_THREADS` e a variável ambiente controlam o número de threads em uma equipe.

Se o número de threads não tiver sido explicitamente definido pelo usuário, o padrão será definido como implementação. Esta função se liga à `parallel` diretiva de fechamento mais próxima. Se chamado de uma parte serial de um programa, ou de uma região paralela aninhada que é serializada, esta função retorna 1.

Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads)
- [num_threads](2-directives.md#23-parallel-construct)
- [parallel](2-directives.md#23-parallel-construct)

### <a name="313-omp_get_max_threads-function"></a><a name="313-omp_get_max_threads-function"></a>3.1.3 função omp_get_max_threads

A `omp_get_max_threads` função retorna um inteiro que é garantido ser pelo menos tão grande quanto o número de threads `num_threads` que seriam usados para formar uma equipe se uma região paralela sem cláusula fosse vista naquele ponto do código. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_max_threads(void);
```

O seguinte expressa um limite inferior `omp_get_max_threads`no valor de :

> *threads-usado-para-próxima equipe* <= `omp_get_max_threads`

Observe que se outra `num_threads` região paralela usar a cláusula para solicitar um número específico `omp_get_max_threads` de threads, a garantia no limite inferior do resultado não se mantém mais.

O `omp_get_max_threads` valor de retorno da função pode ser usado para alocar dinamicamente armazenamento suficiente para todos os segmentos da equipe formada na próxima região paralela.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [omp_set_num_threads](#311-omp_set_num_threads-function)
- [omp_set_dynamic](#317-omp_set_dynamic-function)
- [num_threads](2-directives.md#23-parallel-construct)

### <a name="314-omp_get_thread_num-function"></a><a name="314-omp_get_thread_num-function"></a>3.1.4 função omp_get_thread_num

A `omp_get_thread_num` função retorna o número de rosca, dentro de sua equipe, do segmento executando a função. O número da linha `omp_get_num_threads()`fica entre 0 e -1, inclusive. O fio mestre da equipe é a linha 0.

O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_thread_num(void);
```

Se chamado de uma `omp_get_thread_num` região serial, retorna 0. Se chamado de dentro de uma região paralela aninhada que é serializada, esta função retorna 0.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function) função

### <a name="315-omp_get_num_procs-function"></a><a name="315-omp_get_num_procs-function"></a>3.1.5 função omp_get_num_procs

A `omp_get_num_procs` função retorna o número de processadores disponíveis para o programa no momento em que a função é chamada. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_num_procs(void);
```

### <a name="316-omp_in_parallel-function"></a><a name="316-omp_in_parallel-function"></a>3.1.6 função omp_in_parallel

A `omp_in_parallel` função retorna um valor não zero se for chamada dentro da extensão dinâmica de uma região paralela executando em paralelo; caso contrário, ele retorna 0. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_in_parallel(void);
```

Essa função retorna um valor não zero quando chamada de dentro de uma região executando em paralelo, incluindo regiões aninhadas que são serializadas.

### <a name="317-omp_set_dynamic-function"></a><a name="317-omp_set_dynamic-function"></a>3.1.7 função omp_set_dynamic

A `omp_set_dynamic` função permite ou desativa o ajuste dinâmico do número de threads disponíveis para execução de regiões paralelas. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_dynamic(int dynamic_threads);
```

Se *dynamic_threads* avaliar para um valor não zero, o número de threads usados para executar as próximas regiões paralelas pode ser ajustado automaticamente pelo ambiente de tempo de execução para melhor usar os recursos do sistema. Como conseqüência, o número de threads especificados pelo usuário é a contagem máxima de segmentos. O número de roscas na equipe executando uma região paralela permanece fixo durante `omp_get_num_threads` a duração dessa região paralela e é relatado pela função.

Se *dynamic_threads* avaliar para 0, o ajuste dinâmico será desativado.

Esta função tem os efeitos descritos acima quando `omp_in_parallel` chamada de uma parte do programa onde a função retorna zero. Se for chamado de uma parte do `omp_in_parallel` programa onde a função retorna um valor não zero, o comportamento desta função é indefinido.

Uma chamada `omp_set_dynamic` tem precedência sobre a `OMP_DYNAMIC` variável ambiente.

O padrão para o ajuste dinâmico dos segmentos é definido pela implementação. Como resultado, os códigos de usuário que dependem de um número específico de threads para execução correta devem desabilitar explicitamente os threads dinâmicos. As implementações não são necessárias para fornecer a capacidade de ajustar dinamicamente o número de threads, mas elas são necessárias para fornecer a interface para oferecer suporte à portabilidade em todas as plataformas.

#### <a name="microsoft-specific"></a>Específico da Microsoft

O suporte `omp_get_dynamic` atual `omp_set_dynamic` e é o seguinte:

O parâmetro de `omp_set_dynamic` entrada para não afeta a política de rosca e não altera o número de threads. `omp_get_num_threads`sempre retorna o número definido pelo usuário, se estiver definido, ou o número de segmento padrão. Na implementação atual `omp_set_dynamic(0)` da Microsoft, desativa o threading dinâmico para que o conjunto de segmentos existente possa ser reutilizado para a seguinte região paralela. `omp_set_dynamic(1)`ativa threading dinâmico descartando o conjunto existente de roscas e criando um novo conjunto para a próxima região paralela. O número de threads no novo conjunto é o mesmo do conjunto `omp_get_num_threads`antigo, e é baseado no valor de retorno de . Portanto, para melhor desempenho, use `omp_set_dynamic(0)` para reutilizar os segmentos existentes.

#### <a name="cross-references"></a>Referências cruzadas

- [omp_get_num_threads](#312-omp_get_num_threads-function)
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="318-omp_get_dynamic-function"></a><a name="318-omp_get_dynamic-function"></a>3.1.8 função omp_get_dynamic

A `omp_get_dynamic` função retorna um valor não zero se o ajuste dinâmico dos segmentos estiver ativado e retornar 0 de outra forma. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_dynamic(void);
```

Se a implementação não implementar ajuste dinâmico do número de threads, esta função sempre retorna 0. Para obter mais informações, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

#### <a name="cross-references"></a>Referências cruzadas

- Para obter uma descrição do ajuste dinâmico do segmento, consulte [omp_set_dynamic](#317-omp_set_dynamic-function).

### <a name="319-omp_set_nested-function"></a><a name="319-omp_set_nested-function"></a>3.1.9 função omp_set_nested

A `omp_set_nested` função ativa ou desativa o paralelismo aninhado. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_nested(int nested);
```

Se *avaliado em* 0, o paralelismo aninhado é desativado, que é o padrão, e regiões paralelas aninhadas são serializadas e executadas pelo segmento atual. Caso contrário, o paralelismo aninhado é habilitado, e regiões paralelas aninhadas podem implantar segmentos adicionais para formar equipes aninhadas.

Esta função tem os efeitos descritos acima quando `omp_in_parallel` chamada de uma parte do programa onde a função retorna zero. Se for chamado de uma parte do `omp_in_parallel` programa onde a função retorna um valor não zero, o comportamento desta função é indefinido.

Esta chamada tem precedência sobre a `OMP_NESTED` variável ambiente.

Quando o paralelismo aninhado é ativado, o número de segmentos usados para executar regiões paralelas aninhadas é definido pela implementação. Como resultado, implementações compatíveis com OpenMP são permitidas para serializar regiões paralelas aninhadas mesmo quando o paralelismo aninhado é habilitado.

#### <a name="cross-references"></a>Referências cruzadas

- [OMP_NESTED](4-environment-variables.md#44-omp_nested)
- [omp_in_parallel](#316-omp_in_parallel-function)

### <a name="3110-omp_get_nested-function"></a><a name="3110-omp_get_nested-function"></a>3.1.10 função omp_get_nested

A `omp_get_nested` função retorna um valor não zero se o paralelismo aninhado estiver ativado e 0 se estiver desativado. Para obter mais informações sobre o paralelismo aninhado, consulte [omp_set_nested](#319-omp_set_nested-function). O formato é o seguinte:

```cpp
#include <omp.h>
int omp_get_nested(void);
```

Se uma implementação não implementar o paralelismo aninhado, esta função sempre retorna 0.

## <a name="32-lock-functions"></a>3.2 Funções de bloqueio

As funções descritas nesta seção manipulam bloqueios usados para sincronização.

Para as seguintes funções, a `omp_lock_t`variável de bloqueio deve ter tipo . Esta variável só deve ser acessada através dessas funções. Todas as funções de bloqueio requerem `omp_lock_t` um argumento que tenha um ponteiro para digitar.

- A função [omp_init_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) inicializa um bloqueio simples.
- A função [omp_destroy_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) remove um bloqueio simples.
- A função [omp_set_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) aguarda até que um bloqueio simples esteja disponível.
- A função [omp_unset_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) libera um bloqueio simples.
- A função [omp_test_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) testa um bloqueio simples.

Para as seguintes funções, a `omp_nest_lock_t`variável de bloqueio deve ter tipo .  Esta variável só deve ser acessada através dessas funções. Todas as funções de bloqueio nestable `omp_nest_lock_t` requerem um argumento que tenha um ponteiro para digitar.

- A função [omp_init_nest_lock](#321-omp_init_lock-and-omp_init_nest_lock-functions) inicializa um bloqueio nestable.
- A função [omp_destroy_nest_lock](#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) remove uma trava nestable.
- A função [omp_set_nest_lock](#323-omp_set_lock-and-omp_set_nest_lock-functions) aguarda até que um bloqueio nestable esteja disponível.
- A função [omp_unset_nest_lock](#324-omp_unset_lock-and-omp_unset_nest_lock-functions) libera um bloqueio nestable.
- A função [omp_test_nest_lock](#325-omp_test_lock-and-omp_test_nest_lock-functions) testa uma trava nestable.

As funções de bloqueio OpenMP acessam a variável de bloqueio de tal forma que eles sempre lêem e atualizam o valor mais atual da variável lock. Portanto, não é necessário que um programa OpenMP inclua diretivas explícitas `flush` para garantir que o valor da variável de bloqueio seja consistente entre diferentes segmentos. (Pode haver necessidade `flush` de diretrizes para tornar consistentes os valores de outras variáveis.)

### <a name="321-omp_init_lock-and-omp_init_nest_lock-functions"></a><a name="321-omp_init_lock-and-omp_init_nest_lock-functions"></a>3.2.1 funções omp_init_lock e omp_init_nest_lock

Essas funções fornecem o único meio de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao *bloqueio* de parâmetros para uso em chamadas próximas. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_init_lock(omp_lock_t *lock);
void omp_init_nest_lock(omp_nest_lock_t *lock);
```

O estado inicial é desbloqueado (ou seja, nenhum fio possui o bloqueio). Para uma trava nestable, a contagem inicial de aninhamento é zero. Não é compatível ligar para qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializada.

### <a name="322-omp_destroy_lock-and-omp_destroy_nest_lock-functions"></a><a name="322-omp_destroy_lock-and-omp_destroy_nest_lock-functions"></a>3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock

Essas funções garantem que o *bloqueio* variável apontado para bloqueio não seja inicializado. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_destroy_lock(omp_lock_t *lock);
void omp_destroy_nest_lock(omp_nest_lock_t *lock);
```

Não é compatível ligar para qualquer uma dessas rotinas com uma variável de bloqueio que não é inicializada ou desbloqueada.

### <a name="323-omp_set_lock-and-omp_set_nest_lock-functions"></a><a name="323-omp_set_lock-and-omp_set_nest_lock-functions"></a>3.2.3 funções omp_set_lock e omp_set_nest_lock

Cada uma dessas funções bloqueia o segmento executando a função até que o bloqueio especificado esteja disponível e, em seguida, define o bloqueio. Um bloqueio simples está disponível se estiver desbloqueado. Um bloqueio nestable está disponível se estiver desbloqueado ou se já estiver de propriedade do segmento executando a função. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_set_lock(omp_lock_t *lock);
void omp_set_nest_lock(omp_nest_lock_t *lock);
```

Para um bloqueio simples, `omp_set_lock` o argumento para a função deve apontar para uma variável de bloqueio inicializada. A propriedade do bloqueio é concedida ao segmento que executa a função.

Para um bloqueio nestable, `omp_set_nest_lock` o argumento para a função deve apontar para uma variável de bloqueio inicializada. A contagem de aninhamento é incrementada, e a linha é concedida, ou mantém, a propriedade da fechadura.

### <a name="324-omp_unset_lock-and-omp_unset_nest_lock-functions"></a><a name="324-omp_unset_lock-and-omp_unset_nest_lock-functions"></a>3.2.4 funções omp_unset_lock e omp_unset_nest_lock

Essas funções fornecem os meios de liberar a propriedade de um bloqueio. O formato é o seguinte:

```cpp
#include <omp.h>
void omp_unset_lock(omp_lock_t *lock);
void omp_unset_nest_lock(omp_nest_lock_t *lock);
```

O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializada de propriedade do segmento executando a função. O comportamento é indefinido se o segmento não possui essa fechadura.

Para um bloqueio `omp_unset_lock` simples, a função libera o segmento executando a função a partir da propriedade do bloqueio.

Para um bloqueio nestable, a `omp_unset_nest_lock` função decreta a contagem de aninhamento e libera o fio executando a função da propriedade do bloqueio se a contagem resultante for zero.

### <a name="325-omp_test_lock-and-omp_test_nest_lock-functions"></a><a name="325-omp_test_lock-and-omp_test_nest_lock-functions"></a>3.2.5 funções omp_test_lock e omp_test_nest_lock

Essas funções tentam definir um bloqueio, mas não bloqueiam a execução do segmento. O formato é o seguinte:

```cpp
#include <omp.h>
int omp_test_lock(omp_lock_t *lock);
int omp_test_nest_lock(omp_nest_lock_t *lock);
```

O argumento deve apontar para uma variável de bloqueio inicializada. Essas funções tentam definir um bloqueio `omp_set_lock` da `omp_set_nest_lock`mesma maneira que e , exceto que eles não bloqueiam a execução do segmento.

Para um bloqueio `omp_test_lock` simples, a função retorna um valor não zero se o bloqueio for definido com sucesso; caso contrário, ele retorna zero.

Para um bloqueio nestable, a `omp_test_nest_lock` função retorna a nova contagem de aninhamento se o bloqueio for definido com sucesso; caso contrário, ele retorna zero.

## <a name="33-timing-routines"></a>3.3 Rotinas de cronometragem

As funções descritas nesta seção suportam um temporizador portátil de relógio de parede:

- A função [omp_get_wtime](#331-omp_get_wtime-function) retorna o tempo demorado do relógio de parede.
- A função [omp_get_wtick](#332-omp_get_wtick-function) retorna segundos entre os carrapatos sucessivos do relógio.

### <a name="331-omp_get_wtime-function"></a><a name="331-omp_get_wtime-function"></a>3.3.1 função omp_get_wtime

A `omp_get_wtime` função retorna um valor de ponto flutuante de dupla precisão igual ao tempo de relógio de parede decorrido em segundos desde algum "tempo no passado".  O "tempo no passado" real é arbitrário, mas é garantido não mudar durante a execução do programa de aplicação. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtime(void);
```

Prevê-se que a função será usada para medir os tempos decorridos, como mostrado no exemplo a seguir:

```cpp
double start;
double end;
start = omp_get_wtime();
... work to be timed ...
end = omp_get_wtime();
printf_s("Work took %f sec. time.\n", end-start);
```

Os tempos retornados são "tempos por thread" pelo que significa que eles não são obrigados a ser consistentes globalmente em todos os segmentos participantes de um aplicativo.

### <a name="332-omp_get_wtick-function"></a><a name="332-omp_get_wtick-function"></a>3.3.2 função omp_get_wtick

A `omp_get_wtick` função retorna um valor de ponto flutuante de dupla precisão igual ao número de segundos entre os carrapatos de relógio sucessivos. O formato é o seguinte:

```cpp
#include <omp.h>
double omp_get_wtick(void);
```
