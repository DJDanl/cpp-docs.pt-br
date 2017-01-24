---
title: "CS0157 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CS0157"
dev_langs: 
  - "CSharp"
helpviewer_keywords: 
  - "CS0157"
ms.assetid: a5d9d506-81f8-47dd-85b6-85f8170bcbef
caps.latest.revision: 8
caps.handback.revision: 8
author: "BillWagner"
ms.author: "wiwagn"
manager: "wpickett"
---
# CS0157 de erro do compilador
Controle não pode sair do corpo de uma cláusula finally  
  
 Todas as instruções em uma [Finalmente](../Topic/try-catch-finally%20\(C%23%20Reference\).md) cláusula deve executar. Para obter mais informações, consulte [instruções de tratamento de exceção](../Topic/Exception%20Handling%20Statements%20\(C%23%20Reference\).md) e [Exceções e manipulação de exceções](../Topic/Exceptions%20and%20Exception%20Handling%20\(C%23%20Programming%20Guide\).md).  
  
 O exemplo a seguir gera CS0157:  
  
```  
// CS0157.cs using System; namespace MyNamespace { public class MyClass2 : Exception { } public class MyClass { public static void Main() { try { } finally { return;   // CS0157, cannot leave finally clause } } } }  
```