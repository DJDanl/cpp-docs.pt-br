---
title: "&#218;ltimo caractere em uma cadeia de caracteres | Microsoft Docs"
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
  - "último caractere na cadeia de caracteres"
  - "MBCS [C++], último caractere na cadeia de caracteres"
ms.assetid: 0a180376-4e55-41e8-9c64-539c7b6d8047
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# &#218;ltimo caractere em uma cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as dicas a seguir:  
  
-   Os intervalos de byte final sobreposição do conjunto de caracteres ASCII em muitos casos.  Você pode seguramente usar exames de bytewise para todos os caracteres de controle \(menos de 32\).  
  
-   Considere a seguinte linha de código, que pode ser verificado para saber se o último caractere em uma cadeia de caracteres for um caractere de barra invertida:  
  
    ```  
    if ( sz[ strlen( sz ) - 1 ] == '\\' )    // Is last character a '\'?  
        // . . .  
    ```  
  
     Como `strlen` não estiver ciente MBCS\-, retorna o número de bytes, não o número de caracteres, uma cadeia de caracteres de vários bytes.  Além disso, observe que em algumas páginas de código \(932\), por exemplo, “\\” \(0x5c\) é um byte final é válido \(`sz` cadeia de caracteres c\).  
  
     Uma solução possível é reescrever o código da seguinte maneira:  
  
    ```  
    char *pLast;  
    pLast = _mbsrchr( sz, '\\' );    // find last occurrence of '\' in sz  
    if ( pLast && ( *_mbsinc( pLast ) == '\0' ) )  
        // . . .  
    ```  
  
     Esse código a seguir usa as funções `_mbsrchr` e `_mbsinc`de MBCS.  Como essas funções são MBCS\- reconhecimento, podem distinguir entre “\\” e “caractere de byte final \\”.  O código executar qualquer ação se o último caractere da cadeia de caracteres é nulo \(\\ “0 "\).  
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)   
 [Atribuição de caractere](../text/character-assignment.md)