---
title: "Erro do Compilador C2705 | Microsoft Docs"
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
  - "C2705"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2705"
ms.assetid: 29249ea3-4ea7-4105-944b-bdb83e8d6852
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2705
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“rótulo”: ignorando ilegal de “no escopo do bloco do manipulador exceção”  
  
 A execução pular para um rótulo dentro de `try`\/`catch`, `__try`\/`__except`, `__try`\/bloco de`__finally` .  Para obter mais informações, consulte [Manipulação de exceção](../../cpp/exception-handling-in-visual-cpp.md).  
  
 O seguinte exemplo gera C2705:  
  
```  
// C2705.cpp  
int main() {  
goto trouble;  
   __try {  
      trouble: ;   // C2705  
   }  
   __finally {}  
  
   // try the following line instead  
   // trouble: ;  
}  
```