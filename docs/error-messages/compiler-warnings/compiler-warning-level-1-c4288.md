---
title: "Aviso do compilador (n&#237;vel 1) C4288 | Microsoft Docs"
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
  - "C4288"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4288"
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4288
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: var “”: a variável de controle loop for declarado em para\- loop é usado fora do escopo de para\- loop; entra em conflito com a declaração no escopo externa  
  
 Ao criar com [\/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **\/Zc:forscope\-**, uma variável declarada em um loop de **for** foi usado depois que [para](../../cpp/for-statement-cpp.md)\- dê um loop no escopo.  Uma extensão da Microsoft à linguagem C\+\+ permite que essa variável permaneça no escopo, e C4288 lembra\-o que a primeira declaração de variável não é usada.  
  
 Consulte [\/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar a extensão da Microsoft em loop de **for** com \/Ze.  
  
 O seguinte exemplo gera C4288:  
  
```  
// C4288.cpp  
// compile with: /W1 /c /Zc:forScope-  
int main() {  
   int i = 0;    // not used in this program  
   for (int i = 0 ; ; ) ;  
   i++;   // C4288 using for-loop declaration of i  
}  
```