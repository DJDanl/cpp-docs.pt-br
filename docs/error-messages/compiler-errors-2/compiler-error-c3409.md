---
title: C3409 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3409
dev_langs:
- C++
helpviewer_keywords:
- C3409
ms.assetid: e372d9fa-230c-4b28-b6d3-6ad81ccf9dbb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1964cffd0593e87a790befd8a76ae13847f2058d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33257264"
---
# <a name="compiler-error-c3409"></a>C3409 de erro do compilador
bloco de atributos vazio não é permitido  
  
 Os colchetes foram interpretados pelo compilador como um [atributo](../../windows/cpp-attributes-reference.md) bloco, mas nenhum atributo foi encontrado.  
  
 O compilador pode gerar esse erro quando você usa colchetes como parte da definição de uma expressão lambda. Esse erro ocorre quando o compilador não pode determinar se os colchetes são parte da definição de uma expressão lambda ou de um bloco de atributo. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Se os colchetes são parte de um bloco de atributo:  
  
    1.  Forneça um ou mais atributos no bloco de atributo.  
  
    2.  Remova o bloco de atributo.  
  
2.  Se os colchetes são parte de uma expressão lambda:  
  
    1.  Certifique-se de que a expressão lambda segue as regras de sintaxe válida.  
  
         Para obter mais informações sobre a sintaxe da expressão lambda, consulte [sintaxe da expressão Lambda](../../cpp/lambda-expression-syntax.md).  
  
    2.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3409.  
  
```  
// C3409.cpp  
// compile with: /c  
#include <windows.h>  
[]   // C3409  
class a {};  
  
// OK  
[object, uuid("00000000-0000-0000-0000-000000000000")]  
__interface x {};  
  
[coclass, uuid("00000000-0000-0000-0000-000000000001")]  
class b : public x {};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3409 porque uma expressão lambda usa o `mutable` especificação, mas não fornece uma lista de parâmetros. O compilador não pode determinar se os colchetes são parte da definição de uma expressão lambda ou de um bloco de atributo.  
  
```  
// C3409b.cpp  
  
int main()  
{  
   [] mutable {}();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Atributo](../../windows/cpp-attributes-reference.md)   
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)   
 [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)