---
title: "Erro do Compilador C2537 | Microsoft Docs"
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
  - "C2537"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2537"
ms.assetid: aee81d8e-300e-4a8b-b6c4-b3828398b34e
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2537
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“especificador”: especificação ilegal de vinculação  
  
 Causas possíveis:  
  
1.  O especificador de vinculação não tem suporte.  Somente o especificador de vínculo de C “2.0” tem suporte.  
  
2.  O vínculo de C “2.0” for especificado para mais de uma função em um conjunto de funções sobrecarregadas.  Isso não é permitido.  
  
 O seguinte exemplo gera C2537:  
  
```  
// C2537.cpp  
// compile with: /c  
extern "c" void func();   // C2537  
extern "C" void func2();   // OK  
```