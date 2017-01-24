---
title: "Erro do Compilador C2553 | Microsoft Docs"
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
  - "C2553"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2553"
ms.assetid: 64bc1e9a-627f-4ce9-b7bc-dc911bdb9180
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2553
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“base\_function”: substitua o tipo de retorno virtual da função é diferente de “override\_function”  
  
 Uma função em uma classe derivada tentada substituir uma função virtual em uma classe base, mas a função de classe derivada não incluía o mesmo tipo de retorno da função da classe base.  Uma assinatura da função de substituição deve corresponder a assinatura da função que está sendo substituída.  
  
 O seguinte exemplo gera C2553:  
  
```  
// C2553.cpp  
// compile with: /clr /c  
ref struct C {  
   virtual void f();  
};  
  
ref struct D : C {  
   virtual int f() override ;   // C2553   
  
   // try the following line instead  
   // virtual void f() override;  
};  
```