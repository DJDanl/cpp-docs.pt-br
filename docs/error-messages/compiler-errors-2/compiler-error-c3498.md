---
title: C3498 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3498
dev_langs:
- C++
helpviewer_keywords:
- C3498
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
caps.latest.revision: 8
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
ms.openlocfilehash: 15ab0c7ec9bfce79ad128dc0e48719d35ef380fc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3498"></a>C3498 de erro do compilador
'var': não é possível capturar uma variável que possui um gerenciado ou WinRTtype  
  
 Você não pode capturar uma variável que possui um tipo gerenciado ou um tipo de tempo de execução do Windows na lambda.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Passar o gerenciado ou variável de tempo de execução do Windows à lista de parâmetros da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3498 porque uma variável que possui um tipo gerenciado aparece na lista de captura de uma expressão lambda:  
  
```  
// C3498a.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String ^ s = "Hello";  
   [&s](String ^ r)   
      { return String::Concat(s, r); } (", World!"); // C3498  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir resolve C3498, passando a variável gerenciada `s` à lista de parâmetros da expressão lambda:  
  
```  
// C3498b.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String ^ s = "Hello";  
   [](String ^ s, String ^ r)   
      { return String::Concat(s, r); } (s, ", World!");  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
