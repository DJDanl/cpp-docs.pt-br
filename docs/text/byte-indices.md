---
title: "&#205;ndices de byte | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "índices de byte [C++]"
  - "MBCS [C++], índices de byte"
ms.assetid: f6e7774a-86c6-41c2-89e3-74fd46432e47
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# &#205;ndices de byte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as dicas a seguir:  
  
-   Trabalhando com um índice de bytewise em uma cadeia de caracteres enfrentar problemas semelhantes a levantados pela manipulação do ponteiro.  Considere este exemplo, que examina uma cadeia de caracteres para um caractere de barra invertida:  
  
    ```  
    while ( rgch[ i ] != '\\' )  
        i++;  
    ```  
  
     Isso pode indexar um byte final, não um byte inicial, e assim não pode apontar a `character`.  
  
-   Use a função de [\_mbclen](../c-runtime-library/reference/mbclen-mblen-mblen-l.md) para resolver o problema anterior:  
  
    ```  
    while ( rgch[ i ] != '\\' )  
        i += _mbclen ( rgch + i );  
    ```  
  
     Isso corretamente índices em um byte inicial, por isso a `character`.  A função de `_mbclen` determina o tamanho de um caractere \(1 ou 2 bytes\).  
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)   
 [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)