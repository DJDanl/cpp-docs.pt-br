---
title: 4.1 OMP_SCHEDULE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: d0dce411-2351-4ee9-a1cc-c0322a58b65c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cbdad5ab56ea6979ae2b5952b092b5e85c7bdfa8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433446"
---
# <a name="41-ompschedule"></a>4.1 OMP_SCHEDULE

**OMP_SCHEDULE** só se aplica ao **para** e **paralela para** diretivas com o tipo de agenda **tempo de execução**. O tamanho de bloco e de tipo de agenda para todos os loops pode ser definido em tempo de execução, definindo a variável de ambiente para qualquer um dos tipos reconhecidos agenda e um opcional *chunk_size*.

Para **para** e **paralela para** diretivas que têm um tipo de agenda diferente de **tempo de execução**, **OMP_SCHEDULE** será ignorado. O valor padrão para essa variável de ambiente é definido pela implementação. Se o opcional *chunk_size* for definido, o valor deve ser positivo. Se *chunk_size* não for definido, presume-se um valor de 1, exceto no caso de uma **estático** agendamento. Para um **estático** agendamento, o tamanho da parte padrão é definido como o espaço de iteração do loop dividido pelo número de threads aplicada para o loop.

Exemplo:

```
setenv OMP_SCHEDULE "guided,4"
setenv OMP_SCHEDULE "dynamic"
```

## <a name="cross-references"></a>Entre as referências:

- **para** diretiva, consulte [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página de 11.

- **paralelo para** diretiva, consulte [seção 2.5.1](../../parallel/openmp/2-5-1-parallel-for-construct.md) na página 16.