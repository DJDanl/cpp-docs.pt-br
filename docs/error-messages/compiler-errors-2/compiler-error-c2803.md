---
title: "Erro do Compilador C2803 | Microsoft Docs"
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
  - "C2803"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2803"
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2803
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador operador” deve ter pelo menos um parâmetro formal do tipo de classe  
  
 O operador sobrecarregado não tiver um parâmetro do tipo da classe.  
  
 Você precisa passar pelo menos um parâmetro por referência \(que não use ponteiros, mas referencia\) ou o valor para poder gravar um “ \< b” \(a e b que são da classe do tipo A\).  
  
 Se ambos os parâmetros forem ponteiros será uma comparação pura de endereços do ponteiro e não usará a conversão definido pelo usuário.  
  
 O seguinte exemplo gera C2803:  
  
```  
// C2803.cpp  
// compile with: /c  
class A{};  
bool operator< (const A *left, const A *right);   // C2803  
// try the following line instead  
// bool operator< (const A& left, const A& right);  
```