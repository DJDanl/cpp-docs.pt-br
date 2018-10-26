---
title: Tipos de dados de OpenMP | Microsoft Docs
ms.custom: ''
ms.date: 10/23/2018
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OpenMP data types
- omp_lock_t
- omp_nest_lock_t
dev_langs:
- C++
helpviewer_keywords:
- OpenMP data types
- omp_lock_t OpenMP data type
- omp_nest_lock_t OpenMP data type
ms.assetid: cf1e1045-4d12-4d03-80b7-d5843b80ef85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97cf6ccad0a3b30c0abfa0076ea9c6a30b205d67
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065194"
---
# <a name="openmp-data-types"></a>Tipos de dados de OpenMP

Fornece links para os tipos de dados usados na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui os seguintes tipos de dados.

|Tipo de dados|Descrição|
|---------|-----------|
|[omp_lock_t](#omp-lock-t)|Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.|
|[omp_nest_lock_t](#omp-nest-lock-t)|Um tipo que contém uma das seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.|

## <a name="omp-lock-t"></a>omp_lock_t

Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.

As seguintes funções usam `omp_lock_t`:

- [omp_init_lock](openmp-functions.md#omp-init-lock)
- [omp_destroy_lock](openmp-functions.md#omp-destroy-lock)
- [omp_set_lock](openmp-functions.md#omp-set-lock)
- [omp_unset_lock](openmp-functions.md#omp-unset-lock)
- [omp_test_lock](openmp-functions.md#omp-test-lock)

Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).

### <a name="example"></a>Exemplo

Ver [funções omp_init_lock](openmp-functions.md#omp-init-lock) para obter um exemplo de como usar `omp_lock_t`.

## <a name="omp-nest-lock-t"></a>omp_nest_lock_t

Um tipo que contém as seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.

As seguintes funções usam `omp_nest_lock_t`:

- [omp_init_nest_lock](openmp-functions.md#omp-init-nest-lock)
- [omp_destroy_nest_lock](openmp-functions.md#omp-destroy-nest-lock)
- [omp_set_nest_lock](openmp-functions.md#omp-set-nest-lock)
- [omp_unset_nest_lock](openmp-functions.md#omp-unset-nest-lock)
- [omp_test_nest_lock](openmp-functions.md#omp-test-nest-lock)

Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).

### <a name="example"></a>Exemplo

Ver [omp_init_nest_lock](openmp-functions.md#omp-init-nest-lock) para obter um exemplo de como usar `omp_nest_lock_t`.
