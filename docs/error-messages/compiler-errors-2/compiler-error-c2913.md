---
title: "Erro do Compilador C2913 | Microsoft Docs"
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
  - "C2913"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2913"
ms.assetid: c6cf6090-02e8-49a5-913f-5bc6f864b769
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2913
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

especialização explícita; a declaração “” não é uma especialização de um modelo da classe  
  
 Você não pode especializar uma classe de não modelo.  
  
 O seguinte exemplo gera C2913:  
  
```  
// C2913.cpp  
// compile with: /c  
class X{};  
template <class T> class Y{};  
  
template<> class X<int> {};   // C2913  
template<> class Y<int> {};  
```