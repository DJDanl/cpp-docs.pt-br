---
title: 4.1 OMP_SCHEDULE
ms.date: 11/04/2016
ms.assetid: d0dce411-2351-4ee9-a1cc-c0322a58b65c
ms.openlocfilehash: 4731299a4f7203dd01f660ea25bf2f5b58060630
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432689"
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