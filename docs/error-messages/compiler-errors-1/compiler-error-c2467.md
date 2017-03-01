---
title: C2467 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2467
dev_langs:
- C++
helpviewer_keywords:
- C2467
ms.assetid: f9ead270-5d0b-41cc-bdcd-586a647c67a7
caps.latest.revision: 8
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6f4e682a246b7fbd8d90b5393ad89aaa74500d2c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2467"></a>C2467 de erro do compilador
declaração inválida de anônimo '-tipo definido pelo usuário '  
  
 Um tipo aninhado definido pelo usuário foi declarado. Este é um erro durante a compilação de código-fonte C com a opção de compatibilidade de ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) habilitado.  
  
 O exemplo a seguir gera C2467:  
  
```  
//C2467.c  
// compile with: /Za   
int main() {  
   struct X {  
      union { int i; };   // C2467, nested declaration  
   };  
}  
```
