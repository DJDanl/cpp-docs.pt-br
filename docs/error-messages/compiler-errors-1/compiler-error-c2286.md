---
title: "Erro do Compilador C2286 | Microsoft Docs"
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
  - "C2286"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2286"
ms.assetid: 078e0201-35cc-42e2-8dbc-6f8cf557b098
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2286
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os ponteiros para os membros de representação de “identificador” são definidos mais à declaração de herança” – “ignorada  
  
 Duas representações diferentes de ponteiro\-à\- existem membros da classe.  
  
 Para obter mais informações, consulte [Palavras\-chave de herança](../../cpp/inheritance-keywords.md).  
  
## Exemplo  
 O seguinte exemplo gera C2286:  
  
```  
// C2286.cpp  
// compile with: /c  
class __single_inheritance X;  
class __multiple_inheritance X;   // C2286  
class  __multiple_inheritance Y;   // OK  
```