---
title: "Aviso do compilador (n&#237;vel 4) C4516 | Microsoft Docs"
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
  - "C4516"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4516"
ms.assetid: 6677bb1f-d26e-4ab9-8644-6b5a2a8f4ff8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4516
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class::symbol”: as declarações de acesso são substituídas; usados as declarações de membro fornecem uma alternativa melhor  
  
 O comitê ANSI declarados C\+\+ as declarações de acesso \(que modificam o acesso de um membro em uma classe derivada sem a palavra\-chave de [usando](../../cpp/using-declaration.md) \) para ser desatualizado.  As declarações de acesso não podem ser com suporte em versões futuras do C\+\+.  
  
 O seguinte exemplo gera C4516:  
  
```  
// C4516.cpp  
// compile with: /W4  
class A  
{  
public:  
   void x(char);  
};  
  
class B : protected A  
{  
public:  
   A::x;  // C4516 on access-declaration  
   // use the following line instead  
   // using A::x; // using-declaration, ok  
};  
  
int main()  
{  
}  
```