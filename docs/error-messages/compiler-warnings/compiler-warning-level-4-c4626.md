---
title: "Aviso do compilador (n&#237;vel 4) C4626 | Microsoft Docs"
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
  - "C4626"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4626"
ms.assetid: 7f822ff4-a4a3-4f17-b45b-e8b7b4659a14
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4626
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'derived class': operador de atribuição foi definido implicitamente como excluído como um operador de atribuição de classe base está inacessível ou excluído  
  
 Um operador de atribuição foi excluído ou não está acessível na classe base e, portanto, não foi gerado para uma classe derivada.  Qualquer tentativa de atribuir objetos desse tipo causará um erro do compilador.  
  
 Esse aviso é desativada por padrão.  Consulte [compilador avisos que está desativado por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4626 e mostra como corrigi\-lo:  
  
```  
// C4626  
// compile with: /W4  
#pragma warning(default : 4626)  
class B  
{  
// public:  
   B& operator = (const B&)  
   {  
      return *this;  
   }  
};  
  
class D : public B  
{  
  
}; // C4626 - to fix, make B's copy constructor public  
  
int main()  
{  
   D m;  
   D n;  
   // m = n;   // this line will cause an error  
}  
```