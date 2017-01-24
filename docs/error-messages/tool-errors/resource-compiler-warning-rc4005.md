---
title: "Aviso RC4005 (compilador de recurso) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "RC4005"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC4005"
ms.assetid: 71f03b4a-c9a9-415d-920f-bf2e58507f93
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso RC4005 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: redefinição macro  
  
 O identificador é definido duas vezes.  O compilador usou a segunda definição macro.  
  
 Esse aviso pode ser causado por uma macro na linha de comando e em código com uma política de `#define` .  Também pode ser causado por macros importados do inclui arquivos.  
  
 Para eliminar o aviso, remover uma das definições ou use uma política de `#undef` antes da segunda definição.