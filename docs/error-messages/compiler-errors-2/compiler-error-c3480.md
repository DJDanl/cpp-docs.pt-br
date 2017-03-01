---
title: C3480 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3480
dev_langs:
- C++
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
caps.latest.revision: 9
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
ms.openlocfilehash: 0fda755a1443e084baf63fc2dc84dbab4295a3dc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3480"></a>C3480 de erro do compilador
'var': uma variável de captura lambda deve ser de um escopo delimitador de função  
  
 A variável de captura lambda não é de um escopo delimitador da função.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remova a variável na lista da expressão lambda captura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3480 porque a variável `global` não está em um escopo delimitador de função:  
  
```  
// C3480a.cpp  
  
int global = 0;  
int main()  
{  
   [&global] { global = 5; }(); // C3480  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir resolve C3480 removendo a variável `global` na lista da expressão lambda captura:  
  
```  
// C3480b.cpp  
  
int global = 0;  
int main()  
{  
   [] { global = 5; }();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
