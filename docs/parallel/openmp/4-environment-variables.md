---
title: 4. Variáveis de ambiente
ms.date: 01/16/2019
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
ms.openlocfilehash: e93c59654c17ed6dbfb7483ac2dce716ce24b52a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370262"
---
# <a name="4-environment-variables"></a>4. Variáveis ambientais

Este capítulo descreve as variáveis de ambiente OpenMP C e C++ API (ou mecanismos específicos da plataforma semelhantes) que controlam a execução do código paralelo.  Os nomes das variáveis de ambiente devem ser maiúsculas. Os valores atribuídos a eles são insensíveis e podem ter espaço branco de liderança e de salina.  As modificações nos valores após o início do programa são ignoradas.

As variáveis de ambiente são as seguintes:

- [OMP_SCHEDULE](#41-omp_schedule) define o tipo de cronograma de tempo de execução e o tamanho do pedaço.
- [OMP_NUM_THREADS](#42-omp_num_threads) define o número de threads a serem usados durante a execução.
- [OMP_DYNAMIC](#43-omp_dynamic) habilita ou desativa o ajuste dinâmico do número de threads.
- [OMP_NESTED](#44-omp_nested) habilita ou desativa o paralelismo aninhado.

Os exemplos deste capítulo demonstram apenas como essas variáveis podem ser definidas em ambientes de shell Unix C (csh). Nos ambientes Korn shell e DOS, as ações são semelhantes:

Csh:  
`setenv OMP_SCHEDULE "dynamic"`

Ksh:  
`export OMP_SCHEDULE="dynamic"`

DOS:  
`set OMP_SCHEDULE="dynamic"`

## <a name="41-omp_schedule"></a><a name="41-omp_schedule"></a>4.1 OMP_SCHEDULE

`OMP_SCHEDULE`aplica-se `for` apenas `parallel for` a e diretivas `runtime`que tenham o tipo de agendamento . O tipo de programação e o tamanho do pedaço para todos esses loops podem ser definidos em tempo de execução. Defina essa variável de ambiente para qualquer tipo de horário reconhecido e para uma *chunk_size*opcional .

Pois `for` `parallel for` e diretivas que tenham `runtime`um `OMP_SCHEDULE` tipo de cronograma diferente, é ignorada. O valor padrão para essa variável de ambiente é definido pela implementação. Se a *chunk_size* opcional estiver definida, o valor deve ser positivo. Se *chunk_size* não estiver definido, um valor de 1 `static`é assumido, exceto quando o horário é . Para `static` um cronograma, o tamanho do pedaço padrão é definido para o espaço de iteração de loop dividido pelo número de threads aplicados ao loop.

Exemplo:

```csh
setenv OMP_SCHEDULE "guided,4"
setenv OMP_SCHEDULE "dynamic"
```

### <a name="cross-references"></a>Referências cruzadas

- [para](2-directives.md#241-for-construct) diretiva
- [paralelo para](2-directives.md#251-parallel-for-construct) diretiva

## <a name="42-omp_num_threads"></a><a name="42-omp_num_threads"></a>4.2 OMP_NUM_THREADS

A `OMP_NUM_THREADS` variável ambiente define o número padrão de threads a serem usados durante a execução. `OMP_NUM_THREADS`é ignorado se esse número for explicitamente `omp_set_num_threads` alterado chamando a rotina da biblioteca. Também é ignorado se há uma `num_threads` cláusula explícita `parallel` em uma diretiva.

O valor `OMP_NUM_THREADS` da variável ambiente deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está ativado. Para obter um conjunto abrangente de `OMP_NUM_THREADS` regras sobre a interação entre a variável ambiente e o ajuste dinâmico dos segmentos, consulte [a seção 2.3](2-directives.md#23-parallel-construct).

O número de threads a serem usados é definido pela implementação se:

- a `OMP_NUM_THREADS` variável ambiente não é especificada,
- o valor especificado não é um inteiro positivo, ou
- o valor é maior do que o número máximo de threads que o sistema pode suportar.

Exemplo:

```csh
setenv OMP_NUM_THREADS 16
```

### <a name="cross-references"></a>Referências cruzadas

- [cláusula num_threads](2-directives.md#23-parallel-construct)
- [função omp_set_num_threads](3-run-time-library-functions.md#311-omp_set_num_threads-function)
- [função omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function)

## <a name="43-omp_dynamic"></a><a name="43-omp_dynamic"></a>4.3 OMP_DYNAMIC

A `OMP_DYNAMIC` variável ambiente permite ou desativa o ajuste dinâmico do número de threads disponíveis para a execução de regiões paralelas. `OMP_DYNAMIC`é ignorado quando o ajuste dinâmico é explicitamente `omp_set_dynamic` ativado ou desativado, chamando a rotina da biblioteca. Seu valor `TRUE` deve `FALSE`ser ou .

Se `OMP_DYNAMIC` for `TRUE`definido como , o número de threads usados para executar regiões paralelas pode ser ajustado pelo ambiente de tempo de execução para melhor usar os recursos do sistema.  Se `OMP_DYNAMIC` for `FALSE`definido como , o ajuste dinâmico está desativado. A condição padrão é definida pela implementação.

Exemplo:

```csh
setenv OMP_DYNAMIC TRUE
```

### <a name="cross-references"></a>Referências cruzadas

- [Regiões paralelas](2-directives.md#23-parallel-construct)
- [função omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function)

## <a name="44-omp_nested"></a><a name="44-omp_nested"></a>4,4 OMP_NESTED

A `OMP_NESTED` variável ambiente habilita ou desativa o paralelismo aninhado, `omp_set_nested` a menos que o paralelismo aninhado seja ativado ou desativado, chamando a rotina da biblioteca. Se `OMP_NESTED` for `TRUE`definido para, o paralelismo aninhado está ativado. Se `OMP_NESTED` for `FALSE`definido para, o paralelismo aninhado é desativado. O valor padrão é `FALSE`.

Exemplo:

```csh
setenv OMP_NESTED TRUE
```

### <a name="cross-reference"></a>Referência cruzada

- [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function) função
