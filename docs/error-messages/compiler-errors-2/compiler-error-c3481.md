---
title: C3481 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3481
dev_langs:
- C++
helpviewer_keywords:
- C3481
ms.assetid: 5d09375a-5ed3-4b61-86ed-45e91fd734c7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77fc0f542a74cb077e59882e31dd1acb10c7b7e9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33250479"
---
# <a name="compiler-error-c3481"></a>C3481 de erro do compilador
'var': variável de captura de lambda não encontrada  
  
 O compilador não foi possível encontrar a definição de uma variável que é passado para a lista de captura de uma expressão lambda.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remova a variável na lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3481 porque a variável `n` não está definido:  
  
```  
// C3481.cpp  
  
int main()  
{  
   [n] {}(); // C3481  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)