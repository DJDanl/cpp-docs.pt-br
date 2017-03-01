---
title: "Compilador aviso (nível 1) C4369 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4369
dev_langs:
- C++
helpviewer_keywords:
- C4369
ms.assetid: ade87e84-36be-4e00-be99-2930af848feb
caps.latest.revision: 6
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
ms.openlocfilehash: c7ceb295d8f79634b022e5ef8dd4a3e4229b397f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4369"></a>Compilador C4369 de aviso (nível 1)
'enumerador de ': valor do enumerador 'value' não pode ser representada como 'type', o valor será 'novo_valor'  
  
 Um enumerador foi calculado para ser maior que o valor máximo para o tipo subjacente especificado.  Isso causou um estouro e o compilador encapsulado o valor do enumerador para o menor valor possível para o tipo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4369.  
  
```  
// C4369.cpp  
// compile with: /W1  
int main() {  
   enum Color: char { red = 0x7e, green, blue };   // C4369  
   enum Color2: char { red2 = 0x7d, green2, blue2};   // OK  
}  
```
