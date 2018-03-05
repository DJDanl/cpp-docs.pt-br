---
title: "Função de chamada (C++) | Microsoft Docs"
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
- function calls, C++ functions
- functions [C++], calling
- operator overloading [C++], function calls
- function overloading [C++], function-call operator
- function calls, operator
- operators [C++], overloading
- operator overloading [C++], examples
- function call operator ()
ms.assetid: 5094254a-045b-46f7-8653-69bc91e80dce
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e6d130f087f635306083e58faf7c77b252fc9360
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="function-call-c"></a>Chamada de função (C++)
O operador de chamada de função, invocado usando parênteses, é um operador binário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
primary-expression ( expression-list )  
```  
  
## <a name="remarks"></a>Comentários  
 Neste contexto, `primary-expression` é o primeiro operando e `expression-list`, uma possível lista de argumentos vazia, é o segundo. O operador de chamada de função é usado para operações que exigem um número de parâmetros. Isso funciona porque `expression-list` é uma lista em vez de um operando único. O operador de chamada de função deve ser uma função de membro não estático.  
  
 O operador de chamada de função, quando sobrecarregado, não modifica o modo como as funções são chamadas; modifica o modo como o operador deve ser interpretado quando aplicado aos objetos de um tipo de classe. Por exemplo, o código a seguir normalmente não teria sentido:  
  
```  
Point pt;  
pt( 3, 2 );  
```  
  
 Entretanto, com um operador de chamada de função sobrecarregado apropriado, essa sintaxe pode ser usada para deslocar a coordenada `x` 3 unidades e a coordenada `y` 2 unidades. O código a seguir mostra essa definição:  
  
```  
// function_call.cpp  
class Point  
{  
public:  
    Point() { _x = _y = 0; }  
    Point &operator()( int dx, int dy )  
        { _x += dx; _y += dy; return *this; }  
private:  
    int _x, _y;  
};  
  
int main()  
{  
   Point pt;  
   pt( 3, 2 );  
}  
```  
  
 Observe que o operador de chamada de função é aplicado ao nome de um objeto, não ao nome de uma função.  
  
 Você pode também sobrecarregar o operador de chamada de função usando um ponteiro para a função (em vez da própria função).  
  
```cpp  
typedef void(*ptf)();  
void func()  
{  
}  
struct S  
{  
   operator ptf()  
   {  
      return func;  
   }  
};  
  
int main()  
{  
   S s;  
   s();//operates as s.operator ptf()()  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)