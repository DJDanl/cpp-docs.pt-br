---
title: "Erro do Compilador C2572 | Microsoft Docs"
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
  - "C2572"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2572"
ms.assetid: f1a42d69-727d-4ce5-88c8-d5f55dea66ac
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2572
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class::member”: redefinição de parâmetro padrão: param de parâmetro  
  
 Os parâmetros padrão não podem ser redefinidos.  Se você precisar outro valor para o parâmetro, o parâmetro padrão deve ficar indefinida.  
  
 O seguinte exemplo gera C2572:  
  
```  
// C2572.cpp  
// compile with: /c  
void f(int i = 1);   // function declaration  
  
// function definition  
void f(int i = 1) {}   // C2572  
  
// try the following line instead  
// void f(int i) {}  
```