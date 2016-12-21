---
title: "C3365 de erro do compilador | Microsoft Docs"
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
  - "C3365"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3365"
ms.assetid: 875ec3a4-522c-4e3d-9b67-48808b857f6d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3365 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador 'operator': diferentes operandos do tipo 'type1' e 'type2'  
  
 Foi feita uma tentativa para compor delegados com tipos diferentes.  Consulte [Como compor delegados](../../misc/how-to-compose-delegates.md) para obter mais informações sobre delegados.  
  
 O exemplo a seguir gera C3365:  
  
```  
// C3365.cpp // compile with: /clr delegate void D1(); delegate void D2(int); ref class R { public: void f(){} void g(int){} }; int main() { D1^ d1 = gcnew D1(gcnew R, &R::f); D2^ d2 = gcnew D2(gcnew R, &R::g); D1^ d3 = gcnew D1(gcnew R, &R::f); d1 += d2;   // C3365 d1 += d3;   // OK d1(); }  
```