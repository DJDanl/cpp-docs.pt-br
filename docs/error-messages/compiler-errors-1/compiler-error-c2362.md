---
title: "Erro do Compilador C2362 | Microsoft Docs"
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
  - "C2362"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2362"
ms.assetid: 7aafecbc-b3cf-45a6-9ec3-a17e3f222511
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2362
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a inicialização do e a mensagem” é ignorada “por” rótulos goto  
  
 Quando compile com [\/Za](../../build/reference/za-ze-disable-language-extensions.md), e para o rótulo impedir que o identificador foi inicializado.  
  
 Não é possível ignorar depois de uma declaração com um inicializador a menos que a instrução esteja incluída em um bloco que não seja digitado, ou a variável já tiver sido inicializado.  
  
 O seguinte exemplo gera C2326:  
  
```  
// C2362.cpp  
// compile with: /Za  
int main() {  
   goto label1;  
   int i = 1;      // C2362, initialization skipped  
label1:;  
}  
```  
  
 Solução possível:  
  
```  
// C2362b.cpp  
// compile with: /Za  
int main() {  
   goto label1;  
   {  
      int j = 1;   // OK, this block is never entered  
   }  
label1:;  
}  
```