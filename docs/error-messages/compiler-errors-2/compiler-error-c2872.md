---
title: "Erro do Compilador C2872 | Microsoft Docs"
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
  - "C2872"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2872"
ms.assetid: c619ef97-6e0e-41d7-867c-f8d28a07d553
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2872
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: símbolo ambíguo  
  
 O compilador não pode determinar que símbolo você estiver referenciando.  
  
 C2872 poderá ocorrer se um arquivo de cabeçalho inclui [Diretiva de uso](../../misc/using-directive-cpp.md), e um arquivo de cabeçalho subsequente é `#include`' d e contiver um tipo que também está no namespace especificada na política de `using` .  Especificar uma política de `using` apenas os arquivos de cabeçalho são especificados depois que a `#include`.  
  
 Para obter mais informações sobre como C2872, consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;316317](http://support.microsoft.com/default.aspx?scid=kb;en-us;316317).  
  
 O seguinte exemplo gera C2872:  
  
```  
// C2872.cpp  
namespace A {  
   int i;  
}  
  
using namespace A;  
int i;  
int main() {  
   ::i++;   // ok  
   A::i++;   // ok  
   i++;   // C2872 ::i or A::i?  
}  
```