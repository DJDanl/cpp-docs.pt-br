---
title: "Erro do Compilador C2461 | Microsoft Docs"
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
  - "C2461"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2461"
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2461
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: sintaxe do construtor que não tem parâmetros formais  
  
 O construtor para a classe não especifica nenhum parâmetro formal com.  A declaração de um construtor deve especificar um parâmetro formal. \(A lista pode ser nula.\)  
  
 Adicionar um par de parênteses depois de `class``::``class`.  
  
 O seguinte exemplo gera C2461:  
  
```  
// C2461.cpp  
// compile with: /c  
class C {  
   C::C;   // C2461  
   C::C();   // OK  
};  
```