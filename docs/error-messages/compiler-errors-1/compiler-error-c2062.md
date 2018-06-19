---
title: C2062 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2062
dev_langs:
- C++
helpviewer_keywords:
- C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d11151a8e842796e4a5a8d45956782421daa1c70
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33168653"
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