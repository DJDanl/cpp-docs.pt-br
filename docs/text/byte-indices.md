---
title: "Índices de byte | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MBCS [C++], byte indices
- byte indices [C++]
ms.assetid: f6e7774a-86c6-41c2-89e3-74fd46432e47
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 594acadeedad06e9720180c38bd0bcd657391879
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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