---
title: omp_nest_lock_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_nest_lock_t
dev_langs:
- C++
helpviewer_keywords:
- omp_nest_lock_t OpenMP data type
ms.assetid: fceac9fb-96d2-42b0-af19-c9b078380618
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b25a76332325247987751d8e9c41914da51f4a70
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390119"
---
# <a name="ompnestlockt"></a>omp_nest_lock_t

Um tipo que contém as seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.

As seguintes funções que usam **omp_nest_lock_t**:

- [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md)

- [omp_destroy_nest_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)

- [omp_set_nest_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)

- [omp_unset_nest_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)

- [omp_test_nest_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)

Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).

## <a name="example"></a>Exemplo

Ver [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md) para obter um exemplo de como usar **omp_nest_lock_t**.

## <a name="see-also"></a>Consulte também

[Tipos de Dados](../../../parallel/openmp/reference/openmp-data-types.md)