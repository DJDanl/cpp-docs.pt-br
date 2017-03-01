---
title: "Compilador aviso (nível 4) C4211 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4211
dev_langs:
- C++
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
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
ms.openlocfilehash: bb015e2dfdff01c633894b2942dab5c6aaa8a2c9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4211"></a>Compilador C4211 de aviso (nível 4)
extensão não padrão usada : extern redefinido para static  
  
 Com as extensões da Microsoft padrão (/Ze), você pode redefinir um `extern` identificador como **estático**.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4211.c  
// compile with: /W4  
extern int i;  
static int i;   // C4211  
  
int main()  
{  
}  
```  
  
 Tais redefinições são inválidas em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).  
  
## <a name="see-also"></a>Consulte também  
 [(NOTINBUILD) Especificadores de classe de armazenamento estático](http://msdn.microsoft.com/en-us/3ba9289a-a412-4a17-b319-ceb2c087df48)
