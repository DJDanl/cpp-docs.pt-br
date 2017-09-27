---
title: Incremento e decremento sobrecarregamento (C++) | Microsoft Docs
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
- increment operators
- increment operators, types of
- decrement operators
- decrement operators, types of
ms.assetid: 5423c6ce-3999-4a77-92f6-ad540add1b1d
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
ms.openlocfilehash: 432863fd2d1600ff0e82a69813c0513a32c56612
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="increment-and-decrement-operator-overloading-c"></a>Sobrecarga dos operadores de incremento e decremento (C++)
Os operadores de incremento e decremento formam uma categoria especial porque há duas variantes de cada um:  
  
-   Pré-incremento e pós-incremento  
  
-   Pré-decremento e pós-decremento  
  
 Ao escrever funções de operador sobrecarregado, pode ser útil implementar versões separadas para as versões pré-fixada e pós-fixada desses operadores. Para distinguir entre as duas versões, observa-se a seguinte regra: a forma pré-fixada do operador é declarada exatamente da mesma maneira que qualquer outro operador unário; a forma pós-fixada aceita um argumento adicional do tipo `int`.  
  
> [!NOTE]
>  Ao especificar um operador sobrecarregado para a forma pós-fixada do operador de incremento ou decremento, o argumento adicional deve ser do tipo `int`; especificar qualquer outro tipo gera um erro.  
  
 O exemplo a seguir mostra como definir operadores de incremento e decremento pré-fixados e pós-fixados para a classe `Point`:  
  
```  
// increment_and_decrement1.cpp  
class Point  
{  
public:  
   // Declare prefix and postfix increment operators.  
   Point& operator++();       // Prefix increment operator.  
   Point operator++(int);     // Postfix increment operator.  
  
   // Declare prefix and postfix decrement operators.  
   Point& operator--();       // Prefix decrement operator.  
   Point operator--(int);     // Postfix decrement operator.  
  
   // Define default constructor.  
   Point() { _x = _y = 0; }  
  
   // Define accessor functions.  
   int x() { return _x; }  
   int y() { return _y; }  
private:  
   int _x, _y;  
};  
  
// Define prefix increment operator.  
Point& Point::operator++()  
{  
   _x++;  
   _y++;  
   return *this;  
}  
  
// Define postfix increment operator.  
Point Point::operator++(int)  
{  
   Point temp = *this;  
   ++*this;  
   return temp;  
}  
  
// Define prefix decrement operator.  
Point& Point::operator--()  
{  
   _x--;  
   _y--;  
   return *this;  
}  
  
// Define postfix decrement operator.  
Point Point::operator--(int)  
{  
   Point temp = *this;  
   --*this;  
   return temp;  
}  
int main()  
{  
}  
```  
  
 Os mesmos operadores podem ser definidos no escopo do arquivo (globalmente) usando os seguintes cabeçalhos de função:  
  
```  
friend Point& operator++( Point& )      // Prefix increment  
friend Point& operator++( Point&, int ) // Postfix increment  
friend Point& operator--( Point& )      // Prefix decrement  
friend Point& operator--( Point&, int ) // Postfix decrement  
```  
  
 O argumento do tipo `int` que denota a forma pós-fixada do operador de incremento ou decremento não é muito usado para passar argumentos. Em geral, ele contém o valor 0. No entanto, pode ser usado como se segue:  
  
```  
// increment_and_decrement2.cpp  
class Int  
{  
public:  
    Int &operator++( int n );  
private:  
    int _i;  
};  
  
Int& Int::operator++( int n )  
{  
    if( n != 0 )    // Handle case where an argument is passed.  
        _i += n;  
    else  
        _i++;       // Handle case where no argument is passed.  
    return *this;  
}  
int main()  
{  
   Int i;  
   i.operator++( 25 ); // Increment by 25.  
}  
```  
  
 Não há nenhuma outra sintaxe para usar os operadores de incremento ou decremento para passar esses valores que não seja a invocação explícita, conforme mostrado no código acima. Uma maneira mais simples de implementar essa funcionalidade é sobrecarregar o operador de adição/atribuição (`+=`).  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)
