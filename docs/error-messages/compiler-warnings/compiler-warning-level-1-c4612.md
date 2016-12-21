---
title: "Compilador C4612 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4612"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4612"
ms.assetid: 21ac02b2-51cd-4aff-9b70-d543511d5962
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4612 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Erro ao incluir o nome de arquivo  
  
 Este aviso ocorre com **\#pragma include\_alias** quando um nome de arquivo está incorreta ou ausente.  
  
 Os argumentos para o **\#pragma include\_alias** instrução pode usar a citação de \(**"***filename***"**\) ou forma de colchete angular \(**\<***filename***\>**\), mas ambas devem usar o mesmo formulário.  
  
## Exemplo  
  
```  
// C4612.cpp // compile with: /W1 /LD #pragma include_alias("StandardIO", <stdio.h>) // C4612  
```