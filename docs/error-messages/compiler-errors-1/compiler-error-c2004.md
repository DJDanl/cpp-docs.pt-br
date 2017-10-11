---
title: C2004 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2004
dev_langs:
- C++
helpviewer_keywords:
- C2004
ms.assetid: d81526dd-3a00-4593-87b0-d910d3d29bca
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f4596e43fad713f6b0a81eea9e697c6e0f91c75b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2004"></a>C2004 de erro do compilador
esperado 'defined(id)'  
  
 Um identificador deve aparecer em parênteses após a palavra-chave pré-processador.  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: parênteses ausentes na diretiva de pré-processamento. Se o parêntese de fechamento está faltando de uma diretiva de pré-processamento, o compilador gerará um erro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2004:  
  
```  
// C2004.cpp  
// compile with: /DDEBUG  
#include <stdio.h>  
  
int main()   
{  
    #if defined(DEBUG   // C2004  
        printf_s("DEBUG defined\n");  
    #endif  
}  
```  
  
## <a name="example"></a>Exemplo  
 Possível solução:  
  
```  
// C2004b.cpp  
// compile with: /DDEBUG  
#include <stdio.h>  
  
int main()   
{  
    #if defined(DEBUG)  
        printf_s("DEBUG defined\n");  
    #endif  
}  
```
