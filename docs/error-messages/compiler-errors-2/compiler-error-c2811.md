---
title: "Erro do Compilador C2811 | Microsoft Docs"
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
  - "C2811"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2811"
ms.assetid: 6a44b18e-44c1-49d8-9b99-e0545b9a6e7d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2811
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

tipo “\- 1 ": não pode herdar do tipo “\- 2 ", uma classe de referência só podem herdar de uma classe de referência ou da classe de interface  
  
 Você tentou usar uma classe não gerenciado como uma classe base para uma classe gerenciada.  
  
 O seguinte exemplo gera C2811:  
  
```  
// C2811.cpp  
// compile with: /clr /c  
struct S{};  
ref struct T {};  
ref class C : public S {};   // C2811  
ref class D : public T {};   // OK  
```