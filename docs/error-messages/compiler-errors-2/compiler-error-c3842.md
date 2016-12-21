---
title: "Erro do Compilador C3842 | Microsoft Docs"
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
  - "C3842"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3842"
ms.assetid: 41a1a44a-c618-40a2-8d26-7da27d14095d
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3842
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'function': não há suporte para 'const' e 'volatile' qualificadores em funções de membro do WinRT ou tipos gerenciados  
  
 [const](../../cpp/const-cpp.md) e [volátil](../../cpp/volatile-cpp.md) não há suporte para funções de membro de tempo de execução do Windows ou tipos gerenciados.  
  
 O exemplo a seguir gera C3842:  
  
```  
// C3842a.cpp  
// compile with: /clr /c  
public ref struct A {  
   void f() const {}   // C3842  
   void f() volatile {}   // C3842  
  
   void f() {}  
};  
  
```