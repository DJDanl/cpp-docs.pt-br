---
title: "Erro do Compilador C2383 | Microsoft Docs"
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
  - "C2383"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2383"
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2383
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: os argumentos o não são permitidos neste símbolo  
  
 O compilador do C\+\+ não permite argumentos padrão em ponteiros para as funções.  
  
 Este código foi aceito pelo compilador da versão anterior mas oferece agora um erro.  Para o código que funciona em todas as versões do Visual C\+\+, não atribuir um valor padrão a um argumento de ponteiro\-à\- função.  
  
 A seguinte linha gerenciar C2383:  
  
```  
// C2383.cpp  
// compile with: /c   
void (*pf)(int = 0);   // C2383  
void (*pf)(int);   // OK  
```