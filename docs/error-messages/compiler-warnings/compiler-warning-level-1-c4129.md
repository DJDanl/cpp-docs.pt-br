---
title: "Compilador aviso (nível 1) C4129 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4129
dev_langs:
- C++
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
caps.latest.revision: 7
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
ms.openlocfilehash: 91f3124c159f8dc0ebab2d04b5646ba7c238fe29
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4129"></a>Compilador C4129 de aviso (nível 1)
'character': não reconhecido de sequência de escape de caractere  
  
 O `character` seguindo uma barra invertida (\\) em um caractere ou uma cadeia de caracteres constante não é reconhecida como uma sequência de escape válida. A barra invertida é ignorada e não impressa. O caractere após a barra invertida é impresso.  
  
 Para imprimir uma barra invertida, especifique uma barra invertida dupla (\\\\).  
  
 O C++ padrão, na seção 2.13.2 discute as sequências de escape.  
  
 O exemplo a seguir gera C4129:  
  
```  
// C4129.cpp  
// compile with: /W1  
int main() {  
   char array1[] = "\/709";   // C4129  
   char array2[] = "\n709";   // OK  
}  
```
