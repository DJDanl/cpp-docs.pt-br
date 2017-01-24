---
title: "Erro do Compilador C2555 | Microsoft Docs"
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
  - "C2555"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2555"
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2555
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class1::function1”: substitua o tipo de retorno virtual da função é diferente e não é covariante de “class2::function2”  
  
 Uma função virtual e uma função substituindo derivada têm listas de parâmetros idênticas mas tipos de retorno diferentes.  Uma função substituindo em uma classe derivada não pode ser diferente de uma função virtual em uma classe base somente por seu tipo de retorno.  
  
 Para resolver este erro, converta o valor de retorno depois que a função foi virtual chamada.  
  
 Você também pode consultar este erro quando você cria com \/clr.   Por exemplo, o equivalente do Visual C\+\+ a seguinte declaração C\#:  
  
```  
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);  
```  
  
 é  
  
```  
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];  
```  
  
 Para obter mais informações sobre como C2555, consulte o artigo da Base de Dados de Conhecimento Q240862.  
  
 O seguinte exemplo gera C2555:  
  
```  
// C2555.cpp  
// compile with: /c  
struct X {  
   virtual void func();  
};  
struct Y : X {  
   char func();  // C2555  
   void func2();   // OK  
};  
```