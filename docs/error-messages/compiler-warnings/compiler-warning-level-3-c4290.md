---
title: "Aviso do compilador (n&#237;vel 3) C4290 | Microsoft Docs"
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
  - "C4290"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4290"
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4290
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A especificação de exceção C\+\+ ignorada exceto para indicar uma função não é \_\_declspec \(o nothrow\)  
  
 Uma função é declarado usando a especificação de exceção, que Visual C\+\+ aceita mas não implementa.  O código com especificações de exceção que são ignorados durante a compilação pode precisar ser recompilado e vinculado para ser reutilizado em versões futuras que oferecem suporte às especificações de exceção.  
  
 Para obter mais informações, consulte [Especificações de exceção \(lançar\)](../../cpp/exception-specifications-throw-cpp.md).  
  
 Você pode evitar esse aviso usando o pragma de [aviso](../../preprocessor/warning.md) :  
  
```  
#pragma warning( disable : 4290 )  
```  
  
 O exemplo de código gerenciado C4290:  
  
```  
// C4290.cpp  
// compile with: /EHs /W3 /c  
void f1(void) throw(int) {}   // C4290  
  
// OK  
void f2(void) throw() {}  
void f3(void) throw(...) {}  
```