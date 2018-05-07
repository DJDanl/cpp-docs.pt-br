---
title: Compilador (nível 4) de aviso C4706 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4706
dev_langs:
- C++
helpviewer_keywords:
- C4706
ms.assetid: 89cd3f4f-812c-4a4b-9426-65a5a6d1b99c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1131147a9600525746cb3e89119189ed9e5026a7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4706"></a>Compilador C4706 de aviso (nível 4)
atribuição em expressão condicional  
  
 O valor de teste em uma expressão condicional foi o resultado de uma atribuição.  
  
 Uma atribuição tem um valor (o valor no lado esquerdo da atribuição) que pode ser usado legalmente em outra expressão, incluindo uma expressão de teste.  
  
 O exemplo a seguir gera C4706:  
  
```  
// C4706a.cpp  
// compile with: /W4  
int main()  
{  
   int a = 0, b = 0;  
   if ( a  = b ) // C4706  
   {  
   }  
}  
```  
  
 O aviso ocorrerá mesmo se você duplicar os parênteses delimitando a condição de teste:  
  
```  
// C4706b.cpp  
// compile with: /W4  
int main()  
{  
   int a = 0, b = 0;  
   if ( ( a  =  b ) ) // C4706  
   {  
   }  
}  
```  
  
 Se sua intenção for uma relação de teste e não podem fazer uma atribuição, use o `==` operador. Por exemplo, a seguinte linha testes se um e b são iguais:  
  
```  
// C4706c.cpp  
// compile with: /W4  
int main()  
{  
   int a = 0, b = 0;  
   if ( a == b )  
   {  
   }  
}  
```  
  
 Se você pretende fazer com que o teste o resultado de uma atribuição de valor, teste para garantir que a atribuição é diferente de zero ou não nulo. Por exemplo, o código a seguir não gerará este aviso:  
  
```  
// C4706d.cpp  
// compile with: /W4  
int main()  
{  
   int a = 0, b = 0;  
   if ( ( a = b ) != 0 )  
   {  
   }  
}  
```