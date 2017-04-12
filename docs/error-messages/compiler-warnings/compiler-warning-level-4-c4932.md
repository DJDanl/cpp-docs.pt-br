---
title: "Compilador aviso (nível 4) C4932 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4932
dev_langs:
- C++
helpviewer_keywords:
- C4932
ms.assetid: 0b8d88cc-21f6-45cb-a9f5-1795b7db0dfa
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 773bd08a6a1b8791fbb55ef7a74766d410aa85d9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4932"></a>Compilador C4932 de aviso (nível 4)
__identifier(Identifier) e \__identifier(identifier) não podem ser diferenciados  
  
 O compilador é capaz de distinguir entre **_finally** e `__finally` ou `__try` e **_try** como um parâmetro passado para [Identifier](../../windows/identifier-cpp-cli.md). Você não deve tentar usar ambos como identificadores no mesmo programa, pois resultará em uma [C2374](../../error-messages/compiler-errors-1/compiler-error-c2374.md) erro.  
  
 O exemplo a seguir gera C4932:  
  
```  
// C4932.cpp  
// compile with: /clr /W4 /WX  
int main() {  
   int __identifier(_finally) = 245;   // C4932  
   int __identifier(__finally) = 25;   // C4932  
}  
```
