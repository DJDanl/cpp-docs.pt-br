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
ms.openlocfilehash: 254dffebc258867088f738b10a11bf48d31bd0a4
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990055"
---
# <a name="openmp-data-types"></a>OpenMP Tipos de dados

Fornece links para os tipos de dados usados na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui os seguintes tipos de dados.

Tipo de dados                           | Descrição
----------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[omp_lock_t](#omp-lock-t)           | Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.
[omp_nest_lock_t](#omp-nest-lock-t) | Um tipo que contém uma das seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.

## <a name="omp-lock-t"></a>omp_lock_t

Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.

As seguintes funções usam `omp_lock_t`:

- [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md)
- [omp_destroy_lock](../../../parallel/openmp/reference/omp-destroy-lock.md)
- [omp_set_lock](../../../parallel/openmp/reference/omp-set-lock.md)
- [omp_unset_lock](../../../parallel/openmp/reference/omp-unset-lock.md)
- [omp_test_lock](../../../parallel/openmp/reference/omp-test-lock.md)

Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).

### <a name="example"></a>Exemplo

Ver [funções omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo de como usar `omp_lock_t`.

## <a name="omp-nest-lock-t"></a>omp_nest_lock_t

Um tipo que contém as seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.

As seguintes funções usam `omp_nest_lock_t`:

- [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md)
- [omp_destroy_nest_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)
- [omp_set_nest_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)
- [omp_unset_nest_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)
- [omp_test_nest_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)

Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).

### <a name="example"></a>Exemplo

Ver [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md) para obter um exemplo de como usar `omp_nest_lock_t`.
