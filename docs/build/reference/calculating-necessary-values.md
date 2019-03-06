---
title: Calculando valores necessários
ms.date: 11/04/2016
helpviewer_keywords:
- helper functions, calculating necessary values
ms.assetid: 4f037d0f-881a-4a48-a9d2-9f8872dfccb7
ms.openlocfilehash: 75952bbcdf823aa675b35702841c81e511105ca8
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426401"
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
