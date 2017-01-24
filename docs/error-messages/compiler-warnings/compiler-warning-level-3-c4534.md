---
title: "Aviso do compilador (n&#237;vel 3) C4534 | Microsoft Docs"
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
  - "c4534"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4534"
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4534
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o construtor “” não será um construtor padrão para classes das classes devido ao argumento padrão  
  
 Uma classe não gerenciado pode ter um construtor com parâmetros que têm valores padrão e o compilador usará esse nome como o construtor padrão.  Uma classe marcada com a palavra\-chave de `value` não usará um construtor com valores padrão para os parâmetros como um construtor padrão.  
  
 Para obter mais informações, consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C4534:  
  
```  
// C4534.cpp  
// compile with: /W3 /clr /WX  
value class MyClass {  
public:  
   int ii;  
   MyClass(int i = 9) {   // C4534, will not be the default constructor  
      i++;  
   }  
};  
  
int main() {  
   MyClass ^ xx = gcnew MyClass;  
   xx->ii = 0;  
}  
```