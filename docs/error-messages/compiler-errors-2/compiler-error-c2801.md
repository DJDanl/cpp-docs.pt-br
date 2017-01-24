---
title: "Erro do Compilador C2801 | Microsoft Docs"
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
  - "C2801"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2801"
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2801
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador operador” deve ser um membro de não estático  
  
 Os seguintes operadores sobrecarregados podem ser apenas como membros não estática:  
  
-   Atribuição `=`  
  
-   Acesso `->`do membro da classe  
  
-   Subscrição `[]`  
  
-   Chamada de função `()`  
  
 Causas possíveis: C2801  
  
-   O operador sobrecarregado não é uma classe, uma estrutura, ou um sindicalista.  
  
-   O operador sobrecarregado é declarado `static`.  
  
-   O seguinte exemplo gera C2801:  
  
```  
// C2801.cpp  
// compile with: /c  
operator[]();   // C2801 not a member  
class A {  
   static operator->();   // C2801 static  
   operator()();   // OK  
};  
```