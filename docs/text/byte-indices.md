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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 509e66c7ea458519eaa9dc4f52c8a6b65c789d0f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33863794"
---
# <a name="byte-indices"></a>Índices de byte
Use as dicas a seguir:  
  
-   Trabalhando com um índice bytewise em uma cadeia de caracteres apresenta problemas semelhantes aos representado pela manipulação do ponteiro. Considere este exemplo, que verifica uma cadeia de caracteres para um caractere de barra invertida:  
  
    ```  
    while ( rgch[ i ] != '\\' )  
        i++;  
    ```  
  
     Isso pode indexar um byte final, não um byte inicial, e, portanto, ela não pode apontar para um `character`.  
  
-   Use o [mbclen](../c-runtime-library/reference/mbclen-mblen-mblen-l.md) função para resolver o problema anterior:  
  
    ```  
    while ( rgch[ i ] != '\\' )  
        i += _mbclen ( rgch + i );  
    ```  
  
     Isso índices corretamente para um byte inicial, portanto, para um `character`. O `_mbclen` função determina o tamanho de um caractere (1 ou 2 bytes).  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)