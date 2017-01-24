---
title: "Erro do Compilador C3116 | Microsoft Docs"
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
  - "C3116"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3116"
ms.assetid: 597463e1-a5cc-4ed3-a917-eae9a61d3312
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3116
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“especificador armazenamento”: classe de armazenamento inválido para o método da interface  
  
 Você usou `typedef`, `register`, ou `static` como a classe de armazenamento para um método da interface.  Essas classes de armazenamento não são permitidas em membros da interface.  
  
 O seguinte exemplo gera C3116:  
  
```  
// C3116.cpp  
__interface ImyInterface  
{  
   static void myFunc();   // C3116  
};  
```