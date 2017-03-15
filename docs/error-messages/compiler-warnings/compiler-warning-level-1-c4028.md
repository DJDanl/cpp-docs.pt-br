---
title: "Compilador aviso (nível 1) C4028 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4028
dev_langs:
- C++
helpviewer_keywords:
- C4028
ms.assetid: c3e8b70b-e870-416c-a285-bba5f71dbfc6
caps.latest.revision: 11
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
ms.openlocfilehash: 1db6458377104463d7f350e7ed5cdaa4bc25739a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4028"></a>Compilador C4028 de aviso (nível 1)
parâmetro formal 'number' diferente da declaração  
  
 O tipo do parâmetro formal não concordar com o parâmetro correspondente na declaração. O tipo de declaração original é usado.  
  
 Este aviso só é válido para o código-fonte C.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4028.  
  
```  
// C4028.c  
// compile with: /W1 /Za  
void f(int , ...);  
void f(int i, int j) {}   // C4028  
  
void g(int , int);  
void g(int i, int j) {}   // OK  
  
int main() {}  
```
