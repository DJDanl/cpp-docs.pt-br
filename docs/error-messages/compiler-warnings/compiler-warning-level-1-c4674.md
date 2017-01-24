---
title: "Compilador C4674 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4674"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4674"
ms.assetid: 638dae0b-b82c-4865-9599-72630827ca09
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4674 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'method' deve ser declarado como 'static' e ter exatamente um parâmetro  
  
 A assinatura de um operador de conversão não está correta. O método não é considerado uma conversão definida pelo usuário.  
  
 Ao usar a nova sintaxe \(**\/clr**\), consulte [Operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md) e [Conversões definidas pelo usuário](../../dotnet/user-defined-conversions-cpp-cli.md) para obter informações sobre como definir operadores.  
  
## Exemplo  
 O exemplo a seguir gera C4674.  
  
```  
// C4674.cpp // compile with: /clr /WX /W1 /LD ref class G { int op_Implicit(int i) {   // C4674 return 0; } };  
```  
  
## Exemplo  
 O exemplo a seguir gera C4674.  
  
```  
// C4674_b.cpp // compile with: /clr:oldSyntax /W1 /LD __gc class G { int op_Implicit(int i) {   // C4674 // try the following line instead // static int op_Implicit(int i) { return 0; } };  
```