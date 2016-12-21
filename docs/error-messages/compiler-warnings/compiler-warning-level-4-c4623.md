---
title: "Aviso do compilador (n&#237;vel 4) C4623 | Microsoft Docs"
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
  - "C4623"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4623"
ms.assetid: e630d8d0-f6ea-469c-a74f-07b027587225
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4623
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'`derived class`': construtor padrão foi definido implicitamente como excluído porque um construtor padrão da classe base está inacessível ou excluído  
  
 Um construtor não estava acessível em uma classe base e não foi gerado para a classe derivada.  Qualquer tentativa de criar um objeto desse tipo na pilha causará um erro do compilador.  
  
 Esse aviso é desativada por padrão.  Consulte [compilador avisos que está desativado por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C4623.  
  
```  
// C4623.cpp  
// compile with: /W4  
#pragma warning(default : 4623)  
class B {  
   B();  
};  
  
class C {  
public:  
   C();  
};  
  
class D : public B {};   // C4623 - to fix, make B's constructor public  
class E : public C {};   // OK - class C constructor is public  
  
int main() {  
   // D d;  will cause an error  
}  
```