---
title: C2062 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2062
dev_langs: C++
helpviewer_keywords: C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e4a006bed55f16e6ed94c3b5ed9415320acb86fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2062"></a>C2062 de erro do compilador
tipo 'type' inesperado  
  
 O compilador não esperava um nome de tipo.  
  
 O exemplo a seguir gera C2062:  
  
```  
// C2062.cpp  
// compile with: /c  
struct A {  : int l; };   // C2062  
struct B { private: int l; };   // OK  
```  
  
 C2062 também pode ocorrer devido à maneira que o compilador identificadores de tipos indefinidos na lista de parâmetros do construtor. Se o compilador encontra um tipo (incorreta?) indefinido, ele pressupõe que o construtor é uma expressão e emite C2062. Para resolver, use somente tipos definidos em uma lista de parâmetros do construtor.