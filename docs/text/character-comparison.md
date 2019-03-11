---
title: Comparação de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- comparing characters
- MBCS [C++], character comparison
- characters [C++], comparing
ms.assetid: 18846e44-3e6e-40c4-9b42-3153fb15db20
ms.openlocfilehash: 075a22634f254c2ea634a1171ee157971fe5918e
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749328"
---
# <a name="character-comparison"></a>Comparação de caracteres

Use as dicas a seguir:

- Comparar um byte inicial conhecido com um caractere ASCII funciona corretamente:

    ```cpp
    if( *sz1 == 'A' )
    ```

- Comparação de dois caracteres desconhecidos requer o uso de uma das macros definidas em mbstring:

    ```cpp
    if( !_mbccmp( sz1, sz2) )
    ```

   Isso garante que os dois bytes de um caractere de byte duplo são comparados quanto à igualdade.

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Estouro de buffer](../text/buffer-overflow.md)
