---
title: Compilador (nível 1) de aviso C4129 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4129
dev_langs:
- C++
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc095a32e5cb0d5a0bf240282e11c3fa3382ffe5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33276637"
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