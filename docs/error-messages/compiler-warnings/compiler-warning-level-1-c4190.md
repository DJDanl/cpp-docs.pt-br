---
title: "Aviso do compilador (n&#237;vel 1) C4190 | Microsoft Docs"
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
  - "C4190"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4190"
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4190
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o “identifier1” tem o C \- vinculação especificado, mas o UDT “identifier2” do retorna que é incompatível com C  
  
 Uma função ou um ponteiro a função têm um UDT \(tipo definido pelo usuário, que é uma classe, uma estrutura, uma enum, uma união, ou um tipo de [\_\_value](../../misc/value.md) \) como o tipo de retorno e o vínculo de `extern` C “2.0”.  Isso é válido se:  
  
-   Todas as chamadas a essa função ocorrem C\+\+.  
  
-   A definição da função está em C\+\+.  
  
## Exemplo  
  
```  
// C4190.cpp  
// compile with: /W1 /LD  
struct X  
{  
   int i;  
   X ();  
   virtual ~X ();  
};  
  
extern "C" X func ();   // C4190  
```