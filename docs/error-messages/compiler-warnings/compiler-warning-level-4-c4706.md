---
title: "Compilador (nível 4) de aviso C4706 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4706
dev_langs: C++
helpviewer_keywords: C4706
ms.assetid: 89cd3f4f-812c-4a4b-9426-65a5a6d1b99c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b128a60ce35bc6ec7cce7e10c257fe63d926fa46
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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