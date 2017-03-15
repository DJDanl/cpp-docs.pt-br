---
title: "Usando uma macro NMAKE | Microsoft Docs"
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
  - "Macros , NMAKE"
  - "macros NMAKE, usando"
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando uma macro NMAKE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para usar uma macro, coloque o nome entre parênteses precedido por um sinal de cifrão \($\) como a seguir.  
  
## Sintaxe  
  
```  
$(macroname)  
```  
  
## Comentários  
 Nenhum espaço é permitido.  Os parênteses são opcionais se o *macroname* é um caractere único.  A cadeia de caracteres de definição substitui $ \(*macroname*\); uma macro indefinido é substituído por uma cadeia de caracteres nula.  
  
## Que você deseja saber mais?  
 [Substituição macro](../build/macro-substitution.md)  
  
## Consulte também  
 [Macros e NMAKE](../Topic/Macros%20and%20NMAKE.md)