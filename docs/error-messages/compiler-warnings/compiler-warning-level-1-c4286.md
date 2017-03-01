---
title: "Compilador aviso (nível 1) C4286 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4286
dev_langs:
- C++
helpviewer_keywords:
- C4286
ms.assetid: 93eadd6c-6f36-413b-ba91-c9aa2314685a
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
ms.openlocfilehash: e90f623eaceb996e87c75954010cc0dc5b9e0bad
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4286"></a>Compilador C4286 de aviso (nível 1)
'type1': é capturado pela classe base ('type2') no número de linha  
  
 O tipo de exceção especificado é tratado por um manipulador anterior. O tipo para o segundo problema é derivado do tipo do primeiro. Exceções para uma classe base capturam exceções para uma classe derivada.  
  
## <a name="example"></a>Exemplo  
  
```  
//C4286.cpp  
// compile with: /W1  
#include <eh.h>  
class C {};  
class D : public  C {};  
int main()  
{  
    try  
    {  
        throw "ooops!";  
    }  
    catch( C ) {}  
    catch( D ) {}  // warning C4286, D is derived from C  
}  
```
