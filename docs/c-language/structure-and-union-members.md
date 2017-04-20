---
title: "Membros de união e estrutura | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- member-selection operators
- structure members, referencing
- -> operator, structure and union members
- dot operator (.)
- referencing structure members
- . operator
- operators [C], member selection
- structure member selection
ms.assetid: bb1fe304-af49-4f98-808d-afdc99b3e319
caps.latest.revision: 8
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
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 31118df209db98435a3b9cfb0c38e17dbd818d01
ms.lasthandoff: 04/01/2017

---
# <a name="structure-and-union-members"></a>Membros de união e estrutura
Uma "expressão de seleção de membros" faz referência a membros de estruturas e de uniões. Essas expressões têm o valor e o tipo do membro selecionado.  
  
```  
  
postfix-expression  
.  
identifier  
postfix-expression  
->  
identifier  
  
```  
  
 A lista a seguir descreve os dois formatos de expressões de seleção de membros:  
  
1.  No primeiro formato, *postfix-expression* representa um valor do tipo `struct` ou **união** e *identificador* nomeia um membro da estrutura ou da união especificada. O valor da operação é o de *identificador* e é um l-value se *postfix-expression* for um l-value. Consulte [Expressões de L-value e R-value](../c-language/l-value-and-r-value-expressions.md) para obter mais informações.  
  
2.  No segundo formato, *postfix-expression* representa um ponteiro para uma estrutura ou união e *identificador* nomeia um membro da estrutura ou união especificada. O valor é o de *identificador* e é um l-value.  
  
 Os dois formatos de expressões de seleção de membros têm efeitos semelhantes.  
  
 De fato, uma expressão que envolva o operador de seleção de membros (**->**) é uma versão resumida de uma expressão usando o ponto (****) se a expressão antes do período consistir no operador de indireção (**\***) aplicado a um valor do ponteiro. Portanto,  
  
```  
  
expression  
->  
identifier  
  
```  
  
 equivale a  
  
```  
  
(*  
expression  
) .  
identifier  
  
```  
  
 quando *expressão* for um valor do ponteiro.  
  
## <a name="examples"></a>Exemplos  
 Os exemplos a seguir fazem referência a essa declaração de estrutura. Para obter informações sobre o operador de indireção (**\***) usado nestes exemplos, consulte o tópico sobre [operadores Indirection e Address-of](../c-language/indirection-and-address-of-operators.md).  
  
```  
struct pair   
{  
    int a;  
    int b;  
    struct pair *sp;  
} item, list[10];  
```  
  
 Uma expressão de seleção de membros para a estrutura `item` é semelhante a:  
  
```  
item.sp = &item;  
```  
  
 No exemplo anterior, o endereço da estrutura `item` é atribuído ao membro `sp` da estrutura. Isso significa que `item` contém um ponteiro para si mesmo.  
  
```  
(item.sp)->a = 24;  
```  
  
 Neste exemplo, a expressão de ponteiro `item.sp` é usada com o operador de seleção de membros (**->**) para atribuir um valor ao membro `a`.  
  
```  
list[8].b = 12;  
```  
  
 Essa instrução mostra como selecionar um membro individual da estrutura em uma matriz de estruturas.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de acesso de membro: . e ->](../cpp/member-access-operators-dot-and.md)
