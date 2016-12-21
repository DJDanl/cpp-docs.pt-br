---
title: "Erro do Compilador C2768 | Microsoft Docs"
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
  - "C2768"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2768"
ms.assetid: a7f6047a-6a80-4737-ad5c-c12868639fb5
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2768
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: uso ilegal de argumentos explícitos do modelo  
  
 O compilador não pôde determinar se uma definição de função foi suponha para ser uma especialização explícita de um modelo da função ou se a definição de função foi suponha para ser para uma nova função.  
  
 Esse erro foi introduzido no Visual Studio .NET 2003., como parte dos aprimoramentos de conformidade do compilador.  
  
 O seguinte exemplo gera C2768:  
  
```  
// C2768.cpp  
template<typename T>  
void f(T) {}  
  
void f<int>(int) {}   // C2768  
  
// an explicit specialization  
template<>  
void f<int>(int) {}   
  
// global nontemplate function overload  
void f(int) {}  
```