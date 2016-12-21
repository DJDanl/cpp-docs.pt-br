---
title: "Erro do Compilador C3161 | Microsoft Docs"
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
  - "C3161"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3161"
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3161
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

contadores de “interface”: aninhando a classe, o struct, a união a interface ou em uma interface são ilegais; aninhando da interface em uma classe, o struct ou a união são ilegal  
  
 [\_\_interface](../Topic/__interface.md) só pode aparecer no escopo global ou em um namespace.  Uma classe, uma estrutura, ou uma união não podem aparecer em uma interface.  
  
## Exemplo  
 O exemplo a seguir produz C3161.  
  
```  
// C3161.cpp  
// compile with: /c  
__interface X {  
   __interface Y {};   // C3161 A nested interface  
};  
```