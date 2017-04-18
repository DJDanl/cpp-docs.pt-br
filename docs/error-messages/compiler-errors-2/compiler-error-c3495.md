---
title: C3495 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3495
dev_langs:
- C++
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
caps.latest.revision: 8
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
ms.openlocfilehash: ef8e734669137abdb7d4647f0b87de587765bb3e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3495"></a>C3495 de erro do compilador
'var': uma captura lambda deve ter duração automática de armazenamento  
  
 Não será possível capturar uma variável que não tem duração de armazenamento automático, como uma variável que está marcado como `static` ou `extern`.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não transmita um `static` ou `extern` variável à lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3495 porque o `static` variável `n` aparece na lista de captura de uma expressão lambda:  
  
```  
// C3495.cpp  
  
int main()  
{  
   static int n = 66;  
   [&n]() { return n; }(); // C3495  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)   
 [(NOTINBUILD) Especificadores de classe de armazenamento](http://msdn.microsoft.com/en-us/10b3d22d-cb40-450b-994b-08cf9a211b6c)
