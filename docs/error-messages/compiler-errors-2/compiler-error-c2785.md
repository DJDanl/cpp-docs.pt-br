---
title: "Erro do Compilador C2785 | Microsoft Docs"
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
  - "C2785"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2785"
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2785
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“declaration1” e “declaration2” têm tipos diferentes de retorno  
  
 O tipo de retorno de conhecimento do modelo da função é diferente do tipo de retorno do modelo da função primária.  
  
### Para corrigir este erro  
  
1.  Verificar se todas as especializações do modelo da função para manter a consistência.  
  
## Exemplo  
 O seguinte exemplo gera C2785:  
  
```  
// C2785.cpp  
// compile with: /c  
template<class T> void f(T);  
  
template<> int f(int); // C2785  
template<> void f(int); // OK  
```