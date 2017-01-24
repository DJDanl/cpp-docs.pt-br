---
title: "Erro do Compilador C3536 | Microsoft Docs"
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
  - "C3536"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3536"
ms.assetid: 8d866075-866b-49eb-9979-ee27b308f7e3
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3536
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: não pode ser usado antes que foi inicializado  
  
 O símbolo indicado não pode ser usado antes que foi inicializado.  Na prática, isso significa que uma variável não pode ser usado para inicializar.  
  
### Para corrigir este erro  
  
1.  Não inicializar uma variável com eles.  
  
## Exemplo  
 O exemplo a seguir gerencie C3536 porque cada variável é inicializado com eles.  
  
```  
// C3536.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto a = a;     //C3536  
   auto b = &b;    //C3536  
   auto c = c + 1; //C3536  
   auto* d = &d;   //C3536  
   auto& e = e;    //C3536  
   return 0;  
};  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)