---
title: "Erro do Compilador C2947 | Microsoft Docs"
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
  - "C2947"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2947"
ms.assetid: 6c056f62-ec90-4883-8a67-aeeb6ec13546
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2947
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

aguardando '\>' encerrar a construção, encontrada “sintaxes  
  
 Uma lista genérica ou modelo de argumento não pode ter sido encerrada corretamente.  
  
 C2947 também pode ser gerado por erros de sintaxe.  
  
 O seguinte exemplo gera C2947:  
  
```  
// C2947.cpp  
// compile with: /c  
template <typename T>=   // C2947  
// try the following line instead  
// template <typename T>  
struct A {};  
```