---
title: "Erro do Compilador C2818 | Microsoft Docs"
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
  - "C2818"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2818"
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2818
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'aplicativo do operador sobrecarregado \-\>' é recursiva por meio do tipo “tipo”  
  
 Uma redefinição do operador de acesso do membro da classe contém uma instrução recursiva de `return` .  Para redefinir o operador de `->` com recursão, você deve mover a rotina recursiva para uma função chamada separada da função de substituição do operador.