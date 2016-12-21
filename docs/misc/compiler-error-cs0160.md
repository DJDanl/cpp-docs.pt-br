---
title: "CS0160 de erro do compilador | Microsoft Docs"
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
  - "CS0160"
dev_langs: 
  - "CSharp"
helpviewer_keywords: 
  - "CS0160"
ms.assetid: 4ef07061-8ef5-42d9-b043-3f81307d569f
caps.latest.revision: 9
caps.handback.revision: 9
author: "BillWagner"
ms.author: "wiwagn"
manager: "wpickett"
---
# CS0160 de erro do compilador
Uma cláusula catch anterior já captura todas as exceções desta ou de um tipo superior \('type'\)  
  
 Uma série de **catch** instruções precisa estar em ordem decrescente de derivação. Por exemplo, os objetos mais derivados devem aparecer primeiro.  
  
 Para obter mais informações, consulte [instruções de tratamento de exceção](../Topic/Exception%20Handling%20Statements%20\(C%23%20Reference\).md) e [Exceções e manipulação de exceções](../Topic/Exceptions%20and%20Exception%20Handling%20\(C%23%20Programming%20Guide\).md).  
  
 O exemplo a seguir gera CS0160:  
  
```  
// CS0160.cs public class MyClass2 : System.Exception {} public class MyClass { public static void Main() { try {} catch(System.Exception) {}   // Second-most derived; should be second catch catch(MyClass2) {}   // CS0160  Most derived; should be first catch } }  
```