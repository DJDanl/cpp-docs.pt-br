---
title: "Erro do Compilador C2379 | Microsoft Docs"
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
  - "C2379"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2379"
ms.assetid: 37dc3015-a4af-4341-bbf3-da6150df7e51
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2379
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o número do parâmetro formal tem o tipo diferente quando alto  
  
 O tipo do parâmetro especificado não for compatível, com as promoções padrão, com o tipo em uma instrução anterior.  Este é um erro em ANSI C\) e \(2.0[\/Za](../../build/reference/za-ze-disable-language-extensions.md)um aviso com extensões da Microsoft \(**\/Ze**\).  
  
 O seguinte exemplo gera C2379:  
  
```  
// C2379.c  
// compile with: /Za  
void func();  
void func(char);   // C2379, char promotes to int  
```