---
title: "Erro do Compilador C2743 | Microsoft Docs"
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
  - "C2743"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2743"
ms.assetid: 644cd444-21d2-471d-a176-f5f52c5a0b73
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2743
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: não pode capturar um tipo nativo com destruidor de \_\_clrcall ou o construtor de cópia  
  
 Um módulo compilado com **\/clr** \(não\) **\/clr:pure**tentou capturar uma exceção do tipo nativo e no construtor de destruidor ou de cópia do tipo usa \_`_clrcall` que chama a convenção.  
  
 Quando criada com **\/clr** \(não **\/clr:pure**\), a manipulação de exceção espera as funções de membro em um tipo nativo ser [\_\_cdecl](../Topic/__cdecl.md) e não [\_\_clrcall](../../cpp/clrcall.md).  Os tipos nativos com as funções de membro que usam `__clrcall` que chama a convenção não podem ser capturados em um módulo compilado com **\/clr**.  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir produz C2743.  
  
```  
// C2743.cpp  
// compile with: /clr  
public struct S {  
   __clrcall ~S() {}  
};  
  
public struct T {  
   ~T() {}  
};  
  
int main() {  
   try {}  
   catch(S) {}   // C2743  
   // try the following line instead  
   // catch(T) {}  
  
   try {}  
   catch(S*) {}   // OK  
}  
```