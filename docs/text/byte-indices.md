---
title: Índices de byte | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MBCS [C++], byte indices
- byte indices [C++]
ms.assetid: f6e7774a-86c6-41c2-89e3-74fd46432e47
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 11f7f78e87ddd40fd3cf85fc294e8fadac5dbe45
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423787"
---
# <a name="byte-indices"></a>Índices de byte

Use as dicas a seguir:

- Trabalhar com um índice bytewise em uma cadeia de caracteres apresenta problemas semelhantes aos causados pela manipulação do ponteiro. Considere este exemplo, que verifica a existência de uma cadeia de caracteres para um caractere de barra invertida:

    ```cpp
    while ( rgch[ i ] != '\\' )
        i++;
    ```

   Isso pode indexar um byte final, não é um byte inicial, e, portanto, não pode apontar para um `character`.

- Use o [mbclen](../c-runtime-library/reference/mbclen-mblen-mblen-l.md) função para resolver o problema anterior:

    ```cpp
    while ( rgch[ i ] != '\\' )
        i += _mbclen ( rgch + i );
    ```

   Isso indexa corretamente para um byte inicial, portanto, para um `character`. O `_mbclen` função determina o tamanho de um caractere (1 ou 2 bytes).

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)