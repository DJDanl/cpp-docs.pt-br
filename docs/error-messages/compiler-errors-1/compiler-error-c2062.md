---
title: C2062 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2062
dev_langs:
- C++
helpviewer_keywords:
- C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 27b0f936d214ec4eee30b4da03b4b86751e66dc4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
 C2062 também pode ocorrer devido à maneira que o compilador trata tipos indefinidos na lista de parâmetros do construtor. Se o compilador encontrar tipo indefinido (incorreta?), ele pressupõe que o construtor é uma expressão e problemas C2062. Para resolver, use somente tipos definidos em uma lista de parâmetros do construtor.
