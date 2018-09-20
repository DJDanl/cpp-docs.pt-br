---
title: 3.1.9 função omp_set_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e4afc3aa-bb96-4314-9849-fd5df5f437d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 68e5898b8b57814a152ca2ce9ced84a9df8190cc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414531"
---
# <a name="319-ompsetnested-function"></a>3.1.9 função omp_set_nested

O **omp_set_nested** função habilita ou desabilita o paralelismo aninhado. O formato é o seguinte:

```
#include <omp.h>
void omp_set_nested(int nested);
```

Se *aninhada* é avaliada como 0, aninhados paralelismo estiver desabilitado, o que é o padrão e regiões em paralelo aninhadas são serializadas e executadas pelo thread atual. Se *aninhada* é avaliada como um valor diferente de zero, o paralelismo aninhado está habilitado e regiões em paralelo que estão aninhado podem implantar threads adicionais para formar equipes aninhadas.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o **omp_in_parallel** função retorna zero. Se ele é chamado de uma parte do programa em que o **omp_in_parallel** função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Essa chamada tem precedência sobre o **OMP_NESTED** variável de ambiente.

Quando o paralelismo aninhado é habilitado, o número de threads usados para executar as regiões aninhadas paralelas é definido pela implementação. Como resultado, as implementações em conformidade com o OpenMP têm permissão para serializar aninhadas regiões em paralelo, mesmo quando o paralelismo aninhado está habilitado.

## <a name="cross-references"></a>Entre as referências:

- **OMP_NESTED** consulte de variável de ambiente [seção 4.4](../../parallel/openmp/4-4-omp-nested.md) na página 49.

- **omp_in_parallel** , consulte [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página de 38.