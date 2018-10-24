---
title: OpenMP variáveis de ambiente | Microsoft Docs
ms.custom: ''
ms.date: 10/23/2018
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OpenMP environment variables
- OMP_DYNAMIC
- OMP_NESTED
- OMP_NUM_THREADS
- OMP_SCHEDULE
dev_langs:
- C++
helpviewer_keywords:
- OpenMP environment variables
- OMP_DYNAMIC OpenMP environment variable
- OMP_NESTED OpenMP environment variable
- OMP_NUM_THREADS OpenMP environment variable
- OMP_SCHEDULE OpenMP environment variable
ms.assetid: 2178ce2b-ffa1-45ec-a455-64437711d15d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 395494431c3942832a64cf64c9c150f643389062
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990224"
---
# <a name="openmp-environment-variables"></a>OpenMP Variáveis de ambiente

Fornece links para as variáveis de ambiente usadas na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui as seguintes variáveis de ambiente. Essas variáveis de ambiente são lidas na inicialização do programa e as modificações com seus valores são ignoradas em tempo de execução (por exemplo, usando [putenv, wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)).

Variável de ambiente                | Descrição
----------------------------------- | -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[OMP_DYNAMIC](#omp-dynamic)         | Especifica se o OpenMP no tempo de execução pode ajustar o número de threads em uma região paralela.
[OMP_NESTED](#omp-nested)           | Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.
[OMP_NUM_THREADS](#omp-num-threads) | Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](openmp-clauses.md#num-threads).
[OMP_SCHEDULE](#omp-schedule)       | Modifica o comportamento do [agendamento](openmp-clauses.md#schedule) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.

## <a name="omp-dynamic"></a>OMP_DYNAMIC

Especifica se o OpenMP no tempo de execução pode ajustar o número de threads em uma região paralela.

```
set OMP_DYNAMIC[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

O `OMP_DYNAMIC` variável de ambiente pode ser substituída pelo [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) função.

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [OMP_DYNAMIC 4.3](../../../parallel/openmp/4-3-omp-dynamic.md).

### <a name="example"></a>Exemplo

O seguinte comando define o `OMP_DYNAMIC` variável de ambiente como TRUE:

```
set OMP_DYNAMIC=TRUE
```

O comando a seguir exibe a configuração atual de `OMP_DYNAMIC` variável de ambiente:

```
set OMP_DYNAMIC
```

## <a name="omp-nested"></a>OMP_NESTED

Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.

```
set OMP_NESTED[=TRUE | =FALSE]
```

### <a name="remarks"></a>Comentários

O `OMP_NESTED` variável de ambiente pode ser substituída pelo [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) função.

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [4.4 OMP_NESTED](../../../parallel/openmp/4-4-omp-nested.md).

### <a name="example"></a>Exemplo

O seguinte comando define o `OMP_NESTED` variável de ambiente como TRUE:

```
set OMP_NESTED=TRUE
```

O comando a seguir exibe a configuração atual de `OMP_NESTED` variável de ambiente:

```
set OMP_NESTED
```

## <a name="omp-num-threads"></a>OMP_NUM_THREADS

Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](openmp-clauses.md#num-threads).

```
set OMP_NUM_THREADS[=num]
```

### <a name="parameters"></a>Parâmetros

*num*<br/>
O número máximo de threads que você deseja na região paralela, até 64 na implementação do Visual C++.

### <a name="remarks"></a>Comentários

O `OMP_NUM_THREADS` variável de ambiente pode ser substituída pelo [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função ou pelo [num_threads](openmp-clauses.md#num-threads).

O valor padrão de `num` no Visual C++ a implementação do padrão OpenMP é o número de processadores virtuais, incluindo CPUs hyperthreading.

Para obter mais informações, consulte [4.2 OMP_NUM_THREADS](../../../parallel/openmp/4-2-omp-num-threads.md).

### <a name="example"></a>Exemplo

O seguinte comando define o `OMP_NUM_THREADS` variável de ambiente para 16:

```
set OMP_NUM_THREADS=16
```

O comando a seguir exibe a configuração atual de `OMP_NUM_THREADS` variável de ambiente:

```
set OMP_NUM_THREADS
```

## <a name="omp-schedule"></a>OMP_SCHEDULE

Modifica o comportamento do [agendamento](openmp-clauses.md#schedule) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.

```
set OMP_SCHEDULE[=type[,size]]
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
(Opcional) Especifica o tamanho de iterações. `size` Deve ser um inteiro positivo. O padrão é 1, exceto quando `type` é estático. Não é válida quando `type` é `runtime`.

*type*<br/>
O tipo de agendamento:

- `dynamic`
- `guided`
- `runtime`
- `static`

### <a name="remarks"></a>Comentários

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_SCHEDULE=static,0`.

Para obter mais informações, consulte [OMP_SCHEDULE 4.1](../../../parallel/openmp/4-1-omp-schedule.md).

### <a name="example"></a>Exemplo

O seguinte comando define o `OMP_SCHEDULE` variável de ambiente:

```
set OMP_SCHEDULE="guided,2"
```

O comando a seguir exibe a configuração atual de `OMP_SCHEDULE` variável de ambiente:

```
set OMP_SCHEDULE
```
