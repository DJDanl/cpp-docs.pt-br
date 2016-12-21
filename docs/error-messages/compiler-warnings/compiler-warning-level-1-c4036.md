---
title: "Compilador C4036 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4036"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4036"
ms.assetid: f0b15359-4d62-48ec-8cb1-a7b36587a47f
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4036 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

sem nome 'type' como parâmetro real  
  
 Nenhum nome de tipo é fornecido para uma estrutura, união, enumeração ou classe usada como um parâmetro real. Se você estiver usando [\/Zg](../../build/reference/zg-generate-function-prototypes.md) para gerar protótipos de função, o compilador emite esse aviso e comenta o parâmetro formal no protótipo gerado.  
  
 Especifique um nome de tipo para resolver esse aviso.  
  
## Exemplo  
 O exemplo a seguir gera C4036.  
  
```  
// C4036.c // compile with: /Zg /W1 // D9035 expected typedef struct { int i; } T; void f(T* t) {}   // C4036 // OK typedef struct MyStruct { int i; } T2; void f2(T2 * t) {}  
```