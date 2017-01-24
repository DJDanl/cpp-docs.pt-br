---
title: "Erro do Compilador C2299 | Microsoft Docs"
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
  - "C2299"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2299"
ms.assetid: d001c2bc-f6fd-47aa-8e42-0eb824d6441d
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2299
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: alteração de comportamento: uma especialização explícita não pode ser um construtor de cópia ou um operador de atribuição de cópia  
  
 Esse erro também pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: as versões anteriores do Visual C\+\+ permitiam especializações explícitas para um construtor de cópia ou um operador de atribuição de cópia.  
  
 Para resolver C2299, não faça o construtor de cópia ou o operador de atribuição uma função do modelo, mas em vez de uma função não modelo que usa um tipo de classe.  Qualquer código que chama o construtor ou o operador de atribuição de cópia explicitamente especificando os argumentos do modelo precisa remover os argumentos do modelo.  
  
 O seguinte exemplo gera C2299:  
  
```  
// C2299.cpp  
// compile with: /c  
class C {  
   template <class T>  
   C (T t);  
  
   template <> C (const C&);   // C2299  
   C (const C&);   // OK  
};  
```