---
title: "C3462 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3462"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3462"
ms.assetid: 56b75f35-9fad-42d9-a969-eeca5d709bec
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3462 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': somente um tipo importado pode ser encaminhado  
  
 O atributo TypeForwardedTo deve ser aplicado a um tipo de metadados referenciado.  
  
 Para obter mais informações, consulte [Type Forwarding \(C\+\+\/CLI\)](../../windows/type-forwarding-cpp-cli.md).  
  
## Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C3462.cpp // compile with: /clr /LD public ref class R {};  
```  
  
## Exemplo  
 O exemplo a seguir gera C3462.  
  
```  
// C3462b.cpp // compile with: /clr /c #using "C3462.dll" ref class N {}; [assembly:TypeForwardedTo(N::typeid)];   // C3462 [assembly:TypeForwardedTo(R::typeid)];  
```