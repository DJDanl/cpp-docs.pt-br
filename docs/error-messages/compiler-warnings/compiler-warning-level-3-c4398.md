---
title: "Aviso do compilador (n&#237;vel 3) C4398 | Microsoft Docs"
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
  - "C4398"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4398"
ms.assetid: b6221432-9fed-4272-a547-a73f587904e6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4398
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“variable”: o objeto global do processo pode não funcionar corretamente com vários appdomains; considere usar \_\_declspec \(o criar appdomain\)  
  
 Uma função virtual com [\_\_clrcall](../../cpp/clrcall.md) que chama a convenção em um tipo nativo causa a criação do domínio de aplicativo vtable.  Essa variável não pode corrigir corretamente quando usado em vários domínios de aplicativo.  
  
 Você pode resolver esse aviso compilando com **\/clr:pure**, que faz variáveis globais por appdomain por padrão, ou explicitamente marcando `__declspec(appdomain)`variável.  
  
 Para obter mais informações, consulte [appdomain](../Topic/appdomain.md) e [Domínios de aplicativo e Visual C\+\+](../../dotnet/application-domains-and-visual-cpp.md).  
  
## Exemplo  
 O exemplo a seguir produz C4398.  
  
```  
// C4398.cpp  
// compile with: /clr /W3 /c  
struct S {  
   virtual void f( System::String ^ );   // String^ parameter makes function __clrcall  
};  
  
S glob_s;   // C4398  
__declspec(appdomain) S glob_s2;   // OK  
```