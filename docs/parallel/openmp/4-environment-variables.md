---
title: 4. Variáveis de ambiente
ms.date: 01/16/2019
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
ms.openlocfilehash: 5d08031c252d1f3c45fc45c021d24476b393fe33
ms.sourcegitcommit: 2ebbf8093fadb9a1b78a4381439bcd5c01a89267
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/18/2019
ms.locfileid: "54397323"
---
# <a name="4-environment-variables"></a>4. Variáveis de ambiente

Este capítulo descreve as variáveis de ambiente OpenMP C e C++ API (ou semelhantes mecanismos de específico da plataforma) que controlam a execução do código paralelo.  Os nomes das variáveis de ambiente devem ser maiusculos. Os valores atribuídos a eles diferenciam maiusculas de minúsculas e podem ter espaços em branco à esquerda e à direita.  Modificações aos valores depois que o programa foi iniciado são ignoradas.

As variáveis de ambiente são da seguinte maneira:

- [OMP_SCHEDULE](#41-omp_schedule) define o tamanho de bloco e de tipo de agendamento de tempo de execução.
- [OMP_NUM_THREADS](#42-omp_num_threads) define o número de threads a serem usados durante a execução.
- [OMP_DYNAMIC](#43-omp_dynamic) ativa ou desativa o ajuste dinâmico do número de threads.
- [OMP_NESTED](#44-omp_nested) habilita ou desabilita o paralelismo aninhado.

Os exemplos neste capítulo somente demonstram como essas variáveis podem ser definidas em ambientes de shell (csh) de C do Unix. No shell Korn e ambientes do DOS, as ações são semelhantes:

csh:  
`setenv OMP_SCHEDULE "dynamic"`

ksh:  
`export OMP_SCHEDULE="dynamic"`

DOS:  
`set OMP_SCHEDULE="dynamic"`

## <a name="41-ompschedule"></a>4.1 OMP_SCHEDULE

`OMP_SCHEDULE` aplica-se somente aos `for` e `parallel for` diretivas com o tipo de agenda `runtime`. O tamanho de bloco e de tipo de agenda para todos os loops pode ser definido em tempo de execução. Defina essa variável de ambiente para qualquer tipo de agendamento reconhecidos e um opcional *chunk_size*.

Para `for` e `parallel for` diretivas que têm um tipo de agenda diferente de `runtime`, `OMP_SCHEDULE` será ignorado. O valor padrão para essa variável de ambiente é definido pela implementação. Se o opcional *chunk_size* for definido, o valor deve ser positivo. Se *chunk_size* não estiver definido, um valor de 1 é pressuposto que, exceto quando a agenda é `static`. Para um `static` agendamento, o tamanho da parte padrão é definido como o espaço de iteração do loop dividido pelo número de threads aplicada para o loop.

Exemplo:

```csh
setenv OMP_SCHEDULE "guided,4"
setenv OMP_SCHEDULE "dynamic"
```

### <a name="cross-references"></a>Referências cruzadas

- [para](2-4-1-for-construct.md) diretiva
- [paralelo para](2-5-1-parallel-for-construct.md) diretiva

## <a name="42-ompnumthreads"></a>4.2 OMP_NUM_THREADS

O `OMP_NUM_THREADS` variável de ambiente define o número padrão de threads a serem usados durante a execução. `OMP_NUM_THREADS` será ignorado se esse número é alterado explicitamente, chamando o `omp_set_num_threads` rotina da biblioteca. Ele também será ignorado se não houver um explícito `num_threads` cláusula em uma `parallel` diretiva.

O valor da `OMP_NUM_THREADS` variável de ambiente deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o `OMP_NUM_THREADS` ambiente variável e dinâmico de ajuste de threads, consulte a seção 2.3.

O número de threads a ser usado é definido pela implementação se:

- o `OMP_NUM_THREADS` variável de ambiente não for especificada,
- o valor especificado não é um inteiro positivo, ou
- o valor é maior que o número máximo de threads que o sistema pode dar suporte.

Exemplo:

```csh
setenv OMP_NUM_THREADS 16
```

### <a name="cross-references"></a>Referências cruzadas

- [num_threads](2-3-parallel-construct.md) cláusula
- [omp_set_num_threads](3-1-1-omp-set-num-threads-function.md) função
- [omp_set_dynamic](3-1-7-omp-set-dynamic-function.md) function

## <a name="43-ompdynamic"></a>4.3 OMP_DYNAMIC

O `OMP_DYNAMIC` variável de ambiente ativa ou desativa o ajuste dinâmico do número de threads disponíveis para a execução de regiões em paralelo. `OMP_DYNAMIC` é ignorado quando o ajuste dinâmico está habilitado ou desabilitado chamando explicitamente o `omp_set_dynamic` rotina da biblioteca. Seu valor deve ser `TRUE` ou `FALSE`.

Se `OMP_DYNAMIC` é definido como `TRUE`, o número de threads que são usados para a execução de regiões em paralelo pode ser ajustado pelo ambiente de tempo de execução para usar melhor os recursos do sistema.  Se `OMP_DYNAMIC` é definido como `FALSE`, ajuste dinâmico está desabilitado. A condição padrão é definido pela implementação.

Exemplo:

```csh
setenv OMP_DYNAMIC TRUE
```

### <a name="cross-references"></a>Referências cruzadas

- [Regiões em paralelo](2-3-parallel-construct.md)
- [omp_set_dynamic](3-1-7-omp-set-dynamic-function.md) function

## <a name="44-ompnested"></a>4.4 OMP_NESTED

O `OMP_NESTED` variável de ambiente habilita ou desabilita o paralelismo aninhado, a menos que o paralelismo aninhado está habilitado ou desabilitado chamando o `omp_set_nested` rotina da biblioteca. Se `OMP_NESTED` é definido como `TRUE`, paralelismo aninhado está habilitado. Se `OMP_NESTED` é definido como `FALSE`aninhados paralelismo está desativado. O valor padrão é `FALSE`.

Exemplo:

```csh
setenv OMP_NESTED TRUE
```

### <a name="cross-reference"></a>Referência cruzada

- [omp_set_nested](3-1-9-omp-set-nested-function.md) function
