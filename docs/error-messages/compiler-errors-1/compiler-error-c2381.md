---
title: "Erro do Compilador C2381 | Microsoft Docs"
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
  - "C2381"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2381"
ms.assetid: cc765f67-64ac-406f-93ef-ae7d548d58d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2381
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: redefinição; \_\_declspec \(noreturn difere\)  
  
 Uma função foi declarada definida e então mas a definição usou o modificador de [noreturn](../../cpp/noreturn.md)`__declspec` .  O uso de `noreturn` constitui uma redefinição de função; a declaração e a definição de devem concordar com o uso de `noreturn`.  
  
 O seguinte exemplo gera C2381:  
  
```  
// C2381.cpp  
// compile with: /c  
void f1();  
void __declspec(noreturn) f1() {}   // C2381  
void __declspec(noreturn) f2() {}   // OK  
```