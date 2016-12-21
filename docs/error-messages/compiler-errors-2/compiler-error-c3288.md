---
title: "Erro do Compilador C3288 | Microsoft Docs"
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
  - "C3288"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3288"
ms.assetid: ed08a540-9751-46e1-9cbe-c51d6a49ffab
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3288
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: ilegal desreferenciar de um tipo de identificador  
  
 O compilador detectou um ilegal cancelará de um tipo do identificador.  Você pode desreferenciar um tipo de identificador e atribuí\-lo a uma referência.  Para obter mais informações, consulte [Tracking Reference Operator](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3288.  
  
```  
// C3288.cpp  
// compile with: /clr  
ref class R {};  
int main() {  
   *(System::Object^) nullptr;   // C3288  
  
// OK  
   (System::Object^) nullptr;   // OK  
   R^ r;  
   R% pr = *r;  
}  
```