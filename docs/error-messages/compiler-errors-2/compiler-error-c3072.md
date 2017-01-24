---
title: "Erro do Compilador C3072 | Microsoft Docs"
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
  - "C3072"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3072"
ms.assetid: cdd5cb6b-c478-4698-adfa-c40188d34a18
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3072
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador “operador” não pode ser aplicado a uma instância de uma classe de referência  
  
 use o operador unário de '`operator` 'para converter uma instância de uma classe de referência a um tipo de identificador  
  
 Um tipo CLR requer operadores de CLR, \(padrão\) ou operadores não nativos.  Para obter mais informações, consulte [Tracking Reference Operator](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3072.  
  
```  
// C3072.cpp  
// compile with: /clr  
ref class R {};  
  
int main() {  
   R r1;  
   R^ r2 = &r1;   // C3072  
   R^ r3 = %r1;   // OK  
}  
```