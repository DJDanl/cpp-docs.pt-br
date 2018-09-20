---
title: Comparação de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- comparing characters
- MBCS [C++], character comparison
- characters [C++], comparing
ms.assetid: 18846e44-3e6e-40c4-9b42-3153fb15db20
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3412939bac9dace6f3abaacda75ed73d6e60f21
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428064"
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