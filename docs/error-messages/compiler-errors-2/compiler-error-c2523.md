---
title: "Erro do Compilador C2523 | Microsoft Docs"
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
  - "C2523"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2523"
ms.assetid: 7951b700-8f37-45a0-beb4-a79ae0ced72e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2523
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“mais class::~identifier”: destruidor\/incompatibilidade marca finalizadores  
  
 O nome de destruidor deve ser o nome da classe precedido por um til \(`~`\).  O construtor e o destruidor são os únicos membros que têm o mesmo nome da classe.  
  
 O seguinte exemplo gera C2523:  
  
```  
// C2523.cpp  
// compile with: /c  
class A {  
   ~B();    // C2523  
   ~A();   // OK  
};  
```