---
title: MxCsr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 4f3c229d-0862-4733-acc7-9ed7a0b870ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d18a4247d36e6894230d74322d52cd5854e42fb
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726499"
---
# <a name="mxcsr"></a>MxCsr

O estado de registro também inclui MxCsr. A convenção de chamada divide o registro em uma parte voláteis e uma parte não volátil. A parte volátil consiste dos sinalizadores de 6 status, MXCSR [0:5], enquanto o restante do registrador, MXCSR [6:15] é considerado não-volátil.

A parte não-volátil é definida para os seguintes valores padrão no início da execução do programa:

```
MXCSR[6]         : Denormals are zeros - 0
MXCSR[7:12]      : Exception masks all 1's (all exceptions masked)
MXCSR[13:14]   : Rounding  control - 0 (round to nearest)
MXCSR[15]      : Flush to zero for masked underflow - 0 (off)
```

Um receptor que modifica qualquer um dos campos não-volátil dentro do registro MXCSR deve restaurá-los antes de retornar a seu chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que o contrato, o receptor espera que os valores modificados.

Há duas exceções para regras relativas à não volatilidade dos sinalizadores de controle:

- Em funções em que a finalidade documentada da função fornecida é modificar o registro não volátil MxCsr sinalizadores.

- Quando ele é provavelmente corrigi a que a violação dessas regras resulta em um programa que se comporta/significa que o mesmo que um programa em que essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.

Não pode ser feita nenhuma suposição sobre o estado da parte voláteis de MXCSR em um limite de função, a menos que especificamente descrito na documentação da função.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)