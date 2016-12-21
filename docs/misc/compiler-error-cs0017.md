---
title: "CS0017 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "11/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CS0017"
dev_langs: 
  - "CSharp"
helpviewer_keywords: 
  - "CS0017"
ms.assetid: 5e2a3eb3-6f6e-485d-8293-ceabea4d6905
caps.latest.revision: 10
caps.handback.revision: 10
author: "BillWagner"
ms.author: "wiwagn"
manager: "wpickett"
---
# CS0017 de erro do compilador
O programa 'nome do arquivo de saída' tem mais de um ponto de entrada definido. Compile com \/main para especificar o tipo que contém o ponto de entrada.  
  
 Um programa só pode ter um [principal](../Topic/Main\(\)%20and%20Command-Line%20Arguments%20\(C%23%20Programming%20Guide\).md) método.  
  
 Para resolver esse erro, você pode excluir todos os métodos principal em seu código, exceto um, ou você pode usar o [\/principal](../Topic/-main%20\(C%23%20Compiler%20Options\).md) opção de compilador para especificar qual método Main que você deseja usar.  
  
 O exemplo a seguir gera CS0017:  
  
```  
// CS0017.cs // compile with: /target:exe public class clx { static public void Main() { } } public class cly { public static void Main()   // CS0017, delete one Main or use /main { } }  
```