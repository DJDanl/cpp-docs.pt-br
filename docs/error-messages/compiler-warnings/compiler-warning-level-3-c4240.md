---
title: "Compilador aviso (nível 3) C4240 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4240
dev_langs:
- C++
helpviewer_keywords:
- C4240
ms.assetid: a2657cdb-18e1-493f-882b-4e10c0bca71d
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
ms.openlocfilehash: 0539f8892d017a58d224fdb5afe5037c29917702
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4240"></a>Compilador C4240 de aviso (nível 3)
extensão não padrão usada: acesso a 'classname' agora está definido como 'especificador de acesso,' anteriormente, ele foi definido para ser o especificador de acesso  
  
 Em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), você não pode alterar o acesso a uma classe aninhada. Sob as extensões da Microsoft padrão (/Ze), você pode, com este aviso.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4240.cpp  
// compile with: /W3  
class X  
{  
private:  
   class N;  
public:  
   class N  
   {   // C4240  
   };  
};  
  
int main()  
{  
}  
```
