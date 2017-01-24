---
title: "Erro fatal C1509 | Microsoft Docs"
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
  - "C1509"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1509"
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1509
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: muitos estados do manipulador de exceção na função “expressions”. simplifique a função  
  
 O código exceder um limite interno nos estados do manipulador de exceção estados \(32.768\).  
  
 A causa mais comum é que a função contém uma expressão complexa de variáveis definidas pelo usuário e operadores aritméticos da classe.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifique expressões atribuindo subexpressões comuns para variáveis temporários.  
  
2.  Divida a função em funções secundárias.