---
title: "Erro do Compilador C2142 | Microsoft Docs"
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
  - "C2142"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2142"
ms.assetid: d0dbe10e-0952-49a4-8b33-e82fb7558b19
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2142
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

as declarações de função forem diferentes, os parâmetros especificados somente variáveis em uma delass  
  
 Uma declaração de função contém uma lista de parâmetros variável.  Outra instrução não.  ANSI C \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\).  
  
 O seguinte exemplo gera C2142:  
  
```  
// C2142.c  
// compile with: /Za /c  
void func();  
void func( int, ... );   // C2142  
void func2( int, ... );   // OK  
```