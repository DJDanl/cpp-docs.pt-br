---
title: "Compilador aviso (nível 4) C4670 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4670
dev_langs:
- C++
helpviewer_keywords:
- C4670
ms.assetid: e172b134-b1fb-4dfe-8e9d-209ea08b73c7
caps.latest.revision: 6
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
ms.openlocfilehash: 35b35ee501626384f004993bbf9c7f20cc0449d4
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4670"></a>Compilador C4670 de aviso (nível 4)
'identifier': esta classe base está inacessível  
  
 A classe base especificada de um objeto a ser lançado uma **tente** bloco não está acessível. O objeto não pode ser instanciado se ela é gerada. Verifique que a classe base é herdada com o especificador de acesso correto.  
  
 O exemplo a seguir gera C4670:  
  
```  
// C4670.cpp  
// compile with: /EHsc /W4  
class A  
{  
};  
  
class B : /* public */ A  
{  
} b;   // inherits A with private access by default  
  
int main()  
{  
    try  
    {  
       throw b;   // C4670  
    }  
    catch( B )  
    {  
    }  
}  
```
