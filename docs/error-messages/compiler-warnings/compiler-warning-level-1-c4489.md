---
title: "Aviso do compilador (n&#237;vel 1) C4489 | Microsoft Docs"
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
  - "C4489"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4489"
ms.assetid: 43b51c8c-27b5-44c9-b974-fe4b48f4896f
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4489
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“especificador”: não permitido no método “método da interface;” são permitidos apenas aos especificadores de substituição em métodos da classe de referência e da classe do valor  
  
 Uma palavra\-chave do especificador foi usado incorretamente em um método da interface.  
  
 Para obter mais informações, consulte [Especificadores de Substituição](../../windows/override-specifiers-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C4489.  
  
```  
// C4489.cpp  
// compile with: /clr /c /W1  
public interface class I {   
   void f() new;   // C4489  
   virtual void b() override;   // C4489  
  
   void g();   // OK  
};  
```