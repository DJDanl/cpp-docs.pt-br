---
title: "Aviso do compilador (n&#237;vel 1) C4311 | Microsoft Docs"
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
  - "C4311"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4311"
ms.assetid: ddc579d0-d051-47bc-915d-71ffb32323c9
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4311
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'variable': truncamento de ponteiro de 'type' para 'type'  
  
 Esse aviso detecta problemas de truncamento de ponteiro de 64 bits.  Por exemplo, se o código é compilado para uma arquitetura de 64 bits, o valor de um ponteiro \(64 bits\) será truncado se ela é atribuída a um `int` \(32 bits\).  Para obter mais informações, consulte [regras usando ponteiros](http://msdn.microsoft.com/library/windows/desktop/aa384242).  
  
 Para obter informações adicionais sobre as causas comuns de aviso C4311, consulte [erros comuns de compilador](http://msdn.microsoft.com/library/windows/desktop/aa384160).  
  
 O exemplo de código a seguir gera C4311 quando compilado para um destino de 64 bits e, em seguida, demonstra como corrigi\-lo:  
  
```  
// C4311.cpp  
// compile by using: cl /W1 C4311.cpp  
int main() {  
   void* p = &p;  
   unsigned int i = (unsigned int) p;   // C4311 for 64-bit targets  
   unsigned long long j = (unsigned long long) p;   // OK  
}  
  
```