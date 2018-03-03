---
title: "Compilador (nível 1) de aviso C4129 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4129
dev_langs:
- C++
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6405c7c156f34b49ab892304ee51a6b996ac2595
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4129"></a>Compilador C4129 de aviso (nível 1)
'character': não reconhecido de sequência de escape de caractere  
  
 O `character` seguindo uma barra invertida (\\) em um caractere ou cadeia de caracteres constante não é reconhecida como uma sequência de escape válida. A barra invertida é ignorada e não impresso. O caractere após a barra invertida é impresso.  
  
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