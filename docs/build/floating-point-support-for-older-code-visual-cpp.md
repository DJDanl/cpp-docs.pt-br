---
title: Suporte de ponto flutuante para código anterior (Visual C++)
ms.date: 11/04/2016
ms.assetid: a2a26b96-7bc2-418a-981a-51aa1a0294a2
ms.openlocfilehash: 2340a4d136dee3438a47ce06793ed9274035250d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509637"
---
# <a name="floating-point-support-for-older-code-visual-c"></a>Suporte de ponto flutuante para código anterior (Visual C++)

O MMX e os registros de pilha de ponto flutuante (MM0-MM7/ST0-ST7) são preservados entre alternâncias de contexto.  Não há nenhum convenção de chamada explícita para esses registros.  O uso desses registros é estritamente proibido no código em modo kernel.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)