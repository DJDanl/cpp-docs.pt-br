---
title: "Erro do Compilador C2548 | Microsoft Docs"
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
  - "C2548"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2548"
ms.assetid: 01e9c835-9bf3-4020-9295-5ee448c519f3
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2548
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class::member”: parâmetro padrão ausente para o parâmetro de parâmetro  
  
 A lista de parâmetro padrão está faltando um parâmetro.  Se você fornecer um parâmetro padrão em qualquer lugar em uma lista de parâmetros, você deve definir parâmetros padrão para todos os parâmetros subsequentes.  
  
## Exemplo  
 O seguinte exemplo gera C2548:  
  
```  
// C2548.cpp  
// compile with: /c  
void func( int = 1, int, int = 3);  // C2548  
  
// OK  
void func2( int, int, int = 3);  
void func3( int, int = 2, int = 3);  
```