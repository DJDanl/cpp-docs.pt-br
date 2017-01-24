---
title: "Erro do Compilador C2800 | Microsoft Docs"
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
  - "C2800"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2800"
ms.assetid: a2f1a590-9fe6-44cb-ad09-b4505ef47c6a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2800
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador operador” não pode ser sobrecarregado  
  
 Os seguintes operadores não podem ficar sobrecarregados: acesso do membro da classe`.`\(\), ponteiro para o membro \(`.*`\), resolução de escopo \(\),`::`expressão condicional \(`? :`\), e `sizeof`.  
  
 O seguinte exemplo gera C2800:  
  
```  
// C2800.cpp  
// compile with: /c  
class C {  
   operator:: ();   // C2800  
};  
```