---
title: Precedência em definições de macro
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, precedence in macro definitions
- macros, precedence
ms.assetid: 0c13182d-83cb-4cbd-af2d-f4c916b62aeb
ms.openlocfilehash: 38a653a9f460beae81f9f88ea457870d30f25339
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320156"
---
# <a name="precedence-in-macro-definitions"></a>Precedência em definições de macro

Se uma macro tem várias definições, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência, em ordem decrescente:

1. Uma macro definida na linha de comando

1. Uma macro definida em um makefile ou arquivo de inclusão

1. Uma macro de variável de ambiente herdada

1. Uma macro definida no arquivo Tools. ini

1. Uma macro predefinida, como [CC](command-macros-and-options-macros.md) e [AS](command-macros-and-options-macros.md)

Use /E para fazer com que as macros herdadas de variáveis de ambiente para substituir macros do makefile com o mesmo nome. Use **! UNDEF** para substituir uma linha de comando.

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](defining-an-nmake-macro.md)
