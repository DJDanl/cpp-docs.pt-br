---
title: "Erro do Compilador C2691 | Microsoft Docs"
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
  - "C2691"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2691"
ms.assetid: 6925f8f3-ea60-4909-91e6-b781492c645d
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2691
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'data type': gerenciada ou WinRT matriz não pode ter esse tipo de elemento  
  
 O tipo de um gerenciado ou WinRT elemento da matriz pode ser um tipo de valor ou um tipo de referência.  
  
 O exemplo a seguir gera C2691:  
  
```  
// C2691a.cpp  
// compile with: /clr  
class A {};  
  
int main() {  
   array<A>^ a1 = gcnew array<A>(20);   // C2691  
   array<int>^ a2 = gcnew array<int>(20);   // value type OK  
}  
```  
  
 O exemplo a seguir gera C2691:  
  
```  
// C2691b.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
int main() {  
   int * a1 __gc[];   // C2691  
   int * a1 = new int [20];   // OK  
}  
```  
  
 C2691 também pode ocorrer se você tentar definir uma matriz denteada usando extensões gerenciadas para C\+\+.  Matrizes denteadas têm suporte na sintaxe atual, consulte [Arrays](../../windows/arrays-cpp-component-extensions.md) para obter mais informações.  
  
 O exemplo a seguir gera C2691:  
  
```  
// C2691c.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
using namespace System;  
int main() {  
   Int32 myJaggedArray[][] = new Int32 [50][];   // C2691  
}  
```