---
title: "Compilador C4115 de aviso (n&#237;veis 1 e 4) | Microsoft Docs"
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
  - "C4115"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4115"
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4115 de aviso (n&#237;veis 1 e 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': chamada a definição de tipo entre parênteses  
  
 Determinado símbolo é usado para definir uma estrutura, união ou tipo enumerado dentro de uma expressão entre parênteses. A definição do escopo pode ser inesperado.  
  
 Em uma chamada de função C, a definição tem escopo global. Em uma chamada de C\+\+, a definição tem o mesmo escopo da função que está sendo chamado.  
  
 Esse aviso também pode ser causado por declaradores dentro dos parênteses \(como protótipos\) que não são expressões entre parênteses.  
  
 Este é um aviso de nível 1 com programas do C\+\+ e C compilados em compatibilidade com ANSI \(\/Za\). Caso contrário, ele é o nível 3.