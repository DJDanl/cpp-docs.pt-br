---
title: "Aviso do compilador (n&#237;vel 1) C4091 | Microsoft Docs"
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
  - "C4091"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4091"
ms.assetid: 3a404967-ab42-49b0-b324-fd7ba1859d78
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4091
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“palavra\-chave”: ignorado na esquerda do tipo “” quando nenhuma variável é declarada  
  
 O compilador detectou uma situação em que o usuário provavelmente pretendia uma variável a ser declarada, mas o compilador não foi possível declarar a variável.  
  
## Exemplo  
 Um atributo de `__declspec` no início de uma declaração do tipo definido pelo usuário se aplica à variável do tipo.  C4091 indica que nenhuma variável é declarado.  O exemplo a seguir produz C4091.  
  
```  
// C4091.cpp  
// compile with: /W1 /c  
__declspec(dllimport) class X {}; // C4091  
  
// __declspec attribute applies to varX  
__declspec(dllimport) class X2 {} varX;  
  
// __declspec attribute after the class or struct keyword   
// applies to user defined type  
class __declspec(dllimport) X3 {};  
```  
  
## Exemplo  
 Se um identificador é um typedef, também não pode ser um nome de variável.  O exemplo a seguir produz C4091.  
  
```  
// C4091_b.cpp  
// compile with: /c /W1 /WX  
#define LIST 4  
typedef struct _LIST {} LIST;   // C4091  
```