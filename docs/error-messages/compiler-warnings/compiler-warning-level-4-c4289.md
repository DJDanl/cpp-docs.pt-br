---
title: "Aviso do compilador (n&#237;vel 4) C4289 | Microsoft Docs"
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
  - "C4289"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4289"
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4289
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: var “”: a variável de controle loop for declarado em para\- loop é usado fora do escopo do loop para\-  
  
 Ao criar com [\/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **\/Zc:forScope\-**, uma variável declarada em um loop de [para](../../cpp/for-statement-cpp.md) foi usado depois que **for**\- dê um loop no escopo.  
  
 Consulte [\/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar o comportamento padrão em loop de **for** com **\/Ze**.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 O seguinte exemplo gera C4289:  
  
```  
// C4289.cpp  
// compile with: /W4 /Zc:forScope-  
#pragma warning(default:4289)  
int main() {  
   for (int i = 0 ; ; )   // C4289  
      break;  
   i++;  
}  
```