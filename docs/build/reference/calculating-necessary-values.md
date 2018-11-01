---
title: Calculando valores necessários
ms.date: 11/04/2016
helpviewer_keywords:
- helper functions, calculating necessary values
ms.assetid: 4f037d0f-881a-4a48-a9d2-9f8872dfccb7
ms.openlocfilehash: 80c028a315669fb0032628bb86a834d429935f50
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50513861"
---
# <a name="calculating-necessary-values"></a>Calculando valores necessários

Duas partes críticas de informações precisam ser calculado pela rotina do auxiliar de atraso. Para esse fim, há duas funções embutidas no delayhlp.cpp para calcular essas informações.

- O primeiro calcula o índice da importação atual nas três tabelas diferentes (importação de endereço IAT (tabela), a tabela de endereços de importação associado (BIAT) e a tabela de endereços de importação não associado (UIAT)).

- A segunda conta o número de importações em uma IAT válida.

```cpp
// utility function for calculating the index of the current import
// for all the tables (INT, BIAT, UIAT, and IAT).
__inline unsigned
IndexFromPImgThunkData(PCImgThunkData pitdCur, PCImgThunkData pitdBase) {
    return pitdCur - pitdBase;
    }

// utility function for calculating the count of imports given the base
// of the IAT. NB: this only works on a valid IAT!
__inline unsigned
CountOfImports(PCImgThunkData pitdBase) {
    unsigned        cRet = 0;
    PCImgThunkData  pitd = pitdBase;
    while (pitd->u1.Function) {
        pitd++;
        cRet++;
        }
    return cRet;
    }
```

## <a name="see-also"></a>Consulte também

[Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)