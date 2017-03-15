---
title: "Compara&#231;&#227;o de caracteres | Microsoft Docs"
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
  - "caracteres [C++], comparando"
  - "comparando caracteres"
  - "MBCS [C++], comparação de caracteres"
ms.assetid: 18846e44-3e6e-40c4-9b42-3153fb15db20
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Compara&#231;&#227;o de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as dicas a seguir:  
  
-   Comparação de um byte inicial conhecido com um caractere ASCII funciona corretamente:  
  
    ```  
    if( *sz1 == 'A' )  
    ```  
  
-   Comparar dois caracteres desconhecidos requer o uso de um de macros definidos em Mbstring.h:  
  
    ```  
    if( !_mbccmp( sz1, sz2) )  
    ```  
  
     Isso garante que ambos os bytes de um caractere de byte duplo sejam comparados para fins de igualdade.  
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)   
 [Estouro de buffer](../text/buffer-overflow.md)