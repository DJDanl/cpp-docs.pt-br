---
title: Precedência em definições de macro
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, precedence in macro definitions
- macros, precedence
ms.assetid: 0c13182d-83cb-4cbd-af2d-f4c916b62aeb
ms.openlocfilehash: 8829b3cdbc7b2324ef3d118f8ca45dd2a1621e7e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619070"
---
# <a name="precedence-in-macro-definitions"></a>Precedência em definições de macro

Se uma macro tem várias definições, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência, em ordem decrescente:

1. Uma macro definida na linha de comando

1. Uma macro definida em um makefile ou arquivo de inclusão

1. Uma macro de variável de ambiente herdada

1. Uma macro definida no arquivo Tools. ini

1. Uma macro predefinida, como [CC](../build/command-macros-and-options-macros.md) e [AS](../build/command-macros-and-options-macros.md)

Use /E para fazer com que as macros herdadas de variáveis de ambiente para substituir macros do makefile com o mesmo nome. Use **! UNDEF** para substituir uma linha de comando.

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)