---
title: "Ponto de declaração em C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- point of declaration
ms.assetid: 92ea8707-80cb-497c-b479-f907b8401859
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 64c1fa1d6d8feb4b869957101bb4b37f125d0f8b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="point-of-declaration-in-c"></a>Ponto de declaração em C++
Um nome é considerado declarado imediatamente após seu declarator, mas antes de seu inicializador (opcional). (Para obter mais informações sobre declaradores, consulte [declarações e definições](declarations-and-definitions-cpp.md).)  
  
 Considere este exemplo:  
  
```  
// point_of_declaration1.cpp  
// compile with: /W1   
double dVar = 7.0;  
int main()  
{  
   double dVar = dVar;   // C4700  
}  
```  
  
 Se o ponto de declaração *depois* a inicialização e, em seguida, local `dVar` deve ser inicializado para 7.0, o valor da variável global `dVar`. No entanto, como não é esse o caso, `dVar` é inicializado como um valor indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Escopo](../cpp/scope-visual-cpp.md)