---
title: OpenMP Variáveis de ambiente
ms.date: 03/20/2019
f1_keywords:
- OpenMP environment variables
- OMP_DYNAMIC
- OMP_NESTED
- OMP_NUM_THREADS
- OMP_SCHEDULE
helpviewer_keywords:
- OpenMP environment variables
- OMP_DYNAMIC OpenMP environment variable
- OMP_NESTED OpenMP environment variable
- OMP_NUM_THREADS OpenMP environment variable
- OMP_SCHEDULE OpenMP environment variable
ms.assetid: 2178ce2b-ffa1-45ec-a455-64437711d15d
ms.openlocfilehash: bee9b0fbdf147ee962ff92d0b3b9ff57d4209f84
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363882"
---
# <a name="openmp-environment-variables"></a>OpenMP Variáveis de ambiente

Fornece links para variáveis de ambiente usadas na API OpenMP.

A implementação Visual C++ do padrão OpenMP inclui as seguintes variáveis de ambiente. Essas variáveis de ambiente são lidas na inicialização do programa e as modificações em seus valores são ignoradas em tempo de execução (por exemplo, usando [_putenv, _wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)).

|Variável de ambiente|Descrição|
|--------------------|-----------|
|[OMP_SCHEDULE](#omp-schedule)|Modifica o comportamento [schedule](openmp-clauses.md#schedule) da cláusula `schedule(runtime)` de agendamento `for` quando `parallel for` é especificada em uma diretiva ou diretiva.|
|[OMP_NUM_THREADS](#omp-num-threads)|Define o número máximo de roscas na região paralela, a menos que substituído por [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou [num_threads](openmp-clauses.md#num-threads).|
|[OMP_DYNAMIC](#omp-dynamic)|Especifica se o tempo de execução do OpenMP pode ajustar o número de threads em uma região paralela.|
|[OMP_NESTED](#omp-nested)|Especifica se o paralelismo aninhado está ativado, a menos `omp_set_nested`que o paralelismo aninhado esteja ativado ou desativado com .|

## <a name="omp_dynamic"></a><a name="omp-dynamic"></a>OMP_DYNAMIC

Especifica se o tempo de execução do OpenMP pode ajustar o número de threads em uma região paralela.

```cmd
set OMP_DYNAMIC[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

A `OMP_DYNAMIC` variável ambiente pode ser substituída pela função [omp_set_dynamic.](openmp-functions.md#omp-set-dynamic)

O valor padrão na implementação Visual C++ `OMP_DYNAMIC=FALSE`do padrão OpenMP é .

Para obter mais informações, consulte [4,3 OMP_DYNAMIC](../../../parallel/openmp/4-3-omp-dynamic.md).

### <a name="example"></a>Exemplo

O comando a `OMP_DYNAMIC` seguir define a variável ambiente como TRUE:

```cmd
set OMP_DYNAMIC=TRUE
```

O comando a seguir exibe `OMP_DYNAMIC` a configuração atual da variável ambiente:

```cmd
set OMP_DYNAMIC
```

## <a name="omp_nested"></a><a name="omp-nested"></a>OMP_NESTED

Especifica se o paralelismo aninhado está ativado, a menos `omp_set_nested`que o paralelismo aninhado esteja ativado ou desativado com .

```cmd
set OMP_NESTED[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

A `OMP_NESTED` variável ambiente pode ser substituída pela função [omp_set_nested.](openmp-functions.md#omp-set-nested)

O valor padrão na implementação Visual C++ `OMP_DYNAMIC=FALSE`do padrão OpenMP é .

Para obter mais informações, consulte [4.4 OMP_NESTED](../../../parallel/openmp/4-4-omp-nested.md).

### <a name="example"></a>Exemplo

O comando a `OMP_NESTED` seguir define a variável ambiente como TRUE:

```cmd
set OMP_NESTED=TRUE
```

O comando a seguir exibe `OMP_NESTED` a configuração atual da variável ambiente:

```cmd
set OMP_NESTED
```

## <a name="omp_num_threads"></a><a name="omp-num-threads"></a>OMP_NUM_THREADS

Define o número máximo de roscas na região paralela, a menos que substituído por [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou [num_threads](openmp-clauses.md#num-threads).

```cmd
set OMP_NUM_THREADS[=num]
```

### <a name="parameters"></a>Parâmetros

*num*<br/>
O número máximo de threads que você deseja na região paralela, até 64 na implementação Visual C++.

### <a name="remarks"></a>Comentários

A `OMP_NUM_THREADS` variável ambiente pode ser substituída pela função [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou por [num_threads](openmp-clauses.md#num-threads).

O valor `num` padrão da implementação Visual C++ do padrão OpenMP é o número de processadores virtuais, incluindo CPUs de hiperthreading.

Para obter mais informações, consulte [4.2 OMP_NUM_THREADS](../../../parallel/openmp/4-2-omp-num-threads.md).

### <a name="example"></a>Exemplo

O comando a `OMP_NUM_THREADS` seguir `16`define a variável ambiente para:

```cmd
set OMP_NUM_THREADS=16
```

O comando a seguir exibe `OMP_NUM_THREADS` a configuração atual da variável ambiente:

```cmd
set OMP_NUM_THREADS
```

## <a name="omp_schedule"></a><a name="omp-schedule"></a>Omp_schedule

Modifica o comportamento [schedule](openmp-clauses.md#schedule) da cláusula `schedule(runtime)` de agendamento `for` quando `parallel for` é especificada em uma diretiva ou diretiva.

```cmd
set OMP_SCHEDULE[=type[,size]]
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
(Opcional) Especifica o tamanho das iterações. *tamanho* deve ser um inteiro positivo. O padrão `1`é, exceto quando *o tipo* é estático. Não é válido `runtime`quando o *tipo* é .

*type*<br/>
O tipo de agendamento, `guided` `runtime`ou `dynamic` `static`, ou , ou .

### <a name="remarks"></a>Comentários

O valor padrão na implementação Visual C++ `OMP_SCHEDULE=static,0`do padrão OpenMP é .

Para obter mais informações, consulte [4.1 OMP_SCHEDULE](../../../parallel/openmp/4-1-omp-schedule.md).

### <a name="example"></a>Exemplo

O comando a `OMP_SCHEDULE` seguir define a variável ambiente:

```cmd
set OMP_SCHEDULE="guided,2"
```

O comando a seguir exibe `OMP_SCHEDULE` a configuração atual da variável ambiente:

```cmd
set OMP_SCHEDULE
```
