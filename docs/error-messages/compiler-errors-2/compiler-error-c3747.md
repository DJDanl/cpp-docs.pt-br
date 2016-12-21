---
title: "Erro do Compilador C3747 | Microsoft Docs"
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
  - "C3747"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3747"
ms.assetid: a9a4be67-5d9c-4dcc-9ae9-baae46cbecde
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3747
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

parâmetro de tipo padrão ausente: param de parâmetro  
  
 Os parâmetros genéricas ou modelo com valores padrão não podem ser seguidas na lista de parâmetros pelos parâmetros que não têm valores padrão.  
  
 O seguinte exemplo gera C3747:  
  
```  
// C3747.cpp  
template <class T1 = int, class T2>   // C3747  
struct MyStruct {};  
```  
  
 Solução possível:  
  
```  
// C3747b.cpp  
// compile with: /c  
template <class T1, class T2 = int>  
struct MyStruct {};  
```