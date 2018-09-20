---
title: 3.1.4 função omp_get_thread_num | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5220402b-c109-4b1f-ba79-002e93d08617
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a21a682c051daffde16b3d5cfc63fd2d679c4de
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444912"
---
# <a name="314-ompgetthreadnum-function"></a>3.1.4 função omp_get_thread_num

O `omp_get_thread_num` função retorna o número de threads, dentro de sua equipe do thread executando a função. O reside número de threads entre 0 e **omp_get_num_threads()**-1, inclusivo. O thread mestre da equipe é 0.

O formato é o seguinte:

```
#include <omp.h>
int omp_get_thread_num(void);
```

Se for chamado de uma região serial, `omp_get_thread_num` retornará 0. Se chamado de dentro de uma região paralela aninhada que é serializada, essa função retorna 0.

## <a name="cross-references"></a>Entre as referências:

- `omp_get_num_threads` função, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.