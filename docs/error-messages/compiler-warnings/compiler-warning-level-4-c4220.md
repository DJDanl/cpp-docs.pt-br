---
title: "Compilador aviso (nível 4) C4220 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4220
dev_langs:
- C++
helpviewer_keywords:
- C4220
ms.assetid: aba18868-825f-4763-9af6-3296406a80e4
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
ms.openlocfilehash: 3d2168c54ed1f76085d27044d3867d564de8700e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4220"></a>Compilador C4220 de aviso (nível 4)
varargs corresponde parâmetros restantes  
  
 Sob as extensões da Microsoft padrão (/Ze), um ponteiro para uma função corresponde a um ponteiro para uma função semelhante, mas a variável, argumentos.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4220.c  
// compile with: /W4  
  
int ( *pFunc1) ( int a, ... );  
int ( *pFunc2) ( int a, int b);  
  
int main()  
{  
   if ( pFunc1 != pFunc2 ) {};  // C4220  
}  
```  
  
 Esses ponteiros não correspondem em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
