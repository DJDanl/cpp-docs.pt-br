---
title: C3498 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3498
dev_langs: C++
helpviewer_keywords: C3498
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0429b9d21829f772596b6d0fd2c51d72b0924e26
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3498"></a>C3498 de erro do compilador
'var': não é possível capturar uma variável que tenha um gerenciado ou WinRTtype  
  
 Não é possível capturar uma variável que possui um tipo gerenciado ou um tipo de tempo de execução do Windows em uma expressão lambda.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Passe o gerenciado ou variável de tempo de execução do Windows à lista de parâmetros da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3498 como uma variável que possui um tipo gerenciado aparece na lista de captura de uma expressão lambda:  
  
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
 O exemplo a seguir elimina C3498, passando a variável gerenciada `s` à lista de parâmetros da expressão lambda:  
  
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