---
title: "Aviso do compilador (n&#237;vel 1) C4382 | Microsoft Docs"
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
  - "C4382"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4382"
ms.assetid: 34be9ad3-bae6-411a-8f80-0c8fd0d2c092
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4382
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo de reprodução”: um tipo com destruidor de \_\_clrcall ou o construtor de cópia só pode ser capturado no módulo de \/clr:pure  
  
 Quando criada com **\/clr** \(não **\/clr:pure**\), a manipulação de exceção espera as funções de membro em um tipo nativo ser [\_\_cdecl](../Topic/__cdecl.md) e não [\_\_clrcall](../../cpp/clrcall.md).  Os tipos nativos com as funções de membro que usam `__clrcall` que chama a convenção não podem ser capturados em um módulo compilado com **\/clr**.  
  
 Se a exceção será capturada em um módulo compilado com **\/clr:pure**, você pode ignorar esse aviso.  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir produz C4382.  
  
```  
// C4382.cpp  
// compile with: /clr /W1 /c  
struct S {  
   __clrcall ~S() {}  
};  
  
struct T {  
   ~T() {}  
};  
  
int main() {  
   S s;  
   throw s;   // C4382  
  
   S * ps = &s;  
   throw ps;   // OK  
  
   T t;  
   throw t;   // OK  
}  
```