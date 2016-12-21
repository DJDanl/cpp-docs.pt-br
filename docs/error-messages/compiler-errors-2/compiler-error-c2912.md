---
title: "Erro do Compilador C2912 | Microsoft Docs"
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
  - "C2912"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2912"
ms.assetid: bd55cecd-ab1a-4636-ab8a-a00393fe7b3d
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2912
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

especialização explícita 'declaração' não é uma especialização de um modelo de função  
  
 Não é possível specialize uma função diferente do modelo.  
  
 O exemplo a seguir gera C2912:  
  
```  
// C2912.cpp  
// compile with: /c  
void f(char);  
template<> void f(char);   // C2912  
template<class T> void f(T);   // OK  
```  
  
 Esse erro também será gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: para cada especialização explícita, você deve escolher os parâmetros de especialização explícita, modo que eles correspondam aos parâmetros do modelo primário.  
  
```  
// C2912b.cpp  
class CF {  
public:  
   template <class A> CF(const A& a) {}   // primary template  
  
   // attempted explicit specialization  
   template <> CF(const char* p) {}   // C2912  
  
   // try the following line instead  
   // template <> CF(const char& p) {}  
};  
```