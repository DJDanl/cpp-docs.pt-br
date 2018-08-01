---
title: Ponto de declaração em C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- point of declaration
ms.assetid: 92ea8707-80cb-497c-b479-f907b8401859
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 89f94cdee6be18436b3f39f840fb7880e5860adb
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409371"
---
# <a name="point-of-declaration-in-c"></a>Ponto de declaração em C++
Um nome é considerado declarado imediatamente após seu declarator, mas antes de seu inicializador (opcional). (Para obter mais informações sobre os declaradores, consulte [declarações e definições](declarations-and-definitions-cpp.md).)  
  
 Considere este exemplo:  
  
```cpp 
// point_of_declaration1.cpp  
// compile with: /W1   
double dVar = 7.0;  
int main()  
{  
   double dVar = dVar;   // C4700  
}  
```  
  
 Se o ponto de declaração fosse *após* a inicialização e, em seguida, o local `dVar` seria inicializado como 7.0, o valor da variável global `dVar`. No entanto, como não é esse o caso, `dVar` é inicializado como um valor indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Escopo](../cpp/scope-visual-cpp.md)