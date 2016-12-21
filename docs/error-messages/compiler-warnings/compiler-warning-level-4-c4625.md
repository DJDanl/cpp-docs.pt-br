---
title: "Aviso do compilador (n&#237;vel 4) C4625 | Microsoft Docs"
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
  - "C4625"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4625"
ms.assetid: 4cc99e50-846c-4784-97da-48b977067851
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4625
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'derived class': construtor de cópia foi definido implicitamente como excluído porque um construtor de cópia da classe base está inacessível ou excluído  
  
 Um construtor de cópia foi excluído ou não está acessível na classe base e, portanto, não foi gerado para uma classe derivada.  Qualquer tentativa de copiar um objeto desse tipo causará um erro do compilador.  
  
 Esse aviso é desativada por padrão.  Consulte [compilador avisos que está desativado por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C4625 e mostra como corrigi\-lo.  
  
```  
// C4625.cpp  
// compile with: /W4 /c  
#pragma warning(default : 4625)  
  
struct A {  
   A() {}  
  
private:  
   A(const A&) {}  
};  
  
struct C : private virtual A {};  
struct B :  C {};   // C4625 no copy constructor  
  
struct D : A {};  
struct E :  D {};   // OK  
```