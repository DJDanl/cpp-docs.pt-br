---
title: Atribuição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], assignment
- assignment operators [C++], overloaded
ms.assetid: d87e4f89-f8f5-42c1-9d3c-184bca9d0e15
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c6343d7be23e633fe383343bd7f154d5cc9bb234
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39407605"
---
# <a name="assignment"></a>Atribuição
O operador de atribuição (**=**) é, estritamente falando, um operador binário. Sua declaração é idêntica a qualquer outro operador binário, com as seguintes exceções:  
  
-   Ele deve ser uma função de membro não estático. Não **operador =** pode ser declarado como uma função não membro.  
  
-   Ele não é herdado por classes derivadas.  
  
-   Um padrão **operador =** função pode ser gerada pelo compilador para tipos de classe, se não houver nenhum.  
  
 O exemplo a seguir ilustra como declarar um operador de atribuição:  
  
```cpp 
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
  
```cpp 
pt1 = pt2 = pt3;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)