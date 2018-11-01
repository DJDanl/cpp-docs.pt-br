---
title: FpCsr
ms.date: 11/04/2016
ms.assetid: dff95d5d-7589-4432-82db-64b459c24352
ms.openlocfilehash: 018ce39a194d5153f73fa452990844362190e6bd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472807"
---
# <a name="fpcsr"></a>FpCsr

O estado do registro também inclui x87 palavra de controle FPU. A convenção de chamada determina o registro para ser não-volátil.

X87 registro de palavra de controle FPU é definido com os seguintes valores padrão no início da execução do programa:

```
FPCSR[0:6]: Exception masks all 1's (all exceptions masked)
FPCSR[7]: Reserved - 0
FPCSR[8:9]: Precision Control - 10B (double precision)
FPCSR[10:11]: Rounding  control - 0 (round to nearest)
FPCSR[12]: Infinity control - 0 (not used)
```

Um receptor que modifica qualquer um dos campos dentro de FPCSR necessário restaurá-los antes de retornar a seu chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que o contrato, o receptor espera que os valores modificados.

Há duas exceções para regras relativas à não volatilidade dos sinalizadores de controle:

1. Em funções em que a finalidade documentada da função fornecida é modificar o FpCsr não volátil sinalizadores.

1. Quando ele é provavelmente corrigi a que a violação dessas regras resulta em um programa que se comporta/significa que o mesmo que um programa em que essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)