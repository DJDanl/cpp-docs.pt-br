---
title: "C3398 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3398"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3398"
ms.assetid: 26f8c8a4-526f-415b-8047-155c5cd4f180
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3398 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operator': não é possível converter de 'function\_signature' em 'function\_pointer'. Expressão de origem deve ser um símbolo de função  
  
 Quando o [\_\_clrcall](../../cpp/clrcall.md) convenção de chamada não for especificada durante a compilação com **\/clr**, o compilador gera dois pontos de entrada \(endereços\) para cada função, um ponto de entrada nativo e um ponto de entrada gerenciado.  
  
 Por padrão, o compilador retorna o ponto de entrada nativo, mas há alguns casos em que o ponto de entrada gerenciado é desejado \(por exemplo ao atribuir o endereço para um `__clrcall` ponteiro de função\). Para o compilador confiável, escolha o ponto de entrada gerenciado em uma atribuição, o lado direito deve ser um símbolo de função.