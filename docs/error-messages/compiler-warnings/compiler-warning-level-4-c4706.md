---
title: "Compilador aviso (nível 4) C4706 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4706
dev_langs:
- C++
helpviewer_keywords:
- C4706
ms.assetid: 89cd3f4f-812c-4a4b-9426-65a5a6d1b99c
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d4f4edcbf4a4cb147c2acb8e6cb530a4a0f9a9a9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4706"></a>Compilador C4706 de aviso (nível 4)
atribuição dentro de expressão condicional  
  
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
  
 O aviso ocorrerá mesmo se você duplicar os parênteses ao redor da condição de teste:  
  
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
  
 Se sua intenção é uma relação de teste e não podem fazer uma atribuição, use o `==` operador. Por exemplo, a seguinte linha testes se um e b são iguais:  
  
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
  
 Se você pretende fazer o teste o resultado de uma atribuição de valor, teste para garantir que a atribuição é diferente de zero ou não nulo. Por exemplo, o código a seguir não irá gerar esse aviso:  
  
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
