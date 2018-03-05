---
title: "Atribuição | Microsoft Docs"
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
- operators [C++], assignment
- assignment operators [C++], overloaded
ms.assetid: d87e4f89-f8f5-42c1-9d3c-184bca9d0e15
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4c11664b5a7089187099898fa375cd612e92a83b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="assignment"></a>Atribuição
O operador de atribuição (**=**) é estritamente falando, um operador binário. Sua declaração é idêntica a qualquer outro operador binário, com as seguintes exceções:  
  
-   Ele deve ser uma função de membro não estático. Nenhum `operator=` pode ser declarado como uma função diferente de membro.  
  
-   Ele não é herdado por classes derivadas.  
  
-   Uma função padrão `operator=` pode ser gerada pelo compilador para tipos de classe, se nenhum existir. (Para obter mais informações sobre o padrão `operator=` funções, consulte [Memberwise atribuição e inicialização](http://msdn.microsoft.com/en-us/94048213-8b49-4416-8069-b1b7a6f271f9).)  
  
 O exemplo a seguir ilustra como declarar um operador de atribuição:  
  
```  
// assignment.cpp  
class Point  
{  
public:  
   Point &operator=( Point & );  // Right side is the argument.  
   int _x, _y;  
};  
  
// Define assignment operator.  
Point &Point::operator=( Point &ptRHS )  
{  
   _x = ptRHS._x;  
   _y = ptRHS._y;  
  
   return *this;  // Assignment operator returns left side.  
}  
  
int main()  
{  
}  
```  
  
 Observe que o argumento fornecido é o lado direito da expressão. O operador retorna o objeto para preservar o comportamento do operador de atribuição, que retorna o valor do lado esquerdo após a conclusão da atribuição. Isso permite a gravação de instruções como:  
  
```  
pt1 = pt2 = pt3;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)