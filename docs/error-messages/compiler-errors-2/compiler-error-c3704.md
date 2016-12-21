---
title: "Erro do Compilador C3704 | Microsoft Docs"
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
  - "C3704"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3704"
ms.assetid: ee40ea35-a214-4dec-9489-d7f155dd0ac2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3704
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: um método de vararg não pode disparar eventos  
  
 Você tentou usar [\_\_event](../../cpp/event.md) em um método de vararg.  Para corrigir esse erro, substitua a chamada de `fireEvent(int i, ...)` com a chamada de `fireEvent(int i)` como mostrado no exemplo de código.  
  
 O seguinte exemplo gera C3704:  
  
```  
// C3704.cpp  
[ event_source(native) ]  
class CEventSrc {  
   public:  
      __event void fireEvent(int i, ...);   // C3704  
      // try the following line instead:  
      // __event void fireEvent(int i);  
};  
  
int main() {  
}  
```