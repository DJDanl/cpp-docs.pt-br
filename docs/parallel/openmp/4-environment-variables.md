---
title: 4. Variáveis de ambiente
ms.date: 01/16/2019
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
ms.openlocfilehash: b41829fd9cf2f90312f669ef991f56dda02947f7
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417050"
---
# <a name="4-environment-variables"></a>4. variáveis de ambiente

Este capítulo descreve as variáveis de ambiente C++ de OpenMP C e API (ou mecanismos específicos de plataforma semelhantes) que controlam a execução de código paralelo.  Os nomes das variáveis de ambiente devem estar em letras maiúsculas. Os valores atribuídos a eles não diferenciam maiúsculas de minúsculas e podem ter espaços em branco à esquerda e à direita.  As modificações nos valores após o programa ter sido iniciado serão ignoradas.

As variáveis de ambiente são as seguintes:

- [OMP_SCHEDULE](#41-omp_schedule) define o tipo de agendamento de tempo de execução e o tamanho da parte.
- [OMP_NUM_THREADS](#42-omp_num_threads) define o número de threads a serem usados durante a execução.
- [OMP_DYNAMIC](#43-omp_dynamic) habilita ou desabilita o ajuste dinâmico do número de threads.
- [OMP_NESTED](#44-omp_nested) habilita ou desabilita o paralelismo aninhado.

Os exemplos neste capítulo demonstram apenas como essas variáveis podem ser definidas em ambientes UNIX C shell (csh). Nos ambientes do Shell e DOS do Korn, as ações são semelhantes:

csh:  
`setenv OMP_SCHEDULE "dynamic"`

ksh  
`export OMP_SCHEDULE="dynamic"`

DOS  
`set OMP_SCHEDULE="dynamic"`

## <a name="41-omp_schedule"></a>4,1 OMP_SCHEDULE

`OMP_SCHEDULE` aplica-se somente às diretivas `for` e `parallel for` que têm o tipo de agendamento `runtime`. O tipo de agendamento e o tamanho da parte para todos esses loops podem ser definidos em tempo de execução. Defina essa variável de ambiente para qualquer tipo de agendamento reconhecido e para um *chunk_size*opcional.

Para `for` e `parallel for` diretivas que têm um tipo de agendamento diferente de `runtime`, `OMP_SCHEDULE` é ignorada. O valor padrão para essa variável de ambiente é definido pela implementação. Se o *chunk_size* opcional for definido, o valor deverá ser positivo. Se *chunk_size* não estiver definido, será assumido um valor de 1, exceto quando o agendamento for `static`. Para um agendamento de `static`, o tamanho de parte padrão é definido como o espaço de iteração de loop dividido pelo número de threads aplicados ao loop.

Exemplo:

```csh
setenv OMP_SCHEDULE "guided,4"
setenv OMP_SCHEDULE "dynamic"
```

### <a name="cross-references"></a>Referências cruzadas

- diretiva [for](2-directives.md#241-for-construct)
- [paralelo para](2-directives.md#251-parallel-for-construct) diretiva

## <a name="42-omp_num_threads"></a>4,2 OMP_NUM_THREADS

A variável de ambiente `OMP_NUM_THREADS` define o número padrão de threads a serem usados durante a execução. `OMP_NUM_THREADS` será ignorado se esse número for explicitamente alterado chamando a rotina de biblioteca de `omp_set_num_threads`. Ele também será ignorado se houver uma cláusula `num_threads` explícita em uma diretiva de `parallel`.

O valor da variável de ambiente `OMP_NUM_THREADS` deve ser um inteiro positivo. Seu efeito depende de se o ajuste dinâmico do número de threads está habilitado. Para obter um conjunto abrangente de regras sobre a interação entre a variável de ambiente `OMP_NUM_THREADS` e o ajuste dinâmico de threads, consulte a [seção 2,3](2-directives.md#23-parallel-construct).

O número de threads a serem usados é definido pela implementação se:

- a variável de ambiente `OMP_NUM_THREADS` não está especificada,
- o valor especificado não é um inteiro positivo ou
- o valor é maior que o número máximo de threads aos quais o sistema pode dar suporte.

Exemplo:

```csh
setenv OMP_NUM_THREADS 16
```

### <a name="cross-references"></a>Referências cruzadas

- cláusula [num_threads](2-directives.md#23-parallel-construct)
- função [omp_set_num_threads](3-run-time-library-functions.md#311-omp_set_num_threads-function)
- função [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function)

## <a name="43-omp_dynamic"></a>4,3 OMP_DYNAMIC

A variável de ambiente `OMP_DYNAMIC` habilita ou desabilita o ajuste dinâmico do número de threads disponíveis para a execução de regiões paralelas. `OMP_DYNAMIC` é ignorado quando o ajuste dinâmico é explicitamente habilitado ou desabilitado chamando a rotina de biblioteca de `omp_set_dynamic`. Seu valor deve ser `TRUE` ou `FALSE`.

Se `OMP_DYNAMIC` for definido como `TRUE`, o número de threads usados para a execução de regiões paralelas poderá ser ajustado pelo ambiente de tempo de execução para usar melhor os recursos do sistema.  Se `OMP_DYNAMIC` for definido como `FALSE`, o ajuste dinâmico será desabilitado. A condição padrão é definida pela implementação.

Exemplo:

```csh
setenv OMP_DYNAMIC TRUE
```

### <a name="cross-references"></a>Referências cruzadas

- [Regiões paralelas](2-directives.md#23-parallel-construct)
- função [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function)

## <a name="44-omp_nested"></a>4,4 OMP_NESTED

A variável de ambiente `OMP_NESTED` habilita ou desabilita o paralelismo aninhado, a menos que o paralelismo aninhado seja habilitado ou desativado chamando a rotina de biblioteca de `omp_set_nested`. Se `OMP_NESTED` for definido como `TRUE`, o paralelismo aninhado será habilitado. Se `OMP_NESTED` for definido como `FALSE`, o paralelismo aninhado será desabilitado. O valor padrão é `FALSE`.

Exemplo:

```csh
setenv OMP_NESTED TRUE
```

### <a name="cross-reference"></a>Referência cruzada

- função [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function)
