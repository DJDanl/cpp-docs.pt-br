---
title: "Caracteres especiais em macros | Microsoft Docs"
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
  - "caracteres especiais, em macros NMAKE"
ms.assetid: c0a06cfc-7103-4ee2-a585-e8f6e85dccd7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caracteres especiais em macros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um sinal de número \(\#\) depois que uma definição especifica um comentário.  Para especificar um número literal conectar uma macro, usam um acento circunflexo \(^\), como no ^\#.  
  
 Um cifrão \($\) especifica uma invocação macro.  Para especificar $ literal, use $$.  
  
 Para estender uma definição em uma nova linha, encerra a linha com uma barra invertida \(\\\).  Quando a macro é chamado, a barra invertida mais o caractere de nova linha é substituída por um espaço.  Para especificar uma barra invertida literal no final da linha, precedê\-la com um acento circunflexo \(^\), ou segui\-la com um especificador de comentário \(\#\).  
  
 Para especificar um caractere de nova linha literal, encerra a linha com um acento circunflexo \(^\), como em:  
  
```  
CMDS = cls^  
dir  
```  
  
## Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)