---
title: "Erro do Compilador C3633 | Microsoft Docs"
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
  - "C3633"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3633"
ms.assetid: 7d65babf-2191-4d67-a69f-f5c4c2ddf946
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3633
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível definir o membro “” como um membro de “tipo gerenciado”  
  
 Os membros de dados da classe de referência de CLR não podem ser de um tipo diferente de VAGEM C\+\+.  Você só pode criar uma instância VAGEM nativo em um tipo CLR.  Por exemplo, um tipo de VAGEM não pode conter um construtor de cópia ou um operador de atribuição.  
  
## Exemplo  
 O exemplo a seguir produz C3633.  
  
```  
// C3633.cpp  
// compile with: /clr /c  
#pragma warning( disable : 4368 )  
  
class A1 {  
public:  
   A1() { II = 0; }  
   int II;  
};  
  
ref class B {  
public:  
   A1 a1;   // C3633  
   A1 * a2;   // OK  
   B() : a2( new A1 ) {}  
    ~B() { delete a2; }  
};  
```  
  
## Exemplo  
 O exemplo a seguir produz C3633.  
  
```  
// C3633_b.cpp  
// compile with: /clr:oldSyntax /c  
class A1 {  
public:  
   A1() { II = 0; }  
   int II;  
};  
  
__gc class B {  
public:  
   A1 a1;   // C3633  
   A1 * a2;   // OK  
   B() : a2( new A1 ) {}  
    ~B() { delete a2; }  
};  
```