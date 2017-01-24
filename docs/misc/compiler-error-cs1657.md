---
title: "CS1657 de erro do compilador | Microsoft Docs"
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
  - "CS1657"
dev_langs: 
  - "CSharp"
helpviewer_keywords: 
  - "CS1657"
ms.assetid: 6f0aeebe-5c90-4d5b-981c-1795d2e8fbb9
caps.latest.revision: 9
caps.handback.revision: 9
author: "BillWagner"
ms.author: "wiwagn"
manager: "wpickett"
---
# CS1657 de erro do compilador
Não é possível passar 'parameter' como ref ou out argumento porque ' razão '  
  
 Esse erro ocorre quando uma variável é passada como um [ref](../Topic/ref%20\(C%23%20Reference\).md) ou [out](../Topic/out%20\(C%23%20Reference\).md) argumento em um contexto em que essa variável é somente leitura. Contextos de ReadOnly incluem [foreach](../Topic/foreach,%20in%20\(C%23%20Reference\).md) variáveis de iteração, [usando](../Topic/using%20Statement%20\(C%23%20Reference\).md) variáveis, e `fixed` variáveis. Para resolver esse erro, não chame funções que usam o `foreach`, `using` ou `fixed` variável como um `ref` ou `out` parâmetro `using` blocos, `foreach` instruções e `fixed` instruções.  
  
## Exemplo  
 O exemplo a seguir gera CS1657:  
  
```  
// CS1657.cs using System; class C : IDisposable { public int i; public void Dispose() {} } class CMain { static void f(ref C c) { } static void Main() { using (C c = new C()) { f(ref c);  // CS1657 } } }  
```  
  
## Exemplo  
 O código a seguir ilustra o mesmo problema em um `fixed` instrução:  
  
```  
// CS1657b.cs // compile with: /unsafe unsafe class C { static void F(ref int* p) { } static void Main() { int[] a = new int[5]; fixed(int* p = a) F(ref p); // CS1657 } }  
```