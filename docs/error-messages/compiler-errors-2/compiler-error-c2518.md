---
title: "Erro do Compilador C2518 | Microsoft Docs"
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
  - "C2518"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2518"
ms.assetid: a7895b47-da90-4851-ac97-18e81479595a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2518
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

palavra\-chave “palavra\-chave” ilegal na lista da classe base; ignorado  
  
 As palavras\-chave `class` e `struct` não devem aparecer em uma lista de classe base.  
  
 O seguinte exemplo gera C2518:  
  
```  
// C2518.cpp  
// compile with: /c  
class B {};  
class C : public class B {};   // C2518  
class D: public B {};   // OK  
```