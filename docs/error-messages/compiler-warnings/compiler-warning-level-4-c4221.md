---
title: "Compilador aviso (nível 4) C4221 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4221
dev_langs:
- C++
helpviewer_keywords:
- C4221
ms.assetid: 8532bd68-54dc-4526-8597-f61dcb0a0129
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
ms.openlocfilehash: 4fc77211dd8f3477b30a118e0a45ba395eafa0c6
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4221"></a>Compilador C4221 de aviso (nível 4)
extensão não padrão usada: 'identifier': não pode ser inicializado usando o endereço da variável automática  
  
 Com as extensões da Microsoft padrão (/Ze), você pode inicializar um tipo de agregação (**matriz**, `struct`, ou **união**) com o endereço de uma variável de local (automático).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4221.c  
// compile with: /W4  
struct S  
{  
   int *i;  
};  
  
void func()  
{  
   int j;  
   struct S s1 = { &j };   // C4221  
}  
  
int main()  
{  
}  
```  
  
 Inicializações são inválidas em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
