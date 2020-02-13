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
ms.openlocfilehash: 838427320fcb68cedb97b36156fc18002ed962d8
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143285"
---
# <a name="openmp-environment-variables"></a>OpenMP Variáveis de ambiente

Fornece links para variáveis de ambiente usadas na API de OpenMP.

A implementação C++ visual do padrão de OpenMP inclui as seguintes variáveis de ambiente. Essas variáveis de ambiente são lidas na inicialização do programa e as modificações em seus valores são ignoradas no tempo de execução (por exemplo, usando [_putenv, _wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)).

|Variável de ambiente|Descrição|
|--------------------|-----------|
|[OMP_SCHEDULE](#omp-schedule)|Modifica o comportamento da cláusula [Schedule](openmp-clauses.md#schedule) quando `schedule(runtime)` é especificado em uma diretiva `for` ou `parallel for`.|
|[OMP_NUM_THREADS](#omp-num-threads)|Define o número máximo de threads na região paralela, a menos que seja substituído por [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou [num_threads](openmp-clauses.md#num-threads).|
|[OMP_DYNAMIC](#omp-dynamic)|Especifica se o tempo de execução de OpenMP pode ajustar o número de threads em uma região paralela.|
|[OMP_NESTED](#omp-nested)|Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado esteja habilitado ou desabilitado com `omp_set_nested`.|

## <a name="omp-dynamic"></a>OMP_DYNAMIC

Especifica se o tempo de execução de OpenMP pode ajustar o número de threads em uma região paralela.

```cmd
set OMP_DYNAMIC[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

A variável de ambiente `OMP_DYNAMIC` pode ser substituída pela função [omp_set_dynamic](openmp-functions.md#omp-set-dynamic) .

O valor padrão na implementação Visual C++ do padrão de OpenMP é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [4,3 OMP_DYNAMIC](../../../parallel/openmp/4-3-omp-dynamic.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O comando a seguir define a variável de ambiente `OMP_DYNAMIC` como TRUE:

```cmd
set OMP_DYNAMIC=TRUE
```

O comando a seguir exibe a configuração atual da variável de ambiente `OMP_DYNAMIC`:

```cmd
set OMP_DYNAMIC
```

## <a name="omp-nested"></a>OMP_NESTED

Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado esteja habilitado ou desabilitado com `omp_set_nested`.

```cmd
set OMP_NESTED[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

A variável de ambiente `OMP_NESTED` pode ser substituída pela função [omp_set_nested](openmp-functions.md#omp-set-nested) .

O valor padrão na implementação Visual C++ do padrão de OpenMP é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [4,4 OMP_NESTED](../../../parallel/openmp/4-4-omp-nested.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O comando a seguir define a variável de ambiente `OMP_NESTED` como TRUE:

```cmd
set OMP_NESTED=TRUE
```

O comando a seguir exibe a configuração atual da variável de ambiente `OMP_NESTED`:

```cmd
set OMP_NESTED
```

## <a name="omp-num-threads"></a>OMP_NUM_THREADS

Define o número máximo de threads na região paralela, a menos que seja substituído por [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou [num_threads](openmp-clauses.md#num-threads).

```cmd
set OMP_NUM_THREADS[=num]
```

### <a name="parameters"></a>Parâmetros

*teclas*<br/>
O número máximo de threads que você deseja na região paralela, até 64 na implementação Visual C++ .

### <a name="remarks"></a>Comentários

A variável de ambiente `OMP_NUM_THREADS` pode ser substituída pela função [omp_set_num_threads](openmp-functions.md#omp-set-num-threads) ou por [num_threads](openmp-clauses.md#num-threads).

O valor padrão de `num` na implementação Visual C++ do padrão de OpenMP é o número de processadores virtuais, incluindo CPUs hyperthreading.

Para obter mais informações, consulte [4,2 OMP_NUM_THREADS](../../../parallel/openmp/4-2-omp-num-threads.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O comando a seguir define a variável de ambiente `OMP_NUM_THREADS` como `16`:

```cmd
set OMP_NUM_THREADS=16
```

O comando a seguir exibe a configuração atual da variável de ambiente `OMP_NUM_THREADS`:

```cmd
set OMP_NUM_THREADS
```

## <a name="omp-schedule"></a>OMP_SCHEDULE

Modifica o comportamento da cláusula [Schedule](openmp-clauses.md#schedule) quando `schedule(runtime)` é especificado em uma diretiva `for` ou `parallel for`.

```cmd
set OMP_SCHEDULE[=type[,size]]
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Adicional Especifica o tamanho das iterações. o *tamanho* deve ser um inteiro positivo. O padrão é `1`, exceto quando o *tipo* é estático. Não é válido quando o *tipo* é `runtime`.

*tipo*<br/>
O tipo de agendamento, `dynamic`, `guided`, `runtime`ou `static`.

### <a name="remarks"></a>Comentários

O valor padrão na implementação Visual C++ do padrão de OpenMP é `OMP_SCHEDULE=static,0`.

Para obter mais informações, consulte [4,1 OMP_SCHEDULE](../../../parallel/openmp/4-1-omp-schedule.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O comando a seguir define a variável de ambiente `OMP_SCHEDULE`:

```cmd
set OMP_SCHEDULE="guided,2"
```

O comando a seguir exibe a configuração atual da variável de ambiente `OMP_SCHEDULE`:

```cmd
set OMP_SCHEDULE
```
