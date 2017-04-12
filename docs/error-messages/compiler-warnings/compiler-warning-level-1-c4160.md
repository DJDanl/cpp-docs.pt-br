---
title: "Compilador aviso (nível 1) C4160 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4160
dev_langs:
- C++
helpviewer_keywords:
- C4160
ms.assetid: a9610cb7-cac4-4a74-8b4e-049030ebb92b
caps.latest.revision: 5
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
ms.openlocfilehash: 427c34252924a0307b9644cba1f24df30d7470c4
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4160"></a>Compilador C4160 de aviso (nível 1)
**#pragma**   
 ***pragma* (pop,...): não encontrou anteriormente enviado identificador '**   
 ***identificador* '**  
  
 Uma instrução pragma em seu código-fonte tenta inserir um identificador que não tenha sido enviado. Para evitar esse aviso, certifique-se de que o identificador que está sendo exibido foi enviado corretamente.  
  
 O exemplo a seguir gera C4160:  
  
```  
// C4160.cpp  
// compile with: /W1  
#pragma pack(push)  
  
#pragma pack(pop, id)   // C4160  
// use identifier when pushing to resolve the warning  
// #pragma pack(push, id)  
  
int main() {  
}  
```
