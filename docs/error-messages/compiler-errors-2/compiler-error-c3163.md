---
title: "Erro do Compilador C3163 | Microsoft Docs"
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
  - "C3163"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3163"
ms.assetid: 17dcafa3-f416-4e04-a232-f9569218ba75
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3163
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“construção”: atribui inconsistente com declaração anterior  
  
 Os atributos que são aplicados a um conflito de definição com os atributos que são aplicados a uma instrução.  
  
 Uma forma de resolver C3163 é eliminar atributos na declaração futuras.  Todos os atributos em uma declaração frente devem ser\-lhes menor que os atributos na definição ou, no máximo, em iguais.  
  
 Uma possível causa do erro C3163 envolve o idioma da anotação do código\-fonte da Microsoft \(SAL\).  Macros de SAL não expande a menos que você criar seu projeto usando o sinalizador de **\/analyze** .  Um programa que compilasse limpa sem \/analyze pode gerar C3163 se você tentar recompilar o com a opção do \/analyze.  Para obter mais informações sobre SAL, consulte [Anotações de SAL](../../c-runtime-library/sal-annotations.md).  
  
## Exemplo  
 O exemplo a seguir produz C3163.  
  
```  
// C3163.cpp  
// compile with: /clr /c  
using namespace System;  
  
[CLSCompliant(true)] void f();  
[CLSCompliant(false)] void f() {}   // C3163  
// try the following line instead  
// [CLSCompliant(true)] void f() {}  
```  
  
## Consulte também  
 [Anotações de SAL](../../c-runtime-library/sal-annotations.md)