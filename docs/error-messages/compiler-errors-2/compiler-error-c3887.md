---
title: "Erro do Compilador C3887 | Microsoft Docs"
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
  - "C3887"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3887"
ms.assetid: a7e82426-ef99-437b-9562-2822004e18fe
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3887
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

var “”: o inicializador para um membro de dados literal deve ser uma expressão constante  
  
 Um membro de dados de [literal](../../windows/literal-cpp-component-extensions.md) só pode ser iniciado com um expresion constante.  
  
 O seguinte exemplo gera C3887:  
  
```  
// C3887.cpp  
// compile with: /clr  
ref struct Y1 {  
   static int i = 9;  
   literal  
   int staticConst = i;   // C3887  
};  
```  
  
 Solução possível:  
  
```  
// C3887b.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   literal  
   int staticConst = 9;  
};  
```