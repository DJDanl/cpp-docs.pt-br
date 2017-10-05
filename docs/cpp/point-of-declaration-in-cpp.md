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
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 77f66182052cc2a031b7f1f8db8018f49b36801d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
