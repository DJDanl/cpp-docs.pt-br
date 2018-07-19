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
ms.openlocfilehash: 27e78f7429c4d2a0f83ff7184460eb2ae69df129
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38960980"
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