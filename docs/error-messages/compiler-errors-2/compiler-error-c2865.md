---
title: "Erro do Compilador C2865 | Microsoft Docs"
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
  - "C2865"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2865"
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2865
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: comparação ilegal do handle\_or\_pointer  
  
 Você pode comparar referências a [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md) ou [\_\_gc](../Topic/__gc.md) digitar apenas para fins de igualdade consulta que pertencem ao mesmo objeto \(\=\=\) ou objetos diferentes \(\! \=\).  
  
 Você não pode compará\-los para ordenar porque o tempo de execução do .NET. pode mover objetos gerenciados a qualquer momento, modificando o resultado de teste.